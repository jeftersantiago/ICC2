#include "search_algorithms.h"

int binarySearchIterative(int* vec, int begin, int end, int key){
    int center;
    while(begin <= end){
        center = (int) ((begin + end) / 2.0);

        if(vec[center] == key)
            return center + 1;
        if(vec[center] > key)
            end = center - 1;
        if(vec[center] < key)
            begin = center + 1;
    }
    return -1;
}

int binarySearchRecursive(int* vec, int begin, int end, int key){
    int center = (int) ((begin + end) / 2.0);
    if(key == vec[center])
        return center;
    if(key > end)
        return -1;
    if(key > vec[center])
        return binarySearchRecursive(vec, center + 1, end, key);
    return binarySearchRecursive(vec, begin, center - 1, key);
}

int linearSearchIterative(int* vec, int size, int key){
    for(int i = 0; i < size; i++){
        if(vec[i] == key){
            return i;
        }
    }
    return -1;
}
