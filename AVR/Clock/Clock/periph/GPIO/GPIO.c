#include "GPIO.h"

//init - port (8EA or 5EA)
//init - pin (1EA)

void Gpio_initPort(volatile uint8_t * DDR, uint8_t dir)
{
	if (dir == OUTPUT)
	{
		*DDR = 0xff;
	}
	else
	{
		*DDR = 0x00;
	}
}

void Gpio_initPin(volatile uint8_t * DDR, uint8_t dir, uint8_t pinNum)
{
	if (dir == OUTPUT)
	{
		*DDR |= (1<<pinNum);
	}
	if (dir == INPUT)
	{
		*DDR &= ~(1<<pinNum);
	}
}

//Output - port
//Output - pin

void Gpio_WritePort(volatile uint8_t *PORT, uint8_t data)
{
	*PORT = data;
}

void Gpio_WritePin(volatile uint8_t *PORT, uint8_t pinNum, uint8_t state)
{
	if (state == GPIO_RESET)
	{
		*PORT &= ~(1<< pinNum);
	}
	if (state == GPIO_SET)
	{
		*PORT |= 1<< pinNum;
	}
}

//input - port
//input - pin

uint8_t Gpio_ReadPort(volatile uint8_t *PIN)
{
	return *PIN;
}

uint8_t Gpio_ReadPin(volatile uint8_t *PIN, uint8_t pinNum)
{
	return ((*PIN & (1<<pinNum)) != 0);
	//return (*PIN &(1<<pinNum)) >> pinNum;
}