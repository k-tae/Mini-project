#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
 	while (1)
	{
		float a;
		int n, i;
		printf("���� ������ �Է��ϼ���(0�� �Է��ϸ� ����) : ");
		scanf("%f", &a);
		n = (int)a;
		if (a == 0)
		{
			printf("���α׷��� �����մϴ�.");
				break;
		}
		else if (a < 1 || n!=a)
		{
			printf("�߸��� �����Դϴ�. \n");
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