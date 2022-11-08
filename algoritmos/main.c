#include "util.h"

#include <math.h>


void set_leaves(int *tree, int *v, int n, int t_size);
void build_winner_tree(int *tree, int parent, int t_size);
void transverse(int *tree, int parent, int t_size);
int * tournament_sort(int * tree, int *v, int n, int t_size, int h);

int main(int argc, char* argv[]){

   int n = 4;
 //   int * v = generateRandomVector(n, 1, 10);
   int v[4] = {8, 10, 9, 7}; 
   printf("Array: ");
   print_vector(v, 0, n);

   /**
      O tamanho (qtd de nós) da árvore é dado pela expressão
      t = 2 * 2^ (ceil(log2(n))) onde n é a quantidade de folhas.
   **/
   int h = ceil(log2(n));
   int t_size = (int) 2 * pow(2, h);
   
   int *tree = (int *) malloc(sizeof(int *) * t_size);

   set_leaves(tree, v, n, t_size);
   
   int last_parent = (int) (t_size - 1) / 2.0;

   int i;

   printf("Heap: ");
   print_vector(tree, 1, t_size);
   printf("\n");
   printf("Tournament sort\n");

   for(i = last_parent; i >= 1; i--)
     build_winner_tree(tree, i, t_size);
   
   int * sorted = tournament_sort(tree, v, n, t_size, h);
   
   for(int i = 0; i < n; i++){
     printf("%d ", sorted[i]);
   }
   printf("\n");

   free(sorted);
}

int * tournament_sort(int * tree, int *v, int n, int t_size, int h){

  int *sorted_array = (int *) malloc(sizeof(int *) * n);

  int j = 0;
  while(j != n){
    
    sorted_array[j] = tree[1];
    j++;

    int i = 1;
    
    int first_leaf = pow(2, h);

    /**
       O(logn)
       Percorre a arvore do topo pra baixo até chegar no maior elemento
       na folha.
       Substitui-o por -1.
     **/
    while(i < first_leaf)
      if (tree[i] == tree[2*i]) i = 2*i;
      else i = 2*i+1;

    tree[i] = -1;

    /**
       O(n)
       A partir do elemento na folha, sobe a árvore
       fazendo as comparações de quais são os maiores.
    **/
    while(i > 1){ 
      
      int parent = ceil((i - 1) / 2.0);

      int left_node = 2*parent;
      int right_node = 2*parent + 1;

      if(tree[left_node] > tree[right_node])
        tree[parent] = tree[left_node];
      else
        tree[parent] = tree[right_node];
      i = parent;
    }
  }
  free(tree);
  return sorted_array;
}

/**
   Complexidade: O(logn)
   Seleciona de baixo pra cima os valores maiores por comparacoes com os nós.
 **/
void build_winner_tree(int *tree, int parent, int t_size){

  int left = 2 * parent;
  int right = 2 * parent + 1;

  if(left > t_size)
    return;

  if(tree[left] > tree[parent] || (right <= t_size && tree[right] > tree[parent])){

    if(right <= t_size && tree[right] > tree[left])
      left = right;
    
    tree[parent] = tree[left];

    build_winner_tree(tree, left, t_size);
  }
}

void set_leaves(int *tree, int *v, int n, int t_size){
  int j = 0;
  for(int i = 1; i < t_size; i++){
    if(i < n)
      tree[i] = -1;
    else{
      tree[i] = v[j];
      j++;
    }
  }
}

