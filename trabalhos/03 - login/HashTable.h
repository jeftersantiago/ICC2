#ifndef _HashTable_
#define _HashTable_

#include "Util.h"
#include "LinkedList.h"

typedef struct HASH_TABLE HashTable;

/* Realiza o hashing de acordo com o que foi detalhado no PDF. */
uint32_t hashing (char * n);

/** Retorna uma tabela hash
    Parametros:
    int size - quantidade de entradas.
 **/
HashTable *makeHashTable(int size);

/**
   Insere um novo item à tabela hash.
   Parametros:
   HashTable * hash - tabela que recebe insercao.
   Student * student - item a ser inserido.
 **/
boolean insertHashTable (HashTable * hash, Student * student);

/**
   Parametros:

   HashTable * hash - tabela hash.
   char * line - Numero usp e senha.
   Student ** student - Variavel temporaria usada para
   printar as notas caso o login seja bem sucedido.

   Retorna:

   0 - Login com sucesso
   1 - Senha incorreta.
   2 - Número USP inválido.
 **/
int loginHashTable(HashTable * hash, char * line, Student ** student);

/**
   Percorre toda tabela e remove os elementos da tabela hash.
 **/
void deleteHashTable(HashTable * hash);
#endif
