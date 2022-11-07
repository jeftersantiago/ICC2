#ifndef _wine_
#define _wine_

#include<stdio.h>
#include<stdlib.h>

/**
   Quantidade de colunas do tipo double como fixas.
   1 - citric_acid
   2 - residual_sugar
   3 - density
   4 - ph
   Other - alcohol
**/
#define DOUBLE_COLS 5

typedef struct WINE Wine;

Wine *newWine(const int id, const double citric_acid, const double residual_sugar, const double
              density, const double pH, const double alcohol);
/**
   1 - citric_acid
   2 - residual_sugar
   3 - density
   4 - ph
   Other - alcohol
 **/
double getProperty(const Wine *wine, int property);
int getId(const Wine *wine);
void printWine(Wine *wine);

#endif
