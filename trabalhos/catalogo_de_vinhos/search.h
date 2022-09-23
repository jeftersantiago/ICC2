#ifndef _search_
#define _search_
#include "wine.h"


Wine *binarySearch(Wine **list, const Wine *key, int begin, int end,const int property);
void insertionSort(Wine **list, const int listSize, const int property);

void swap(Wine **list, int currentIndex, int newIndex);
void wineSort(Wine **list, const int size, const int property);

#endif
