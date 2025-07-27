#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_LINES 100
#define MAX_LEN 1000


int main()
{	
	/*FILE* file = fopen("lines.text", "w");
	fprintf(file, "line1\n");
	fprintf(file, "line2\n");
	fprintf(file, "line3\n");
	fprintf(file, "line4\n");
	fprintf(file, "line5\n");
	fclose(file); */
	char data[MAX_LINES][MAX_LEN];
	FILE* file = fopen("lines.text", "r");
	if (!file) {
		printf("Error opening file\n");
		return 1;
	}
	int line = 0; 
	while(fgets(data[line], MAX_LINES, file))
	{
		line++;
		if (line >= MAX_LINES) break;
	}
	fclose(file);
	printf("File contents:\n");
	for (int i = 0; i < line; i++)
	{
		printf("Line %d: %s", i + 1, data[i]);
	}
	return 0;
}