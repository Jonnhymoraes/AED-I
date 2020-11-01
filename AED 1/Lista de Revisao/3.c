/*
Qual é o valor das seguintes expressões ?
a) p = &i
b) *p - *q
c) **&p
d) 3* - *p/(*q)+7
*/

#include <stdio.h>

int main(){

    int i=3,j=5;
    int *p, *q;
    float res;
    
    p = &i;
    q = &j;

    printf ("Resultado: %f", res);

return 0;
}
