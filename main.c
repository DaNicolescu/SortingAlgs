#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "header.h"

int main()
{
	int *array;
	size_t n;

	RandomArray(&array, &n);
	//PrintArray(array, n);

	printf("SelectionSort ");
	TestAlg(SelectionSort, array, n);
	printf("\nBubbleSort ");
	TestAlg(BubbleSort, array, n);
	printf("\nRecBubbleSort ");
	TestAlg(RecBubbleSort, array, n);
	printf("\nInsertionSort ");
	TestAlg(InsertionSort, array, n);
	printf("\nRecInsertionSort ");
	TestAlg(RecInsertionSort, array, n);
	printf("\nMergeSort ");
	TestAlg(MergeSort, array, n);
	printf("\nIterMergeSort ");
	TestAlg(IterMergeSort, array, n);
	printf("\nQuickSort ");
	TestAlg(QuickSort, array, n);
	printf("\nIterQuickSort ");
	TestAlg(IterQuickSort, array, n);
	printf("\nHeapSort ");
	TestAlg(HeapSort, array, n);
	printf("\nCountingSort ");
	TestAlg(CountingSort, array, n);

	FreeArray(&array);
	printf("\n");

	return 0;
}