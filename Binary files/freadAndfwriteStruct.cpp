#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	char name[50];
	int age;
	double average;
} Student;

int main()
{
	Student students[3];

	strcpy(students[0].name, "Amit");
	students[0].age = 22;
	students[0].average = 89.55;

	strcpy(students[1].name, "John");
	students[1].age = 24;
	students[1].average = 74.52;

	strcpy(students[2].name, "Doe");
	students[2].age = 23;
	students[2].average = 91.34;

	FILE* file = fopen("student.bin", "wb");
	if (!file) {
		printf("Failed to open file for writing\n");
		return 1;
	}
	int total = 3;
	fwrite(&total, sizeof(int), 1, file); // save how many students
	fwrite(students, sizeof(Student), total, file); // save all students
	fclose(file);
	printf(" Students written to file.\n\n");

	file = fopen("student.bin", "rb");
	if (!file) {
		printf("Error opening file for reading\n");
		return 1;
	}

	int read_total;
	fread(&read_total, sizeof(int), 1, file);

	Student* read_students = (Student*)malloc(sizeof(Student) * read_total);
	if (!read_students) {
		printf("Memory allocation failed\n");
		fclose(file);
		return 1;
	}

	fread(read_students, sizeof(Student), read_total, file);
	fclose(file);

	printf("Students read from file : \n\n");
	for (int i = 0; i < read_total; i++) {
		printf("Student #%d: %s\n", i + 1, read_students[i].name);
		printf("Age: %d\n", read_students[i].age);
		printf("Average: %.2f\n\n", read_students[i].average);
	}

	free(read_students);
	return 0;
}
