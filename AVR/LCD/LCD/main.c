#define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/io.h>
#include <stdio.h>
#include "driver/LCD/LCD.h"

int main(void)
{
	LCD_init();
	
	char buff[30];
	uint16_t counter = 0;
    
    while (1) 
    {
		 sprintf(buff, "counter : %d", counter++);
		 LCD_writeStringXY(buff,0,3);
		 _delay_ms(1000);
    }
	
}