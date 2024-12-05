#include "TIM.h"

void TIM0_OVF_init()   // 1ms interrupt Enable
{
	// prescaler /128
	TCCR0 |= (1<<CS02) |(0<<CS01) | (1<<CS00);
	//TIMSK Timer Overflow Interrupt Enable
	TIMSK |= (1<<TOIE0);
	TCNT0 = 131;
}

void TIM2_CTC_init()
{
	TCCR2 |= (0<<CS02) | (1<<CS01) | (1<<CS00); //prescaler /64
	TCCR2 |= (1<<WGM21) |(0<<WGM20); //CTC 모드
	TIMSK |= (1<<OCIE2); //Output Compare Match Interrupt Enable
	OCR2 = 249;
}