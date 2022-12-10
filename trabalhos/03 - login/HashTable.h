#ifndef _HashTable_
#define _HashTable_

#include "Util.h"
#include "LinkedList.h"

#include <math.h>

typedef struct HASH_TABLE HashTable;


/** Funcao Hashing
    Realiza o hashing de acordo com o que foi detalhado no PDF.
    Retorna posição para inserção na tabela.
 **/
uint32_t hashing (char * n);

HashTable *makeHashTable(int size);

boolean insertHashTable (HashTable * hash, Student * student);

int getSize (HashTable * hash);

void deleteHashTable(HashTable * hash);

#endif
