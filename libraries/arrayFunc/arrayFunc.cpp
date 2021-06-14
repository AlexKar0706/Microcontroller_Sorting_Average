#include "arrayFunc.h"

int freeRAM() {
  //Function for computing the avaliable RAM memory in the compiler stack

  extern int __heap_start, *__brkval;
  int v;
  return (int) &v - (__brkval == 0 ? (int) &__heap_start : (int) __brkval);
}


void timer_setup() {
  //Setup of the timer1 for computing the avaliable RAM memory in the compiler stack during the sorting process

  noInterrupts();
  //set timer1 interrupt at 2kHz
  TCCR1A = 0;// set entire TCCR1A register to 0
  TCCR1B = 0;// same for TCCR1B
  TCNT1  = 0;//initialize counter value to 0
  // set compare match register for 1hz increments
  OCR1A = 8000;// = (16*10^6) / (2000*1) - 1 (must be <65536)
  // turn on CTC mode
  TCCR1B |= (1 << WGM12);
  // Set CS10 bits for 1 prescaler
  TCCR1B |= (1 << CS10);  
  // enable timer compare interrupt
  TIMSK1 |= (1 << OCIE1A);
  interrupts();
}

int currFreeMem = 2299;
int prevFreeMem = 2299;

void printArr(short arr[], size_t len) {
  //Function for printing array to the Serial monitor

  Serial.println();
  Serial.print("[ ");
  for (short i = 0; i < len; i++) {
    Serial.print(arr[i]);
    Serial.print(" ");
    if (!(i%50) && i != 0) Serial.println();
  }
  Serial.print("]");
}

void createRandomArr(short arr[], size_t len) {
  //Function for the create new random order of the "short" typed integers in array.

  srand(analogRead(rand() % 6)); //As a seed, srand function takes analog value from the 0 port of Arduino
  for (int i = 0; i < len; i++)
    arr[i] = rand() % len;
}

void checkArr(short arr[], size_t len) {
  //Simple function for check, if array is sorted correctly
  // - If array is sorted correctly, function will write "Array is sorted" in the Serial monitor window.
  // - If array is not sorted correctly, function will write "Array is not sorted" in the Serial monitor window.

  short check = 1;
  for (short i = 0; i < len - 1; i++)
    if (arr[i + 1] < arr[i]) check = 0;
  Serial.println();
  if (check) Serial.print("Array is sorted");
  else Serial.print("Array is not sorted");
}

void avgTime (short arr[], short len, void (*sortAlg)(short [], short, short)) {
  //Function for computing the average time needed to sort array
  //and for computing the average usage of RAM memory during the sorting process

  unsigned long start_t;
  double sum;
  for (short i = 0; i < 100; i++){
    //For-cycle sorting array 100 times to compute the average time
    
    createRandomArr(arr, len);
    start_t = millis();
    (*sortAlg)(arr, 0, len - 1);
    start_t = millis() - start_t;
    sum += start_t;
  }

  timer_setup();

  Serial.println();
  Serial.print("Available RAM before testing: ");
  Serial.print(freeRAM());

  for (short i = 0; i < 100; i++){
    //For-cycle sorting array 100 times to compute the average usage of RAM memory

    createRandomArr(arr, len);
    (*sortAlg)(arr, 0, len - 1);
  }

  Serial.println();
  Serial.print("Average time to sort array: ");
  Serial.print(sum/100);
  Serial.println();

  Serial.print("Minimum of available RAM: ");
  Serial.print(prevFreeMem);
  Serial.println();
}

ISR(TIMER1_COMPA_vect){//timer1 interrupt 2kHz
  //Interrupt function, which is computing free RAM memory every 0.5ms

  currFreeMem = freeRAM();
  if (currFreeMem < prevFreeMem) {
    prevFreeMem = currFreeMem;
  }
}