#ifndef _catalogue_
#define _catalogue_
#include "wine.h"

typedef struct CATALOGUE Catalogue;

Catalogue *newCatalogue(const char *fname);
Wine **getList(const Catalogue *catalogue);
int getAmount(const Catalogue *catalogue);
void destroyCatalogue(Catalogue *catalogue);

#endif
