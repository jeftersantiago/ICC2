#ifndef _search_
#define _search_
#include "wine.h"

int binarySearch(Wine **list, const double key, int begin, int end, const int property);

void search(Wine **list, double key, int property, int size);

void insertionSort(Wine **list, const int listSize, const int property);

void swap(Wine **list, int currentIndex, int newIndex);
Wine** wineSort(Wine **list, const int size, const int property);

#endif
