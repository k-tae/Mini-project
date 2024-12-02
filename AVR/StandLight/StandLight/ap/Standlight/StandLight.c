#include "StandLight.h"

uint8_t state;

void StandLight_init()
{
	state = level_0;
	BUTTON_init(&buttonMode,&BUTTON_DDR,&BUTTON_PIN,0);
	BUTTON_init(&buttonOff,&BUTTON_DDR,&BUTTON_PIN,1);
	LED_init(&led_0,&LED_DDR,&LED_PORT,0);
	LED_init(&led_1,&LED_DDR,&LED_PORT,1);
	LED_init(&led_2,&LED_DDR,&LED_PORT,2);
	LED_init(&led_3,&LED_DDR,&LED_PORT,3);
	LED_init(&led_4,&LED_DDR,&LED_PORT,4);
	LED_init(&led_5,&LED_DDR,&LED_PORT,5);
	LED_init(&led_6,&LED_DDR,&LED_PORT,6);
	LED_init(&led_7,&LED_DDR,&LED_PORT,7);
}

//void StandLight_execute()
//{
	//switch(state)
	//{
		//case level_0:
		//led0();
		//if (BUTTON_GETSTATE(&buttonMode) == ACT_REALESED)
		//{
			//led1();
			//state = level_1;
		//}
		//break;
		//case level_1:
		//if (BUTTON_GETSTATE(&buttonMode) == ACT_REALESED)
		//{
			//led2();
			//state = level_2;
		//}
		//if (BUTTON_GETSTATE(&buttonOff) == ACT_REALESED)
		//{
			//led0();
			//state = level_0;
		//}
		//break;
		//case level_2:
		//if (BUTTON_GETSTATE(&buttonMode) == ACT_REALESED)
		//{
			//led3();
			//state = level_3;
		//}
		//if (BUTTON_GETSTATE(&buttonOff) == ACT_REALESED)
		//{
			//led0();
			//state = level_0;
		//}
		//break;
		//case level_3:
		//if (BUTTON_GETSTATE(&buttonMode) == ACT_REALESED)
		//{
			//led4();
			//state = level_4;
		//}
		//if (BUTTON_GETSTATE(&buttonOff) == ACT_REALESED)
		//{
			//led0();
			//state = level_0;
		//}
		//break;
		//case level_4:
		//if (BUTTON_GETSTATE(&buttonMode) == ACT_REALESED)
		//{
			//led0();
			//state = level_0;
		//}
		//if (BUTTON_GETSTATE(&buttonOff) == ACT_REALESED)
		//{
			//led0();
			//state = level_0;
		//}
		//break;
	//}
//}

void StandLight_run()
{
	StandLight_eventCheck();
	
	StandLight_execute();
}
void StandLight_eventCheck()
{
	switch(state)
	{
		case level_0:
		if (BUTTON_GETSTATE(&buttonMode) ==ACT_REALESED)
		{
			state = level_1;
		}
		break;
		case level_1:
		if (BUTTON_GETSTATE(&buttonMode) ==ACT_REALESED)
		{
			state = level_2;
		}
		else if (BUTTON_GETSTATE(&buttonOff) ==ACT_REALESED)
		{
			state = level_0;
		}
		break;
		case level_2:
		if (BUTTON_GETSTATE(&buttonMode) ==ACT_REALESED)
		{
			state = level_3;
		}
		else if (BUTTON_GETSTATE(&buttonOff) ==ACT_REALESED)
		{
			state = level_0;
		}
		break;
		case level_3:
		if (BUTTON_GETSTATE(&buttonMode) ==ACT_REALESED)
		{
			state = level_4;
		}
		else if (BUTTON_GETSTATE(&buttonOff) ==ACT_REALESED)
		{
			state = level_0;
		}
		break;
		case level_4:
		if (BUTTON_GETSTATE(&buttonMode) ==ACT_REALESED)
		{
			state = level_0;
		}
		else if (BUTTON_GETSTATE(&buttonOff) ==ACT_REALESED)
		{
			state = level_0;
		}
		break;
	}
}

void StandLight_execute()
{
	if (state == level_0)
	{
		led0();
	}
	if (state == level_1)
	{
		led1();
	}
	if (state == level_2)
	{
		led2();
	}
	if (state == level_3)
	{
		led3();
	}
	if (state == level_4)
	{
		led4();
	}
}

void led0()
{
	LED_ALLOFF(&LED_PORT);
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