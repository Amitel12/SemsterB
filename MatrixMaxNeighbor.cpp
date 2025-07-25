#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include <stdio.h>

#define COLS 4
int** matrixMaxNeighbor(int A[][COLS], int rows, int cols);
int neighborMax(int A[][COLS], int row, int cols, int i, int j);
int** allocMatrix(int rows, int cols);
void main()
{
	int A[4][4] =
	{
		{5,12,6, 8},
		{4,7, 1, 9},
		{13,20,5,2},
		{18,10,2,6}
	};
	int rows = 4, cols = 4;
	int** B = matrixMaxNeighbor(A, rows, cols);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			printf("%d ", B[i][j]);
		}
		printf("\n");
	}
	for (int i = 0; i < rows; i++)
	{
		free(B[i]);
	}
	free(B);
}

int** matrixMaxNeighbor(int A[][COLS], int rows, int cols)
{
	int** B = allocMatrix(rows, cols);
	int i, j;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			B[i][j] = neighborMax(A, rows, cols, i, j);

		}
	}
	return B;

}

int** allocMatrix(int rows, int cols)
{
	int** B = (int**)calloc(rows, sizeof(int*));
	int i;
	for (i = 0; i < rows; i++)
	{
		B[i] = (int*)calloc(cols, sizeof(int));
	}
	return B;
}

int neighborMax(int A[][COLS], int row, int cols, int i, int j)
{
	int max = 0;

	if (i + 1 >= 0 && i + 1 < row) // Down
	{
		if (max < A[i + 1][j])
		{
			max = A[i + 1][j];
		}
	}
	if (i - 1 >= 0 && i - 1 < row) //Up
	{
		if (max < A[i - 1][j])
		{
			max = A[i - 1][j];
		}
	}
	if (j + 1 >= 0 && j + 1 < cols) //Right
	{
		if (max < A[i][j + 1])
		{
			max = A[i][j + 1];
		}
	}
	if (j - 1 >= 0 && j - 1 < cols) //Left
	{
		if (max < A[i][j - 1])
		{
			max = A[i][j - 1];
		}
	}
	return max;
}