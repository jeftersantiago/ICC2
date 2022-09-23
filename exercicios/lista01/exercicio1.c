//  Verifica seu um número é primo utilizando recursão.
#include<stdio.h>
#define true 1
#define false 0

int is_prime(int n, int i){
    if(n <= 2 || i == 1) return true;
//    if(i == 1) return true;
    if(n % i == 0) return false;
    return is_prime(n, i - 1);
}
int main(){
    int x;
    scanf("%d", &x);
    // Starts from 2.
    int y = is_prime(x, 2);
    if(y == false)
        printf("Is not prime.\n");
    else
        printf("Is prime.\n");
    return 0;
}
