#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "ap/Standlight/StandLight.h"
#include "periph/GPIO/GPIO.h"

int main(void)
{
    StandLight_init();
	
    while (1) 
    {
		//StandLight_execute();
		StandLight_run();
    }
}

