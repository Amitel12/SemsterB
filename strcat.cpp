#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
	char dest[20] = "This and ";
	char src[5] = "that";
	strcat(dest, src);
	printf("dest: %s\n", dest);

	char dest2[20] = "This and ";
	char src2[5] = "that";
	strncat(dest2, src2,3);
	printf("dest2:%s\n", dest2);
	return 0;
}