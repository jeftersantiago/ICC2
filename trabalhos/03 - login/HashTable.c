#include "HashTable.h"

/**
   Retorna o elemento na posição dada da tabela. Realiza a busca na lista ligada
   caso tenha havido algum conflito.
   Parametros:
   HashTable * hash - tabela hash.
   uint32_t position - posicao calculada por h(k) % N .
   char * nUSP - chave da busca.
 **/
static Student * search_hash_table(HashTable * hash, uint32_t position, char * nUSP);

#define M 65521
/* Tamanho da tabela hash. */
#define N 256

struct HASH_TABLE {
  LinkedList ** table;
  uint16_t size;
};

HashTable * makeHashTable (int size) {

  HashTable * hash = (HashTable *) malloc(sizeof(HashTable));
  
  hash->size = N;
  LinkedList ** table = (LinkedList **) malloc(sizeof(LinkedList*) * hash->size);
  /* Inicializa os indices da tabela hash. */
  for(int i = 0; i < hash->size; i++) table[i] = NULL;
  hash->table = table;
  return hash;
}

void deleteHashTable (HashTable * hash) {
  if(hash != NULL){
    for(int i = 0; i < hash->size; i++){
      if(hash->table[i] != NULL)
        deleteLinkedList(hash->table[i]);
    }
    free(hash->table);
    free(hash);
  }
}
boolean insertHashTable (HashTable * hash, Student * student) {
  if(hash != NULL){

    /* Calcula indice do elemento na tabela hash */
    uint32_t position = (uint32_t) hashing(getNUSP(student)) % hash->size;

    /* Caso 1 -> não há conflito */
    if(hash->table[position] == NULL){
      hash->table[position] = newLinkedList();
      insertLinkedList(hash->table[position], student);
      return true;
    }
    /* Caso 2 -> há conflito */
    else if(search_hash_table(hash, position, getNUSP(student)) == NULL){
      insertLinkedList(hash->table[position], student);
      return true;
    }
  }
  /* Caso 3 -> Numero USP invalido */
  deleteStudent(student);
  return false;
}

int loginHashTable(HashTable * hash, char * line, Student ** student) {

  char * nUSP = strsep(&line, " ");
  uint32_t password = hashing(strsep(&line, " "));
  uint32_t position = hashing(nUSP) % hash->size;

  *student = search_hash_table(hash, position, nUSP);

  if(*student != NULL){
    if(password == getPassword(*student))
      return 0;
    else
      return 1;
  }
  return 2;
}

uint32_t hashing (char * n) {

  uint16_t high = 0;
  uint16_t low = 1;
  int length = strlen(n);

  for(int i = 0; i < length; i++){
    low = (low + n[i]) % M;
    high = (high + low) % M;
  }

  uint32_t sum = (high << 16) | low;

  return sum;
}

static Student * search_hash_table (HashTable * hash, uint32_t position, char * nUSP) {
  if(hash != NULL){
    return searchLinkedList(hash->table[position], nUSP);
  }
  return NULL;
}
