#ifndef _sorting_algorhtms_
#define _sorting_algorhtms_
#include <stdlib.h>

void insertionSort(int* v, int size);

/** Merge Sort **/
void mergeSort(int* v, int begin, int end);
void merge(int* v, int begin, int center, int end);
#endif
