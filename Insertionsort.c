#include <stdio.h>
#include <stdlib.h>

void Insertionsort (int data[], int n);
void imprimir(int vet[], int n);
void inserir(int vet[], int n);

int main(){

    int n;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);
    
    int vet[n];

    inserir(vet, n);
    Insertionsort(vet, n);
    printf("\nVetor ordenado\n"); 
    imprimir(vet, n);



return 0;
}

void inserir(int vet[], int n){
    int i;

    for( i = 0; i < n; i++){
        vet[i] = rand()%100;   
    }
    printf("\nVetor antes de ordenar\n");
    imprimir(vet, n);

}

void imprimir(int vet[], int n){
    int i;

    for( i = 0; i < n; i++){
        printf("%d ", vet[i]); 
    }
}

void Insertionsort (int data[], int n) {

    int tmp,i,j;
    
    for (j=1; j<n; j++){
        i =j - 1;                             // i recebe 0
        tmp = data[j];                        // variavel temporaria recebe o vetor
    while ( (i>=0) && (tmp < data[i]) ){      // realiza a comparação de tds os numeros do vetor inicial
        data[i+1] = data[i];
        i--;
    }//while
    data[i+1] = tmp;
    }
}