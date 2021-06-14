#include "timSort.h"

short min(short a, short b) {
	if (a < b) return a;
	return b;
}

void timSort(short arr[], short empty, short n)
{
	short size, iLeft, iMiddle, iRight;
	const short run = 32;
	n += 1;
	for (short i = 0; i < n; i += run)
		insertionSort(arr, i, min((i + 31), (n - 1)));
	for (size = run; size < n; size = 2 * size)
	{
		for (iLeft = 0; iLeft < n; iLeft += 2 * size)
		{
			iMiddle = iLeft + size - 1;
			iRight = min((iLeft + 2 * size - 1), (n - 1));

			merge(arr, iLeft, iMiddle, iRight);
		}
	}
}