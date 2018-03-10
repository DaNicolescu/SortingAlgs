#ifndef HEADER_H
#define HEADER_H
	typedef void (*Sorter)(int*, size_t);

	void RandomArray(int**, size_t*);
	void PrintArray(int*, size_t);
	void FreeArray(int**);
	void TestAlg(Sorter, int*, size_t);
	void SelectionSort(int*, size_t);
	void BubbleSort(int*, size_t);
	void RecBubbleSort(int*, size_t);
	void InsertionSort(int*, size_t);
	void RecInsertionSort(int*, size_t);
	void MergeSort(int*, size_t);
	void IterMergeSort(int*, size_t);
	void QuickSort(int*, size_t);
	void IterQuickSort(int*, size_t);
	void HeapSort(int*, size_t);
	void CountingSort(int*, size_t);
#endif