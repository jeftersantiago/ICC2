/**
   Jefter Santiago
   nºUSP: 12559016
   SCC0201
**/
#include "wine.h"
#include "search.h"

#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int main(){
    char fname[50];
//    scanf("%s", &fname);
    strcpy(fname, "./data/vinho.csv");
    Wine **wineList = loadData(fname);

    if(wineList == NULL) return 1;

    for(int i = 0; i < 10; i++){
        printWine(wineList[i]);
    }

    printf("\n");
    Wine *key = newWine(9, 0.36, 6.1, 0.9978, 3.35, 10.5);

    Wine *searched = binarySearch(wineList, key, 0, N_ROWS - 1, 4);
    free(key);

    printf("\nBusca pelo vinho: \n");
    printWine(searched);
    printf("\n");

    if(getId(searched) == -1){
        printf("No wine was found.\n");
    }
    else {
        printf("Vinho encontrado: \n");
        printWine(searched);   
    }
    for(int i = 0; i < N_ROWS; i++){
        destroyWine(wineList[i]);
    }
    return 0;
}

char *readLine() {
    char *string = NULL;
    char currentInput;
    int index = 0;
    do {
        currentInput = (char)getchar();
        string = (char *) realloc(string, sizeof(char) * (index + 1));
        string[index] = currentInput;
        index++;
        if(currentInput == '\r')
        {
            currentInput = (char) getchar();
        }
    } while((currentInput != '\n') && (currentInput != EOF));
    string[index - 1] = '\0';
    return string;
}
