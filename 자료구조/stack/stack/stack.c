#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define	MAX_STACK	10
#define	STACK_EMPTY	MAX_STACK
#define	STACK_FULL	0

int stack[MAX_STACK];
int Sptr = STACK_EMPTY;
int a[MAX_STACK + 1] = { 1,2,3,4,5,6,7,8,9,10,11 };

int Push_Stack(int data)
{
	if (Sptr == STACK_FULL)
	{
		return -1;
	}
	stack[Sptr-1] = data;
	Sptr -= 1;
	return 1;
}

int Count_Full_Data_Stack()
{
	return MAX_STACK - Sptr;
}

int Count_Empty_Data_Stack(void)
{
	return Sptr;
}

int Pop_Stack(int *p)
{
	if (Sptr == STACK_EMPTY)
	{
		return -1;
	}
	*p = stack[Sptr];
	Sptr = Sptr + 1;
	return 1;
}

int Print_Stack()
{
	int i;
	for( i = 0; i < (MAX_STACK - Sptr); i++)
	{
		printf("STACK[%d] = %d\n", Sptr+i, stack[Sptr+ i]);
	}
	return i;
}


int main()
{
	int i;
	for (i = 0; i < (MAX_STACK + 1); i++)
	{
		printf("%d, ", a[i]);
	}
	printf("\n");

	for (i = 0; i < 5; i++)
	{
		printf("Push Result = %d\n", Push_Stack(a[i]));
		printf("Print Result = %d, ", Print_Stack());
		printf("Full = %d ", Count_Full_Data_Stack());
		printf("Empty = %d\n", Count_Empty_Data_Stack());
		printf("Sptr = %d\n", Sptr);
	}

	for (i = 0; i < 5; i++)
	{
		printf("Pop Result = %d\n", Pop_Stack(&a[i]));
		printf("Print Result = %d, ", Print_Stack());
		printf("Full = %d ", Count_Full_Data_Stack());
		printf("Empty = %d\n", Count_Empty_Data_Stack());
		printf("Sptr = %d\n", Sptr);
	}

	for (i = 0; i < (MAX_STACK + 1); i++)
	{
		printf("%d, ", a[i]);
	}
	printf("\n");

	for (i = 0; i < (MAX_STACK + 1); i++)
	{
		printf("Push Result = %d\n", Push_Stack(a[i]));
		printf("Print Result = %d, ", Print_Stack());
		printf("Full = %d ", Count_Full_Data_Stack());
		printf("Empty = %d\n", Count_Empty_Data_Stack());
		printf("Sptr = %d\n", Sptr);
	}
	
	for (i = 0; i < (MAX_STACK + 1); i++)
	{
		printf("Pop Result = %d\n", Pop_Stack(&a[i]));
		printf("Print Result = %d, ", Print_Stack());
		printf("Full = %d ", Count_Full_Data_Stack());
		printf("Empty = %d\n", Count_Empty_Data_Stack());
		printf("Sptr = %d\n", Sptr);
	}

	for (i = 0; i < (MAX_STACK + 1); i++)
	{
		printf("%d, ", a[i]);
	}

	return 0;
}