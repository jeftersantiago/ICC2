/**
   Jefter Santiago
   nºUSP: 12559016
   SCC0201
**/

#include "catalogue.h"
#include "search.h"

#include<string.h>

int main(){

    char fname[50];
//    scanf("%49[^\n]%*c", fname);
    scanf("%s", fname);

    Catalogue *catalogue = newCatalogue(fname);

    if(getList(catalogue) == NULL) return 1;

    int nSearch;
    scanf("%d", &nSearch);
    int property;
    char propertyName[20];
    double key;

    int i = 0;
    while(i < nSearch){
        scanf("%s %lf", propertyName, &key);
        /**
           1 - citric_acid
           2 - residual_sugar
           3 - density
           4 - ph
           Other - alcohol
         **/
        if(strcmp(propertyName, "citric_acid") == 0)
            property = 1;
        else if(strcmp(propertyName, "residual_sugar") == 0)
            property = 2;
        else if(strcmp(propertyName, "density") == 0)
            property = 3;
        else if(strcmp(propertyName, "pH") == 0)
            property = 4;
        else property = 5;

        search (getList(catalogue), key, property, getAmount(catalogue));
        i++;
    }
    destroyCatalogue(catalogue);
    return 0;
}
