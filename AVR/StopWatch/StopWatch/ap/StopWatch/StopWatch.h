#ifndef STOPWATCH_H_
#define STOPWATCH_H_
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "../../driver/fnd/fnd.h"
#include "../../periph/TIM/TIM.h"
#include "../../driver/Button/Button.h"

enum {STOP,RUN,RESET};
void StopWatch_incMilisec();
void StopWatch_init();
void StopWatch_run();
void StopWatch_eventCheck();
void StopWatch_execute();
#endif /* STOPWATCH_H_ */