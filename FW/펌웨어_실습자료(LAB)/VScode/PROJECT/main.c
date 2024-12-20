#include "device_driver.h"

static void Sys_Init(void)
{
	Clock_Init();
	LED_Init();
	Uart_Init(115200);
	Key_Poll_Init();
	Motor_Init();
}

void Main(void)
{

	Sys_Init();

	for (;;)
	{
		while (Macro_Extract_Area(USART1->SR,0x1,5)!=1){}
		char data=USART1->DR;
		while (Macro_Extract_Area(USART1->SR,0x1,7)!=1){}
		USART1->DR = data;
		Motor_run(data);
	}
}