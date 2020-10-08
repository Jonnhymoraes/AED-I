#include <stdio.h>
int main(){

    int n;

    printf("Digite um numero: ");
    scanf("%d", &n);

    if(n%2==0)
        printf("O numero eh par");
    else
        printf("O numero eh impar");

return 0;
}