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
    char * tmp = strsep(&line, " ");
    int j = atoi(tmp);
    grades[i] = j;
  }

  student->n_grades = n_grades;
  student->grades = grades;
  student->mean = mean(student->grades, student->n_grades);

  return student;
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

double get_mean(_student *student) {
  return student->mean;
}

static float mean(int *grades, int n){
  float mean = 0;
  for(int i = 0; i < n; i++) mean += grades[i];
  return mean/n;
}

void remove_student(_student *student) {
  free(student->name);
  free(student->grades);
  free(student);
}
