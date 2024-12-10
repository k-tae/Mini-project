#include "device_driver.h"

#if 1

void Main(void)
{
	RCC->APB2ENR |= (1<<3);

	GPIOB->CRH = 0x66 << 0;
	GPIOB->ODR = 0x1 << 8;
}

#endif

#if 0

void Main(void)
{
	/* �� �κ��� ���Ƿ� �ٲ��� ���ÿ� */
	RCC->APB2ENR |= (1<<3);

	/* ��Ʈ ������ �̿��Ͽ� LED0�� ON, LED1�� OFF�� �ϴ� �ڵ带 �����Ͻÿ� */




}

#endif

/* Bit ���� Macro Ȱ�� */

#if 0

void Main(void)
{
	/* �� �κ��� �������� �� �� */
	Macro_Set_Bit(RCC->APB2ENR, 3);

	/* Macro�� �̿��Ͽ� LED0�� ON, LED1�� OFF�� �ϴ� �ڵ带 �����Ͻÿ� */



}

#endif

/* Bit ���� Macro Ȱ�� LED Toggling */

#if 0

void Main(void)
{
	volatile int i;

	/* �� �κ��� �������� �� �� */
	Macro_Set_Bit(RCC->APB2ENR, 3);

	/* ��ũ�θ� �̿��Ͽ� �ʱ⿡ LED ��� OFF */



	for(;;)
	{
	/* LED ���� �� Delay, Delay�� 0x80000���� ���� */



	}
}

#endif
