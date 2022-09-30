#include "catalogue.h"
/**
   TODO: alocação dinâmica. 

   Faz leitura do arquivo .CSV
   Retorna vetor de structs com todos elementos do arquivo lido.
   Parametros:
   char *fname: nome do arquivo.
 */

void loadData(const char* fname, Catalogue *catalogue);

struct CATALOGUE {
    Wine **list;
    int amount;
};

Wine **getList(const Catalogue *catalogue){
    return catalogue->list;
}
int getAmount(const Catalogue *catalogue){
    return catalogue->amount;
}

Catalogue *newCatalogue(const char *fname){
    Catalogue *catalogue = (Catalogue *) malloc(sizeof(Catalogue));
    loadData(fname, catalogue);
    return catalogue;
}

void loadData(const char *fname, Catalogue *catalogue){

    int count = 0;

    catalogue->list = NULL;

    FILE *file;
    file = fopen(fname, "r");

    if(file == NULL)
    {
        printf("Error opening file.\n");
        return;
    }
    int id;
    // Valor de DOUBLE_COLS definido no arquivo wine.h
    // citric_acid, residual_sugar ...
    double val[DOUBLE_COLS];
    char line[100];

    while(fgets(line, 50, file) != NULL){

        count++;

        catalogue->list = (Wine **) realloc(catalogue->list, sizeof(Wine *) * count);

        sscanf(line, "%d,%lf,%lf,%lf,%lf,%lf", &id, &val[0], &val[1], &val[2], &val[3], &val[4]);

        catalogue->list[count - 1] = newWine(id, val[0], val[1], val[2], val[3], val[4]);
        // count - 1 -> ignora a primeira linha.
    }
    catalogue->amount = count;
    fclose(file);
}

void destroyCatalogue(Catalogue *catalogue){
    for(int i = 0; i < catalogue->amount; i++){
        free(catalogue->list[i]);
    }
    free(catalogue->list);
    free(catalogue);
}
