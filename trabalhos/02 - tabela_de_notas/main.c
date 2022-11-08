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

  /* Lista a ser ordenada */
  _student **list = (_student **) malloc(sizeof(_student *) * n_students);

  int i = 0;

  char * c; 
  while(i < n_students) {

    c = readLine();

    _student *student  = new_student(n_grades , c);

    free(c);
    c = NULL;
    
    list[i] = student; 
    i++;
  }

  tournament_sort(list, n_students);

  /** Imprime os estudantes em ordem e o critério de desempate **/

  printf("Maior media: %.3f\n",get_mean(list[0]));
  for(int i = 0; i < n_students; i++){
    if(i+1 < n_students)
      compare(list[i], list[i+1], true);
    print_student(list[i], i+1, get_criteria(), n_students);
  }

  /*  Libera a memoria utilizada  */
  for(int i = 0; i < n_students; i++){
    remove_student(list[i]);
  }
  free(list);

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
