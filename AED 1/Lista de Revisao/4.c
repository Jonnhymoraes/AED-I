/*
Qual será a saída deste programa supondo que “i” ocupa o endereço 1000 na memória? 
*/

#include <stdio.h>

int main(){
    int i = 5, *p;
    
    p = &i;
    printf("%p %d %d %d %d \n", p, *p+2, **&p, 3**p, **&p+4);

return 0;
}
