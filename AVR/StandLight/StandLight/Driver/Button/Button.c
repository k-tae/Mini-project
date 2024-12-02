#include "Button.h"

void BUTTON_init(btn_t *btn, volatile uint8_t *ddr, volatile uint8_t *pin, uint8_t pinNum)
{
	btn ->DDR = ddr;
	btn ->PIN = pin;
	btn ->PinNum = pinNum;
	btn ->prevstate = Realesed;
	//*(btn->DDR) &= ~(1<<btn->PinNum);
	Gpio_initPin(btn->DDR,INPUT,btn->PinNum);
}

uint8_t BUTTON_GETSTATE(btn_t *btn)
{	
	uint8_t cur_state = Gpio_ReadPin(btn->PIN,btn->PinNum);
	//uint8_t cur_state = *(btn -> PIN) & (1<<(btn -> PinNum));
	if ((cur_state == Pushed) && (btn->prevstate) == Realesed)
	{
		_delay_ms(10);
		btn -> prevstate = Pushed;
		return ACT_PUSHED; 
	}
	else if (!(cur_state == Pushed) && (btn->prevstate) == Pushed)
	{
		_delay_ms(10);
		btn -> prevstate = Realesed;
		return ACT_REALESED;
	}
	return ACT_NONE;
}