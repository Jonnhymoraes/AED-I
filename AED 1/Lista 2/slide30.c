/*
Implementar em C um programa que utilize uma matriz com vetor de ponteiros e que ofereça as seguintes opções para o usuário:
1) Criar e redimencionar uma matriz m x n, onde n e m são fornecidos pelo usuário;
2) Realizar a leitura dos elementos da matriz;
3) Fornecer a soma dos elementos da matriz;
4) Retornar em um vetor (utilizando ponteiros) os elementos de uma determinada coluna da matriz;
5) Imprimir a matriz
6) Sair do programa

Observações:

1) A matriz deve ser alocada dinamicamente no programa por meio do uso da função malloc.
2) O programa deve ser modularizado e utilizar os seguintes protótipos de subalgoritmos:

a. int ** criaMatriz(int m, int n)
b. void leiaMatriz(int **mat, int m, int n)
c. int somaMatriz(int **mat, int m, int n) }
d. int* colunaMatriz(int ** mat, int m, int n, int ncoluna)
e. void liberaMatriz(int **mat, int ncoluna)
f. void imprimeMatriz(int **mat, int m, int n)
g. void imprimeVetor (int *vet, int n) { }

3) O subalgoritmo int* colunaMatriz(int ** mat, int m, int n, int ncoluna) deve criar um novo vetor (ponteiro para
vetor) e retornar o mesmo para o programa principal que será responsável pela impressão dos valores a partir
da chamada de void imprimeVet (int *vet, int n) { }
*/

#include <stdio.h>
#include <stdlib.h>

int** criaMatriz(int m, int n);
void leiaMatriz(int **mat, int m, int n);
int somaMatriz(int **mat, int m, int n);
int* colunaMatriz(int ** mat, int m, int ncoluna);
void liberaMatriz(int **mat, int ncoluna);
void liberaVetor(int *vet);
void imprimeMatriz(int **mat, int m, int n);
void imprimeVetor (int *vet, int n);
int menu();

int main(){

    int m,n,**mat,escolha=0,ncoluna=0,*vet;

    printf(">>>>>>> Crie uma matriz <<<<<<< \n");

    for (;;) {
        escolha = menu();
        switch (escolha) {
            case 1:
                printf("Digite o numero de linhas da matriz: ");
                scanf("%d", &m);
                printf("Digite o numero de colunas da matriz: ");
                scanf("%d", &n);
                mat = criaMatriz(m,n);
                break;
            case 2:
                leiaMatriz(mat,m,n);
                break;
            case 3:
                somaMatriz(mat,m,n);
                break;
            case 4:
                printf("\n\tInforme o numero da coluna que deseja imprimir: ");
                scanf("%d", &ncoluna);
                vet = colunaMatriz(mat,m,ncoluna);
                imprimeVetor(vet, n);
                break;
            case 5:
                imprimeMatriz(mat, m,n);
                break;
            case 6:
                liberaMatriz(mat,m);
                liberaVetor(vet);
                exit(1);
        }
    }
}

int menu(){
    int c = 0;
    do {
        printf("\n\t\t----- ESCOLHA UMA OPCAO -----\n\n\t");
        printf("\n\t\t 1 - Criar ou Redimensionar Matriz\n\t");
        printf("\t 2 - Realizar a leitura dos elementos da Matriz\n\t");
        printf("\t 3 - Soma dos elementos da Matriz\n\t");
        printf("\t 4 - Retornar em um vetor os elementos de uma determinada coluna da Matriz\n\t");
        printf("\t 5 - Imprimir Matriz\n\t");
        printf("\t 6 - Sair\n\t");
        printf("\tDigite a opcao que deseja: ");
        scanf("%d", &c);
    } while (c <= 0 || c > 6);
    return c;
}

int** criaMatriz(int m, int n){

    int **mat,i;

    mat = (int  **) malloc(m * sizeof(int *));
    for(i = 0; i < m; i++){
        mat[i] = (int *) malloc(n * sizeof(int));
    }

    printf("\n\tMatriz criada!!\n");

    return mat;
}

void leiaMatriz(int **mat, int m, int n){

    int i,j;

    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            mat[i][j] = rand()%100;
        }
    }
}

int somaMatriz(int **mat, int m, int n){
    int i,j,soma=0;

    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            soma = soma + mat[i][j];
        }
    }
    printf("\n Matriz \n\n");
    imprimeMatriz(mat,m,n);
    printf("\n\nA soma dos valores: %d\n", soma);

    return soma;
}

int* colunaMatriz(int ** mat, int m, int ncoluna){

    int *vet, i;

    vet = (int*) malloc (m * sizeof(int));
    if(vet==NULL){
        printf("MEMORIA INSUFICIENTE\n");
        exit(1);
    }
    for(i=0; i<m; i++){
        vet[i] = mat[i][ncoluna];
    }

    return vet;
}

void liberaMatriz(int **mat, int ncoluna){

    if (*mat != NULL){
        for(int i=0;i<ncoluna;i++){
            free(mat[i]);
        }
        free(mat);
        printf("Matriz liberada da memoria!\n");
    }

}

void liberaVetor(int *vet){
    if (*vet){
        free(vet);
        printf("Vetor liberado da memoria!\n");
    }
}

void imprimeMatriz(int **mat, int m, int n){

    int i,j;

    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
}

void imprimeVetor (int *vet, int n){

    int i;
    for(i = 0; i < n; i++)
        printf("Linha[%d]: %d\n", i, vet[i]);

}