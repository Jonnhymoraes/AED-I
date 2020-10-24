/*
Faça a implementação da função realloc, você
deve utilizar a função malloc para isso

void *realloc(void *pont, size_t newSize);

Dica: void * memcpy ( void * destination, const void * source, size_t num );
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

   char *frase[30];
   int n;

   frase = (char*) malloc (30*sizeof(char));
   
   if(frase==NULL){
        printf("Falta de memoria!");
        exit(1);
   }

   printf("Digite uma frase: ");
   scanf("%s", frase);
   printf("frase informada: %s\n", frase);

   n = strlen(frase);
   printf("Tamanho da frase: %d\n", n);

   memcpy(frase, frase, n);

   printf("frase 'realocada': %s\n", frase);

   free(frase);
   printf("free\n");
}