#define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/io.h>
#ifndef CLOCKMACHINE_H_
#define CLOCKMACHINE_H_
#include <stdio.h>
#include "../../driver/fnd/fnd.h"
#include "../../periph/TIM/TIM.h"
#include "../../driver/Button/Button.h"
#include "../../driver/LCD/LCD.h"
#include "../../driver/LED/Led.h"

#define		btnModify			btn2
#define		btnModifyHour		btn3
#define		btnModifyMin		btn4
#define		btnStartStop		btn2
#define		btnStomWatchReset	btn3
#define		btnStomWatchRecord	btn4
#define		btnSet				btn3
#define		btnTimverSec		btn4
#define		btnTimverMin		btn3
#define		btnTimverHour		btn2
#define		btnReset			btn4

enum {CLOCK_NORMAL,CLOCK_MODIFY,STOPWATCH_STOP,STOPWATCH_RUN,STOPWATCH_RESET,STOPWATCH_RECORD,TIMER_STOP,TIMER_SET,TIMER_RUN,TIMER_OVER};

void TimeClock_incMilisec();
void StopWatch_incMilisec();
void Modify_Blink();
void Timer_decMilisec();
void ClockMachine_init();
void ClockMachine_run();
void ClockMachine_eventCheck();
void ClockMachine_execute();
#endif /* CLOCKMACHINE_H_ */