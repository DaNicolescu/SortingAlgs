#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "header.h"


void RandomArray(int **array, size_t *n)
{
	size_t i, max;

	*n = 100000;
	max = 100000;

	*array = (int*)malloc(*n * sizeof(int));

	srand(time(NULL));

	for(i = 0; i < *n; i++)
	{
		(*array)[i] = rand() % max;
	}
}

void PrintArray(int *array, size_t n)
{
	size_t i;

	for(i = 0; i < n; i++)
		printf("%d ", array[i]);
	printf("\n");
}

void FreeArray(int **array)
{
	free(*array);
	*array = NULL;
}

void TestAlg(Sorter Algorithm, int *array, size_t n)
{
	int *array_copy;

	array_copy = (int*)malloc(n * sizeof(int));

	int i;

	memcpy(array_copy, array, n * sizeof(int));

	//PrintArray(array_copy, n);

	clock_t t1=clock();

	Algorithm(array_copy, n);

	clock_t t2=clock();
	printf("%li", (t2-t1));

	//PrintArray(array_copy, n);

	FreeArray(&array_copy);
}

