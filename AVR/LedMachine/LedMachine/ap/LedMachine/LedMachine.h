
#ifndef LEDMACHINE_H_
#define LEDMACHINE_H_
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "../../driver/Button/Button.h"
#include "../../driver/Led/Led.h"

enum {led1, led2, led3, led4};
void L1();
void L2();
void L3();
void L4();
void LedMachine_init();
void LedMachine_execute();


#endif /* LEDMACHINE_H_ */