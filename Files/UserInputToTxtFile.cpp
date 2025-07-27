#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define BUFFER_SIZE  1024
int main()
{
	char buffer[BUFFER_SIZE];
	bool keep_going = true;
	FILE* file = fopen("output.txt", "w");
	if (!file) return NULL;
	while (keep_going == true)
	{
		fgets(buffer, BUFFER_SIZE, stdin);


		if (strcmp(buffer, "quit\n") == 0) keep_going = false;
		else fputs(buffer, file);

	}
	fclose(file);
}