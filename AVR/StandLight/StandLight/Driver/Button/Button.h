
#ifndef BUTTON_H_
#define BUTTON_H_
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "../../periph/GPIO/GPIO.h"

enum {Pushed,Realesed};
enum {ACT_NONE,ACT_PUSHED,ACT_REALESED};
typedef struct _button
{	
	volatile uint8_t *DDR;
	volatile uint8_t *PIN;
	uint8_t PinNum;
	uint8_t prevstate;
} btn_t;

void BUTTON_init(btn_t *btn, volatile uint8_t *ddr, volatile uint8_t *pin, uint8_t pinNum);
uint8_t BUTTON_GETSTATE(btn_t *btn);


#endif /* BUTTON_H_ */