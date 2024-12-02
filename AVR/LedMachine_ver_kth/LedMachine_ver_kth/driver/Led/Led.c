#include "Led.h"

void Led_init(Led_t *led, volatile uint8_t *ddr, volatile uint8_t *port, uint8_t pinNum)
{
	led ->ddr = ddr;
	led ->port = port;
	led ->pinNum = pinNum;
	*led->ddr |= (1<<(led->pinNum));
}

uint8_t Led_On(Led_t *led)
{
	*(led->port) |= (1<< led->pinNum);
}

uint8_t Led_Off(Led_t *led)
{
	*(led->port) &= ~(1<< led->pinNum);
}
