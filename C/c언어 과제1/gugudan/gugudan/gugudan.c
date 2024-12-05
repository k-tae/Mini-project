#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
 	while (1)
	{
		float a;
		int n, i;
		printf("양의 정수를 입력하세요(0을 입력하면 종료) : ");
		scanf("%f", &a);
		n = (int)a;
		if (a == 0)
		{
			printf("프로그램을 종료합니다.");
				break;
		}
		else if (a < 1 || n!=a)
		{
			printf("잘못된 숫자입니다. \n");
		}
		else
		{
			for (i = 1; i < 10; i++)
			{
				printf("%d*%d = %d\n", n, i, n*i);
			}

		}
	}
	return 0;

}