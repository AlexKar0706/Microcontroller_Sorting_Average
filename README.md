# Introduction
This project is made to compute average time needed and average RAM needed for Arduino Uno Rev 3 microcontroller to sort array with differnt sorting algorithms.
## Available sorting algorithm
There is 8 available sorting algorthms.
| Name of sorting algorithm | Corresponding function |
| ------ | ------ |
| Bubble sort | void bubbleSort(short arr[], short empty, short len) |
| Insertion sort | void insertionSort(short arr[], short start, short end_f) |
| Selection sort | void selectionSort(short arr[], short empty, short len) |
| Heap sort | void heapSort(short arr[], short empty, short len) |
| Quick sort | void quickSort(short arr[], short start, short end_f) |
| Merge sort | void mergeSort(short arr[], short iLeft, short iRight) |
| Introsort | void introSort(short arr[], short empty, short len) |
| Tim sort | void timSort(short arr[], short empty, short n) |

Some sorting algorithms has "short empty" variable, which is just used to fill the function with additional attribute.
## Main function
To calculate average time needed for sorting, it is needed to include sorting algorithm header and then pass sorting algorithm's function into avgTime function.
### Warning!
avgTime function can't handle errors that can be occurred by overloading RAM memory of microcontroller.
