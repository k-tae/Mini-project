#include "StandLight.h"

uint8_t state;

void StandLight_init()
{
	state = level_0;
	BUTTON_init(&buttonMode,&DDRA,&PINA,0);
	BUTTON_init(&buttonOff,&DDRA,&PINA,1);
	LED_init(&led_0,&DDRD,&PORTD,0);
	LED_init(&led_1,&DDRD,&PORTD,1);
	LED_init(&led_2,&DDRD,&PORTD,2);
	LED_init(&led_3,&DDRD,&PORTD,3);
	LED_init(&led_4,&DDRD,&PORTD,4);
	LED_init(&led_5,&DDRD,&PORTD,5);
	LED_init(&led_6,&DDRD,&PORTD,6);
	LED_init(&led_7,&DDRD,&PORTD,7);
}

void StandLight_execute()
{
	switch(state)
	{
		case level_0:
		led0();
		if (BUTTON_GETSTATE(&buttonMode) == ACT_REALESED)
		{
			led1();
			state = level_1;
		}
		break;
		case level_1:
		if (BUTTON_GETSTATE(&buttonMode) == ACT_REALESED)
		{
			led2();
			state = level_2;
		}
		if (BUTTON_GETSTATE(&buttonOff) == ACT_REALESED)
		{
			led0();
			state = level_0;
		}
		break;
		case level_2:
		if (BUTTON_GETSTATE(&buttonMode) == ACT_REALESED)
		{
			led3();
			state = level_3;
		}
		if (BUTTON_GETSTATE(&buttonOff) == ACT_REALESED)
		{
			led0();
			state = level_0;
		}
		break;
		case level_3:
		if (BUTTON_GETSTATE(&buttonMode) == ACT_REALESED)
		{
			led4();
			state = level_4;
		}
		if (BUTTON_GETSTATE(&buttonOff) == ACT_REALESED)
		{
			led0();
			state = level_0;
		}
		break;
		case level_4:
		if (BUTTON_GETSTATE(&buttonMode) == ACT_REALESED)
		{
			led0();
			state = level_0;
		}
		if (BUTTON_GETSTATE(&buttonOff) == ACT_REALESED)
		{
			led0();
			state = level_0;
		}
		break;
	}
}

void led0()
{
	LED_OFF(&led_0);
	LED_OFF(&led_1);
	LED_OFF(&led_2);
	LED_OFF(&led_3);
	LED_OFF(&led_4);
	LED_OFF(&led_5);
	LED_OFF(&led_6);
	LED_OFF(&led_7);
}

void led1()
{
	LED_ON(&led_0);
	LED_ON(&led_1);
}

void led2()
{
	LED_ON(&led_2);
	LED_ON(&led_3);
}

void led3()
{
	LED_ON(&led_4);
	LED_ON(&led_5);
}

void led4()
{
	LED_ON(&led_6);
	LED_ON(&led_7);
}