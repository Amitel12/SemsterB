#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

int main(void)
{
	FILE* file;
	file = fopen("Text.txt", "w");
	//fputs("Hello There ", file);
	//fputs("How are you doing? \n", file);
	//int data = 5;
	//fprintf(file, "Data: %d\n",data);
	//for (int i = 0; i <= 10; i++)
	{
		//	fprintf(file, "%d ", i);
		//}
		int input = 0;
		while (true)
		{
			printf("Write whatever (-1 quits):  ");
			scanf("%d", &input);
			if (input == -1) break;
			else fprintf(file, "%d\n", input);
		}
		fclose(file);
		FILE* file;
		file = fopen("Text.txt", "r");
		int finput = 0;
		int lines = 0;
		int numbers[100];
		while (fscanf(file, "%d", &finput) != EOF)
		{
			numbers[lines] = finput;
			printf("file line %d: %d\n",lines+1, finput);
			lines++;
		}
		int total = 0;
		for (int i = 0; i < lines; i++)
		{
			total += numbers[i];
		}
		printf("Average: %d\n", total / lines);
		fclose(file);
		file = fopen("in.txt", "r");
		char buffer[256];
		fgets(buffer, 256, file);
		printf("Buffer: %s\n",buffer);
		fclose(file);
		return 0;
	}
}