#include "student.h"

static float mean(int *grades, int n);

struct STUDENT {
  char * name;
  int * grades; 
  int n_grades;
  double mean;
};

_student * new_student(const int n_grades, char * line) {

  _student * student = (_student *) malloc(sizeof(_student));

  char * name = strsep(&line, " ");
  size_t length = strlen(name);

  student->name = (char *) malloc(sizeof(char *) * (int) length);
  strcpy(student->name, name);


  int * grades = (int *) malloc(sizeof(int) * n_grades); 

  for(int i = 0; i < n_grades; i++){
    int j = atoi(strsep(&line, " "));
    grades[i] = j;
  }

  student->n_grades = n_grades;
  student->grades = grades;

  //  print_vector(student->grades, 0, n_grades);

  student->mean = mean(student->grades, student->n_grades);

  //  printf("média = %.3f\n", student->mean);

  return student;
}

_student ** new_list_students(int n_amount){
  return (_student **) malloc(sizeof(_student*) * n_amount);
}

char * get_name(_student * student) {
  if(student == NULL) return "NULL";
  char *name = student->name;
  return name;
}

float get_grade(_student *student, int grade_number){
  if(grade_number > student->n_grades){
    printf("Nota inválida.\n");
    return -1;
  }
  return student->grades[grade_number];
}

int get_amount_grades(_student *student) {
  return student->n_grades;
}

float get_mean(_student *student) {
  return student->mean;
}

static float mean(int *grades, int n){
  float mean = 0;
  for(int i = 0; i < n; i++)
    mean += grades[i];
  return mean/n;
}

void remove_student(_student *student) {
  free(student->name);
  free(student->grades);
  free(student);
}

/**
   Retorna true se s1 > s2 dado todas as comparacoes necessarias.
 **/
boolean is_greater (_student * s1, _student * s2) {

  
  /**  Trata os casos de alguma das váriaveis ser NULL.   **/
  if(s1 == NULL && s2 == NULL)
    return false;
  if(s1 != NULL && s2 == NULL)
    return true;
  if(s1 == NULL && s2 != NULL)
    return false;

  printf("Nome (Estudante 1) = %s\n", get_name(s1));
  printf("Media (Estudante 1) = %.3f\n", get_mean(s1));

  printf("Nome (Estudante 2) = %s\n", get_name(s2));
  printf("Media (Estudante 2) = %.3f\n", get_mean(s2));

  if(s1->mean > s2->mean){
    printf("Media\n");
    return true;
  }
  else if (s1->mean < s2->mean){
    printf("Media\n");
    return false;
  }
  for(int i = 0; i < s1->n_grades; i++){
    if(s1->grades[i] > s2->grades[i]){
      printf("- desempate: nota %d\n", i);
      return true;
    }
    else if (s1->grades[i] < s2->grades[i]) {
      printf("Criterio = %d\n", i);
      return false;
    }
  }
  return false;
}


