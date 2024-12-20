#include "device_driver.h"


#if 0
void Main(void)
{
	volatile int i, j;

	LED_Init();

	for(i=0;i<16;i++)
	{
		LED_Display(i);
		for(j=0; j<0x40000; j++);
	}

	for(;;)
	{
		LED_All_Off();
		for(j=0; j<0x20000; j++);

		LED_All_On();
		for(j=0; j<0x20000; j++);
	}
}

#endif

#if 1
void Main(void)
{
	volatile int i;
	Macro_Write_Block(GPIOA->CRL,0xf,0x6,8);
	Macro_Clear_Bit(GPIOA->ODR,2);
	for(;;)
	{
		Macro_Invert_Bit(GPIOA->ODR,2);
		for(i=0;i<0x40000;i++)
		{}
	}
}

#endif