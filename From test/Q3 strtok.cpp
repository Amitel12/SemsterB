#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int wordAppearanceNum(const char* file_name, const char* word);
int main()
{
	const char* filename = "note.txt";
	const char* target = "live";

	int count = wordAppearanceNum(filename, target);

	if (count == -1) {
		printf("Failed to open the file.\n");
	}
	else {
		printf("The word '%s' appeared %d times in the file.\n", target, count);
	}

	return 0;
}
int wordAppearanceNum(const char* file_name,const char* word)
{
	FILE* fptr = fopen(file_name, "r");// opening the file
	char str[100]; //array of 100 "The buffer"
	const char* seperators = " \n"; //The seperators : " ", "\n"
	char* token; //a line
	int count = 0;
	if (!fptr)
		return -1;
	while (fgets(str, 100, fptr)) //reads up to 100-1 characters OR untill \n (it copies line by line each loop)
	{
		token = strtok(str, seperators); //the first word
		while (token != NULL)
		{
			if (strcmp(token, word) == 0) //checks if the token(the single word) == live
				count++;
			token = strtok(NULL, seperators); // continue to the next word 
		}
	}
	fclose(fptr);
	return count;
}
	
	