#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

#define FND_DIGIT_DDR	DDRE
#define FND_DIGIT_PORT	PORTE
#define FND_NUM_DDR		DDRF
#define FND_NUM_PORT	PORTF
#define FND_DIGIT_1		4
#define FND_DIGIT_2		5
#define FND_DIGIT_3		6
#define FND_DIGIT_4		7


#ifndef FND_H_
#define FND_H_

void FND_init();
void FND_dispNum(uint16_t fndNum);
void FND_setfndData(uint16_t data);
void FND_ISR_Process();

#endif /* FND_H_ */