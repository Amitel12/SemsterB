#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
	char s[] = "AASDFS123423";
	char num[] = "0123456789";
	char *match = strpbrk(s, num);
	printf("%s\n", match);
	char punct[] = ",;:";
	char* fail = strpbrk(s, punct);
	if (fail == NULL)
		printf("Could not find!\n");
	return 0;
}