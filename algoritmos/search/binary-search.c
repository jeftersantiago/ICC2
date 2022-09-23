#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ERROR -1

int *generateRandomVector(int size, int min, int max, int sorted);
int *sortVector(int* vec, int size);
void printVector(int* vec, int size);
int linearSearchIterative(int* vec, int size, int key);
int binarySearchIterative(int* vec, int begin, int end, int key);
// int binarySearchRecursive();

int main(int argc, char* argv[]){

    int size = atoi(argv[1]);
    int min = atoi(argv[2]);
    int max = atoi(argv[3]);
    int n = atoi(argv[4]);

    // Analise do pior caso.
    int key = n + 1;

    int *vec;

    clock_t ti, tf;
    FILE* fp = fopen("time_bin.dat", "w");

    for(int m = size;  m <= n; m = m * 2){

        ti = clock();
        vec = generateRandomVector(m, min, max, 1);
        binarySearchIterative(vec, 0, m - 1, key);
        tf = clock();

        double tt = (tf - ti)/ (double) CLOCKS_PER_SEC;

        printf("N = %d, time = %f s\n", m, tt);
        fprintf(fp, "%d\t%f\n", m, tt);

        free(vec);
        vec = NULL;
    }

    fclose(fp);
    return 0;
}

int linearSearchIterative(int* vec, int size, int key){
    for(int i = 0; i < size; i++){
        if(vec[i] == key){
            return i;
        }
    }
    return ERROR;
}

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
    return ERROR;
}

/**
int binarySearchRecursive(int* vec, int begin, int end, int key){
    int center = (int) ((begin + end) / 2.0);
    if(key == vec[center])
        return center;
    if(key > end)
        return -1;
    if(key > vec[center])
        return binarySearchRecursive(vec, center + 1, end, key);
    if(key < vec[center])
        return binarySearchRecursive(vec, begin, center - 1, key);
}
*/

int *sortVector(int* vec, int size){
    int i, j;
    for(i = 1; i < size; i++){
        j = i;
        while(j > 0 && (vec[j] < vec[j-1])){
            int tmp = vec[j];
            vec[j] = vec[j-1];
            vec[j-1] = tmp;
            j = j-1;
        }
    }
    return vec;
}

int *generateRandomVector(int size, int min, int max, int sorted){
    int *vec = malloc(sizeof(int) * size);
    srand(time(NULL));

    for(int i = 0; i < size; i++){
        vec[i] = (rand() % (max - min + 1)) + min;
    }
    if(sorted == 1)
        vec = sortVector(vec, size);
    return vec;
}
void printVector(int* vec, int size){
    for(int i = 0; i < size; i++){
        printf("%d ", vec[i]);
    }
    printf("\n");
}
