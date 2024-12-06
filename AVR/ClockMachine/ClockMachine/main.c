#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "ap/ClockMachine/ClockMachine.h"
#include "driver/FND/fnd.h"

//ISR(TIMER0_OVF_vect)
//{
	//FND_ISR_Process();
	//TCNT0 = 131;
//}

ISR(TIMER2_COMP_vect)
{
	TimeClock_incMilisec();
	StopWatch_incMilisec();
    Modify_Blink();
	Timer_decMilisec();
}

int main(void)
{
    ClockMachine_init();
	sei();
	
    while (1) 
    {
		ClockMachine_run();
    }
}