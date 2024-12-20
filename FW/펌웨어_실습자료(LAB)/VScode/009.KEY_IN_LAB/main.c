#include "device_driver.h"

static void Sys_Init(void)
{
	Clock_Init();
	LED_Init();
	Uart_Init(115200);
}

/* Key 인식 */

#if 0

void Main(void)
{
	Sys_Init();
	Uart_Printf("KEY Input Test #1\n");

	// KEY[1:0], GPB[7:6]을 GPIO 입력으로 선언
	Macro_Write_Block(GPIOB->CRL,0xff,0x44,24);

	for(;;)
	{
		LED_All_Off();
		// KEY0이 눌렸으면 LED0를 ON, 안 눌렸으면 OFF
		if (!(GPIOB->IDR &(1<<6)))
		{
			LED_Display(0x01);
		}

		// KEY1이 눌렸으면 LED1를 ON, 안 눌렸으면 OFF
		if (!(GPIOB->IDR &(1<<7)))
		{
			LED_Display(0x02);
		}
	}
}

#endif

/* Key에 의한 LED Toggling */

#if 1

void Main(void)
{
	Sys_Init();
	Uart_Printf("KEY Input Toggling #1\n");
	uint8_t post=1;

	// KEY[1:0], GPB[7:6]을 GPIO 입력으로 선언
	Macro_Write_Block(GPIOB->CRL,0xff,0x44,24);


	for(;;)
	{
		// KEY0가 눌릴때마다 LED0의 값을 Toggling
		if ((post==1) && (!(GPIOB->IDR &(1<<6))))
		{
			Macro_Invert_Bit(GPIOB->ODR,8);
			post=0;
		}

		if ((post==0)&& (GPIOB->IDR &(1<<6)))
		{
			post=1;
		}
	}
}

#endif
