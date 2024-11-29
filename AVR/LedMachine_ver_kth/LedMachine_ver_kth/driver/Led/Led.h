#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

#ifndef LED_H_
#define LED_H_

typedef struct _led
{
	volatile uint8_t *ddr;
	volatile uint8_t *port;
	uint8_t pinNum;	
}Led_t;

void Led_init(Led_t led, volatile uint8_t *ddr, volatile uint8_t *port, uint8_t pinNum);
uint8_t Led_On(Led_t led);
uint8_t Led_Off(Led_t led);
#endif /* LEDMACHINE_H_ */