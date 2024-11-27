#include "Button.h"

void Button_init(button_t *btn, volatile uint8_t *ddr,volatile uint8_t *pin,uint8_t pinNum) //버튼이 연결된 곳을 정의하는 함수
{
	btn -> DDR = ddr;
	btn -> PIN = pin;
	btn -> pinNum = pinNum;
	btn -> prevstate = RELEASED;
	*btn -> DDR &= ~(1<<btn->pinNum); //DDRx의 pinNum을 입력모드로 바꾸겠다.
}

uint8_t Button_GetState(button_t *btn) //버튼의 동작을 얻어오는 함수
{
	uint8_t curState = *(btn -> PIN) & (1<<(btn -> pinNum));

	if ((curState == PUSHED) && ((btn -> prevstate) == RELEASED))
	{
		_delay_ms(10);
		btn -> prevstate = PUSHED;
		return ACT_PUSHED;
	}

	else if ((curState != PUSHED) && (btn -> prevstate  == PUSHED))
	{
		_delay_ms(10);
		btn -> prevstate = RELEASED;
		return ACT_RELEASED;
	}
	return ACT_NONE;
}