#include "Student.h"
#include "HashTable.h"

#define n_grades 4

struct STUDENT {
  uint32_t nUSP;
  uint32_t password;
  double * grades;
};

Student * newStudent(char * line){
  char * tmp_str = line;

  Student * student = malloc(sizeof(Student));

  student->nUSP = hashing(strsep(&line, " "));
  student->password = hashing(strsep(&line, " "));

  double * grades = (double *) malloc(sizeof(double *) * n_grades);

  for(int i = 0; i < n_grades; i++){
    char * tmp = strsep(&line, " ");
    double j = atof(tmp);
    grades[i] = j;
  }
  student->grades = grades;

  free(tmp_str);
  tmp_str = NULL;
  return student;
}

uint32_t getNUSP (Student * student) { return student->nUSP; }
uint32_t getPassword (Student * student) { return student->password; }

void deleteStudent (Student * student) {
  free(student->grades);
  free(student);
}

void printStudent (Student * student) {
  printf("Notas: P1=%.1lf, P2=%.1lf, T1=%.1lf, T2=%.1lf",
         student->grades[0], student->grades[1],
         student->grades[2], student->grades[3]);
  printf("\n");
}
