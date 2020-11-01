#include <stdio.h>

int raiz (int n);

int main(){

    int n = 4;

    // printf("Digite um numero: ");
    // scanf("%d", &n);

    printf("\nResultado: %d", raiz(n));

return 0;    
}

int raiz (int n){

    if (n == 0) 
    return n;
    
    int i,j,k=0;
    
    for(i = 1; i <= n; i++){           
      for(j = 0; j < n; j++){               //condição de parada de i
         k++;
      }
   }

return k;
}

