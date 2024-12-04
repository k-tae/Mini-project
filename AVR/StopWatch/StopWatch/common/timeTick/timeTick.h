#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>


#ifndef TIMETICK_H_
#define TIMETICK_H_

void incTick();
void Tick_init();
uint32_t getTick();

#endif /* TIMETICK_H_ */