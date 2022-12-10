#ifndef _LinkedList_
#define _LinkedList_

#include "Util.h"
#include "Student.h"

typedef struct LINKED_LIST LinkedList;

/**
   Insere novo elemento Student * na lista ligada.
   Parametros:
   LinkedList * list - lista ligada.
   Student * student - elemento a ser inserido.
**/
void insertLinkedList (LinkedList * list, Student * student);
/**
   Realiza busca na lista ligada e retorna um elemento Student *.
   Linkedlist * list - lista ligada.
   char * nUSP - chave de busca.
 **/
Student * searchLinkedList (LinkedList * list, char * nUSP);

/* Percorre a lista ligada LinkedList * list e remove todos elementos dela. */
void deleteLinkedList (LinkedList * list);
/* Retorna lista ligada vazia. */
LinkedList * newLinkedList ();

#endif
