#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//int main(void)
//{
//	int ary[3];
//	int i;
//
//	*(ary + 0) = 10;                   // ary[0] = 10
//	*(ary + 1) = *(ary + 0) + 10;      // ary[1] = ary[0] + 10
//
//	printf("�� ��° �迭 ��ҿ� Ű���� �Է� : ");
//	scanf("%d", ary + 2);              // &ary[2]
//
//	for (i = 0; i < 3; i++)            // ��� �迭 ��� ���
//	{
//		printf("%5d", *(ary + i));     // ary[i]
//	}
//
//	return 0;
//}

//int main(void)
//{
//	printf("apple�� ����� ���� �ּ� �� : %p\n", "apple");    // �ּ� �� ���
//	printf("�� ��° ������ �ּ� �� : %p\n", "apple" + 1);     // �ּ� �� ���
//	printf("ù ��° ���� : %c\n", *"apple");                  // ���� ���� ����
//	printf("�� ��° ���� : %c\n", *("apple" + 1));            // ������ �����
//	printf("�迭�� ǥ���� �� ��° ���� : %c\n", "apple"[2]);  // �迭 ǥ����
//
//	return 0;
//}

//int main(void)
//{
//	char* dessert = "apple";                     // �����Ϳ� ���ڿ� �ʱ�ȭ
//
//	printf("���� �Ľ��� %s�Դϴ�.\n", dessert);  // ���ڿ� ���
//	dessert = "banana";                          // ���ο� ���ڿ� ����
//	printf("���� �Ľ��� %s�Դϴ�.\n", dessert);  // �ٲ� ���ڿ� ���
//	dessert = "strawberry";
//
//	return 0;
//}
//
//#include <stdio.h>
//#include <string.h>                        // strcpy �Լ��� ����ϱ� ���� ��Ŭ�����
//
//int main(void)
//{
//	char str1[80] = "strawberry";          // char �迭�� ���ڿ� �ʱ�ȭ
//	char str2[80] = "apple";               // char �迭�� ���ڿ� �ʱ�ȭ
//	char* ps1 = "banana";                  // �����ͷ� ���ڿ� ��� ����
//	char* ps2 = str2;                      // �����ͷ� �迭 ����
//
//	printf("���� ���ڿ� : %s\n", str1);
//	strcpy(str1, str2);                    // �ٸ� char �迭�� ���ڿ� ����
//	printf("�ٲ� ���ڿ� : %s\n", str1);
//
//	strcpy(str1, ps1);                     // ���ڿ� ����� ������ ������ ���
//	printf("�ٲ� ���ڿ� : %s\n", str1);
//
//	strcpy(str1, ps2);                     // �迭�� ������ ������ ���
//	printf("�ٲ� ���ڿ� : %s\n", str1);
//
//	strcpy(str1, "banana");                // ���ڿ� ��� ���
//	printf("�ٲ� ���ڿ� : %s\n", str1);
//
//	return 0;

//void auto_func(void);     // auto_func �Լ� ����
//void static_func(void);   // static_func �Լ� ����
//
//int main(void)
//{
//	int i;
//
//	printf("�Ϲ� ���� ����(auto)�� ����� �Լ�...\n");
//	for (i = 0; i < 3; i++)
//	{
//		auto_func();
//	}
//
//	printf("���� ���� ����(static)�� ����� �Լ�...\n");
//	for (i = 0; i < 3; i++)
//	{
//		static_func();
//	}
//
//	return 0;
//}
//
//void auto_func(void)
//{
//	auto int a = 0;       // ���� ���� ����� �ʱ�ȭ
//
//	a++;                  // a �� 1 ����
//	printf("%d\n", a);    // a ���
//}
//
//void static_func(void)
//{
//	static int a=3;         // ���� ���� ���� ����
//
//	a++;                  // a �� 1 ����
//	printf("%d\n", a);    // a ���
//}

#include <stdio.h>

int* sum(int a, int b);   // int�� ������ �ּҸ� ��ȯ�ϴ� �Լ� ����

int main(void)
{
	int* resp;            // ��ȯ���� ������ ������ resp(result pointer)

	resp = sum(10, 20);   // ��ȯ�� �ּҴ� resp�� ����
	printf("�� ������ �� : %d\n", *resp);   // resp�� ����Ű�� ������ ���

	return 0;
}

int* sum(int a, int b)    // int�� ������ �ּҸ� ��ȯ�ϴ� �Լ�
{
	static int res;       // ���� ���� ����

	res = a + b;          // �� ������ ���� res(result)�� ����

	return &res;          // ���� ���� ������ �ּ� ��ȯ
}