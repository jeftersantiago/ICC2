#ifndef _student_tad_
#define _student_tad_

#include "util.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct STUDENT _student;


_student * new_student(const int n_grades, char * line);

char * get_name(_student * student);

float get_grade(_student *student, int grade_number);
double get_mean(_student *student);
int get_amount_grades(_student *student);

void remove_student(_student *student);

#endif    
