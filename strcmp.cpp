#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
// <0 if the 1st non-matching char has a lower ascii value in s1 than s2
// 0 if the strings are equal
// >0 if the 1st non-matching char has a higher ascii value in s1 than s2
int main()
{
	char s1[] = "Thiz is the way.";
	char s2[] = "This is the way.";
	if (strcmp(s1, s2) == 0)
		printf("strings are equal");
	else if (strcmp(s1, s2) < 0)
		printf("s1<s2");
	else if (strcmp(s1, s2) > 0)
		printf("s1>s2\n");
}