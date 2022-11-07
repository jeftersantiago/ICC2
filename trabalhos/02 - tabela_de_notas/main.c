/**
   Jefter Santiago Mares
   nºUSP: 12559016
 **/

#include "tournament.h"

char *readLine();

int main () {

  char * n =   readLine();

  int n_students = atoi(strsep(&n, " "));
  int n_grades = atoi(n);


  /**
     printf("# students = %d\n", n_students);
     printf("# grades = %d\n", n_grades);
  **/

  _student **student_list = (_student **) malloc(sizeof(_student *) * n_students);

  int i = 0;

  while(i < n_students) {

    n = readLine();

    _student *student  = new_student(n_grades , n);

    student_list[i] = student; 

    free(n);
    n = NULL;
    i++;

  }

  tournament_sort(student_list, n_students);

  for(int i = 0; i < n_students; i++){
    remove_student(student_list[i]);
  }
  free(student_list);

  return 0;
}


char *readLine() {
    char *string = NULL;
    char currentInput;
    int index = 0;
    do {

      currentInput = (char) getchar();
      string = (char *) realloc(string, sizeof(char) * (index + 1));
      string[index] = currentInput;
      index++;
        
      if(currentInput == '\r')
        currentInput = (char)getchar();
      
    } while((currentInput != '\n') && (currentInput != EOF));
    string[index - 1] = '\0';
    return string;
}
