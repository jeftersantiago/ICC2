#include "HashTable.h"
#include <math.h>

Student * searchHashTable(HashTable * hash, uint32_t position, Student * student);

// static void bin(unsigned n);

#define M 65521
#define N 256

struct HASH_TABLE {
  LinkedList ** table;
  uint16_t size;
};

HashTable * makeHashTable (int size) {

  HashTable * hash = (HashTable *) malloc(sizeof(HashTable));
  
  hash->size = N;

  //  printf("Hash size = %d\n", hash->size);
  LinkedList ** table = (LinkedList **) malloc(sizeof(LinkedList*) * hash->size);
  for(int i = 0; i < hash->size; i++) table[i] = NULL;
  hash->table = table;
  return hash;
}

void deleteHashTable (HashTable * hash) {
  if(hash != NULL) {
    for(int i = 0; i < hash->size; i++)
      if(hash->table[i] != NULL)
        deleteLinkedList(hash->table[i]);
    free(hash->table);
    free(hash);
  }
}
boolean insertHashTable (HashTable * hash, Student * student) {
  if(hash != NULL){

    uint32_t position = (uint32_t) getNUSP(student) % hash->size;
    //    printf("Position = %d\n", position);
    
    if(hash->table[position] == NULL){
      hash->table[position] = newLinkedList();
      insertLinkedList(hash->table[position], student);
      return true;
    }
    if(searchHashTable(hash, position, student) == NULL){
      insertLinkedList(hash->table[position], student);
      return true;
    }
  }
  deleteStudent(student);
  return false;
}

Student * searchHashTable (HashTable * hash, uint32_t position, Student * student) {
  if(hash != NULL){
    //    printStudent(student);
    Student * s = searchLinkedList(hash->table[position], student);
    //    if(s == NULL) printf("AQUI\n");
    return s;
  }
  return NULL;
}

/**
boolean loginHashTable(HashTable * hash, char * line) {

  char * nUSP = strsep(&line, " ");
  char * password = strsep(&line, " ");


  int position = hashing(nUSP) / hash->size;
  
  return false;
}
*/

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

int getSize (HashTable * hash){
  return hash->size;
}

/**
static void bin(unsigned n){
    unsigned i;
    for (i = 1 << 31; i > 0; i = i / 2)
        (n & i) ? printf("1") : printf("0");
    printf("\n");
}
**/
