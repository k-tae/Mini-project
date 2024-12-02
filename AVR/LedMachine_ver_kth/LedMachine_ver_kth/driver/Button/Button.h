#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

#ifndef BUTTON_H_
#define BUTTON_H_

enum {PUSHED,RELEASED};
enum {ACT_NONE,ACT_PUSHED,ACT_RELEASED};
	

typedef struct _button
{
	volatile uint8_t *ddr;
	volatile uint8_t *pin;
	uint8_t pinNum;
	uint8_t prevState;
} btn_t;

uint8_t Button_GetState(btn_t *btn);
void Button_init(btn_t *btn, volatile uint8_t *DDR, volatile uint8_t *PIN, uint8_t PINNUM);


#endif /* BUTTON_H_ */