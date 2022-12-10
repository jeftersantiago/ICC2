/**
   Jefter Santiago Mares
   nºUSP: 12559016
 **/
#include "HashTable.h"
#include "Student.h"


char * readLine();
int main () {

  int n;
  scanf("%d\n", &n);

  HashTable * table = makeHashTable(n);
  Student * student = NULL;
  int i;

  i = 0;
  while(i < n) {
    student = newStudent(readLine());
    if(insertHashTable(table, student))
      printf("Cadastro efetuado com sucesso\n");
    else
      printf("NUSP ja cadastrado\n");
    i++;
  }
  scanf("%d\n", &n);
  i = 0;
  while(i < n){

    Student * student = NULL;
    char * c =  readLine();
    int k = loginHashTable(table, c, &student);
    if(k == 0){
      printGrades(&student);
    }
    else if (k == 2){
      printf("NUSP invalido\n");
    }
    else if (k == 1){
      printf("Senha incorreta para o NUSP digitado\n");
    }
    free(c);
    c = NULL;
    i++;
  }
  deleteHashTable(table);
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
