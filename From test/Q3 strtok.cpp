#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int wordAppearanceNum(char* file_name, char* word);
void replaceWordInFile(char* file_name, char* oldWord, char* newWord);

int main()
{
    char* filename = (char*)"note.txt"; 
    char* target = (char*)"live";

   // int count = wordAppearanceNum(filename, target);
    replaceWordInFile(filename, "live", "love");
   // if (count == -1) {
     //   printf("Failed to open the file.\n");
   // }
    //else {
    //    printf("The word '%s' appeared %d times in the file.\n", target, count);
   // }

    return 0;
}

void replaceWordInFile(char* file_name, char* oldWord, char* newWord)
{
    FILE* file = fopen(file_name, "r");
    if (!file) return -1;
    FILE* temp = fopen("temp.txt", "w");
    if (!temp) 
    { 
        fclose(file);
            return -1;
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
            if (token != NULL) fprintf(temp, " "); //add space between words
            
            fprintf(temp, "\n"); // next line
        }
        
    }
    fclose(file);
    fclose(temp);
    
    remove(file_name);
    rename("temp.txt", file_name);
}




int wordAppearanceNum(char* file_name, char* word)
{
    FILE* file = fopen(file_name, "r");
    if (!file) return -1;
    int counter = 0;
    char str[100];
    const char* seperators = " \n";
    char* token;
    while (fgets(str, 100, file)) //Sentence by sentence
    {
        token = strtok(str, seperators); // first word
        while (token != NULL)
        {
            if (strcmp(token, word) == 0) counter++; //checks if the token == word
            fprintf(file,)
            token = strtok(NULL, seperators); //next word
        }
    }
    fclose(file);
    return counter;

}