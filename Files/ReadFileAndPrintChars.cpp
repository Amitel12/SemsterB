#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	FILE* file = fopen("file.txt", "w+");
	if (!file) return -1;
	fprintf(file, "Hello there how is it going?\n");
	fprintf(file, "Beautiful day outside sucks that im studying for a re-do test i failed");
	rewind(file);
	char c;
	while ((c = fgetc(file)) != EOF)
	{
		putchar(c);
	}
	fclose(file);
	return 0;
	
}