#include "device_driver.h"

static void Sys_Init(void)
{
	Clock_Init();
	LED_Init();
	Uart_Init(115200);
}

/* Key �ν� */

#if 1

void Main(void)
{
	Sys_Init();
	Uart_Printf("KEY Input Test #1\n");

	// KEY[1:0], GPB[7:6]�� GPIO �Է����� ����



	for(;;)
	{
		// KEY0�� �������� LED0�� ON, �� �������� OFF



		// KEY1�� �������� LED1�� ON, �� �������� OFF



	}
}

#endif

/* Key�� ���� LED Toggling */

#if 0

void Main(void)
{
	Sys_Init();
	Uart_Printf("KEY Input Toggling #1\n");


	// KEY[1:0], GPB[7:6]�� GPIO �Է����� ����



	for(;;)
	{
		// KEY0�� ���������� LED0�� ���� Toggling



	}
}

#endif
