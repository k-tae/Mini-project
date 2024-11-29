#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct _score
{
	int id;
	int jumsu;
	char name[10];
	int next;
}SCORE;

#define MAX_ST	20

SCORE exam[MAX_ST] = { {-1, 0, "", 0} };

SCORE test[22] = { {10, 50, "kim", 0}, {2, 80, "lew", 0}, {8, 50, "lew", 0}, {4, 45, "lee", 0}, {1, 90, "song", 0},\
				   {3, 45, "kim", 0}, {5, 50, "song", 0 }, {9, 100, "lee", 0}, {7, 75, "moon", 0}, {6, 90, "park", 0},\
				   {22, 0, "choi", 0}, {12, 28, "mo", 0 }, {18, 51, "lee", 0}, {14, 43, "lee", 0}, {11, 91, "min", 0},\
				   {13, 41, "kim", 0}, {15, 15, "kong", 0}, {19, 100, "park", 0}, {17, 72, "seo", 0}, {16, 99, "lim", 0},\
				   {20, 98, "do", 0}, {21, 100, "kong", 0} };

void Make_Test_Data(int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		exam[i] = test[i];
	}
}

int Create_Data(SCORE * p)
{
	printf("\n사번을 입력하시오 => ");
	scanf(" %d", &p->id);
	printf("이름을 입력하시오 => ");
	scanf(" %s", p->name);
	printf("점수를 입력하시오 => ");
	scanf("%d", &p->jumsu);
	p->next = 0;

	return 1;
}

int Print_All_Data(void)
{
	int i, cnt = 0;

	printf("Head.next = %d\n", exam[0].next);

	for (i = 1; i < MAX_ST; i++)
	{
		if (exam[i].id == 0) continue;
		printf("[%d] ID=%d, NAME=%s, SCORE=%d, next = %d\n", i, exam[i].id, exam[i].name, exam[i].jumsu, exam[i].next);
		cnt++;
	}

	return cnt;
}

int Print_Data(int no)
{
	if (exam[no].id == 0) return -1;
	printf("[%d] ID=%d, NAME=%s, SCORE=%d, next = %d\n", no, exam[no].id, exam[no].name, exam[no].jumsu, exam[no].next);
	return 1;
}

int Count_Data(void)
{
	int i, cnt = 0;

	for (i = 1; i < MAX_ST; i++)
	{
		if (exam[i].id == 0) continue;
		cnt++;
	}

	return cnt;
}

int Insert_Data(SCORE * p)
{
	int i, empty = 0;

	for (i = 1; i < MAX_ST; i++)
	{
		if (empty == 0 && exam[i].id == 0)
		{
			empty = i;
		}

		if (exam[i].id == p->id)
		{
			return -2;
		}
	}

	if (empty != 0)
	{
		exam[empty] = *p;
		return empty;
	}

	return -1;
}

int Insert_Node(SCORE * d)
{
	int r = Insert_Data(d);

	if (r < 0)
	{
		return r;
	}

	int curr = 0;
	int next = exam[0].next;

	while (next != 0 && exam[r].id > exam[next].id)
	{
		curr = next;
		next = exam[next].next;
	}
	exam[r].next = next;
	exam[curr].next = r;
	return 1;
}

int Print_All_Node(void)
{
	int i;
	int n = exam[0].next;
	for (i = 1; i < MAX_ST; i++)
	{
		Print_Data(n);
		n = exam[n].next;
		if (exam[n].next == 0)
		{
			Print_Data(n);
			break;
		}
	}
	return i+1;
}

int Search_Id_Node(int id)
{
	int i;
	int next = exam[0].next;
	for (i = 0; i < MAX_ST; i++)
	{
		if (exam[next].id == id)
		{
			return next;
			break;
		}
		next = exam[next].next;
	}
	return -1;
}

int Delete_Node(int id)
{
	int i;
	int curr = 0;
	int next = exam[0].next;
	for (i = 0; i < MAX_ST; i++)
	{
		if (exam[next].id == id)
		{
			exam[next].id = 0;
			exam[curr].next = exam[next].next;
			return 1;
		}
		curr = next;
		next = exam[next].next;
	}
	return -1;
}

void main(void)
{
	//int i,pos;

	//for (i = 0; i < 8; i++)
	//{
	//	printf("Insert Node Result = %d\n", Insert_Node(&test[i]));
	//}
	//printf("Printed Data Count = %d\n", Print_All_Node());

	//printf("Searched Node Index = %d\n", pos = Search_Id_Node(8));
	//if (pos != -1) Print_Data(pos);

	//printf("Searched Node Index = %d\n", pos = Search_Id_Node(7));
	//if (pos != -1) Print_Data(pos);

	int i;
	for (i = 0; i < 8; i++)
	{
		printf("Insert Node Result = %d\n", Insert_Node(&test[i]));
	}
	printf("Printed Node Count = %d\n", Print_All_Node());
	printf("Delete Node(%d) Result = %d\n", 8, Delete_Node(8));
	printf("Delete Node(%d) Result = %d\n", 7, Delete_Node(7));
	printf("Delete Node(%d) Result = %d\n", 1, Delete_Node(1));
	printf("Delete Node(%d) Result = %d\n", 10, Delete_Node(10));
	printf("Printed Node Count = %d\n", Print_All_Node());
}
