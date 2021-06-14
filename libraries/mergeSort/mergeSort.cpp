#include "mergeSort.h"

void merge(short arr[], short iLeft, short iMiddle, short iRight)
{
	short n1 = iMiddle - iLeft + 1;
	short n2 = iRight - iMiddle;

	short* LeftArr = (short*)calloc(n1, sizeof(short));
	short* RightArr = (short*)calloc(n2, sizeof(short));

	for (short i = 0; i < n1; i++) LeftArr[i] = arr[iLeft + i];
	for (short j = 0; j < n2; j++) RightArr[j] = arr[iMiddle + 1 + j];

	short i = 0, j = 0, k = iLeft;
	for (; i < n1 && j < n2; k++) {
		if (LeftArr[i] <= RightArr[j]) {
			arr[k] = LeftArr[i];
			i++;
		}
		else {
			arr[k] = RightArr[j];
			j++;
		}
	}

	for (; i < n1; i++, k++) arr[k] = LeftArr[i];

	for (; j < n2; j++, k++) arr[k] = RightArr[j];
	free(LeftArr);
	free(RightArr);
}


void mergeSort(short arr[], short iLeft, short iRight) {
	if (iLeft < iRight) {
		short iMiddle = (iLeft + iRight) / 2;

		mergeSort(arr, iLeft, iMiddle);
		mergeSort(arr, iMiddle + 1, iRight);

		merge(arr, iLeft, iMiddle, iRight);
	}
}