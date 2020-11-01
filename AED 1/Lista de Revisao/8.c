/*
Faça um programa que leia uma string (de 80 caracteres) chamada linha
e, com uma função, identifique cada palavra (substring) desta linha
copiando-a para um novo vetor. Ao final, o programa deve imprimir as
palavras separadas, uma palavra por linha.
Dicas: i) faça uma função para identificar o fim e/ou o início de cada substring em linha
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void substring (char *frase);

int main(){

    char *linha;
    
    linha = (char*) malloc (50*sizeof(char));
    
    printf("Digite uma frase: ");
    scanf("%[^\n]", linha);
    printf("\nFrase completa: %s\n", linha);

    substring (linha);
    free (linha);
    return 0;
}

void substring (char *frase){
    
    char *frase2;
    
    frase2 = strtok (frase, " ,.-!?"); //frase2 retorna NULL no ponteiro onde tem os caracteres
    while (frase2 != NULL) {
        printf ("\n%s\n", frase2);
        frase2 = strtok (NULL, " ,.-!?");
    }
}