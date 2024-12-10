#include "device_driver.h"

void Main(void)
{
	volatile int i;

	Uart_Init(115200);
	Uart_Printf("CMSIS Based Register Define\n");

	// 이 부분은 수정하지 말 것
	RCC->APB2ENR |= (1<<3);

	// LED Pin을 출력으로 설정


	for(;;)
	{
		// LED 모두 ON


		for(i=0; i<0x40000; i++);

		// LED 모두 OFF


		for(i=0; i<0x40000; i++);
	}
}
