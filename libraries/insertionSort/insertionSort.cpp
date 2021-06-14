#include "insertionSort.h"

void insertionSort(short arr[], short start, short end_f) {
	for (short i = start + 1, j = 0, tempNum; i <= end_f; i++) {
		tempNum = arr[i];
		for (j = i - 1; j >= start && arr[j] > tempNum; j--) arr[j + 1] = arr[j];
		arr[j + 1] = tempNum;
	}
}