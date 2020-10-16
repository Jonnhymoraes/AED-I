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
int* colunaMatriz(int ** mat, int m, int n, int ncoluna);
void liberaMatriz(int **mat, int ncoluna);
void imprimeMatriz(int **mat, int m, int n);
void imprimeVetor (int *vet, int n);

int main(){
	
	int m,n,**pt,i,j;

    printf("linha: ");
    scanf("%d", &m);
    printf("coluna: ");
    scanf("%d", &n);

    pt = (int **)criaMatriz(m,n);

    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            pt[i][j]=rand()%100;
			
        }
    }
	imprimeMatriz(pt,m,n);
	liberaMatriz(pt,n);

return 0;
}


int** criaMatriz(int m, int n){

	  int **mat;

    mat = (int **)malloc(m*sizeof(int *));
	mat = (int *)malloc(n*sizeof(int));
    
	printf("Matriz criada!!\n");

    return mat;
}

void leiaMatriz(int **mat, int m, int n){

}

int somaMatriz(int **mat, int m, int n){

}

 int* colunaMatriz(int ** mat, int m, int n, int ncoluna){

 }

void liberaMatriz(int **mat, int ncoluna){

	int i;
    
    for(i=0;i<ncoluna;i++){
        free(mat[i]);    
    }
    free(mat);
	printf("Matriz liberada!\n");
}

void imprimeMatriz(int **mat, int m, int n){

   int i,j;

    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            printf("%d\t",mat[i][j]);
        }
        printf("\n");
    }
}

void imprimeVetor (int *vet, int n){

	int i;
    for(i=0;i<n;i++)
        printf("vet[%d]=%d\n",i,vet[i]);
    
}
