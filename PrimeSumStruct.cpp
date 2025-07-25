#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include <stdio.h>

typedef struct number
{
	unsigned long long num;
	int sum;
}Number;

Number* primeSums(unsigned long long n1, unsigned long long n2, int* p_size);
int isPrime(int num);
int digitSum(unsigned long long num);
void loopNumbers(Number* arr, int size);
void main()
{
	int n1 = 221, n2 = 233, size;
	Number* arr = primeSums(n1, n2, &size);
	loopNumbers(arr, size);
	free(arr);
}
 
Number* primeSums(unsigned long long n1, unsigned long long n2, int* p_size)
{
	int i, tmp_sum;
	Number* arr = NULL;
	int size = 0;
	for (i = n1; i <= n2; i++)
	{
		tmp_sum = digitSum(i);
		if (isPrime(tmp_sum) == 1)
		{
			size++;
			arr = (Number*)realloc(arr, size * sizeof(Number));
			arr[size - 1].num = i;
			arr[size - 1].sum = tmp_sum;
		}
	}
	*p_size = size;
	return arr;
}

int isPrime(int num)
{
	int i;
	if (num < 2) return 0;
	for (i = 2; i * i <= num; i++)
	{
		if (num % i == 0)
		{
			return 0;
		}
	}
	return 1;
}
int digitSum(unsigned long long num)
{
	int sum = 0;
	while (num > 0)
	{
		sum += num % 10;
		num /= 10;
	}
	return sum;
}
void loopNumbers(Number* arr, int size)
{
	int i;
	printf("num:\t");
	for (i = 0; i < size; i++)
	{
		printf("%llu\t", arr[i].num);
	}

	printf("\nsum:\t");
	for (i = 0; i < size; i++)
	{
		printf("%d\t", arr[i].sum);
	}
	printf("\n");
}
