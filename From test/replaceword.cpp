#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
void printFile(const char* file_name);
int wordAppearanceNum(const char* file_name, const char* word);
void replaceWordInFile(const char* file_name, const char* oldWord, const char* newWord);

int main()
{
    const char* filename = "note.txt";
    const char* oldword = "live";
    const char* newword = "love";
    printf("Before replacing: \n");
    printFile(filename);
   
    replaceWordInFile(filename,oldword,newword);
    printf("\nAfter replacing: \n");
    printFile(filename);
    //return to normal
    replaceWordInFile(filename, newword, oldword);
    

    return 0;
}


void replaceWordInFile(const char* file_name, const char* oldWord, const char* newWord)

{
    FILE* file = fopen(file_name, "r");
    if (!file) return;
    FILE* temp = fopen("temp.txt", "w");
    if (!temp)
    {
        fclose(file);
        return;
    }
    char* token;
    char line[1024];
    while (fgets(line, sizeof(line), file)) { // get line by line
        token = strtok(line, " \n"); // first word
        while (token != NULL)
        {
            if (strcmp(token, oldWord) == 0)
            {
                fprintf(temp, "%s", newWord); //write the new word on temp
            }
            else
            {
                fprintf(temp, "%s", token); // if its not oldword write the word normally on temp
            }
            token = strtok(NULL, " \n"); // next word 
            fprintf(temp, " "); //add space between words
        }
        fprintf(temp, "\n"); // next line
         

    }
    fclose(file);
    fclose(temp);

    remove(file_name);
    rename("temp.txt", file_name);
}

void printFile(const char* file_name)
{
    FILE* file = fopen(file_name, "r");
    if (!file) { printf("fail\n"); return; }

    char line[1024];
    while (fgets(line, sizeof(line), file))
    {
        printf("%s\n", line);
    }
    fclose(file);
}


