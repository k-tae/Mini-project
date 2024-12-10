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
	volatile int i;

	Sys_Init();
	Uart_Printf("UART Echo-Back Test\n");

	for(;;)
	{
		Uart1_Printf("\nŰ����� �޴� ���� 10���� echo-back\n");
		Uart1_Printf("\nŰ���带 ������ �ٽ� PC�� ���ڸ� �����Ѵ� (10����)\n");

		for(i=0; i<10; i++)
		{
			Uart1_Printf("\n>");
			Uart1_Printf("%c", Uart1_Get_Char());
		}

		Uart1_Printf("\n��� LED Toggling�ϰ� ������ Ű������ x�� ������ ���� ��");

		do
		{
			LED_Display(0x1);
			for(i=0; i<0x100000; i++);
			LED_Display(0x2);
			for(i=0; i<0x100000; i++);
		}while(Uart1_Get_Pressed() != 'x');
	}
}
