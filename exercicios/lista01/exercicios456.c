#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int main(){
    srand(time(NULL));
    int num = rand() % 100;
    printf("%d\n", num);

    int *vetorHeap = malloc(num * sizeof(int));
    int randNum;
    /*
      Exercicio 4
    */
    printf("\n\nExercicio 4\n\n");
    for(int i = 0; i < num; i++){
        randNum = rand() % 10;
        *(vetorHeap+i) = randNum * i;
        int val = *(vetorHeap+i);
        if(val % 3 != 0 && val % 5 != 0 && val % 7 != 0)
            printf("%d -> Não é divisível por 3, 5 e 7\n", val);
    }

    printf("Elementos do vetor heap.\n");
    for(int i = 0; i < num; i++){
        printf("%d\n", *(vetorHeap+i));
    }
    free(vetorHeap);

    /*
      Exercicio 5
     */
    printf("\n\nExercicio 5\n\n");
    int *vector1 = malloc(num * sizeof(int));
    int *vector2 = malloc(num * sizeof(int));
    int rand1, rand2;

    for(int i = 0; i < num; i++){
        rand1 = rand() % 10;
        rand2 = rand() % 10;
        *(vector1+i) = rand1 * i;
        *(vector2+i) = rand2 * i;

        printf("%d + %d = %d\n", *(vector1+i), *(vector2+i), *(vector1+i)+*(vector2+i));
    }
    free(vector1);
    free(vector2);

    /*
      Exercicio 6
    */
    int *vector = malloc(num * sizeof(int));
    for(int i = 0; i < num; i++){
        *(vector + i) = rand() % 10 * i;
        printf("%d\n", *(vector+i));
    }
    int input;
    printf("Informe um número inteiro\n");
    scanf("%d", &input);

    for(int i = 0; i < num; i++){
        if(*(vector+i) == input)
            printf("O valor %d existe na sequência gerada.\n", input);
    }
    return 0;
}
