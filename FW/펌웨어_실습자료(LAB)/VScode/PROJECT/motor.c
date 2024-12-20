#include "device_driver.h"

enum {FRONT,REVERSE,STOP};
uint8_t state;

void Motor_Init(void)
{
	Macro_Set_Bit(RCC->APB2ENR, 2);
	Macro_Write_Block(GPIOA->CRL, 0xff, 0xbb, 8);
	Macro_Set_Bit(RCC->APB1ENR, 0);
	Macro_Write_Block(TIM2->CCMR2,0x7,0x6,4);
	Macro_Write_Block(TIM2->CCMR2,0x7,0x6,12);
	TIM2->CCER |= (0<<13)|(1<<12)|(0<<9)|(1<<8);
    TIM2->PSC = 8;
    TIM2->ARR = (double)4000;
    state=STOP;
}

void Motor_Stop(void)
{
	TIM2->CCR4 = TIM2->ARR*100/100;
	TIM2->CCR3 = TIM2->ARR*100/100; //duty rate
	Macro_Set_Bit(TIM2->EGR,0);
	TIM2->CR1 = (1<<4)|(0<<3)|(1<<0);
}

void Motor_Front(unsigned short level)
{
	TIM2->CCR4 = TIM2->ARR*0/100;
	TIM2->CCR3 = TIM2->ARR*(level*5+50)/100; //duty rate
	Macro_Set_Bit(TIM2->EGR,0);
	TIM2->CR1 = (1<<4)|(0<<3)|(1<<0);
}

void Motor_Reverse(unsigned short level)
{
	TIM2->CCR3 = TIM2->ARR*0/100;
	TIM2->CCR4 = TIM2->ARR*(level*5+50)/100; //duty rate
	Macro_Set_Bit(TIM2->EGR,0);
	TIM2->CR1 = (1<<4)|(0<<3)|(1<<0);
}

void Motor_level_Front(char data)
{
    Motor_Front((int)data-48);
}

void Motor_level_Reverse(char data)
{
    Motor_Reverse((int)data-48);
}

void Motor_run(char data)
{
    switch(state)
    {
        case FRONT:
        Motor_level_Front(data);
        if (data == 'S'|| data=='s')
        {
            state = STOP;
            Motor_Stop();
        }
        if (data == 'R' || data == 'r')
        {
            state = REVERSE;
            Motor_level_Reverse('1');
        }
        if (data == 'F' || data=='f');
        break;
        case REVERSE:
        Motor_level_Reverse(data);
        if (data == 'S'|| data=='s')
        {
            state = STOP;
            Motor_Stop();
        }
        if (data == 'F' || data == 'f')
        {
            state = FRONT;
            Motor_level_Front('1');
        }
        break;
        case STOP:
        if (data == 'F' || data == 'f')
        {
            state = FRONT;
            Motor_level_Front('1');
        }
        if (data == 'R' || data == 'r')
        {
            state = REVERSE;
            Motor_level_Reverse('1');
        }
        
        break;
    }
}