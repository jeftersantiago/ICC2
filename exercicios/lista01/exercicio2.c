/* Cálcula n-ésimo termo da sequência de Fibonacci
   de forma recursiva. */
#include<stdio.h>
/* Fibonacci recursivo
   Fn = Fn-1 + Fn+2
 */
int fib(int n){
    if(n <= 1) return n;
    return fib(n-1) + fib(n-2);
}
int main(){
    int x;
    scanf("%d", &x);
    printf("%d\n", fib(x));
    return 0;
}
