#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int SearchWord(char* filename, char* word);
int main()
{
	/*FILE* file = fopen("Boggle.txt", "w");
	if (!file) return -1;
	fprintf(file, "etybag");
	fclose(file);
	*/
	const char filename[] = "Boggle.txt";
	const char word[] = "baby";
	if (SearchWord((char*)filename, (char*)word) == 1)
	{
		printf("Found word %s!", word);
	}else printf("Didnt find word %s",word);

}
int SearchWord(char* filename, char* word)
{
	FILE* file = fopen(filename, "r");
	if (file == NULL) return -1;
	int i = 0;
	//Bounderies 
	fseek(file, 0, SEEK_END);
	long size = ftell(file);
	rewind(file);
	//------
	char c;
	while ((c = fgetc(file)) != EOF) //read each char untill EOF
	{
		if (c == word[i])
		{
			i++;
			fseek(file, -1, SEEK_CUR);
			break;
		}
		
	} //find first character of the word

	if (c == EOF) return 0;

	char right, left;
	while (1)
	{
		if (ftell(file) == 0)
		{
			fseek(file, 1, SEEK_CUR);
			right = fgetc(file);// the right of the curr
			fseek(file, -2, SEEK_CUR); //go back to the same spot
			left = '!';
		}
		else if (ftell(file) == size - 1)
		{
			fseek(file, -1, SEEK_CUR);
			left = fgetc(file); //the left of the curr
			right = '!';
		}
		else
		{
			fseek(file, 1, SEEK_CUR);
			right = fgetc(file);
			fseek(file, -3, SEEK_CUR);
			left = fgetc(file);
		}
		if (right == word[i])
		{
			i++;
			fseek(file, 1, SEEK_CUR);
		}
		else if (left == word[i])
		{
			i++;
			fseek(file, -1, SEEK_CUR);
		}
		else
		{
			return 0;
		}
		if(word[i] == '\0')
		{
			return 1;
		}
	}
}