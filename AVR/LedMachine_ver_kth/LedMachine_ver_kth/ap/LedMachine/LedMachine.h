#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "../../driver/Button/Button.h"
#include "../../driver/Led/Led.h"


#ifndef LEDMACHINE_H_
#define LEDMACHINE_H_

enum {led1_on, led1_off, led2_on, led2_off, led3_on, led3_off, led4_on, led4_off};
	
void LedMachine_init();
void L1_On();
void L1_Off();
void L2_On();
void L2_Off();
void L3_On();
void L3_Off();
void L4_On();
void L4_Off();
void LedMahine_run();
btn_t b_left, b_right;
Led_t led_1,led_2,led_3,led_4;

#endif /* LEDMACHINE_H_ */