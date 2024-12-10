#include "device_driver.h"

void Main(void)
{
	volatile int i;

	Uart_Init(115200);
	Uart_Printf("CMSIS Based Register Define\n");

	// �� �κ��� �������� �� ��
	RCC->APB2ENR |= (1<<3);

	// LED Pin�� ������� ����


	for(;;)
	{
		// LED ��� ON


		for(i=0; i<0x40000; i++);

		// LED ��� OFF


		for(i=0; i<0x40000; i++);
	}
}
