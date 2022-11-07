#include "util.h"

int *generateRandomVector(int size, int min, int max){
    int *vec = malloc(sizeof(int) * size);
    srand(time(NULL));
    for(int i = 0; i < size; i++)
        vec[i] = (rand() % (max - min + 1)) + min;
    return vec;
}

void print_vector(int* vec, int index, int size){
    for(int i = index; i < size; i++){
        printf("%d ", vec[i]);
    }
    printf("\n");
}
