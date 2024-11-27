
#ifndef LED_H_
#define LED_H_

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

enum {OFF,ON};
typedef struct _led
{
	volatile uint8_t *DDR; // port
	volatile uint8_t *PORT;
	uint8_t pinNum;     // pin
} led_t;

void Led_init(led_t *led, volatile uint8_t *ddr, volatile uint8_t *port, uint8_t pinNum);
void Led_Off(led_t *led);
void Led_On(led_t *led);

#endif /* LED_H_ */