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
    // regex para ler path.
//    scanf("%49[^\n]%*c", fname);
    scanf("%s", fname);
//    strcpy(fname, "./data/vinhos dados.csv");
    Wine **wineList = loadData(fname);

    if(wineList == NULL) return 1;

    /**
       for(int i = 0; i < 10; i++){
       printWine(wineList[i]);
       }
    **/

    int nSearch;
    scanf("%d", &nSearch);

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

        /**
           Ver quantos vinhos iguais foram encontrados na busca
           e printar na tela além do primeiro vinho da lista
           também quantos vinhos foram os resultados.
        **/
        int index = binarySearch(wineList, key, 0, N_ROWS - 1, numProp);
        int counter = 0;
        Wine *searchedWine = emptyWine();

        while(getWine(wineList[index], numProp) == key){
            for(int i = index + 1; i < N_ROWS; i++){
                if(getId(wineList[index]) < getId(wineList[i]))
                   searchedWine = wineList[i];
            }
            counter++;
            index++; 
        }
//        printWine(result);
        i++;
    }

    for(int i = 0; i < nSearch; i++){

        /**
        wineSort(list, size, property);
        int index = binarySearch(list, key, 0, size - 1, property);
        if(index == -1){
            return -1;
        }
        **/
 

        
        /**
        if(getId(searchedWine[i]) == -1){
            printf("Nenhum vinho encontrado.\n");
        }
        else {
//            int total = 1;
            printWine(searchedWine[i]);   
            printf("Total de vinhos encontrados: %d\n", 33);
        }
        **/
    }
    for(int i = 0; i < N_ROWS; i++){
        destroyWine(wineList[i]);
    }
    return 0;
}
