#include "student.h"
#include <math.h>


static void print_students(_student ** list, int index, int n_students);
/**
   Inicializa a arvore e define os nos folha da árvore.

   Parametros:
   _student ** list : Elementos que estarao no nós folha da árvore.
   int parent : Nó pai
   int t_size : Numero de nós da arvore
   int n_students : Numero de folhas.

   Complexidade: O(n)
**/
static _student ** initialize_tree(_student ** list, int n_students, int t_size);

/**
   Constroi a arvore dos vencedores.
   Essa funcao so é chamada uma vez na execução do tournament_sort();

   Parametros:
   _student ** list: Heap binario.
   int t_size : Numero de nós da arvore.
   
   Complexidade: O(logn)
   Importante: No algoritmo essa funcao e executada
   em um loop que e seu uso se torna O(n).
 **/
static void build_winner_tree(_student ** tree, int parent, int t_size);
/**
   Retorna uma lista ordenada com os estudantes.
   Parametros:
   _student ** tree : Heap com os elementos a serem ordenados.
   int n_students: numero de elementos.
   Complexidade: O(nlogn)
 **/
void tournament_sort (_student ** list, int n_students) {

  /**
     O tamanho da arvore é dado pela equação t = 2 * k,
     onde k = 2^h e h = ceil(log2(n)) é a profundidade
     da arvore e n é a quantidade de folhas.
  **/

  int h =ceil(log2(n_students));
  int t_size = (int) 2 * pow(2, h);
  
  printf(" HEAP : \n");
  _student ** tree = initialize_tree(list, n_students, t_size);

  int last_parent = (int)  (t_size - 1) / 2.0;

  int i;

  for(i = last_parent; i >= 1; i--){
    printf("LP=%d\n-------------\n", i);
    build_winner_tree(tree, i, t_size);
    print_students(tree, 1, t_size);
    printf("-----------------------\n");
  }
  //  print_students(tree, 1, t_size);
}

static void build_winner_tree(_student ** tree, int parent, int t_size){
  int left = 2 * parent;
  int right = 2 * parent + 1;
  boolean l;
  boolean r;

  printf("Parent = %d\n", parent);

  if(left > t_size) return;
  

  l = is_greater(tree[left], tree[parent]);
  r = is_greater(tree[right], tree[parent]);

  if(l  || (right <= t_size && r)){

    if (right <= t_size && is_greater(tree[right], tree[left]))
      left = right;
    
    tree[parent] = tree[left];
    
    build_winner_tree(tree, left, t_size);

  }
}

static _student ** initialize_tree(_student ** list, int n_leafs, int t_size){
  printf("t_size = %d\n", t_size);

  _student **tree = (_student **) malloc(sizeof(_student *) * t_size);

  int j = 0;
  for(int i = 1; i < t_size; i++){
    if(i > n_leafs && j < n_leafs){
      tree[i] = list[j];
      j++;
    }
    else tree[i] = NULL;
  }
  //  print_students(tree, 1, t_size);
  return tree;
}

static void print_students(_student ** tree, int index, int n) {
  for(int i = index; i < n; i++){
    printf("Tree[%d] = %s\n",i , get_name(tree[i]));
  }
}
