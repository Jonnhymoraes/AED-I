/*
Faça a implementação da função realloc, você
deve utilizar a função malloc para isso

void *realloc(void *pont, size_t newSize);

Dica: void * memcpy ( void * destination, const void * source, size_t num );
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

   char *frase;
   int tamanho;

      frase = (char*) malloc (50*sizeof(char));       //alocando memoria para a frase
   
      if(frase==NULL){
         printf("Impossivel alocar!");
         exit(1);
   }

      printf("\nDigite uma frase: ");
      scanf("%[^\n]", frase);

      tamanho = strlen(frase);
      printf("\nTamanho da frase: %d\n", tamanho);

      memcpy(frase, frase, tamanho);

      printf("\nFrase realocada para tamanho ideal!");

   free(frase);
return 0;
}