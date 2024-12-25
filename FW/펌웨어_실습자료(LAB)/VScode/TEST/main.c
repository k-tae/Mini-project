
#if 0
//문제2
#include "device_driver.h"

static void Sys_Init(void)
{
	Clock_Init();
	LED_Init();
	Uart_Init(115200);
	Key_Poll_Init();
}
void Main(void)
{
	Sys_Init();
	Macro_Write_Block(GPIOB->CRL,0xf,0x1,0);
	for(;;)
	{
		Macro_Set_Bit(GPIOB->ODR,0);
		TIM2_Delay(100);
		Macro_Clear_Bit(GPIOB->ODR,0);
		TIM2_Delay(100);
	}
}

#endif

#if 0
//문제3
#include "device_driver.h"

static void Sys_Init(void)
{
	Clock_Init();
	LED_Init();
	Uart_Init(115200);
	Key_Poll_Init();

	SCB->VTOR = 0x08003000;
	SCB->SHCSR = 0;

}

extern volatile int Key_Value;

void Main(void)
{
	Sys_Init();
	NVIC_ClearPendingIRQ(37);
	USART1->CR1 |=(1<<5);
	NVIC_EnableIRQ(37);

	for(;;)
	{
		LED_Display(1);
		TIM2_Delay(1000);
		LED_Display(0);
		TIM2_Delay(1000);
	}
}

#endif

#if 0
//문제 4
#include "device_driver.h"

static void Sys_Init(void)
{
	Clock_Init();
	Uart_Init(115200);
}

unsigned int func(unsigned int x)
{
	// 코드 구현
	Macro_Clear_Bit(x,0);
	Macro_Set_Area(x,0xf,4);
	Macro_Invert_Bit(x,23);
	return x;
}

void Main(void)
{
	Sys_Init();

	Uart_Printf("0x%.8X\n", func(0xFFFFFFFFu));
	Uart_Printf("0x%.8X\n", func(0x00000000u));
	Uart_Printf("0x%.8X\n", func(0x55555555u));
	Uart_Printf("0x%.8X\n", func(0xCCCCCCCCu));
	Uart_Printf("0x%.8X\n", func(0xAAAAAAAAu));
	Uart_Printf("0x%.8X\n", func(0x33333333u));
}

#endif

#if 0
//문제5
#include "device_driver.h"

static void Sys_Init(void)
{
	Clock_Init();
	LED_Init();
	Uart_Init(115200);
	Key_Poll_Init();
}

void Test_5(uint8_t DutyRate)
{
	TIM2->CCR4 = TIM2->ARR*DutyRate/100;
	Macro_Set_Bit(TIM2->EGR, 0);
	TIM2->CR1 = (1 << 4) | (0 << 3) | (1 << 0);
}

void Main(void)
{
	uint8_t prev=0;
	int State =0;
	Sys_Init();
	Macro_Set_Bit(RCC->APB2ENR, 2);
  	Macro_Write_Block(GPIOA->CRL, 0xf, 0xb, 12);
	Macro_Set_Bit(RCC->APB1ENR, 0);
	Macro_Write_Block(TIM2->CCMR2, 0x7, 0x6, 12);
	TIM2->CCER |= (0 << 13) | (1 << 12);
	TIM2->PSC = 8;
	TIM2->ARR = (double)8000;
	Test_5(50);

	for (;;)
	{
		uint8_t current = Key_Get_Pressed();
		switch(State)
		{
			case 0:
			if ((prev != current) && (current ==1))
			{
				Test_5(20);
				State = 1;
				prev = 1;
			}
			if ((prev != current) && (current ==2))
			{
				Test_5(80);
				State = 2;
				prev = 2;
			}
			if ((prev== 1 || prev==2) && (current == 0 ))
			{
				prev = 0;
			}
			break;
			case 1:
			if ((prev != current) && (current ==1))
			{
				Test_5(50);
				State = 0;
				prev = 1;
			}
			if ((prev != current) && (current ==2))
			{
				Test_5(80);
				State = 2;
				prev = 2;
			}
			if ((prev == 1) && (current == 0 ))
			{
				prev = 0;
			}
			break;
			case 2:
			if ((prev != current) && (current ==1))
			{
				Test_5(20);
				State = 1;
				prev = 1;
			}
			if ((prev != current) && (current ==2))
			{
				Test_5(50);
				State = 0;
				prev = 2;
			}
			if ((prev == 2) && (current == 0 ))
			{
				prev = 0;
			}
			break;
		}
		
	}
}

#endif

#if 1
//문제 6
#include "device_driver.h"

static void Sys_Init(void)
{
	Clock_Init();
	LED_Init();
	Uart_Init(115200);
	Key_Poll_Init();

	SCB->VTOR = 0x08003000;
	SCB->SHCSR = 0;
}

#define base  (500) //msec

static void Buzzer_Beep(unsigned char tone, int duration)
{
	const static unsigned short tone_value[] = {261,277,293,311,329,349,369,391,415,440,466,493,523,554,587,622,659,698,739,783,830,880,932,987};
	TIM3_Out_Freq_Generation(tone_value[tone]);
	TIM4_Repeat(duration);
	while(!TIM4_Check_Timeout())
	{
		Uart1_Printf(".");
	}
	TIM3_Out_Stop();
}

void TIM4_Repeat(int time)
{
	Macro_Set_Bit(RCC->APB1ENR, 2);

	TIM4->CR1 = (1<<4)|(1<<3);
	TIM4->PSC = (unsigned int)(TIMXCLK/(double)TIM4_FREQ + 0.5)-1;
	TIM4->ARR = TIME4_PLS_OF_1ms * time - 1;

	Macro_Set_Bit(TIM4->EGR,0);
	Macro_Clear_Bit(TIM4->SR, 0);
	Macro_Set_Bit(TIM4->DIER, 0);
	Macro_Set_Bit(TIM4->CR1, 0);
}

void Main(void)
{
	int i;

	enum key{C1, C1_, D1, D1_, E1, F1, F1_, G1, G1_, A1, A1_, B1, C2, C2_, D2, D2_, E2, F2, F2_, G2, G2_, A2, A2_, B2};
	enum note{N16=base/4, N8=base/2, N4=base, N2=base*2, N1=base*4};
	const int song1[][2] = {{G1,N4},{G1,N4},{E1,N8},{F1,N8},{G1,N4},{A1,N4},{A1,N4},{G1,N2},{G1,N4},{C2,N4},{E2,N4},{D2,N8},{C2,N8},{D2,N2}};
	const char * note_name[] = {"C1", "C1#", "D1", "D1#", "E1", "F1", "F1#", "G1", "G1#", "A1", "A1#", "B1", "C2", "C2#", "D2", "D2#", "E2", "F2", "F2#", "G2", "G2#", "A2", "A2#", "B2"};

	Sys_Init();
	Uart1_Printf("Buzzer Test!!\n");

	TIM3_Out_Init();

	Uart1_Printf("%s ", note_name[C1]);
	Buzzer_Beep(C1,N4);
	Uart1_Printf("%s ", note_name[D1]);
	Buzzer_Beep(D1,N4);
	Uart1_Printf("%s ", note_name[E1]);
	Buzzer_Beep(E1,N4);
	Uart1_Printf("%s ", note_name[F1]);
	Buzzer_Beep(F1,N4);
	Uart1_Printf("%s ", note_name[G1]);
	Buzzer_Beep(G1,N4);
	Uart1_Printf("%s ", note_name[A1]);
	Buzzer_Beep(A1,N4);
	Uart1_Printf("%s ", note_name[B1]);
	Buzzer_Beep(B1,N4);
	Uart1_Printf("%s ", note_name[C2]);
	Buzzer_Beep(C2,N4);

	Uart1_Printf("\nSong Play\n");

	for(i=0; i<(sizeof(song1)/sizeof(song1[0])); i++)
	{
		Uart1_Printf("%s ", note_name[song1[i][0]]);
		Buzzer_Beep(song1[i][0], song1[i][1]);
	}
}
#endif