#include "bubbleSort.h"

void bubbleSort(short arr[], short empty, short len) {
	short temp;
    len += 1;
	for (short i = 0; i < len; i++) {
		for (short j = 0; j < len - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				temp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = temp;
			}
		}
	}
}