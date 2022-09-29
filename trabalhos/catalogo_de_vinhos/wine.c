#include "wine.h"
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

struct WINE {
    int id;
    double citric_acid;
    double residual_sugar;
    double density;
    double pH;
    double alcohol;
};
    
/**
   Talvez não seja uma boa prática.
   Ver de alterar depois.
 **/
Wine *emptyWine(){
    Wine *tmp = (Wine *) malloc(sizeof(Wine));
    tmp->id = -1;
    return tmp;
}

void destroyWine(Wine *wine){
    free(wine);
}

Wine *newWine(const int id, const double citric_acid, const double residual_sugar, const double
              density, const double pH, const double alcohol){

    Wine *wine = (Wine *) malloc(sizeof(Wine));

    wine->id = id;
    wine->citric_acid = citric_acid;
    wine->residual_sugar = residual_sugar;
    wine->density = density;
    wine->pH = pH;
    wine->alcohol = alcohol;

    return wine;
}


double getProperty(const Wine *wine, int property){
    if(property == 1)
        return wine->citric_acid;
    if(property == 2)
        return wine->residual_sugar;
    if(property == 3)
        return wine->density;
    if(property == 4)
        return wine->pH;
    
    return wine->alcohol;
}

int getId(const Wine *wine){
    return wine->id;
}

void printWine(Wine *wine){
    printf("ID: %d, Citric Acid: %.5f, Residual Sugar %.5f, Density %.5f, pH %.5f, Alcohol %.5f\n",
           wine->id, wine->citric_acid, wine->residual_sugar,
           wine->density, wine->pH, wine->alcohol);
}

/**
   TODO: alocação dinâmica. 

   Faz leitura do arquivo .CSV
   Retorna vetor de structs com todos elementos do arquivo lido.
   Parametros:
   char *fname: nome do arquivo.
 */
Wine **loadData (const char *fname){

    Wine **wineList = (Wine **) malloc(N_ROWS * sizeof(Wine*));

    FILE *file;
    file = fopen(fname, "r");

    if(file == NULL)
    {
        printf("Error opening file.\n");
        return NULL;
    }
    int id;
    // Valor de DOUBLE_COLS definido no arquivo wine.h
    // citric_acid, residual_sugar ...
    double val[DOUBLE_COLS];

    int i = 0;
    char line[100];
    while(fgets(line, 50, file) != NULL){
        sscanf(line, "%d,%lf,%lf,%lf,%lf,%lf", &id, &val[0], &val[1], &val[2], &val[3], &val[4]);
        wineList[i-1] = newWine(id, val[0], val[1], val[2], val[3], val[4]);
        i++;
    }
    fclose(file);
    return wineList;
}
