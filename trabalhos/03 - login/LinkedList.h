#ifndef _LinkedList_
#define _LinkedList_

#include "Util.h"
#include "Student.h"

typedef struct LINKED_LIST LinkedList;

void insertLinkedList (LinkedList * list, Student * student);
Student * searchLinkedList (LinkedList * list, Student * student);

void deleteLinkedList (LinkedList * list);
LinkedList * newLinkedList ();

#endif
