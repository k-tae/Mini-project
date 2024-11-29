#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>


//리스트 기초
//typedef struct _score
//{
//	int id;
//	int jumsu;
//	char name[10];
//
//} SCORE;
//
////SCORE exam[SIZE];
//
//void func(SCORE *p)
//{
//	(*p).jumsu = 200;
//}
//
//int main()
//{
//	SCORE x;
//
//	x.id = 10;
//	x.jumsu = 100;
//	strcpy(x.name, "Kwon");
//	func(&x);
//
//	printf("%s %d %d \n", x.name, x.id, x.jumsu);
//	return 0;
//}

typedef struct _score
{
	int id;
	int jumsu;
	char name[10];
}SCORE;

#define MAX_ST		20

SCORE exam[MAX_ST];

SCORE test[22] = { {10, 50, "kim"}, {2, 80, "lew"}, {8, 50, "lew"}, {4, 45, "lee"}, {1, 90, "song"},\
				   {3, 45, "kim"}, {5, 50, "song"}, {9, 100, "lee"}, {7, 75, "moon"}, {6, 90, "park"},\
				   {22, 0, "choi"}, {12, 28, "mo"}, {18, 51, "lee"}, {14, 43, "lee"}, {11, 91, "min"},\
				   {13, 41, "kim"}, {15, 15, "kong"}, {19, 100, "park"}, {17, 72, "seo"}, {16, 99, "lim"},\
				   {20, 98, "do"}, {21, 100, "kong" }, };

void Make_Test_Data(int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		exam[i] = test[i];
	}
	printf("Printed Data Count = %d\n", i);
}

//전체 리스트 출력
int Print_All_Data(void)
{
	int i;
	int r=0;
	for (i = 0; i < MAX_ST; i++)
	{
		if (exam[i].id == 0)
		{
			break;
		}
		printf("[%d] ID=%d, NAME=%s, SCORE=%d\n", i,exam[i].id,exam[i].name,exam[i].jumsu);
		r++;
		
	}
	return r;
}

//특정 요소 출력
int Print_Data(int no)
{
	if (exam[no].id != 0)
	{
		printf("ID=%d, NAME=%s, SCORE=%d\n", exam[no].id, exam[no].name, exam[no].jumsu);
		return 1;
	}
	return -1;
}

//배열에 데이터 insert
int Insert_Data(SCORE *p)
{
	for (int i = 0; i < MAX_ST; i++)
	{
		if (p->id == exam[i].id)
		{
			return -2;
		}

		if ((exam[i].id) == 0)
		{
			
			*(&exam[i].id) = p->id;
			*(&exam[i].jumsu) = p->jumsu;
			strcpy(exam[i].name, p->name);
			return i;
		}
	}

	return -1;
}

//요소 수 세기
int Count_Data()
{	
	int r = 0;
	for (int i = 0; i < MAX_ST; i++)
	{	
		if (exam[i].id == 0)
		{
			break;
		}
		r++;
	}
	return r;
}

//요소 삭제
int Delete_Data(int id)
{
	SCORE D = { 0,0,0 };
	if (exam[0].id == 0)
	{
		return -2;
	}
	for (int i = 0; i < MAX_ST; i++)
	{
		if (exam[i].id == id)
		{
			int j = i; //10
			while (exam[j].id != 0)
			{
				if (j == MAX_ST-1)
				{
					exam[j] = D;
				}
				else
				{
					exam[j] = exam[j + 1];
					j++;
				}
			}
			return i;
		}
	}
	return -1;
}

int Search_Complete_Data(SCORE * p)
{
	if (exam[0].id == 0)
	{
		return -2;
	}
	for (int i = 0; i < MAX_ST; i++)
	{
		if (!(memcmp(p,&exam[i],sizeof(exam[i]))))
		{
			return i;
		}
	}
	return -1;
}

int Compare_Id(SCORE *x, SCORE *y)
{
	if (x->id == y->id)
	{
		return 0;
	}
	else if (x->id > y->id)
	{
		return 1;
	}
	else if (x->id < y->id)
	{
		return -1;
	}
}

int Compare_Name(SCORE *x, SCORE *y)
{
	if (x->name == y->name)
	{
		return 0;
	}
	else if (x->name > y->name)
	{
		return 1;
	}
	else if (x->name < y->name)
	{
		return -1;
	}
}

int Compare_Jumsu(SCORE *x, SCORE *y)
{
	if (x->jumsu == y->jumsu)
	{
		return 0;
	}
	else if (x->jumsu > y->jumsu)
	{
		return 1;
	}
	else if (x->jumsu < y->jumsu)
	{
		return -1;
	}
}

int Search_Data(int n, SCORE *p, int(*comp)(SCORE *x, SCORE *y)) //comp는 *인데 함수를 가리키고 그 함수는 int 리턴
{
	if (exam[0].id == 0)
	{
		return -2;
	}

}



SCORE tmp = { 8, 50, "lew" };


void main(void)
{
	int n;
	Make_Test_Data(4);
	n = Search_Data(0, &tmp, Compare_Id);
	printf("Searched Element (ID) = %d\n", n);
	Print_Data(n);

	n = 0;

	//do
	//{
	//	n= Search_Data(n, &tmp, Compare_Name);
	//	printf(printf("Searched Element (ID) = %d\n", n));
	//	Printf_Data(n);
	//	n++;
	//} while (n > 0);

	//n = 0;

	//do
	//{
	//	n = Search_Data(n, &tmp, Compare_Jumsu);
	//	printf(printf("Searched Element (ID) = %d\n", n));
	//	Printf_Data(n);
	//	n++;
	//} while (n > 0);
}