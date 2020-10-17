/*
Faça a implementação da função realloc, você
deve utilizar a função malloc para isso

void *realloc(void *pont, size_t newSize);

Dica: void * memcpy ( void * destination, const void * source, size_t num );
*/

#include<stdio.h>
#include<stdlib.h>

int cria(int m, int n){

    int **mat;

    mat = (int **)malloc(m*sizeof(int *));

    
    mat = (int *)malloc(n*sizeof(int));
    

    return mat;
}

void imprime(int m,int n,int **mat){

    int i,j;

    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            printf("%d\t",mat[i][j]);
        }
        printf("\n");
    }
}

void liberamem(int n,int **mat){

    int i;
    
    for(i=0;i<n;i++){
        free(mat[i]);    
    }
    free(mat);
}

int main(){

    int m,n,**pt,i,j;

    printf("linha: ");
    scanf("%d", &m);
    printf("coluna: ");
    scanf("%d", &n);

    pt = (int **)cria(m,n);

    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            pt[i][j]=rand()%100;
        }
    }

    imprime(m,n,pt);

    liberamem(n,pt);

    return 0;
}