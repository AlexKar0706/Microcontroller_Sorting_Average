#include "selectionSort.h"

void selectionSort(short arr[], short empty, short len) {
	short tempIndex, tempNum;
	len += 1;
	for (short i = 0; i < len - 1; i++) {
		tempIndex = i;
		for (short j = i + 1; j < len; j++) {
			if (arr[j] < arr[tempIndex]) {
				tempIndex = j;
			}
		}
		tempNum = arr[i];
		arr[i] = arr[tempIndex];
		arr[tempIndex] = tempNum;
	}
}