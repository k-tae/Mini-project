#include "device_driver.h"

void Key_Poll_Init(void)
{
	Macro_Set_Bit(RCC->APB2ENR, 3);
	Macro_Write_Block(GPIOB->CRL, 0xff, 0x44, 24);
}

/* 0: ������ ���� */
/* 1: ���� ���ۿ� ���� */

#if 0
	#define N	20000
#else
	#define N	3000000
#endif

int Key_Get_Pressed(void)
{
	/* N ��ŭ ���� ���� ������ Key ������ ���� */



}

void Key_Wait_Key_Released(void)
{
	while(Key_Get_Pressed());
}

int Key_Wait_Key_Pressed(void)
{
	int k;

	while((k = Key_Get_Pressed()) == 0);
	return k;
}
