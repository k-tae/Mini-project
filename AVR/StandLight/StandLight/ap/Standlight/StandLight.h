
#ifndef STANDLIGHT_H_
#define STANDLIGHT_H_

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "../../Driver/Button/Button.h"
#include "../../Driver/Led/Led.h"

#define		LED_DDR		DDRD
#define		LED_PORT	PORTD
#define		BUTTON_DDR	DDRA
#define		BUTTON_PIN	PINA

enum {level_0,level_1,level_2,level_3,level_4};

btn_t buttonMode, buttonOff;
led_t led_0,led_1,led_2,led_3,led_4,led_5,led_6,led_7;


void StandLight_init();
void StandLight_run();
void led0();
void led1();
void led2();
void led3();
void led4();
void StandLight_eventCheck();
void StandLight_execute();


#endif /* STANDLIGHT_H_ */