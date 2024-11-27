


#ifndef LED_H_
#define LED_H_
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

typedef struct _led
{	
	volatile uint8_t *DDR;
	volatile uint8_t *PORT;
	uint8_t PinNum;
} led_t;

void LED_init(led_t *led, volatile uint8_t *ddr, volatile uint8_t *port, uint8_t pinNum);
void LED_ON(led_t *led);
void LED_OFF(led_t *led);

#endif /* LED_H_ */