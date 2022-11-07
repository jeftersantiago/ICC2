#ifndef _util_
#define _util_
#include <time.h>
#include <stdlib.h>
#include <stdio.h>


#define true 1
#define false 0
#define boolean int


int *generateRandomVector(int size, int min, int max);
void printVector(int* vec, int size);
void print_vector(int* vec, int index, int size);
#endif
