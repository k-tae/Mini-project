#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define	MAX_Q	5
#define	Q_EMPTY	0
#define	Q_FULL	MAX_Q

int Queue[MAX_Q];
int Wrptr = Q_EMPTY;
int Rdptr = Q_EMPTY;
int a[MAX_Q + 1] = { 1,2,3,4,5,6 };
int In_Queue(int data)
{
	if ((Wrptr == Q_FULL) && (Rdptr == Q_EMPTY))
	{
		return -1;
	}
	if (Wrptr > MAX_Q)
	{
		for (int j = 0; j < (Wrptr - Rdptr); j++)
		{
			Queue[j] = Queue[Rdptr + j];
		}
		Wrptr = Wrptr - Rdptr;
		Rdptr = 0;
	}
	Queue[Wrptr] = data;
	Wrptr += 1;
	return 1;
}

int Out_Queue(int *p)
{
	if (Wrptr == Rdptr)
	{
		return -1;
	}
	*p = Queue[Rdptr];
	Rdptr += 1;
	return 1;
	
}

int Print_Queue()
{
	int i;
	for (i = 0; i < (Wrptr - Rdptr); i++)
	{
		printf("QUEUE[%d] = %d\n", i, Queue[i]);
	}
	return Wrptr - Rdptr;
}

int Count_Full_Data_Queue()
{
	return Wrptr - Rdptr;
}

int Count_Empty_Data_Queue()
{
	return MAX_Q - Count_Full_Data_Queue();
}
int main()
{
	int i;
	for (i = 0; i < (MAX_Q + 1); i++)
	{
		printf("%d, ", a[i]);
	}
	printf("\n");

	for (i = 0; i < 3; i++)
	{
		printf("Queue Result = %d\n", In_Queue(a[i]));
		printf("Print Result = %d, ", Print_Queue());
		printf("Full = %d ", Count_Full_Data_Queue());
		printf("Empty = %d\n", Count_Empty_Data_Queue());
		printf("Wrptr = %d, Rdptr = %d\n", Wrptr, Rdptr);
	}

	for (i = 0; i < 3; i++)
	{
		a[i] = 0;
	}

	for (i = 0; i < 3; i++)
	{
		printf("Dequeue Result = %d\n", Out_Queue(&a[i]));
		printf("Print Result = %d, ", Print_Queue());
		printf("Full = %d ", Count_Full_Data_Queue());
		printf("Empty = %d\n", Count_Empty_Data_Queue());
		printf("Wrptr = %d, Rdptr = %d\n", Wrptr, Rdptr);
	}

	for (i = 0; i < (MAX_Q + 1); i++)
	{
		printf("%d, ", a[i]);
	}
	printf("\n");

	for (i = 0; i < (MAX_Q + 1); i++)
	{
		printf("Queue Result = %d\n", In_Queue(a[i]));
		printf("Print Result = %d, ", Print_Queue());
		printf("Full = %d ", Count_Full_Data_Queue());
		printf("Empty = %d\n", Count_Empty_Data_Queue());
		printf("Wrptr = %d, Rdptr = %d\n", Wrptr, Rdptr);
	}

	for (i = 0; i < MAX_Q + 1; i++)
	{
		a[i] = 0;
	}

	for (i = 0; i < (MAX_Q + 1); i++)
	{
		printf("Dequeue Result = %d\n", Out_Queue(&a[i]));
		printf("Print Result = %d, ", Print_Queue());
		printf("Full = %d ", Count_Full_Data_Queue());
		printf("Empty = %d\n", Count_Empty_Data_Queue());
		printf("Wrptr = %d, Rdptr = %d\n", Wrptr, Rdptr);
	}

	for (i = 0; i < (MAX_Q + 1); i++)
	{
		printf("%d, ", a[i]);
	}

	return 0;
}