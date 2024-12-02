#include "Led.h"

void LED_init(led_t *led, volatile uint8_t *ddr, volatile uint8_t *port, uint8_t pinNum)
{
	led -> DDR = ddr;
	led -> PORT = port;
	led -> PinNum = pinNum;
	//*(led -> DDR) |= (1<<led ->PinNum);
	Gpio_initPin(led->DDR, OUTPUT, led ->PinNum);
}

void LED_OFF(led_t *led)
{
	Gpio_WritePin(led->PORT,led->PinNum,GPIO_RESET);
}

void LED_ON(led_t *led)
{
	Gpio_WritePin(led->PORT,led->PinNum,GPIO_SET);
}

void LED_ALLOFF(volatile uint8_t *PORT)
{
	Gpio_WritePort(PORT,0x00);
}

void LED_ALLON(volatile uint8_t *PORT)
{
	Gpio_WritePort(PORT,0xff);
}

void LED_writeData(volatile uint8_t *PORT, uint8_t data)
{
	Gpio_WritePort(PORT,data);
};