#include "Button.h"

void Button_init(btn_t *btn, volatile uint8_t *DDR, volatile uint8_t *PIN, uint8_t PINNUM)
{
	btn -> ddr = DDR;
	btn -> pin = PIN;
	btn -> pinNum = PINNUM;
	btn -> prevState = RELEASED;
	*btn -> ddr &= ~(1<<(btn -> pinNum));
}

uint8_t Button_GetState(btn_t *btn)
{
	uint8_t curstate= *(btn->pin) & (1<<btn->pinNum);

	if((curstate == PUSHED) && ((btn ->prevState)==RELEASED))
	{
		_delay_ms(10);
		btn -> prevState = PUSHED;
		return ACT_PUSHED;
	}
	if((curstate != PUSHED) && ((btn ->prevState)==PUSHED))
	{
		_delay_ms(10);
		btn -> prevState = RELEASED;
		return ACT_RELEASED;
	}
	return ACT_NONE;
}