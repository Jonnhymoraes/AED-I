/*
Com base nos trechos de código acima, fale qual será o resultado e explique.
*/

#include <stdio.h>

// Trecho 1
int main(){

    int mat[2][2] = {{1,2},{3,4}};                //criou uma matriz com 4 elementos
    int i,j;

    for (i=0;i<2;i++)                            //percorre as linhas e colunas da matriz
        for (j=0;j<2;j++)
        printf("%d\n",mat[i][j]);               //imprimi na tela
    
    system("pause");
}
// Trecho 2
// int main(){

//     int mat[2][2] = {{1,2},{3,4}};          //criou uma matriz com 4 elementos
//     int *p = &mat[0][0];                    //criou um ponteiro que recebeu a posição de memoria da matriz anterior
//     int i;

//     for (i=0;i<4;i++)                       //percorre o tamanho da matriz
//     printf("%d\n",*(p+i));                  //printa o valor através da aritmetca de ponteiros
// system("pause");
// }