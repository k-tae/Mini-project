#include "Led.h"

void Led_init(led_t *led, volatile uint8_t *ddr,volatile uint8_t *port,uint8_t pinNum)
{
	led -> DDR = ddr;
	led -> PORT = port;
	led -> pinNum = pinNum;
	*led -> DDR |= (1<<led->pinNum);
}

void Led_Off(led_t *led) 
{
	*(led->PORT) = (*(led->PORT) & ~(ON<< led -> pinNum));
}

void Led_On(led_t *led)
{
	*(led->PORT) = (*(led->PORT) | (ON<< led -> pinNum));
}