#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "../../driver/Button/Button.h"
#include "../../driver/Led/Led.h"

#ifndef LEDMACHINE_H_
#define LEDMACHINE_H_

btn_t b_left, b_right;
Led_t led_1,led_2,led_3,led_4;


#endif /* LEDMACHINE_H_ */