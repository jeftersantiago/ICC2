#include<stdio.h>
#include<stdlib.h>

int main(int argc, char* argv[]) {

    int size_word = atoi(argv[1]);
    char* word = argv[2];
    
//    reverse_iterative(word, size_word);
    reverse_recursive(word, size_word, 0);
    return 0;
}
/* Função recursiva  */
void reverse_recursive(char* word, int size_word, int index){
    if(size_word == index){
        printf("\n");
        return;
    }
    char aux = word[index];
    reverse_recursive(word, size_word, index + 1);
    printf("%c", aux);
}
void reverse_iterative(char* word, int size_word){
//    Reverte a palavra iterativamente.
    char reverse_word[size_word];
    for(int i = size_word - 1; i >= 0 ; i--){
        reverse_word[size_word-i-1] = word[i];
    }
    printf("%s\n", reverse_word);
}
