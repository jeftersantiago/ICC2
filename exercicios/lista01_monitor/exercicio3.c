#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char* argv[]){

    
    int amountTerms = atoi(argv[1]);

    char* tmpTerms = argv[2];
    int* listTerms = malloc(amountTerms * sizeof(int));

    for(int i = 0; i < amountTerms; i++){
        *(listTerms+i) = (int) tmpTerms[i];
        printf("%d\n", *(listTerms+i));
    }
    return 0;
}


