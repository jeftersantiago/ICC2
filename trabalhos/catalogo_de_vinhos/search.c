#include "search.h"
#include "wine.h"
#include <stdio.h>
/**
   Verifique se o valor encontrado é o primeiro dentre
   todos os outros iguais no vetor, caso contrário,
   busque o primeiro deles.
**/
Wine *binarySearch(Wine **list, const Wine *key, int begin, int end, const int property){
//     insertionSort(list, N_ROWS, property);
     wineSort(list, N_ROWS, property);
     int center;
     while(begin <= end) {
         center = (int) ((begin + end) / 2.0);
         if(getWine(list[center], property) == getWine(key, property))
             return list[center + 1];
         if(getWine(list[center], property) > getWine(key, property))
             end = center - 1;
         if(getWine(list[center], property) < getWine(key, property))
             begin = center + 1;
     }
     return emptyWine(); 
}
/**
   Ordenação descrita nas especificações do trabalho.
   Parameters:
   Wine **list: list of structs of wines.
   int size: size of list of structs. 
   int property: attribute we want to sort.
      1 - citric_acid
      2 - residual_sugar
      3 - density
      4 - ph
      Other - alcohol
 **/
void wineSort(Wine **list, const int size, const int property){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size - i; j++){
            if(getWine(list[j], property) > getWine(list[i], property))
                swap(list, j, i);
            /**
               Check the cases where the attribute value is equal and
               if it is, sort it by ID in increasing order.
             **/
            if((getWine(list[j], property) == getWine(list[i], property)) && getId(list[j]) > getId(list[i]))
                swap(list, i, j);
        }
    }
}
void swap(Wine **list, int currentIndex, int newIndex){
    Wine *aux = list[currentIndex];
    list[currentIndex] = list[newIndex];
    list[newIndex] = aux;
}

/**
   ## DEBUG 

   Parameters:
   int property:
      1 - citric_acid
      2 - residual_sugar
      3 - density
      4 - ph
      Other - alcohol
**/
void insertionSort(Wine **list, const int listSize, const int property){
    for(int i = 1; i < listSize; i++){
        int j = i;
        while((j > 0) && (getWine(list[j], property) < getWine(list[j - 1], property))){
            Wine *tmp_wine = list[j];
            list[j] = list[j - 1];
            list[j - 1] = tmp_wine;
            j = j - 1;
        }
    }
}
