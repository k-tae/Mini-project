#include "device_driver.h"

enum { FRONT, REVERSE, STOP };
enum { MANUAL, CDS };
uint8_t fan_state;
uint8_t state;
unsigned int KeyState;

void Motor_Init(void) {
  Macro_Set_Bit(RCC->APB2ENR, 2);
  Macro_Write_Block(GPIOA->CRL, 0xff, 0xbb, 8);
  Macro_Set_Bit(RCC->APB1ENR, 0);
  Macro_Write_Block(TIM2->CCMR2, 0x7, 0x6, 4);
  Macro_Write_Block(TIM2->CCMR2, 0x7, 0x6, 12);
  TIM2->CCER |= (0 << 13) | (1 << 12) | (0 << 9) | (1 << 8);
  TIM2->PSC = 8;
  TIM2->ARR = (double)400;
  state = MANUAL;
  fan_state = STOP;
}

void Motor_Stop(void) {
  TIM2->CCR4 = 0;
  TIM2->CCR3 = 0;  // duty rate
  Macro_Set_Bit(TIM2->EGR, 0);
  TIM2->CR1 = (1 << 4) | (0 << 3) | (1 << 0);
}

void Motor_Front(unsigned short level) {
  TIM2->CCR4 = 0;
  TIM2->CCR3 = TIM2->ARR * (level * 5 + 55) / 100;  // duty rate
  Macro_Set_Bit(TIM2->EGR, 0);
  TIM2->CR1 = (1 << 4) | (0 << 3) | (1 << 0);
}

void Motor_Reverse(unsigned short level) {
  TIM2->CCR3 = 0;
  TIM2->CCR4 = TIM2->ARR * (level * 5 + 55) / 100;  // duty rate
  Macro_Set_Bit(TIM2->EGR, 0);
  TIM2->CR1 = (1 << 4) | (0 << 3) | (1 << 0);
}

void Motor_level_Front(char data) { Motor_Front((int)data - 48); }

void Motor_level_Reverse(char data) { Motor_Reverse((int)data - 48); }

void Motor_Light(void) {
  static int prev=-1;
  Adc_Start();
  KeyState = Key0_Get_State();
  volatile unsigned int AdcState = Adc_Get_Data();
  TIM2_Delay(1);
  int current;
  if (0x000 <= AdcState && AdcState < 0x400) {
    current =0;
    Motor_Front(1);
    if (prev!=current) { 
      Uart1_Printf("%d\n",60);
    }
  } 
  else if (0x400 <= AdcState && AdcState < 0x800) {
    current =1;
    Motor_Front(4);
    if (prev!=current) { 
      Uart1_Printf("%d\n",75);
    }
  }
  else if (0x800 <= AdcState && AdcState < 0xc00) {
    current =2;
    Motor_Front(7);
    if (prev!=current) { 
      Uart1_Printf("%d\n",90);
    }
  }
  else if (0xc00 <= AdcState && AdcState <= 0xfff) {
    current =3;
    Motor_Front(9);
    if (prev!=current) { 
      Uart1_Printf("%d\n",100);
    }
  }
  else {
    current = -1;
  }
  prev = current;
}

void Motor_Manual(void) {
  while (Macro_Extract_Area(USART1->SR,0x1,5)!=1)
  {
    if ((KeyState = Key0_Get_State())==1)
    {
      return;
    }
  }
  char data = USART1->DR;
  USART1->DR = data;

  switch (fan_state) {
    case FRONT:
      if (49<=data && data<=57)
      {
        Motor_level_Front(data);
      }
      if (data == 'S' || data == 's') {
        fan_state = STOP;
        Motor_Stop();
      }
      if (data == 'R' || data == 'r') {
        fan_state = REVERSE;
        Motor_level_Reverse('9');
      }
      if (data == 'F' || data == 'f')
        ;
      break;
    case REVERSE:
    if (49<=data && data<=57)
      {
        Motor_level_Reverse(data);
      }
      if (data == 'S' || data == 's') {
        fan_state = STOP;
        Motor_Stop();
      }
      if (data == 'F' || data == 'f') {
        fan_state = FRONT;
        Motor_level_Front('9');
      }
      break;
    case STOP:
      if (data == 'F' || data == 'f') {
        fan_state = FRONT;
        Motor_level_Front('9');
      }
      if (data == 'R' || data == 'r') {
        fan_state = REVERSE;
        Motor_level_Reverse('9');
      }
      break;
  }
}

void Motor_run(void) {
  
  switch (state) {
    case MANUAL:
      Motor_Manual();
      if (KeyState == 1) {
        state = CDS;
        KeyState = 0;
      }
      break;
    case CDS:
      Motor_Light();
      if (KeyState == 1) {
        state = MANUAL;
        fan_state = STOP;
        Motor_Stop();
        KeyState = 0;
      }
      break;
  }
}