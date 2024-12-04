#include "StopWatch.h"

uint16_t milisec;
uint8_t sec, min, hour;

uint8_t state;

btn_t btnRunStop, btnReset;

void StopWatch_init()
{
	milisec = 0;
	sec = 0;
	min = 0;
	hour = 0;
	state = STOP;
	FND_init();
	TIM0_OVF_init();
	TIM2_CTC_init();
	BUTTON_init(&btnRunStop,&DDRA,&PINA,0);
	BUTTON_init(&btnReset,&DDRA,&PINA,1);
}

void StopWatch_incMilisec()
{
	if(state == RUN)
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

void StopWatch_eventCheck()
{
	switch(state)
	{
		case STOP:
		if (BUTTON_GETSTATE(&btnRunStop) == ACT_REALESED)
		{
			state = RUN;
		}
		if( BUTTON_GETSTATE(&btnReset) == ACT_REALESED)
		{
			state = RESET;
		}
		break;
		case RUN:
		if (BUTTON_GETSTATE(&btnRunStop) == ACT_REALESED)
		{
			state = STOP;
		}
		if( BUTTON_GETSTATE(&btnReset) == ACT_REALESED)
		{
			state = RESET;
		}
		break;
		case RESET:
		state = STOP;
		break;
	}
}

void StopWatch_execute()
{
	uint16_t stopWatchData;
	switch(state)
	{
		case STOP:
		break;
		case RUN:
		if (min<10 && hour<1)
		{
			stopWatchData = (min%10 *1000) + (sec * 10) + (milisec/100);	
		}
		else if (hour<10)
		{
			stopWatchData =  min*100 + sec;
		}
		else
		{
			stopWatchData =  hour*100 + min;
		}
		FND_setfndData(stopWatchData);
		break;
		case RESET:
		milisec = 0;
		sec = 0;
		min = 0;
		hour = 0;
		stopWatchData = 0;
		FND_setfndData(stopWatchData);
		break;
	}
}

void StopWatch_run()
{
	StopWatch_eventCheck();
	StopWatch_execute();
}