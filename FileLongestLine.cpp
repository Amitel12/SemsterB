#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int longestLine(char* filename, int* Length);
int main()
{
	char filename[] = "note.txt";
	FILE* file = fopen(filename, "w");
	if (!file) return -1;
	fprintf(file, "aaaaaaa\n");
	fprintf(file, "bbbbbbbb\n");
	fprintf(file, "ccccccc");
	fclose(file);
	int len = 0;
	int lineNum = longestLine(filename, &len);
	printf("longest line: %d with %d Characters", lineNum, len);
}
int longestLine(char* filename, int* length)
{
	FILE* file = fopen(filename, "r");
	if (!file) return -1;
	char str[102];
	int Maxlen = 0;
	int Maxline = 0;
	int line = 0;

	while (fgets(str, sizeof(str), file)) //reads first line
	{
		line++;
		int len = strlen(str)-1;
		if (len > Maxlen)
		{
			Maxlen = len;
			Maxline = line;
		}
	}
	*length = Maxlen;
	fclose(file);
	return Maxline;
}