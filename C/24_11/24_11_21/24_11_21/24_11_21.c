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
//	printf("세 번째 배열 요소에 키보드 입력 : ");
//	scanf("%d", ary + 2);              // &ary[2]
//
//	for (i = 0; i < 3; i++)            // 모든 배열 요소 출력
//	{
//		printf("%5d", *(ary + i));     // ary[i]
//	}
//
//	return 0;
//}

//int main(void)
//{
//	printf("apple이 저장된 시작 주소 값 : %p\n", "apple");    // 주소 값 출력
//	printf("두 번째 문자의 주소 값 : %p\n", "apple" + 1);     // 주소 값 출력
//	printf("첫 번째 문자 : %c\n", *"apple");                  // 간접 참조 연산
//	printf("두 번째 문자 : %c\n", *("apple" + 1));            // 포인터 연산식
//	printf("배열로 표현한 세 번째 문자 : %c\n", "apple"[2]);  // 배열 표현식
//
//	return 0;
//}

//int main(void)
//{
//	char* dessert = "apple";                     // 포인터에 문자열 초기화
//
//	printf("오늘 후식은 %s입니다.\n", dessert);  // 문자열 출력
//	dessert = "banana";                          // 새로운 문자열 대입
//	printf("내일 후식은 %s입니다.\n", dessert);  // 바뀐 문자열 출력
//	dessert = "strawberry";
//
//	return 0;
//}
//
//#include <stdio.h>
//#include <string.h>                        // strcpy 함수를 사용하기 위해 인클루드함
//
//int main(void)
//{
//	char str1[80] = "strawberry";          // char 배열에 문자열 초기화
//	char str2[80] = "apple";               // char 배열에 문자열 초기화
//	char* ps1 = "banana";                  // 포인터로 문자열 상수 연결
//	char* ps2 = str2;                      // 포인터로 배열 연결
//
//	printf("최초 문자열 : %s\n", str1);
//	strcpy(str1, str2);                    // 다른 char 배열의 문자열 복사
//	printf("바뀐 문자열 : %s\n", str1);
//
//	strcpy(str1, ps1);                     // 문자열 상수를 연결한 포인터 사용
//	printf("바뀐 문자열 : %s\n", str1);
//
//	strcpy(str1, ps2);                     // 배열을 연결한 포인터 사용
//	printf("바뀐 문자열 : %s\n", str1);
//
//	strcpy(str1, "banana");                // 문자열 상수 사용
//	printf("바뀐 문자열 : %s\n", str1);
//
//	return 0;

//void auto_func(void);     // auto_func 함수 선언
//void static_func(void);   // static_func 함수 선언
//
//int main(void)
//{
//	int i;
//
//	printf("일반 지역 변수(auto)를 사용한 함수...\n");
//	for (i = 0; i < 3; i++)
//	{
//		auto_func();
//	}
//
//	printf("정적 지역 변수(static)를 사용한 함수...\n");
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
//	auto int a = 0;       // 지역 변수 선언과 초기화
//
//	a++;                  // a 값 1 증가
//	printf("%d\n", a);    // a 출력
//}
//
//void static_func(void)
//{
//	static int a=3;         // 정적 지역 변수 선언
//
//	a++;                  // a 값 1 증가
//	printf("%d\n", a);    // a 출력
//}

#include <stdio.h>

int* sum(int a, int b);   // int형 변수의 주소를 반환하는 함수 선언

int main(void)
{
	int* resp;            // 반환값을 저장할 포인터 resp(result pointer)

	resp = sum(10, 20);   // 반환된 주소는 resp에 저장
	printf("두 정수의 합 : %d\n", *resp);   // resp가 가리키는 변숫값 출력

	return 0;
}

int* sum(int a, int b)    // int형 변수의 주소를 반환하는 함수
{
	static int res;       // 정적 지역 변수

	res = a + b;          // 두 정수의 합을 res(result)에 저장

	return &res;          // 정적 지역 변수의 주소 반환
}