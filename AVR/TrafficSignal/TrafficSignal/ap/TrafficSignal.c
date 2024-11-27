#include "TrafficSignal.h"

led_t led_1,led_2,led_3,led_4,led_5,led_6;
button_t btnAuto,btnManual,btnSwitching;
uint8_t ledData;
uint8_t ledState = RG;
uint32_t timeTick = 0 ;
uint8_t state = Auto;

void redGreen()
{
	Led_Off(&led_2);
	Led_Off(&led_4);
	Led_On(&led_1);
	Led_On(&led_6);
}

void redYellow()
{
	Led_Off(&led_6);
	Led_On(&led_5);
}

void greenRed()
{
	Led_Off(&led_5);
	Led_Off(&led_1);
	Led_On(&led_3);
	Led_On(&led_4);
}

void yellowRed()
{
	Led_Off(&led_3);
	Led_On(&led_2);
}

void autoMode()
{
	static uint32_t prevTime = 0 ;
	switch(ledState)
	{
		case RG:
		redGreen();
		if(timeTick - prevTime >= 3000)
		{
			prevTime = timeTick;
			ledState = RY;
		}
		break;
		case RY:
		redYellow();
		if(timeTick - prevTime >= 1000)
		{
			prevTime = timeTick;
			ledState = GR;
		}
		break;
		case GR:
		greenRed();
		if(timeTick - prevTime >= 3000)
		{
			prevTime = timeTick;
			ledState = YR;
		}
		break;
		case YR:
		yellowRed();
		if(timeTick - prevTime >= 1000)
		{
			prevTime = timeTick;
			ledState = RG;
		}
		break;
	}
}

void manualMode()
{
	if (Button_GetState(&btnSwitching)==ACT_RELEASED)
	{
		ledState = (ledState +1)%4;
	}
	switch(ledState)
	{
		case RG:
		redGreen();
		break;
		case RY:
		redYellow();
		break;
		case GR:
		greenRed();
		break;
		case YR:
		yellowRed();
		break;
	}
}

//초기화
void TrafficSignal_init()
{
	Led_init(&led_1, &DDRF, &PORTF, 0);
	Led_init(&led_2, &DDRF, &PORTF, 1);
	Led_init(&led_3, &DDRF, &PORTF, 2);
	Led_init(&led_4, &DDRF, &PORTF, 3);
	Led_init(&led_5, &DDRF, &PORTF, 4);
	Led_init(&led_6, &DDRF, &PORTF, 5);
	Button_init(&btnAuto, &DDRA, &PINA, 0);
	Button_init(&btnManual, &DDRA, &PINA, 1);
	Button_init(&btnSwitching, &DDRA, &PINA, 2);
	
}
//실행
void TrafficSignal_execute()
{
	if (Button_GetState(&btnAuto))
	{
		state = Auto;
	}
	if (Button_GetState(&btnManual))
	{
		state = Manual;
	}

	switch(state)
	{
		case Auto:
		autoMode();
		break;
		case Manual:
		manualMode();
		break;
	}
	_delay_ms(1);
	timeTick++;
}