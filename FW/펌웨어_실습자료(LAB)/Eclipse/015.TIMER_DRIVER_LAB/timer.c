#include "device_driver.h"

void TIM2_Stopwatch_Start(void)
{
	Macro_Set_Bit(RCC->APB1ENR, 0);

	// TIM2 CR1 ����: down count, one pulse
	// PSC �ʱⰪ ���� => 20usec tick�� �ǵ��� ���� (50KHz)
	// ARR �ʱⰪ ���� => �ִ밪 0xFFFF ����
	// UG �̺�Ʈ �߻�
	// TIM2 start

}

unsigned int TIM2_Stopwatch_Stop(void)
{
	unsigned int time;

	// TIM2 stop
	// CNT �ʱ� ������ (0xffff)�� ���� CNT�� �޽��� ���̸� ���ϰ�
	// �� �޽��� �ϳ��� 20usec�̹Ƿ� 20�� ���Ѱ��� time�� ����
	// ���� time ���� ����(������ usec)

}

void TIM2_Delay(int time)
{
	Macro_Set_Bit(RCC->APB1ENR, 0);

	// TIM2 CR1 ����: down count, one pulse

	// PSC �ʱⰪ ���� => 20usec tick�� �ǵ��� ���� (50KHz)

	// ARR �ʱⰪ ���� => ��û�� time msec�� �ش��ϴ� �ʱⰪ ����

	// UG �̺�Ʈ �߻�

	// Update Interrupt Pending Clear

	// Update Interrupt Enable

	// TIM2 start

	// Wait timeout

	// Stop and Power off
	Macro_Clear_Bit(TIM2->CR1, 0);
	Macro_Clear_Bit(TIM2->DIER, 0);
}

void TIM4_Repeat(int time)
{
	Macro_Set_Bit(RCC->APB1ENR, 2);

	// TIM4 CR1: ARPE=0, down counter, repeat mode

	// PSC(50KHz),  ARR(reload�� ��) ����

	// UG �̺�Ʈ �߻�

	// Update Interrupt Pending Clear

	// Update Interrupt Enable

	// TIM4 start

}

int TIM4_Check_Timeout(void)
{
	// Ÿ�̸Ӱ� timeout �̸� 1 ����, �ƴϸ� 0 ����



}

void TIM4_Stop(void)
{
	Macro_Clear_Bit(TIM4->CR1, 0);
	Macro_Clear_Bit(TIM4->DIER, 0);
	Macro_Clear_Bit(RCC->APB1ENR, 2);
}

void TIM4_Change_Value(int time)
{
	TIM4->ARR = 50 * time;
}
