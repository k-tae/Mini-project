#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void fizzbuzz(int num);

int main(void)
{
	int a;
	printf("정수를 입력하세요. : ");
	scanf("%d", &a);
	fizzbuzz(a);
	return 0;
}

void fizzbuzz(int num)
{
	int i;
	for (i = 1; i < num + 1; i++)
	{
		if ((i % 3) == 0 && (i % 5) == 0)
		{
			printf("fizzbuzz\n");
		}
		else if ((i % 5) == 0)
		{
			printf("fizz\n");
		}
		else if ((i % 3) == 0)
		{
			printf("buzz\n");
		}
		else
		{
			printf("%d\n", i);
		}
	}
}