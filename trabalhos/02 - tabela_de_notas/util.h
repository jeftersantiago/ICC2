#ifndef _util_
#define _util_

#define true 1
#define false 0
#define boolean int

#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int *generateRandomVector(int size, int min, int max);
void print_vector(int* vec, int index, int size);

#endif
