#ifndef STOPWATCH_H_
#define STOPWATCH_H_
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include "../../driver/fnd/fnd.h"
#include "../../periph/TIM/TIM.h"
#include "../../driver/Button/Button.h"
#include "../../driver/LCD/LCD.h"

enum {SECMIL,HOURMIN,MODIFY};
void Clock_incMilisec();
void Clock_init();
void Clock_run();
void Clock_eventCheck();
void Clock_execute();
#endif /* STOPWATCH_H_ */