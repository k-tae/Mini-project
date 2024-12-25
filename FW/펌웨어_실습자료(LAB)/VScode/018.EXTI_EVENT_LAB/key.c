#include "device_driver.h"

void Key_Poll_Init(void) {
  Macro_Set_Bit(RCC->APB2ENR, 3);
  Macro_Write_Block(GPIOB->CRL, 0xff, 0x44, 24);
}

#define COUNT_FOR_CHAT 20000

static int Key_Check_Input(void) {
  return ~Macro_Extract_Area(GPIOB->IDR, 0x3, 6) & 0x3;
}

int Key_Get_Pressed(void) {
  unsigned int i, k;

  for (;;) {
    k = Key_Check_Input();

    for (i = 0; i < COUNT_FOR_CHAT; i++) {
      if (k != Key_Check_Input()) {
        break;
      }
    }

    if (i == COUNT_FOR_CHAT) break;
  }

  return k;
}

void Key_Wait_Key_Released(void) { while (Key_Get_Pressed()); }

int Key_Wait_Key_Pressed(void) {
  int k;

  while ((k = Key_Get_Pressed()) == 0);
  return k;
}

void Key_ISR_Enable(int en) {
  if (en) {
    // GPIO-B Port�� AFIO Clock Enable(RXX->APB2ENR)
    RCC->APB2ENR |= (1 << 3) | (1 << 0);
    // PB[7:6]�� �Է����� ����(GPIOB->CRL)
    Macro_Write_Block(GPIOB->CRL, 0xff, 0x44, 24);
    // PB[7:6]�� EXTI �ҽ��� ����(AFIO->EXTICR[1])
    Macro_Write_Block(AFIO->EXTICR[1], 0xff, 0x11, 8);
    // EXT[7:6]�� Falling Edge�� ����(EXTI->FTSR)
    Macro_Set_Area(EXTI->FTSR, 0x3, 6);
    // EXT[7:6] ���ͷ�Ʈ Pending Clear(EXTI->PR)
    EXTI->PR = 3 << 6;
    // IRQ #23 Pending Clear(CMSIS Function)
    NVIC_ClearPendingIRQ(23);
    // EXT[7:6] ���ͷ�Ʈ ���(EXTI->IMR)
    Macro_Set_Area(EXTI->IMR, 0x3, 6);
    // IRQ #23 ���ͷ�Ʈ ���(CMSIS Function)
    NVIC_EnableIRQ(23);
  }

  else {
    NVIC_DisableIRQ(23);
    Macro_Clear_Bit(RCC->APB2ENR, 3);
    Macro_Clear_Bit(RCC->APB2ENR, 0);
  }
}
