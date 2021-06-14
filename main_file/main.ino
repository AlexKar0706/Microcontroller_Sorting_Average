/*
  #include <bubbleSort.h>
  #include <heapSort.h>
  #include <insertionSort.h>
  #include <introSort.h>
  #include <mergeSort.h>
  #include <quickSort.h>
  #include <selectionSort.h>
  #include <timSort.h>
*/
#include <introSort.h>
#include <arrayFunc.h>

short arr[750];
size_t len = sizeof(arr) / sizeof(arr[0]);

void setup() {
  Serial.begin(9600);

  avgTime(arr, len, introSort);

  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(500);
  digitalWrite(LED_BUILTIN, LOW);
  delay(500);
}
