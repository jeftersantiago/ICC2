#include "tournament.h"

/**
   Implementacao do torneio geral.
   Complexidade: O(nlogk)
 **/
static void general_tournament_sort (_student ** tree, _student ** list, int n_students, int h);

/**
   Essa variavel só é utilizada na main no momento de imprimir os
   elementos e seus respectivos criterios de desempate.

   La é passada a flag with_criteria e atualizado o valor desta variavel.
   
   Criterio de desempate. 
   0 - Média
   != 0 - Número da nota usada no desempate.
 **/
int criteria = 0;

int * get_criteria () {
  return & criteria;
};

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
   _student ** list: Lista com elementos que serao colocados nas folhas.
   int t_size : Numero de nós da arvore.
   
   Complexidade: O(logn)
   
   
   A construção da arvore de torneio é semelhante a construcao de um max-heap,
   e é feita em um loop para todos nós da árvore que possuem filho, por causa
   disso a complexidade real é O(n).

 **/
static void build_winner_tree(_student ** tree, int parent, int t_size);


/**
   Constroi a arvore de torneio de ordena o vetor usando o
   tournament_sort.
 **/
void sort (_student ** list, int n_students) {

  /**
     O tamanho da arvore é dado pela equação t = 2 * k,
     onde k = 2^h e h = ceil(log2(n)) é a profundidade
     da arvore e n é a quantidade de folhas. Entao

     t = 2 * 2 ^ ceil(log2(n))
     
  **/
  
  int h = ceil(log2(n_students));
  /* k */
  int t_size = (int) 2 * pow(2, h);
  
  _student ** tree = initialize_tree(list, n_students, t_size);

  int last_parent = (int)  (t_size - 1) / 2.0;

  /* Constroi a estrutura heap da arvore de torneio.
     O(n)
   */
  int i;
  for(i = last_parent; i >= 1; i--)
    build_winner_tree(tree, i, t_size);

  /* Ordena a lista em O(nlogk)*/
  general_tournament_sort(tree, list, n_students, h);

}

/**
   Ordenada lista de estudantes de acordo com suas notas.
   Parametros:
   _student ** list : Lista com os elementos a serem ordenados.
   int n_students: numero de elementos.

   Complexidade: O(nlogn)
 **/
static void general_tournament_sort (_student ** tree, _student ** list, int n_students, int h) {
  /* Atualiza a arvore de torneio e ordena os elementos da lista. */
  int i = 1;
  int j = 0;

  /* O(n) */
  while(j != n_students) {

    list[j] = tree[1];
    j++;

    i = 1;
    int first_leaf = pow(2, h);
    /**
       Desce na árvore até chegar na posição do maior elemento nas folhas.
       O(logk)
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
       O(logk)
     **/
    while(i > 1){
      int parent = ceil((i - 1) / 2.0);

      int left_node = 2 * parent;
      int right_node = 2 * parent + 1;

      /* Realiza comparacoes e trocas */
      if(tree[left_node] == compare(tree[left_node], tree[right_node], false))
        tree[parent] = tree[left_node];
      else
        tree[parent] = tree[right_node];
      i = parent;
    }
  }
  free(tree);
  tree = NULL;
}

/**
   Semelhante ao algoritmo heapify, mantem a max-heap para os sub-arvores
   da arvore de torneio.
 **/
static void build_winner_tree(_student ** tree, int parent, int t_size){
  int left = 2 * parent;
  int right = 2 * parent + 1;

  boolean l;
  boolean r;

  if(left >= t_size) return;
  
  l = tree[left] == compare(tree[left], tree[parent], false);
  r = tree[right] == compare(tree[right], tree[parent], false);

  if(l  || (right <= t_size && r)){

    if (right <= t_size && tree[right] == compare(tree[right], tree[left], false))
      left = right;

    tree[parent] = tree[left];
    
    build_winner_tree(tree, left, t_size);
  }
}

static _student ** initialize_tree(_student ** list, int n_leafs, int t_size){

  _student ** tree = (_student **) malloc(sizeof(_student *) * t_size);

  int j = 0;
  for(int i = 1; i < t_size; i++)
    /* Condicao para ser nó folha. */
    if(i > n_leafs && j < n_leafs){
      tree[i] = list[j];
      j++;
    }
    else tree[i] = NULL;
  return tree;
}

_student * compare (_student * s1, _student * s2, boolean with_criteria) {
  
  /**  Trata os casos de alguma das váriaveis ser NULL.   **/
  if(s1 == NULL && s2 == NULL) return NULL;
  if(s1 != NULL && s2 == NULL) return s1;
  if(s1 == NULL && s2 != NULL) return s2;
  
  if(get_mean(s1) > get_mean(s2)) return s1;
  if(get_mean(s1) < get_mean(s2)) return s2;

  /* Comparacao por notas */
  for(int i = 0; i < get_amount_grades(s1); i++){
    if(with_criteria) criteria = i + 1;

    float n1 = get_grade(s1, i);
    float n2 = get_grade(s2, i);

    if(n1 > n2) return s1;
    if(n1 < n2) return s2; 
  }
  return NULL;
}

void print_student(_student *student, int index, int * crit, int n_students){

  if(* crit == 0 && index < n_students)
    printf("%d. %s - media\n", index, get_name(student));

  if(* crit != 0)
    printf("%d. %s - desempate: nota %d\n", index, get_name(student), *crit);

  if(index == n_students)
    printf("%d. %s \n", index, get_name(student)); 

  /* De volta ao padrão. */
  *crit = 0;
}


