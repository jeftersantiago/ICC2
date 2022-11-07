#ifndef _tournament_
#define _tournament_

#include "student.h"

typedef struct QUEUE _queue;

void tournament_sort (_student ** list, int n_students);

void print_students (_queue * q);

#endif
