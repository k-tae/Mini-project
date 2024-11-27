#include "LedMachine.h"

uint8_t ledData;
uint32_t timeTick = 0 ;
static uint32_t prevtime ;
uint8_t ledState;
button_t btnNext, btnPrev;

void L1()
{
	if (timeTick-prevtime >= 200)
	{
		ledData ^= 0x01;
		//LED_PORT = ledData;
		Led_writeData(ledData);
		prevtime = timeTick;
	}
}

void L2()
{
	if (timeTick-prevtime >= 200)
	{
		ledData ^= 0x02;
		//LED_PORT = ledData;
		Led_writeData(ledData);
		prevtime = timeTick;
	}
}

void L3()
{
	if (timeTick-prevtime >= 200)
	{
		ledData ^= 0x04;
		//LED_PORT = ledData;
		Led_writeData(ledData);
		prevtime = timeTick;
	}

}

void L4()
{
	if (timeTick-prevtime >= 200)
	{
		ledData ^= 0x08;
		//LED_PORT = ledData;
		Led_writeData(ledData);
		prevtime = timeTick;
	}
	
}

void LedMachine_init()
{
	
	Led_init();
	Button_init(&btnNext, &DDRA, &PINA, 0);
	Button_init(&btnPrev, &DDRA, &PINA, 1);
	
	ledData = 0x01;
	ledState = led1;

}

void LedMachine_execute()
{switch(ledState)
	{
		case led1:
		L1();
		if (Button_GetState(&btnNext) == ACT_RELEASED)
		{
			ledState = led2;
			ledData=0x00;
		}
		else if (Button_GetState(&btnPrev) == ACT_RELEASED)
		{
			ledState = led4;
			ledData=0x00;
		}
		break;
		case led2:
		L2();
		if (Button_GetState(&btnNext) == ACT_RELEASED)
		{
			ledState = led3;
			ledData=0x00;
		}
		else if (Button_GetState(&btnPrev) == ACT_RELEASED)
		{
			ledState = led1;
			ledData=0x00;
		}
		break;
		case led3:
		L3();
		if (Button_GetState(&btnNext) == ACT_RELEASED)
		{
			ledState = led4;
			ledData=0x00;
		}
		else if (Button_GetState(&btnPrev) == ACT_RELEASED)
		{
			ledState = led2;
			ledData=0x00;
		}
		break;
		case led4:
		L4();
		if (Button_GetState(&btnNext) == ACT_RELEASED)
		{
			ledState = led1;
			ledData=0x00;
		}
		else if (Button_GetState(&btnPrev) == ACT_RELEASED)
		{
			ledState = led3;
			ledData=0x00;
		}
		break;
	}
	_delay_ms(1);
	timeTick ++;
}