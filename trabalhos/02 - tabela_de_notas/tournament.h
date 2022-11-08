#ifndef _tournament_
#define _tournament_

#include "student.h"
#include <math.h>


int * get_criteria ();

/** Funcoes de ordenacao **/
void tournament_sort (_student ** list, int n_students);

/**
   Compara os dois valores dados.
   Retorna o maior entre os dois.
   Atualiza a variável crit de acordo com o critério utilizado
   para realizar a comparacao.
   Parametros:
   _student * s1, s2 : valores a serem comparados.
   boolean with_criteria: Flag utilizada para alterar o valor da variavel global
   *criteria* . 
 **/
_student * compare (_student * s1, _student * s2, boolean with_criteria);

/**
   Imprime o estudante e o criterio de desempate.
 **/
void print_student(_student *student, int index, int * crit, int n_students);

#endif
