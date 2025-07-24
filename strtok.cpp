#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int main()
{
	char s[] = "Hate Tovia for not telling me what this function is on the test";
	char d[] = " ";
	
	/*
	char* portion1 = strtok(s, d);
	printf("%s\n", portion1);
	char* portion2 = strtok(NULL, d);
	printf("%s\n", portion2);
	char* portion3 = strtok(NULL, d);
	printf("%s\n", portion3);
	char* portion4 = strtok(NULL, d);
	printf("%s\n", portion4);
	*/
	char* portion = strtok(s, d);
	while (portion != NULL)
	{
		printf("%s\n", portion);
		portion = strtok(NULL, d);
	}

	return 0;
}
