#include "Clock.h"

uint16_t milisec;
uint8_t sec, min, hour;

uint8_t state;

btn_t btnMode, btnModify, btnHour, btnMin;

void Clock_init()
{
	milisec = 0;
	sec = 0;
	min = 0;
	hour = 0;
	state = SECMIL;
	FND_init();
	LCD_init();
	TIM0_OVF_init();
	TIM2_CTC_init();
	BUTTON_init(&btnMode,&DDRA,&PINA,0);
	BUTTON_init(&btnModify,&DDRA,&PINA,1);
	BUTTON_init(&btnHour,&DDRA,&PINA,2);
	BUTTON_init(&btnMin,&DDRA,&PINA,3);
}

void Clock_incMilisec()
{
	if(state == SECMIL || state == HOURMIN)
	{
		milisec = (milisec+1) % 1000;
		if(milisec) return;
		
		sec = (sec+1) % 60;
		if(sec) return;
		
		min = (min+1) % 60;
		if(min) return;
		
		hour = (hour+1) % 24;
		if(hour) return;
	}
}

void Clock_eventCheck()
{
	switch(state)
	{
		case SECMIL:
		if (BUTTON_GETSTATE(&btnMode) == ACT_REALESED)
		{
			state = HOURMIN;
		}
		break;
		case HOURMIN:
		if (BUTTON_GETSTATE(&btnMode) == ACT_REALESED)
		{
			state = SECMIL;
		}
		if (BUTTON_GETSTATE(&btnModify) == ACT_REALESED)
		{
			state = MODIFY;
		}
		break;
		case MODIFY:
		if (BUTTON_GETSTATE(&btnModify) == ACT_REALESED)
		{
			state = HOURMIN;
		}
		if (BUTTON_GETSTATE(&btnHour) == ACT_REALESED)
		{
			hour = (hour+1)%24;
		}
		if (BUTTON_GETSTATE(&btnMin) == ACT_REALESED)
		{
			min = (min+1)%60;
		}
		break;
	}
}

void Clock_execute()
{
	uint16_t stopWatchData;
	switch(state)
	{
		char Time[10];
		case SECMIL:
		stopWatchData =  (sec*100) + (milisec/10);
		FND_setfndData(stopWatchData);
		if ((milisec%100)<50)
		{
			FND_colonOn();
		}
		else
		{
			FND_colonOff();
		}
		static uint8_t prevSec = 0xff;
		if(sec!=prevSec)
		{
			LCD_writeStringXY("Time Clock",0,3);
			sprintf(Time,"%02d:%02d:%02d",hour,min,sec);
			LCD_writeStringXY(Time,1,4);
			prevSec=sec;
		}
		break;
		case HOURMIN:
		stopWatchData =  hour*100 + min;
		FND_setfndData(stopWatchData);
		if (milisec<500)
		{
			FND_colonOn();
		}
		else
		{
			FND_colonOff();
		}
		if(sec!=prevSec)
		{
			LCD_writeStringXY("Time Clock",0,3);
			sprintf(Time,"%02d:%02d:%02d",hour,min,sec);
			LCD_writeStringXY(Time,1,4);
			prevSec=sec;
		}
		break;
		case MODIFY:
		stopWatchData =  hour*100 + min;
		FND_setfndData(stopWatchData);
		sprintf(Time,"%02d:%02d:%02d",hour,min,sec);
		LCD_writeStringXY(Time,1,4);
		break;
	}
}

void Clock_run()
{
	Clock_eventCheck();
	Clock_execute();
}