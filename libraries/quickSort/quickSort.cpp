#include "quickSort.h"

short partition(short arr[], short start, short end_f) {
    short pivot = arr[end_f];
    short tempNum;
    short i = (start - 1);

    for (short j = start; j <= end_f - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            tempNum = arr[i];
            arr[i] = arr[j];
            arr[j] = tempNum;
        }
    }
    i++;
    tempNum = arr[i];
    arr[i] = arr[end_f];
    arr[end_f] = tempNum;
    return i;
}

void quickSort(short arr[], short start, short end_f) {
    if (start >= end_f) return;
    short divider = partition(arr, start, end_f);
    quickSort(arr, start, divider - 1);
    quickSort(arr, divider + 1, end_f);
}