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
	Uart_Printf("UART Echo-Back Test\n");

	for(;;)
	{
		// 받은 글자를 다시 UART로 출력한다
		while (Macro_Extract_Area(USART1->SR,0x1,5)!=1){}
		char data=USART1->DR;
		while (Macro_Extract_Area(USART1->SR,0x1,7)!=1){}
		
		USART1->DR = data;
	}
}