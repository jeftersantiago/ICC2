#include "student.h"

/**
   Criterio de desempate. 
   0 - Média
   != 0 -> Número da nota usada no desempate.
 **/
static int crit = 0;

/** Compara os dois valores dados
    Retorna true se s1 > s2, dado os critérios de comparação.
    Atualiza a variável crit de acordo com o critério utilizado.
 **/
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

static void print_students(_student ** tree, int index, int n) {
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
     da arvore e n é a quantidade de folhas. Entao

       t = 2 * 2 ^ ceil(log2(n))
     
  **/

  int h = ceil(log2(n_students));
  int t_size = (int) 2 * pow(2, h);
  
  _student ** tree =  initialize_tree(list, n_students, t_size);

  int last_parent = (int)  (t_size - 1) / 2.0;

  /* Constroi a estrutura heap da arvore de torneio. */
  int i;
  for(i = last_parent; i >= 1; i--)  build_winner_tree(tree, i, t_size);

  //  printf("Maior media: %.3f\n",get_mean(tree[1]));

  /**
     Realiza a ordenacao do vetor list e imprime
     a partir do maior.
   **/
  int j = 0;
  while(j != n_students) {

    list[j] = tree[1];

    /** Printa os elementos ordenados. **/

    /**
    if(crit == 0 && j + 1 < n_students) printf("%d. %s - media\n", j+1, get_name(list[j]));
    else if(j + 1 == n_students) printf("%d. %s \n", j+1, get_name(list[j]));
    else{
      printf("%d. %s - desempate: nota %d\n", j+1, get_name(list[j]), crit);
      crit = 0;
    }
    **/
    j++;

    i = 1;
    int first_leaf = pow(2, h);
    /**
       Desce na árvore até chegar na posição do maior elemento nas folhas.
       O(logn)
     **/
    while(i < first_leaf)
      if(tree[i] == tree[2*i]) i = 2 * i;
      else i = 2 * i + 1;
    /* Remove elemento */
    tree[i] = NULL;

    /**
       Sobe a arvore atualizando os nós.
       No fim desse loop a arvore está atualizada com o
       elemento da raíz sendo o maior.
       O(n)
     **/
    while(i > 1){
      int parent = ceil((i - 1) / 2.0);

      int left_node = 2 * parent;
      int right_node = 2 * parent + 1;

      /* Realiza comparacoes e trocas */
      if(is_greater(tree[left_node], tree[right_node]))
        tree[parent] = tree[left_node];
      else
        tree[parent] = tree[right_node];

      i = parent;
    }
  }
  free(tree);
  tree = NULL;
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
  
  if(get_mean(s1) > get_mean(s2)) return true;
  if (get_mean(s2) > get_mean(s1)) return false;
  
  for(int i = 0; i < get_amount_grades(s1); i++){
    if(get_grade(s1, i) > get_grade(s2, i)){
      printf("%s\n", get_name(s1));
      crit = i + 1;
      return true;
    }
    crit = 0;
    return false;
  }
  return false;
}
