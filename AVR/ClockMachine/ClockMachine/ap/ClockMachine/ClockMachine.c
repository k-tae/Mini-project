#include "ClockMachine.h"

uint16_t milisec, stopWatchmilisec, modifymilisec, timermilisec;
uint8_t sec, min, hour, stopWatchsec,stopWatchmin,stopWatchhour,timerhour,timermin,timersec,modifysec ;

uint8_t state;
uint16_t Time;

led_t led0,led1,led2,led3,led4,led5,led6,led7;
btn_t btnMode, btn2, btn3, btn4;

void ClockMachine_init()
{
	milisec = 0;
	sec = 0;
	min = 0;
	hour = 0;
	stopWatchmilisec = 0;
	stopWatchsec = 0;
	stopWatchmin = 0;
	stopWatchhour = 0;
	timerhour = 0;
	timermin = 0;
	timersec = 0;
	timermilisec = 0;
	state = CLOCK_NORMAL;
	FND_init();
	LCD_init();
	//TIM0_OVF_init();
	TIM2_CTC_init();
	Led_init(&led0,&DDRD,&PORTD,0);
	Led_init(&led1,&DDRD,&PORTD,1);
	Led_init(&led2,&DDRD,&PORTD,2);
	Led_init(&led3,&DDRD,&PORTD,3);
	Led_init(&led4,&DDRD,&PORTD,4);
	Led_init(&led5,&DDRD,&PORTD,5);
	Led_init(&led6,&DDRD,&PORTD,6);
	Led_init(&led7,&DDRD,&PORTD,7);
	BUTTON_init(&btnMode,&DDRA,&PINA,0);
	BUTTON_init(&btn2,&DDRA,&PINA,1);
	BUTTON_init(&btn3,&DDRA,&PINA,2);
	BUTTON_init(&btn4,&DDRA,&PINA,3);
}

void TimeClock_incMilisec()
{
	
	if(state != CLOCK_MODIFY)
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
void Modify_Blink()
{
	if(state == CLOCK_MODIFY)
	{
		modifymilisec = (modifymilisec+1) % 1000;
		if(modifymilisec) return;
	}
}


void StopWatch_incMilisec()
{
	if(state == STOPWATCH_RUN)
	{
		stopWatchmilisec = (stopWatchmilisec+1) % 1000;
		if(stopWatchmilisec) return;
		
		stopWatchsec = (stopWatchsec+1) % 60;
		if(stopWatchsec) return;
		
		stopWatchmin = (stopWatchmin+1) % 60;
		if(stopWatchmin) return;
		
		stopWatchhour = (stopWatchhour+1) % 24;
		if(stopWatchhour) return;
	}
}

void Timer_decMilisec()
{
	if(state == TIMER_RUN)
	{
		
		if(timermilisec==0)
		{
			timermilisec = 999;
			if (timersec == 0)
			{
				timersec = 59;
				if(timermin == 0)
				{
					timermin = 59;
					timerhour = timerhour-1;
				}
				else
				timermin=timermin-1;
			}
			else
			timersec=timersec-1;
		}
		else
		timermilisec = timermilisec -1;
	}
}

void ClockMachine_eventCheck()
{
	switch(state)
	{
		case CLOCK_NORMAL:
		if (BUTTON_GETSTATE(&btnMode) == ACT_REALESED)
		{
			state = STOPWATCH_STOP;
		}
		if (BUTTON_GETSTATE(&btnModify) == ACT_REALESED)
		{
			state = CLOCK_MODIFY;
		}
		break;
		case CLOCK_MODIFY:
		if (BUTTON_GETSTATE(&btnModify) == ACT_REALESED)
		{
			state = CLOCK_NORMAL;
		}
		if (BUTTON_GETSTATE(&btnModifyHour) == ACT_REALESED)
		{
			hour=(hour+1)%24;
		}
		if (BUTTON_GETSTATE(&btnModifyMin) == ACT_REALESED)
		{
			min=(min+1)%60;
		}
		break;
		case STOPWATCH_STOP:
		if (BUTTON_GETSTATE(&btnMode) == ACT_REALESED)
		{
			LCD_writeCmdData(LCD_DISPLAY_CLEAR);
			state = TIMER_STOP;
		}
		if (BUTTON_GETSTATE(&btnStartStop) == ACT_REALESED)
		{
			state = STOPWATCH_RUN;
		}
		if (BUTTON_GETSTATE(&btnStomWatchReset) == ACT_REALESED)
		{
			state = STOPWATCH_RESET;
		}
		break;
		case STOPWATCH_RUN:
		if (BUTTON_GETSTATE(&btnStartStop) == ACT_REALESED)
		{
			state = STOPWATCH_STOP;
		}
		if (BUTTON_GETSTATE(&btnStomWatchRecord) == ACT_REALESED)
		{
			state = STOPWATCH_RECORD;
		}
		break;
		case STOPWATCH_RESET:
		state = STOPWATCH_STOP;
		break;
		case STOPWATCH_RECORD:
		state = STOPWATCH_RUN;
		break;
		case TIMER_STOP:
		if (BUTTON_GETSTATE(&btnMode) == ACT_REALESED)
		{
			state = CLOCK_NORMAL;
		}
		if (BUTTON_GETSTATE(&btnStartStop) == ACT_REALESED)
		{
			state = TIMER_RUN;
		}
		if (BUTTON_GETSTATE(&btnSet) == ACT_REALESED)
		{
			state = TIMER_SET;
		}
		if (BUTTON_GETSTATE(&btnReset) == ACT_REALESED)
		{
			timerhour = 0;
			timermin = 0;
			timersec = 0;
			timermilisec = 0;
		}
		break;
		case TIMER_SET:
		if (BUTTON_GETSTATE(&btnMode) == ACT_REALESED)
		{
			LCD_writeCmdData(LCD_DISPLAY_CLEAR);
			state = TIMER_STOP;
		}
		if (BUTTON_GETSTATE(&btnTimverHour) == ACT_REALESED)
		{
			timerhour = (timerhour+1)%100;
		}
		if (BUTTON_GETSTATE(&btnTimverMin) == ACT_REALESED)
		{
			timermin = (timermin+1)%60;
		}
		if (BUTTON_GETSTATE(&btnTimverSec) == ACT_REALESED)
		{
			timersec = (timersec+1)%60;
		}
		case TIMER_OVER:
		if (BUTTON_GETSTATE(&btnStartStop) == ACT_REALESED)
		{
			Led_Off(&led0);
			Led_Off(&led1);
			Led_Off(&led2);
			Led_Off(&led3);
			Led_Off(&led4);
			Led_Off(&led5);
			Led_Off(&led6);
			Led_Off(&led7);
			state = TIMER_STOP;
		}
		break;
	}
}

void ClockMachine_execute()
{
	char Time[10];
	switch(state)
	{
		case CLOCK_NORMAL:
		{
			static uint8_t prevSec = 0xff;
			if(sec!=prevSec)
			{
				LCD_writeStringXY("Time Clock",0,3);
				sprintf(Time,"%02d:%02d:%02d",hour,min,sec);
				LCD_writeStringXY(Time,1,4);
				prevSec=sec;
			}
		}
		break;
		case CLOCK_MODIFY:
		{
			if (modifymilisec<700)
			{
				sprintf(Time,"%02d:%02d:%02d",hour,min,sec);
				LCD_writeStringXY(Time,1,4);
			}
			else
			{
				LCD_writeStringXY("  :  :  ",1,4);
			}
		}
		break;
		case STOPWATCH_STOP:
		LCD_writeStringXY("Stop Watch",0,3);
		sprintf(Time,"%02d:%02d:%02d",stopWatchmin,stopWatchsec,stopWatchmilisec/10);
		LCD_writeStringXY(Time,1,4);
		break;
		case STOPWATCH_RUN:
		sprintf(Time,"%02d:%02d:%02d",stopWatchmin,stopWatchsec,stopWatchmilisec/10);
		LCD_writeStringXY(Time,1,4);
		break;
		case STOPWATCH_RESET:
		stopWatchmilisec = 0;
		stopWatchsec = 0;
		stopWatchmin = 0;
		stopWatchhour = 0;
		break;
		case STOPWATCH_RECORD:
		
		break;
		case TIMER_STOP:
		LCD_writeStringXY("Timer",0,5);
		sprintf(Time,"%02d:%02d:%02d",timerhour,timermin,timersec);
		LCD_writeStringXY(Time,1,4);
		break;
		case TIMER_SET:
		LCD_writeStringXY("Timer Set",0,3);
		sprintf(Time,"%02d:%02d:%02d",timerhour,timermin,timersec);
		LCD_writeStringXY(Time,1,4);
		break;
		case TIMER_RUN:
		sprintf(Time,"%02d:%02d:%02d",timerhour,timermin,timersec);
		LCD_writeStringXY(Time,1,4);
		if (timerhour==0 && timermin==0 && timersec==0)
		{
			sprintf(Time,"%02d:%02d:%02d",timerhour,timermin,timersec);
			LCD_writeStringXY(Time,1,4);
			Led_On(&led0);
			Led_On(&led1);
			Led_On(&led2);
			Led_On(&led3);
			Led_On(&led4);
			Led_On(&led5);
			Led_On(&led6);
			Led_On(&led7);
			state = TIMER_OVER;
		}
		break;
	}
}

void ClockMachine_run()
{
	ClockMachine_eventCheck();
	ClockMachine_execute();
}