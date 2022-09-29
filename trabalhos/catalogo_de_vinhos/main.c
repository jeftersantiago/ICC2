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
//    scanf("%49[^\n]%*c", fname);
    scanf("%s", fname);
    Wine **wineList = loadData(fname);

    if(wineList == NULL) return 1;

    int nSearch;
    scanf("%d", &nSearch);
    int property;
    char prop[20];
    double key;

    int i = 0;
    while(i < nSearch){

        scanf("%s %lf", prop, &key);
        
        /**
           1 - citric_acid
           2 - residual_sugar
           3 - density
           4 - ph
           Other - alcohol
         **/
        if(strcmp(prop, "citric_acid") == 0)
            property = 1;
        else if(strcmp(prop, "residual_sugar") == 0)
            property = 2;
        else if(strcmp(prop, "density") == 0)
            property = 3;
        else if(strcmp(prop, "pH") == 0)
            property = 4;
        else property = 5;

        // tmp.
        int size = N_ROWS; 
       
        search (wineList, key, property, size);
        i++;
    }
    for(int i = 0; i < N_ROWS; i++){
        free(wineList[i]);
    }
    free(wineList);
    return 0;
}
