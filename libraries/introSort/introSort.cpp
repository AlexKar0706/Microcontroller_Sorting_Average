#include "introSort.h"

void _heapify(short arr[], short len, short i, short start)
{
	short root = i;
	short tempNum;
	short lChild = 2 * i + 1 - start;
	short rChild = 2 * i + 2 - start;
	do {
		i = root;
		if (lChild < len && arr[lChild] > arr[root])
			root = lChild;

		if (rChild < len && arr[rChild] > arr[root])
			root = rChild;

		if (root != i) {
			tempNum = arr[i];
			arr[i] = arr[root];
			arr[root] = tempNum;
			lChild = 2 * root + 1 - start;
			rChild = 2 * root + 2 - start;
		}
	} while (root != i);
}

void _heapSort(short arr[], short start, short end) {
	short tempNum, sum = start + end;
	for (short i = short(ceil(sum / 2.0)) - 1; i >= start; i--)
		_heapify(arr, end + 1, i, start);
	for (short i = end; i > start; i--) {
		tempNum = arr[start];
		arr[start] = arr[i];
		arr[i] = tempNum;
		_heapify(arr, i, start, start);
	}
}

void introsort_imp(short arr[], short start, short end, short depth) {

	if (end - start < 16) {
		insertionSort(arr, start, end);
		return;
	}

	if (depth == 0) {
		_heapSort(arr, start, end);
		return;
	}

	short divider = partition(arr, start, end);
	introsort_imp(arr, start, divider - 1, depth - 1);
	introsort_imp(arr, divider + 1, end, depth - 1);
}

void introSort(short arr[], short empty, short len) {
	len += 1;
	short depth = 2 * short(log(double(len - 1)));
	introsort_imp(arr, 0, len - 1, depth);
}