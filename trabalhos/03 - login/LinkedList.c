#include "LinkedList.h"

typedef struct NODE Node;

/* Retorna true se a lista estiver vazia. */
static boolean is_empty(LinkedList * list);

/**
   Função auxiliar para deletar lista ligada.
   Realiza a remoção de nós da lista ligada recursivamente.
**/
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

Student * searchLinkedList (LinkedList * list, char * nUSP){
  if(list != NULL){
    Node * node = list->begin;
    while(node != NULL){
      if(strcmp(getNUSP(node->student), nUSP) == 0){
        return node->student;
      }
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
    deleteStudent(node->student);
    free(node);
    delete_node(aux);
  }
}

void deleteLinkedList (LinkedList * list) {
  Node * node = list->begin;
  delete_node(node);
  free(list);
}
