#include "sorting_algorithms.h"

/** MERGE SORT **/

void mergeSort(int* v, int begin, int end){
    if(end <= begin) return;

    int center = (int) ((begin + end) / 2.0);

    mergeSort(v, begin, center);
    mergeSort(v, center + 1, end);
    merge(v, begin, center, end);
}

void merge(int* v, int begin, int center, int end){
    int* auxVec = (int *) malloc(sizeof(int) * (end - begin) + 1);
    int i = begin;
    int j = center + 1;
    int k = 0;

    while(i <= center && j <= end){
        if(v[i] <= v[j]){
            auxVec[k] = v[i];
            i++;
        }
        else{
            auxVec[k] = v[j];
            j++;
        }
        k++;
    }
    /** Se não entrar em nenhum caso, ou seja, a lista está vazia **/
    while(i <= center){
        auxVec[k] = v[i];
        i++;
        k++;
    }
    while(j <= end){
        auxVec[k] = v[j];
        j++;
        k++;
    }

    for(i = begin, k = 0; i <= end; i++, k++)
        v[i] = auxVec[k];
    free(auxVec);
}


/** INSERTION SORT  **/
void insertionSort(int* v,  int size){
    int i, j;
    for(i = 1; i < size; i++){
        j = i;
        while((j > 0) && (v[j] < v[j-1])){
            int aux = v[j];
            v[j] = v[j-1];
            v[j-1] = aux;
            j--;
        }
    }
}
