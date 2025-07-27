#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
int main()
{
	/*FILE* file = fopen("file.txt", "w");
	fprintf(file, "I hope there won't be any hard questions on the test\n");
	fprintf(file, "Hopefully it will run smooth I feel like i studied enough\n");
	fprintf(file, "But still want to check how many times the word hope occurred here :]");
	fclose(file); */
	FILE* file = fopen("file.txt", "r");
	char str[101];
	int counter = 0;
	char* word;
	while (fgets(str, sizeof(str), file))// whole sentence each loop
	{
		word = strtok(str, " \n"); //first word
		while (word !=NULL) 
		{
			if (strcmp(word, "hope") == 0)
				counter += 1;
			word = strtok(NULL, " \n");
		}
		
	}
	fclose(file);
	printf("The word hope occurred %d times! \n",counter);


}