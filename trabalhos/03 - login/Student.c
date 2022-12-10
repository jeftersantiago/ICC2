#include "Student.h"
#include "HashTable.h"

#define n_grades 4

struct STUDENT {
  char * nUSP;
  uint32_t password;
  double * grades;
};

Student * newStudent(char * line){
  char * tmp_str = line;

  Student * student = malloc(sizeof(Student));

  char * nUSP = strsep(&line, " ");
  size_t length = strlen(nUSP);

  student->nUSP = (char *) malloc(sizeof(char *) * length);
  strcpy(student->nUSP, nUSP);
  
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

char * getNUSP (Student * student) { return student->nUSP; }
uint32_t getPassword (Student * student) { return student->password; }

void deleteStudent (Student * student) {
  free(student->nUSP);
  free(student->grades);
  free(student);
}

void printGrades (Student ** student) {
  if(student != NULL){
    printf("Notas: P1=%.1lf, P2=%.1lf, T1=%.1lf, T2=%.1lf",
           (*student)->grades[0], (*student)->grades[1],
           (*student)->grades[2], (*student)->grades[3]);
    printf("\n");
  }
}
