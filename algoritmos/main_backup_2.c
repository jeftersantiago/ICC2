#include "util.h"

void set_leaves(int *tree, int *v, int n, int t_size);
void build_winner_tree(int *tree, int parent, int t_size);
void transverse(int *tree, int parent, int t_size);
int * tournament_sort(int *v, int n);

int main(int argc, char* argv[]){

   int n = 4;
 //   int * v = generateRandomVector(n, 1, 10);
   int v[4] = {8, 10, 9, 7}; 
   printf("Array: ");
   print_vector(v, 0, n);

   int *sorted = tournament_sort(v, n);

   printf("\nSorted array: ");
   print_vector(sorted, 0, n);
   free(sorted);
}

int * tournament_sort(int *v, int n){

  int t_size = 2 * n;

  int *tree = (int *) malloc(sizeof(int *) * t_size);

  set_leaves(tree, v, n, t_size);

  int last_parent = (int) (t_size - 1) / 2.0;

  int *sorted_array = (int *) malloc(sizeof(int *) * n);

  int i;
  int j = 0;

  printf("Heap: ");
  print_vector(tree, 1, t_size);
  printf("\n");
  printf("Tournament sort\n");

  while(j < n){
    for(i = last_parent; i >= 1; i--)
      build_winner_tree(tree, i, t_size);

    printf("Winner Tree: ");
    print_vector(tree, 1, t_size);

    transverse(tree, 1, t_size);

    printf("Remove Winner: ");
    //    printf("%d\n", tree[1]);
    sorted_array[j] = tree[1];
    tree[1] = -1;
    print_vector(tree, 1, t_size);
    j++;
  }

  free(tree);
  return sorted_array;
}

/**
   Removes the winner from the tree.
   Changes it to -1.
 **/
void transverse(int *tree, int parent, int t_size) {

  int left = 2 * parent;
  int right = 2 * parent + 1;
  int node;

  if(left > t_size) return;

  if(tree[left] == tree[parent] || (right <= t_size && tree[right] == tree[parent])){

    if(tree[left] == tree[parent]){
      node = left;
      transverse(tree, left, t_size);
    }
    else {
      node = right;
      transverse(tree, right, t_size);
    }
  }
  tree[node] = -1;
}

/**
   Selects from bottom to top the bigger values by comparisions
   with the nodes.
 **/
void build_winner_tree(int *tree, int parent, int t_size){

  int left = 2 * parent;
  int right = 2 * parent + 1;

  if(left > t_size)
    return;
  /**
     1 - Node at left is greater than parent.
     2 - Exists node at right.
     3 - Node at right is greater than parent.
   **/
  if(tree[left] > tree[parent] || (right <= t_size && tree[right] > tree[parent])){

    if(right <= t_size && tree[right] > tree[left])
      left = right;
    
    tree[parent] = tree[left];

    build_winner_tree(tree, left, t_size);
  }
}

void set_leaves(int *tree, int *v, int n, int t_size){
  int j = 0;
  for(int i = 0; i <= t_size - 1; i++){
    if(i < n)
      tree[i] = -1;
    else{
      tree[i] = v[j];
      j++;
    }
  }
}

