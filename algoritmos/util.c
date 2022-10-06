#include "util.h"

int *generateRandomVector(int size, int min, int max){
    int *vec = malloc(sizeof(int) * size);
    srand(time(NULL));
    for(int i = 0; i < size; i++)
        vec[i] = (rand() % (max - min + 1)) + min;
    return vec;
}

void printVector(int* vec, int size){
    for(int i = 0; i < size; i++){
        printf("%d ", vec[i]);
    }
    printf("\n");
}
