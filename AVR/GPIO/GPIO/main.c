#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>
#include <time.h>

#define		BUTTON_PIN		PINA
#define		BUTTON_DDR		DDRA
#define		BUTTON_PORT		PORTA
#define		LED_PORT		PORTD
#define		LED_DDR			DDRD

//int main(void)
//{
	//DDRD = 0xff;
	//uint8_t ledData = 0x01;
	//while(1)
	//{
		//PORTD = ledData;
		//_delay_ms(200);
		//ledData = ledData * 2;
		//if(ledData == 0)
		//ledData = 0x01;
		//PORTD = ledData;
		//_delay_ms(200);
		//ledData=(ledData>>7|ledData<<1);
	//}
//}



//
//왕복
//int main(void)
//{
	//DDRD = 0xff;  //input인지 output인지 결정
	//while (1)
	//{	PORTD = 0x01;
		//for (int i=0; i<7; i++)
		//{
			//_delay_ms(200);
			//PORTD <<= 1;
		//}
		//for (int i=0;i<7; i++)
		//{
			//_delay_ms(200);
			//PORTD >>= 1;
		//}
	//}
//}
//
//신호등
//int main(void)
//{
	//DDRD = 0xff;
	//while(1)
	//{
		//PORTD = 0x0f;
		//_delay_ms(5000);
		//PORTD = 0xf0;
		//_delay_ms(5000);
		//for (int i=0;i<10;i++)
		//{
			//PORTD = 0x00;
			//_delay_ms(500);
			//PORTD = 0xf0;
			//_delay_ms(500);
		//}
	//}
//}
//
//int main(void)
//{
	//DDRD = 0xff;
	//while(1)
	//{
		//PORTD=0x01;
		//while(PORTD!=0xff)
		//{
			//_delay_ms(200);
			//PORTD = PORTD + 0x01;
		//}
	//}
//}
//
//
//확산
//int main(void)
//{
	//DDRD = 0xff;
	//srand(time(NULL));
	//while(1)
	//{
		//PORTD = 0x00;
		//int R = rand() % 8;
		//switch(R)
		//{
			//case 0:
			//PORTD = 0x01;
			//int i = 0x01, j = 0x01;
			//while (PORTD != 0xff)
			//{
				//i=i<<1, j=j>>1;
				//_delay_ms(500);
				//PORTD = PORTD + i + j;
			//}
			//PORTD = 0xff;
			//_delay_ms(500);
			//break;
			//case 1:
			//PORTD = 0x02;  
			//i = 0x02, j = 0x02;
			//while (PORTD != 0xff)
			//{
				//i=i<<1, j=j>>1;
				//_delay_ms(500);
				//PORTD = PORTD + i + j;
			//}
			//PORTD = 0xff;
			//_delay_ms(500);
			//break;
			//case 2:
			//PORTD = 0x04;
			//i = 0x04, j = 0x04;
			//while (PORTD != 0xff)
			//{
				//i=i<<1, j=j>>1;
				//_delay_ms(500);
				//PORTD = PORTD + i + j;
			//}
			//PORTD = 0xff;
			//_delay_ms(500);
			//break;
			//case 3:
			//PORTD = 0x08;
			//i = 0x08, j = 0x08;
			//while (PORTD != 0xff)
			//{
				//i=i<<1, j=j>>1;
				//_delay_ms(500);
				//PORTD = PORTD + i + j;
			//}
			//PORTD = 0xff;
			//_delay_ms(500);
			//break;
			//case 4:
			//PORTD = 0x10;
			//i = 0x10, j = 0x10;
			//while (PORTD != 0xff)
			//{
				//i=i<<1, j=j>>1;
				//_delay_ms(500);
				//PORTD = PORTD + i + j;
			//}
			//PORTD = 0xff;
			//_delay_ms(500);
			//break;
			//case 5:
			//PORTD = 0x20;
			//i = 0x20, j = 0x20;
			//while (PORTD != 0xff)
			//{
				//i=i<<1, j=j>>1;
				//_delay_ms(500);
				//PORTD = PORTD + i + j;
			//}
			//PORTD = 0xff;
			//_delay_ms(500);
			//break;
			//case 6:
			//PORTD = 0x40;
			//i = 0x40, j = 0x40;
			//while (PORTD != 0xff)
			//{
				//i=i<<1, j=j>>1;
				//_delay_ms(500);
				//PORTD = PORTD + i + j;
			//}
			//PORTD = 0xff;
			//_delay_ms(500);
			//break;
			//case 7:
			//PORTD = 0x80;
			//i = 0x80, j = 0x80;
			//while (PORTD != 0xff)
			//{
				//i=i<<1, j=j>>1;
				//_delay_ms(500);
				//PORTD = PORTD + i + j;
			//}
			//PORTD = 0xff;
			//_delay_ms(500);
			//break;
		//}
	//}
//}
//

//차량통제 화살표1
int main()
{
	DDRD = 0xff;
	uint8_t ledData=0x03, led=0x0c;
	while(1)
	{
		PORTD = ledData;
		_delay_ms(100);
		ledData=(ledData|led);
		led<<=2;
		if (led == 0)
		{PORTD = ledData;
		_delay_ms(100);
		ledData=0x03, led=0x0c;
		}
	}
}

//차량통제 화살표2
//int main()
//{
	//DDRD = 0xff;
	//uint8_t ledData =0x03;
	//while(1)
	//{
		//for (int i=0;i<4;i++)
		//{
			//PORTD = ledData;
			//ledData = (ledData<<2)|ledData;
			//_delay_ms(500);
		//}
		//ledData=0x03;
	//}
//}

//크리스마스트리
//void delay_sec(uint8_t sec)
//{
	//volatile uint16_t i,j,k;
	//for(i=0;i<sec;i++)
	//{
		//for(j=0;j<500;j++)
		//{
			//for (k=0;k<500;k++)
			//{
				////1000*1000번 세는 중 저거를 sec번 만큼
			//}
		//}
	//}
//}
//
//int main()
//{
	//DDRD = 0xff;
	//srand(time(NULL));
	//while(1)
	//{
		//PORTD= rand() % 256;
		//delay_sec(rand()%10);
	//}
//}
//int main()
//{
	//DDRD = 0xff;
	//srand(time(NULL));
	//while(1)
	//{
		//uint8_t R = rand()%5;
		//PORTD= rand() % 256;
		//switch(R)
		//{case 0:
			//_delay_ms(50);
		//case 1:
			//_delay_ms(100);
		//case 2:
			//_delay_ms(150);
		//case 3:
			//_delay_ms(200);
		//case 4:
			//_delay_ms(250);
		//}
	//}
//}

//int main()
//{
	//DDRA = 0x00;
	//DDRD = 0xff;
	//uint8_t ledData = 0xff;
	//uint8_t buttonState;
	//
	//while(1)
	//{
		//buttonState = PINA;
		//if (buttonState == 0x0e) //00001110
		//PORTD = ledData;
		//else if (buttonState == 0x0d) //00001101
		//PORTD = ~(ledData);
	//}
//}
//int main()
//{
	//BUTTON_DDR = 0x00;
	//LED_DDR = 0xff;
	//BUTTON_PORT = 0xff;
	//
	//uint8_t ledData = 0xff;
	//uint8_t buttonState;
	//
	//while(1)
	//{
		//buttonState = BUTTON_PIN;
		//if ((buttonState & (1<<0)) ==0) //00001110 & 00000001
		//{
			//LED_PORT = ledData;
		//}
		//else if ((buttonState & (1<<1))==0) //00001101 & 00000010
		//{
			//LED_PORT = ~(ledData);
		//}
		//else if ((buttonState & (1<<2))==0) //00001101 & 00000010
		//{
			//LED_PORT = (ledData);
		//}
		//else if ((buttonState & (1<<3))==0) //00001101 & 00000010
		//{
			//LED_PORT = ~(ledData);
		//}
	//}
//}


//enum {RIGHT, LEFT, STOP};
//
//int main()
//{
	//LED_DDR = 0xff;
	//BUTTON_DDR = 0x00;
	//BUTTON_PORT = 0xff;
	//
	//uint8_t ledData= 0x01;
	//uint8_t buttonState;
	//uint8_t state=LEFT;
	//
	//
	//while(1)
	//{
		//buttonState = BUTTON_PIN;
		//if ((buttonState & (1<<RIGHT))==0)
			//{
				//state=RIGHT;
			//}
		//if ((buttonState & (1<<LEFT))==0)
			//{
				//state=LEFT;
			//}
		//if ((buttonState & (1<<STOP))==0)
			//{
				//state=STOP;
			//}
			//
		//switch(state)
		//{case RIGHT:
			//LED_PORT = ledData;
			//ledData = (ledData<<7 | ledData>>1);
			//break;
		//case LEFT:
			//LED_PORT = ledData;
			//ledData = (ledData>>7 | ledData<<1);
			//break;
		//case STOP:
			//LED_PORT = ledData;
			//break;
		//
		//}
	//_delay_ms(200);}
//}

//enum {LEFT, RIGHT, BLINK, OFF};
//
//int main()
//{
	//LED_DDR = 0xff;
	//BUTTON_DDR = 0x00;
	//BUTTON_PORT = 0xff;
	//
	//uint8_t ledData= 0x01;
	//uint8_t buttonState;
	//uint8_t state=OFF;
	//uint8_t stateLast = 0x01;
	//
	//while(1)
	//{
		//buttonState = BUTTON_PIN;
		//if ((buttonState & (1<<LEFT))==0)
		//{
			//state=LEFT;
		//}
		//if ((buttonState & (1<<RIGHT))==0)
		//{
			//state=RIGHT;
		//}
		//if ((buttonState & (1<<BLINK))==0)
		//{
			//state=BLINK;
		//}
		//if ((buttonState & (1<<OFF))==0)
		//{
			//state=OFF;
		//}
		//
		//switch(state)
		//{case LEFT:
			//LED_PORT = ledData;       //00000001
			//ledData = (ledData>>7) | (ledData<<1); //00000010
			//stateLast = (ledData<<7) | (ledData>>1);
			//break;
			//
			//case RIGHT:
			//LED_PORT = ledData;  //00000010
			//ledData = (ledData<<7) | (ledData>>1); //00000001 
			//stateLast = (ledData>>7) | (ledData<<1);
			//break;
			//
			//case BLINK:
			//LED_PORT = 0x00;
			//_delay_ms(200);
			//LED_PORT = 0xff;
			//ledData = stateLast;
			//break;
			//
			//case OFF:
			//LED_PORT = 0x00;
			//ledData = stateLast;
			//
			//break;
		//}
	//_delay_ms(200);}
//}


//함수를 이용한 1,2,3,4 버튼 LED

//enum {LEFT, RIGHT, BLINK, OFF};
//uint8_t ledData;
//uint8_t stateLast = 0x01;
//
//void ledLeftShift(void)
//{
	//LED_PORT = ledData;
	//ledData = (ledData>>7) | (ledData<<1);
	//stateLast = (ledData<<7) | (ledData>>1);	
//}
//
//void ledRightShift(void)
//{
	//LED_PORT = ledData;
	//ledData = (ledData<<7) | (ledData>>1);	
	//stateLast = (ledData>>7) | (ledData<<1);
//}
//
//void ledAllBlink(void)
//{
	////PORTD = 0x00;
	////_delay_ms(200);
	////PORTD = 0xff;
	////ledData = stateLast;
	//
	//static uint8_t ledBlinkData = 0x00;
	//ledBlinkData ^= 0xff;
	//LED_PORT = ledBlinkData;
	//ledData = stateLast;
//}
//
//void ledAllOff(void)
//{
	//LED_PORT = 0x00;
	//ledData = stateLast;
//}
//
//int main()
//{
	//LED_DDR = 0xff;
	////BUTTON_DDR = 0x00;
	//BUTTON_DDR &= ~((1<<LEFT) | (1<<RIGHT) | (1<<BLINK) | (1<<OFF)); //  ????1111 & ~ (00000001 | 00000010 | 00000100 | 00001000) -> ???????? & 11110000 -> ????0000
	//BUTTON_PORT = 0xff;
	//
	//uint8_t state = OFF;
	//ledData = 0x01;
		//
	//while(1)
	//{
		//if((BUTTON_PIN & (1<<LEFT))==0)
		//{
			//state = LEFT;
		//}
		//if((BUTTON_PIN & (1<<RIGHT))==0)
		//{
			//state = RIGHT;
		//}
		//if((BUTTON_PIN & (1<<BLINK))==0)
		//{
			//state = BLINK;
		//}
		//if((BUTTON_PIN & (1<<OFF))==0)
		//{
			//state = OFF;
		//}
		//
		//switch(state)
		//{
			//case LEFT:
			//ledLeftShift();
			//break;
			//case RIGHT:
			//ledRightShift();
			//break;
			//case BLINK:
			//ledAllBlink();
			//break;
			//case OFF:
			//ledAllOff();
			//break;
		//}
		//_delay_ms(200);
	//}
//}