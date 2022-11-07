/**
   Jefter Santiago Mares
   nºUSP: 12559016
 **/

#include "tournament.h"

char *readLine();

int main () {


  int n_students;
  int n_grades;
  scanf("%d %d\n", &n_students, &n_grades);

  _student **student_list = (_student **) malloc(sizeof(_student *) * n_students);

  int i = 0;

  char * c; 
  while(i < n_students) {

    c = readLine();

    _student *student  = new_student(n_grades , c);

    free(c);
    c = NULL;
    
    student_list[i] = student; 
    
    i++;
  }

  tournament_sort(student_list, n_students);

  printf("[OUTPUT]\n");
  /**
  for(int i = 0; i < n_students; i++){
    printf("%d. %s\n", i+1, get_name(student_list[i]));
  }
  **/

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
    currentInput = (char)getchar();
    string = (char *) realloc(string, sizeof(char) * (index + 1));
    string[index] = currentInput;
    index++;
    if(currentInput == '\r')
      currentInput = (char)getchar();
  } while((currentInput != '\n') && (currentInput != EOF));
  string[index - 1] = '\0';
  return string;
}
