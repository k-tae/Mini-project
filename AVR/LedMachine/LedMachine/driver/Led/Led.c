#include "Led.h"

void Led_init()
{
	LED_DDR = 0xff;
}

void Led_writeData(uint8_t data)
{
	LED_PORT = data;
}

void Led_allOff()
{
	LED_PORT = 0x00;
}

void Led_allOn()
{
	LED_PORT = 0xff;
}