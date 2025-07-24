#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
int switchCaps(char chr);
char* WordSwitch(char word[]);
void FixCaps(char word[]);
int main()
{
	char ch = 'z';
	char word[] = "wOrlD oF wARcRafT";
	char after = switchCaps(ch);
	printf("%c Turns into  %c\n",ch,after);
	char* afterword = WordSwitch(word);
	printf("%s turns into %s\n", word, afterword);
	FixCaps(word);
	printf("Fixed caps: %s", word);
}

char* WordSwitch(char word[])
{
	int size = strlen(word);
	int i = 0;
	char* newWord = (char*)malloc(size + 1);
	while (i < size )
	{
		newWord[i] = switchCaps(word[i]);
		i++;
	}
	newWord[size] = '\0';
	return newWord;
}
void FixCaps(char word[])
{
	int size = strlen(word);
	int i = 0;
	int capitalnext = 1;
	while (word[i] != '\0')
	{
		if (isalpha(word[i]))
		{
			if (capitalnext==1) 
			{
				word[i] = toupper(word[i]);
				capitalnext = 0;
			}
			else
			{
				word[i] = tolower(word[i]);
			}
		}
		else if (isspace(word[i])) 
		{
			capitalnext = 1;
		}
		i++;
	}
}

int switchCaps(char chr)
{
	if (chr >= 'a' && chr <= 'z')
	{
		return chr - 'a' + 'A';
	}
	if (chr >= 'A' && chr <= 'Z')
	{
		return chr - 'A' + 'a';
	}
	else {
		return chr;
	};
}