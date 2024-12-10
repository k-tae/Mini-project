#include "device_driver.h"
#include <stdlib.h>

#define LCDW (320)
#define LCDH (240)
#define X_MIN (0)
#define X_MAX (LCDW - 1)
#define Y_MIN (0)
#define Y_MAX (LCDH - 1)

#define TIMER_PERIOD (10)

static unsigned short color[] = {RED, YELLOW, GREEN, BLUE, WHITE, BLACK};

extern volatile int TIM4_expired;
extern volatile int Jog_key_in;
extern volatile int Jog_key;

void Main(void)
{
	Uart_Printf("Game Project\n");

	Lcd_Init();
	Jog_Poll_Init();
	Jog_ISR_Enable(1);
	Uart1_RX_Interrupt_Enable(1);
	Lcd_Clr_Screen();

	int frog_pos_x = (LCDW / 2), frog_pos_y = LCDH - 10;
	int tick_count = 0;
	int Car_count = 0;
	int frog_size = 10;
	int car_size = 10;
	int feed_pos_x = (rand() % 31) * 10;
	int feed_pos_y = (rand() % 23) * 10;
	int Score = 0;
	int car_pos_x[10] = {150, (rand() % 31) * 10, (rand() % 31) * 10, (rand() % 31) * 10, (rand() % 31) * 10, (rand() % 31) * 10, (rand() % 31) * 10, (rand() % 31) * 10, (rand() % 31) * 10, (rand() % 31) * 10};
	int car_pos_y[10] = {80, (rand() % 23) * 10, (rand() % 23) * 10, (rand() % 23) * 10, (rand() % 23) * 10, (rand() % 23) * 10, (rand() % 23) * 10, (rand() % 23) * 10, (rand() % 23) * 10, (rand() % 23) * 10};
	int i;
	int Car_Num = 1;
	int j;

	TIM4_Repeat_Interrupt_Enable(1, TIMER_PERIOD * 10);
	Lcd_Draw_Box(feed_pos_x, feed_pos_y, 10, 10, color[4]);
	Lcd_Draw_Box(frog_pos_x, frog_pos_y, frog_size, frog_size, color[2]);
	Lcd_Draw_Box(car_pos_x[0], car_pos_y[0], car_size, car_size, color[0]);

	for (;;)
	{

		if (Jog_key_in)
		{
			switch (Jog_key)
			{
			case 0:
				if (frog_pos_y == Y_MIN)
					break;
				else
				{
					Lcd_Draw_Box(frog_pos_x, frog_pos_y, frog_size, frog_size, color[5]);
					frog_pos_y -= 10;
					Lcd_Draw_Box(frog_pos_x, frog_pos_y, frog_size, frog_size, color[2]);
					Jog_key_in = 0;
				}
				break;
			case 1:
				if (frog_pos_y == LCDH - 10)
					break;
				else
				{
					Lcd_Draw_Box(frog_pos_x, frog_pos_y, frog_size, frog_size, color[5]);
					frog_pos_y += 10;
					Lcd_Draw_Box(frog_pos_x, frog_pos_y, frog_size, frog_size, color[2]);
					Jog_key_in = 0;
				}
				break;
			case 2:
				if (frog_pos_x == X_MIN)
					break;
				else
				{
					Lcd_Draw_Box(frog_pos_x, frog_pos_y, frog_size, frog_size, color[5]);
					frog_pos_x -= 10;
					Lcd_Draw_Box(frog_pos_x, frog_pos_y, frog_size, frog_size, color[2]);
					Jog_key_in = 0;
				}
				break;
			case 3:
				if (frog_pos_x == LCDW - 10)
					break;
				else
				{
					Lcd_Draw_Box(frog_pos_x, frog_pos_y, frog_size, frog_size, color[5]);
					frog_pos_x += 10;
					Lcd_Draw_Box(frog_pos_x, frog_pos_y, frog_size, frog_size, color[2]);
					Jog_key_in = 0;
				}
				break;
			}
		}

		if ((frog_pos_x == feed_pos_x) && (frog_pos_y == feed_pos_y))
		{
			Score += 1;
			feed_pos_x = (rand() % 31) * 10;
			feed_pos_y = (rand() % 23) * 10;
			Lcd_Draw_Box(feed_pos_x, feed_pos_y, 10, 10, color[4]);
			Uart_Printf("Score : %d\n", Score);
		}
		else
		{
			for (i = 0; i < Car_Num; i++)
			{
				if ((car_pos_x[i] == feed_pos_x) && (car_pos_y[i] == feed_pos_y))
				{
					Score -= 1;
					feed_pos_x = (rand() % 31) * 10;
					feed_pos_y = (rand() % 23) * 10;
					Lcd_Draw_Box(feed_pos_x, feed_pos_y, 10, 10, color[4]);
					Uart_Printf("Score : %d\n", Score);
				}
			}
		}

		for (i = 0; i < Car_Num; i++)
		{
			if ((frog_pos_x == car_pos_x[i]) && (frog_pos_y == car_pos_y[i]))
			{
				break;
			}
		}
		if ((frog_pos_x == car_pos_x[i]) && (frog_pos_y == car_pos_y[i]))
		{
			Uart_Printf("Game Over");
			break;
		}
		if (TIM4_expired)
		{
			tick_count = (tick_count + 1) % 5;

			if (tick_count == 0)
			{
				for (i = 0; i < Car_Num; i++)
				{
					int R = rand() % 4;
					int new_x = car_pos_x[i];
					int new_y = car_pos_y[i];
					switch (R)
					{
					case 0:
						if (car_pos_x[i] + 10 <= X_MAX)
							new_x = car_pos_x[i] + 10;
						break;
					case 1:
						if (car_pos_x[i] - 10 >= X_MIN)
							new_x = car_pos_x[i] - 10;
						break;
					case 2:
						if (car_pos_y[i] + 10 <= Y_MAX)
							new_y = car_pos_y[i] + 10;
						break;
					case 3:
						if (car_pos_y[i] - 10 >= Y_MIN)
							new_y = car_pos_y[i] - 10;
						break;
					}

					int collision = 0;
					for (j = 0; j < Car_Num; j++)
					{
						if (i != j && new_x == car_pos_x[j] && new_y == car_pos_y[j])
						{
							collision = 1;
							break;
						}
					}

					if (!collision)
					{
						Lcd_Draw_Box(car_pos_x[i], car_pos_y[i], car_size, car_size, color[5]);
						car_pos_x[i] = new_x;
						car_pos_y[i] = new_y;
						Lcd_Draw_Box(car_pos_x[i], car_pos_y[i], car_size, car_size, color[0]);
					}
				}
			}

			Car_count = (Car_count + 1) % 200;
			if (Car_count == 0 && Car_Num != 9)
			{
				Car_Num = Car_Num + 1;
			}

			TIM4_expired = 0;
		}
	}
}
