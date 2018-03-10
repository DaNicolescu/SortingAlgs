#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "header.h"

void Swap(int *a, int *b)
{
	int temp = *a;

	*a = *b;
	*b = temp;
}

void SelectionSort(int *array, size_t n)
{
	size_t i, j, min_index;
	int temp;

	for(i = 0; i < n-1; i++)
	{
		min_index = i;

		for(j = i+1; j < n; j++)
		{
			if(array[j] < array[min_index])
				min_index = j;
		}

		Swap(&array[i], &array[min_index]);
	}
}

void BubbleSort(int *array, size_t n)
{
	size_t i, j, swap;
	int temp;

	for(i = 0; i < n-1; i++)
	{
		swap = 0;
		for(j = 0; j < n-i-1; j++)
		{
			if(array[j] > array[j+1])
			{
				swap = 1;

				Swap(&array[j], &array[j+1]);
			}
		}

		if(swap == 0)
			break;
	}
}

void RecBubbleSort(int *array, size_t n)
{
	size_t i, swap = 0;
	int temp;

	if(n == 1)
		return;

	for(i = 0; i < n-1; i++)
	{
		if(array[i] > array[i+1])
		{
			swap = 1;

			Swap(&array[i], &array[i+1]);
		}
	}

	if(swap == 0)
		return;

	RecBubbleSort(array, n-1);
}

void InsertionSort(int *array, size_t n)
{
	int i, j;
	int temp;

	for(i = 1; i < n; i++)
	{
		temp = array[i];
		j = i-1;

		while(j >= 0 && array[j] > temp)
		{
			array[j+1] = array[j];
			--j;
		}

		array[++j] = temp;
	}
}

void RecInsertionSort(int *array, size_t n)
{
	int j;
	int temp;

	if(n == 1)
		return;

	RecInsertionSort(array, n-1);

	temp = array[n-1];
	j = n-2;

	while(j >= 0 && array[j] > temp)
	{
		array[j+1] = array[j];
		--j;
	}

	array[++j] = temp;
}

void Merge(int *array, size_t l, size_t m, size_t r)
{
	int *left, *right;
	size_t i, j, k;

	left = (int*)malloc((m-l+1) * sizeof(int));
	right = (int*)malloc((r-m) * sizeof(int));

	for(i = 0; i < m-l+1; i++)
		left[i] = array[i+l];
	for(i = 0; i < r-m; i++)
		right[i] = array[i+m+1];

	i = 0;
	j = 0;
	k = l;

	while((i < m-l+1) && (j < r-m))
	{
		if(left[i] < right[j])
		{
			array[k] = left[i];
			++i;
		}
		else
		{
			array[k] = right[j];
			++j;
		}

		++k;	
	}

	if(k < r+1)
	{
		while(i < m-l+1)
		{
			array[k] = left[i];
			++k;
			++i;
		}

		while(j < r-m)
		{
			array[k] = right[j];
			++k;
			++j;
		}
	}

	FreeArray(&left);
	FreeArray(&right);
}

void MSort(int *array, size_t l, size_t r)
{
	if(l < r)
	{
		size_t m = (l+r)/2;

		MSort(array, l, m);
		MSort(array, m+1, r);

		Merge(array, l, m, r);
	}
}

void MergeSort(int *array, size_t n)
{
	size_t l = 0;
	size_t r = n-1;

	MSort(array, l, r);
}

void IterMergeSort(int *array, size_t n)
{
	size_t l, m, r, sub_size;

	for(sub_size = 1; sub_size < n; sub_size *= 2)
	{
		for(l = 0; l < n-1; l += 2 * sub_size)
		{
			if((l + sub_size - 1) < n - 1)
				m = l + sub_size - 1;
			else
				m = n - 1;

			if((l + 2 * sub_size) < n - 1)
				r = l + 2 * sub_size - 1;
			else
				r = n - 1;

			Merge(array, l, m, r);
		}
	}
}

int Partition(int *array, int low, int high)
{
	int i, j;
	int temp, pivot;

	i = low - 1;
	pivot = array[high];

	for(j = low; j < high; j++)
	{
		if(array[j] <= pivot)
		{
			++i;

			Swap(&array[i], &array[j]);
		}
	}

	++i;
	Swap(&array[i], &array[high]);

	return i;
}

void Qsort(int *array, int low, int high)
{
	if(low < high)
	{
		int pivot_index;

		pivot_index = Partition(array, low, high);

		if(low < pivot_index - 1)
			Qsort(array, low, pivot_index - 1);

		if(high > pivot_index + 1)
			Qsort(array, pivot_index + 1, high);
	}
}

void QuickSort(int *array, size_t n)
{
	int low, high;

	low = 0;
	high = n - 1;

	Qsort(array, low, high);
}

void IterQsort(int *array, size_t low, size_t high)
{
	int stack[high - low + 1];
	int top;
	int pivot_index;
	int l, h;

	top = -1;

	stack[++top] = low;
	stack[++top] = high;

	while(top > 0)
	{
		h = stack[top];
		l = stack[--top];

		pivot_index = Partition(array, l, h);

		if(pivot_index - 1 > l)
		{
			stack[++top] = l;
			stack[++top] = pivot_index - 1;
		}

		if(pivot_index + 1 < h)
		{
			stack[++top] = pivot_index + 1;
			stack[++top] = h;
		}
	}
}

void IterQuickSort(int *array, size_t n)
{
	size_t low, high;

	low = 0;
	high = n - 1;

	IterQsort(array, low, high);
}

void Heapify(int *array, size_t heap_size, int node_index)
{
	int left = 2 * node_index + 1;
	int right = 2 * node_index + 2;

	int largest_index = node_index;

	if(left < heap_size && array[left] > array[largest_index])
		largest_index = left;

	if(right < heap_size && array[right] > array[largest_index])
		largest_index = right;

	if(largest_index != node_index)
	{
		Swap(&array[node_index], &array[largest_index]);

		Heapify(array, heap_size, largest_index);
	}
}

void HeapSort(int *array, size_t n)
{	
	int i;

	for(i = (n - 1) / 2; i >= 0; --i)
		Heapify(array, n, i);

	for(i = n - 1; i >= 0; --i)
	{
		Swap(&array[0], &array[i]);

		Heapify(array, i, 0);
	}
}

void CountingSort(int *array, size_t n)
{
	int input[n];
	int count[n];
	size_t i;

	memcpy(input, array, n * sizeof(int));
	memset(count, 0, n * sizeof(int));

	for(i = 0; i < n; i++)
		++count[input[i]];

	for(i = 1; i < n; i++)
		count[i] += count[i-1];

	for(i = 0; i < n; i++)
		array[count[input[i]]-- -1] = input[i];
}