#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "ap/Clock/Clock.h"
#include "driver/fnd/fnd.h"
#include "driver/LCD/LCD.h"

ISR(TIMER0_OVF_vect)
{
	FND_ISR_Process();
	TCNT0 = 131;
}

ISR(TIMER2_COMP_vect)
{
	Clock_incMilisec();
}

int main(void)
{
	Clock_init();
	//Global Interrupt Enable
	sei();
	
	while (1)
	{
		Clock_run();
		
	}
}

