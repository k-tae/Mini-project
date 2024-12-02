#include "LedMachine.h"

uint8_t state;
uint32_t timeTick=0;
static uint32_t prevTime;

void LedMachine_init()
{
	Button_init (&b_left,&DDRA, &PINA, 0);
	Button_init (&b_right,&DDRA, &PINA, 1);
	Led_init(&led_1,&DDRD,&PORTD,0);
	Led_init(&led_2,&DDRD,&PORTD,1);
	Led_init(&led_3,&DDRD,&PORTD,2);
	Led_init(&led_4,&DDRD,&PORTD,3);
	state = led1_on;
}

void L1_On()
{
	Led_On(&led_1);
	
	if (timeTick -prevTime >= 200)
	{
		prevTime = timeTick;
		state = led1_off;
	}
}

void L1_Off()
{
	Led_Off(&led_1);
	if (timeTick -prevTime >= 200)
	{
		prevTime = timeTick;
		state = led1_on;
	}
}

void L2_On()
{
	Led_On(&led_2);
	if (timeTick -prevTime >= 200)
	{
		prevTime = timeTick;
		state = led2_off;
	}
}

void L2_Off()
{
	Led_Off(&led_2);
	if (timeTick -prevTime >= 200)
	{
		prevTime = timeTick;
		state = led2_on;
	}
}

void L3_On()
{
	Led_On(&led_3);
	if (timeTick -prevTime >= 200)
	{
		prevTime = timeTick;
		state = led3_off;
	}
}

void L3_Off()
{
	Led_Off(&led_3);
	if (timeTick -prevTime >= 200)
	{
		prevTime = timeTick;
		state = led3_on;
	}
}

void L4_On()
{
	Led_On(&led_4);
	if (timeTick -prevTime >= 200)
	{
		prevTime = timeTick;
		state = led4_off;
	}
}

void L4_Off()
{
	Led_Off(&led_4);
	if (timeTick -prevTime >= 200)
	{
		prevTime = timeTick;
		state = led4_on;
	}
}

void LedMahine_run()
{
	switch(state)
	{
		case led1_on:
		L1_On();
		if (Button_GetState(&b_left) == ACT_RELEASED)
		{
			state = led2_on;
			L1_Off();
		}
		else if (Button_GetState(&b_right) == ACT_RELEASED)
		{
			state = led4_on;
			L1_Off();
		}
		break;
		case led1_off:
		L1_Off();
		if (Button_GetState(&b_left) == ACT_RELEASED)
		{
			state = led2_on;
		}
		else if (Button_GetState(&b_right) == ACT_RELEASED)
		{
			state = led4_on;
		}
		break;
		case led2_on:
		L2_On();
		if (Button_GetState(&b_left) == ACT_RELEASED)
		{
			state = led3_on;
			L2_Off();
		}
		else if (Button_GetState(&b_right) == ACT_RELEASED)
		{
			state = led1_on;
			L2_Off();
		}
		break;
		case led2_off:
		L2_Off();
		if (Button_GetState(&b_left) == ACT_RELEASED)
		{
			state = led3_on;
		}
		else if (Button_GetState(&b_right) == ACT_RELEASED)
		{
			state = led1_on;
		}
		break;
		case led3_on:
		L3_On();
		if (Button_GetState(&b_left) == ACT_RELEASED)
		{
			state = led4_on;
			L3_Off();
		}
		else if (Button_GetState(&b_right) == ACT_RELEASED)
		{
			state = led2_on;
			L3_Off();
		}
		break;
		case led3_off:
		L3_Off();
		if (Button_GetState(&b_left) == ACT_RELEASED)
		{
			state = led4_on;
		}
		else if (Button_GetState(&b_right) == ACT_RELEASED)
		{
			state = led2_on;
		}
		break;
		case led4_on:
		L4_On();
		if (Button_GetState(&b_left) == ACT_RELEASED)
		{
			state = led1_on;
			L4_Off();
		}
		else if (Button_GetState(&b_right) == ACT_RELEASED)
		{
			state = led3_on;
			L4_Off();
		}
		break;
		case led4_off:
		L4_Off();
		if (Button_GetState(&b_left) == ACT_RELEASED)
		{
			state = led1_on;
		}
		else if (Button_GetState(&b_right) == ACT_RELEASED)
		{
			state = led3_on;
		}
		break;
	}
	_delay_ms(1);
	timeTick++;
}