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

void Main(void)
{
	Sys_Init();
	Uart1_Printf("EXTI Test\n");

	// AFIO, Port-B Clock Enable

	// PB[7:6]�� �Է����� ����

	// PB[7:6]�� EXTI �ҽ��� �����ϰ� Falling edge ����, EXTI[7:6] ���ͷ�Ʈ ���

	// EXTI[7:6] Pending Clear �� NVIC�� ���ͷ�Ʈ Pending clear

	// EXTI9_5 ���ͷ�Ʈ ���

	for(;;)
	{
		LED_Display(1);
		TIM2_Delay(500);
		LED_Display(2);
		TIM2_Delay(500);
	}
}
