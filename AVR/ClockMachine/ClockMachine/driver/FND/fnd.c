#include "fnd.h"

uint16_t fndData  = 0;
uint8_t fndColonFlag;

void FND_init()
{
	DDRE |= (1<<FND_DIGIT_4) |(1<<FND_DIGIT_3) |(1<<FND_DIGIT_2) |(1<<FND_DIGIT_1) ;
	DDRF = 0xff;
}

void FND_dispNum(uint16_t fndNum)
{
	uint8_t Number[11] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x80}; //0 -> 0x3f 1->0x06 2-> 0x5b 3->0x4f 4->0x66 5->0x6d 6->0x7d 7-> 0x07 8->0x7f 9->0x6f
	
	static uint8_t fndDigitState = 0;
	fndDigitState = (fndDigitState + 1) % 5;
	
	FND_DIGIT_PORT |= (1<<7) | (1<<6) | (1<<5) | (1<<4);
	switch(fndDigitState)
	{
		case 0:
		
		FND_NUM_PORT = Number[fndNum/1000%10];
		FND_DIGIT_PORT &= ~(1<<4);
		break;
		case 1:
		
		FND_NUM_PORT = Number[fndNum/100%10];
		FND_DIGIT_PORT &= ~(1<<5);
		break;
		case 2:
		
		FND_NUM_PORT = Number[fndNum/10%10];
		FND_DIGIT_PORT &= ~(1<<6);
		break;
		case 3:
		
		FND_NUM_PORT = Number[fndNum%10];
		FND_DIGIT_PORT &= ~(1<<7);
		break;
		case 4:
		if (fndColonFlag)
		{
			FND_NUM_PORT = Number[FND_COLON];
			FND_DIGIT_PORT &= ~(1<<5);			
		}
		else
		{
			FND_NUM_PORT = Number[FND_COLON];
			FND_DIGIT_PORT |= (1<<5);
		}

		break;
	}
}

void FND_setfndData(uint16_t data)
{
	fndData= data;
}

void FND_ISR_Process()
{
	FND_dispNum(fndData);
}

void FND_colonOn()
{
	fndColonFlag = 1;	
}

void FND_colonOff()
{
	fndColonFlag = 0;
}