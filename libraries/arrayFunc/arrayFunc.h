#ifndef arrayFunc_h
#define arrayFunc_h
#include <Arduino.h>
#include <stdlib.h>
#include <time.h>
int freeRAM();
void printArr(short arr[], size_t len);
void createRandomArr(short arr[], size_t len);
void checkArr(short arr[], size_t len);
void avgTime (short arr[], short len, void (*sortAlg)(short [], short, short));
#endif