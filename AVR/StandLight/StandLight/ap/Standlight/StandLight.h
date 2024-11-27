
#ifndef STANDLIGHT_H_
#define STANDLIGHT_H_

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "../../Driver/Button/Button.h"
#include "../../Driver/Led/Led.h"

enum {level_0,level_1,level_2,level_3,level_4};

btn_t buttonMode, buttonOff;
led_t led_0,led_1,led_2,led_3,led_4,led_5,led_6,led_7;


void StandLight_init();
void StandLight_execute();
void led0();
void led1();
void led2();
void led3();
void led4();


#endif /* STANDLIGHT_H_ */