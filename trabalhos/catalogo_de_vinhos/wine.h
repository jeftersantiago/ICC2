#ifndef _wine_
#define _wine_

#define DOUBLE_COLS 5
#define N_ROWS 739


typedef struct WINE Wine;

Wine *newWine(const int id, const double citric_acid, const double residual_sugar, const double
              density, const double pH, const double alcohol);

Wine *emptyWine();

void destroyWine(Wine *wine);

void printWine(Wine *wine);

int getId(const Wine *wine);

Wine **loadData(const char *fname);


double getProperty(const Wine *wine, int property);
int getId(const Wine *wine);


#endif
