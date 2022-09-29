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
//    regex para ler path.
//    scanf("%49[^\n]%*c", fname);
    scanf("%s", fname);
//    strcpy(fname, "./data/vinhos dados.csv");
    Wine **wineList = loadData(fname);

    if(wineList == NULL) return 1;

    int nSearch;
    scanf("%d", &nSearch);
//    nSearch = 1;
    int numProp;
    char prop[20];
    double key;

    int i = 0;
    while(i < nSearch){

        scanf("%s %lf", prop, &key);
        
        /**
           Selects what property will be searched.
                 1 - citric_acid
                 2 - residual_sugar
                 3 - density
                 4 - ph
                 Other - alcohol
         **/
        if(strcmp(prop, "citric_acid") == 0)
            numProp = 1;
        else if(strcmp(prop, "residual_sugar") == 0)
            numProp = 2;
        else if(strcmp(prop, "density") == 0)
            numProp = 3;
        else if(strcmp(prop, "pH") == 0)
            numProp = 4;
        else numProp = 5;

        // tmp.
        int size = N_ROWS;
       
        search (wineList, key, numProp, size);
        i++;
    }
    for(int i = 0; i < N_ROWS; i++){
        destroyWine(wineList[i]);
    }
    return 0;
}
