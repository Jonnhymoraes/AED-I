/*
Dado o código à esquerda, preencha a tabela à direita com todas as mudanças de valor das variáveis até o final da execução do
programa. Para representar o endereço de uma variável, utilize o símbolo & seguido do nome da variável. Ex.: &t (endereço da
variável t).
*/

#include <stdio.h>

void main() {
    int t, j = 1, *p, *g;
    t = 5;
    p = &t;
    j = 3;
    g = &j;

    *p = (*g + t) * 2;
    *g = 4;
     
    g = p;
    
    for(j = 0; j < 2;j++) {
        *g = t*j + 1;
    }
    
    *p = t + j + *g;

}