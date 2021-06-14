#include "heapSort.h"

void heapify(short arr[], short len, short i)
{
	short root = i;
	short tempNum;
	short lChild = 2 * i + 1;
	short rChild = 2 * i + 2;

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
			lChild = 2 * root + 1;
			rChild = 2 * root + 2;
		}
	} while (root != i);
}

void heapSort(short arr[], short empty, short len) {
	short tempNum;
	len += 1;
	for (short i = len / 2 - 1; i >= 0; i--)
		heapify(arr, len, i);
	for (short i = len - 1; i > 0; i--) {
		tempNum = arr[0];
		arr[0] = arr[i];
		arr[i] = tempNum;
		heapify(arr, i, 0);
	}
}
