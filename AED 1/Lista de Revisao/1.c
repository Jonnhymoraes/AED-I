/*
Assinale a alternativa que apresenta, corretamente, o que esse trecho de código fará ao
ser executado.
a) Mostrará na tela os valores de 0 a 9.
b) Mostrará na tela os valores de 1 a 10.
c) Escreverá na tela myCount por 10 vezes.
d) Escreverá na tela 0 por 10 vezes.
e) Entrará em looping infinito.
*/

#include <stdio.h>

int main(){
    int myCount = 0;

    while (myCount < 10){
    printf("%d",myCount+1);
    }
return 0;
}

// resposta: e) Entrará em looping infinito.
