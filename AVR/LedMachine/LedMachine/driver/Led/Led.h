


#ifndef LED_H_
#define LED_H_
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#define		LED_DDR		DDRD
#define		LED_PORT	PORTD

void Led_init();
void Led_writeData(uint8_t data);
void Led_allOff();
void Led_allOn();


#endif /* LED_H_ */