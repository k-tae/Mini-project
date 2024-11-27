#include "Led.h"

void LED_init(led_t *led, volatile uint8_t *ddr, volatile uint8_t *port, uint8_t pinNum)
{
	led -> DDR = ddr;
	led -> PORT = port;
	led -> PinNum = pinNum;
	*(led -> DDR) |= (1<<led ->PinNum);
}

void LED_OFF(led_t *led)
{
	*(led -> PORT) &= ~(1<< led -> PinNum);
}

void LED_ON(led_t *led)
{
	*(led -> PORT) |= 1<< led -> PinNum;
}