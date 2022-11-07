#include "student.h"

static char crit [100];
static double greater_mean = -1.0; 

static boolean is_greater (_student * s1, _student * s2);

#include <math.h>

/**
   Inicializa a arvore e define os nos folha da árvore.

   Parametros:
   _student ** list : Elementos que estarao no nós folha da árvore.
   int parent : Nó pai
   int t_size : Numero de nós da arvore
   int n_students : Numero de folhas.

   Complexidade: O(n)
**/
static _student ** initialize_tree(_student ** list, int n_leafs, int t_size);

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


void print_students(_student ** tree, int index, int n) {
  for(int i = index; i < n; i++){
    printf("Tree[%d] = %s\n",i , get_name(tree[i]));
  }
}

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

  int h = ceil(log2(n_students));
  int t_size = (int) 2 * pow(2, h);
  
  // printf(" HEAP : \n");

  _student ** tree =  initialize_tree(list, n_students, t_size);

  //  print_students(tree, 1, t_size);

  int last_parent = (int)  (t_size - 1) / 2.0;

  /* Constroi a arvore de torneio. */
  int i;
  for(i = last_parent; i >= 1; i--){
    //    printf("\nlast_parent = %d\n\n", i);
    build_winner_tree(tree, i, t_size);
    //    print_students(tree, 1, t_size);
    //    printf("\n");
  }

  int j = 0;

  while(j != n_students) {

    /**
    if(j == n_students - 1) printf("%d. %s\n", j+1, get_name(list[j]));
    else {
      printf("%d. %s%s\n", j+1, get_name(list[j]), crit);
      sprintf(crit, "");
    }
    **/

    list[j] = tree[1];
    j++;


    i = 1;
    int first_leaf = pow(2, h);
    
    while(i < first_leaf)
      if(tree[i] == tree[2*i]) i = 2 * i;
      else i = 2 * i + 1;

    tree[i] = NULL;

    while(i > 1){
      int parent = ceil((i - 1) / 2.0);

      int left_node = 2 * parent;
      int right_node = 2 * parent + 1;

      if(is_greater(tree[left_node], tree[right_node]))
        tree[parent] = tree[left_node];
      else
        tree[parent] = tree[right_node];
      i = parent;
    }
  }
  free(tree);
}

static void build_winner_tree(_student ** tree, int parent, int t_size){
  int left = 2 * parent;
  int right = 2 * parent + 1;
  boolean l;
  boolean r;

  if(left >= t_size) return;
  
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

  _student ** tree = (_student **) malloc(sizeof(_student *) * t_size);
  for(int i = 0; i < t_size; i++) tree[i] = NULL;

  int j = 0;
  for(int i = 1; i < t_size; i++)
    if(i > n_leafs && j < n_leafs){
      tree[i] = list[j];
      j++;
    }
  return tree;
}

/**
   Retorna true se s1 > s2 dado todas as comparacoes necessarias.

   Tá falhando para um caso.
   Falta resolver.
 **/
boolean is_greater (_student * s1, _student * s2) {

  
  /**  Trata os casos de alguma das váriaveis ser NULL.   **/
  if(s1 == NULL && s2 == NULL)
    return false;
  if(s1 != NULL && s2 == NULL)
    return true;
  if(s1 == NULL && s2 != NULL)
    return false;

  if(get_mean(s1) > get_mean(s2)){
    if(get_mean(s1) > greater_mean) greater_mean = get_mean(s1);
    return true;
  }
  else if (get_mean(s2) > get_mean(s1)){
    if(get_mean(s2) > greater_mean) greater_mean = get_mean(s2);
    // sprintf(crit, " - media\n");
    return false;
  }
  int i;
  for(i = 0; i < get_amount_grades(s1); i++){
    if(get_grade(s1, i) > get_grade(s2, i)){
      //      sprintf(crit, " - desempate: nota %d", i);
      return true;
    }
    return false;
  }
  return false;
}
