/*
 Suponha as declarações: int mat[4], *p, x; Quais expressões são válidas? Justifique:
 a) p= mat + 1 = Resultado: 6422288
 b) p= mat++ = Resultado: ERROR, forma errada de incrementar uma matriz
 c) p= ++mat = Resultado: ERROR, forma errada de incrementar uma matriz
 d) x=(*mat)++ = Resultado: 4200816

*/

#include <stdio.h>

int main(){

    int mat[4], *p, x;

    x=(*mat)++; 

    printf("Resultado: %d", x);

return 0;
}