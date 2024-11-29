#include "LedMachine.h"

uint8_t state;
uint8_t timeTick=0;
void LedMachine_init();
{
	Button_init (b_right,&DDRA, &PINA, 0);
	Button_init (b_right,&DDRA, &PINA, 1);
	Led_init(led_1,&DDRD,&PORTD,0);
	Led_init(led_2,&DDRD,&PORTD,1);
	Led_init(led_3,&DDRD,&PORTD,2);
	Led_init(led_4,&DDRD,&PORTD,3);
	state = 1;
}
void LedMahine_run();
{
	switch(state)
	{
		case 1:
		break;
		case 2:
		break;
		case 3:
		break;
		case 4:
		break;
	}
	_delay_ms(1);
	timeTick++;
}