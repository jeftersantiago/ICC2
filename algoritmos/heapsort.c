#include "util.h"


/**
   p -> parent
   n -> size
 **/
void max_heapify(int *v, int p, int n){

  // Left node
  int l = p * 2;
  int r = p * 2 + 1;
  int largest;

  if(l > n) return;
  /**
     Verifies max heap property
     -> comparision between left and right node.
   **/
  if(v[l] > v[p] || (r <= n && v[r] > v[p]))
    largest = l;
  else largest = p;

  if(r <= n && v[r] > v[largest])
    largest = r;
  if(largest != p){
    int aux = v[p];
    v[p] = v[largest];
    v[largest] = aux;
    max_heapify(v, largest, n);
  }
}

void heap_sort(int *v, int n){
  
}
























