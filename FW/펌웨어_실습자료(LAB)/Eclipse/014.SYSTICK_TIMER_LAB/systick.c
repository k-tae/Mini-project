#include "device_driver.h"

void SysTick_Run(unsigned int msec)
{
	// Timer ���� : ���ͷ�Ʈ �߻� ����, clock source�� HCLK/8, Timer ����

	// �־��� msec �� ��ŭ�� msec�� count�ϴ� �ʱⰪ ���� (LOAD)

	// VAL �������� �� �ʱ�ȭ(0) �� COUNTFLAG Clear

	// Timer Start (������ �Ǹ� �ڵ����� LOAD�� ���� VAL�� ��������)

}

int SysTick_Check_Timeout(void)
{
	// Timer�� Timeout�� �߻��ϸ� ��(1)����, �ƴϸ� ����(0) ����

}

unsigned int SysTick_Get_Time(void)
{
	// Timer�� ���� count �� ����

}

unsigned int SysTick_Get_Load_Time(void)
{
	// Timer�� ������ �ʱⰪ�� ����

}

void SysTick_Stop(void)
{
	// Timer Stop

}
