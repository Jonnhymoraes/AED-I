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

int** criaMatriz(int n, int m){

	int **mat;

	mat = (int **) malloc( m * sizeof(int*));

	for (int i = 0; i < m; ++i)
	{
		mat[i] = (int*) malloc( n * sizeof(int));
	}

	printf("Matriz criada!\n");
	return mat;

}

void liberaMatriz(int **mat,int m){

	for (int i = 0; i < m; ++i)
	{
		free(mat[i]);
	}

	free(mat);
	printf("Matriz liberada!\n");
}

int main(int argc, char const *argv[])
{
	int m=2, n=2;
	int **ptr;

	ptr = criaMatriz(m,n);
	liberaMatriz(ptr,m);


	return 0;
}