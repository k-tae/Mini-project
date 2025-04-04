#include <stdio.h>

char *strcat(char *str1, char *str2)
{
	int i, j;
	i = sizeof(str1) / sizeof(str1[0]);
	j = 0;
	while (str2[j])
	{
		str1[i + j] = str2[j];
		j++;
	}
	str1[i + j] = '\0';
	return str1;
}

int main()
{
	char fruit[80] = "straw";
	strcat(fruit, "berry");
	printf("연결된 문자열 : %s\n", fruit);
	return 0;
}