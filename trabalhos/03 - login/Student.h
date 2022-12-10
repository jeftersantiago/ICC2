#ifndef _student_
#define _student_

#include "Util.h"

typedef struct STUDENT Student;

Student * newStudent (char * line);

void deleteStudent (Student * student);

char * getNUSP (Student * student);
uint32_t getPassword (Student * student);

void login (char * c);

void printGrades (Student ** student);

#endif
