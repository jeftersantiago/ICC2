#include "LinkedList.h"

typedef struct NODE Node;

static boolean is_empty(LinkedList * list);
static void delete_node(Node *node);

struct NODE {
  Student * student;
  Node * next;
};

struct LINKED_LIST {
  Node * begin;
  Node * end;
  //  int size;
};


LinkedList * newLinkedList () {
  LinkedList * list = (LinkedList *) malloc(sizeof(LinkedList));
  if(list != NULL){
    list->begin = NULL;
    list->end = NULL;
    //    list->size = 0;
  }
  return list;
}

void insertLinkedList (LinkedList * list, Student * student){
  if(list != NULL) {
    Node * node = (Node *) malloc(sizeof(Node));
    node->student = student;
    node->next = NULL;
    if(is_empty(list))
      list->begin = node;
    else
      list->end->next = node;
    list->end = node;
    //    list->size++;
  }
}

Student * searchLinkedList (LinkedList * list, Student * student){
  if(list != NULL){
    Node * node = list->begin;
    while(node != NULL){
      if(getNUSP(node->student) == getNUSP(student))
        return student;
      node = node->next;
    }
  }
  return NULL;
}
static boolean is_empty(LinkedList * list){
  if(list != NULL)
    return list->begin == NULL;
  return false; 
}

static void delete_node(Node *node){
  Node *aux = NULL;
  if(node != NULL){
    aux = node->next;
    free(node);
    delete_node(aux);
  }
}

void deleteLinkedList (LinkedList * list) {
  Node * node = list->begin;
  delete_node(node);
  free(list);
}
