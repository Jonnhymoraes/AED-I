#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define VERDADEIRO 1
#define FALSE 0
typedef int BOOL;

typedef struct teste {

	char *palavra;
	struct teste *next;
} Teste;

Teste *start = NULL;

// cria um novo elemento de lista do tipo Teste a partir da string de texto fornecida
Teste *NovoElemento(char *text){

        Teste *novo_ponteiro;

        novo_ponteiro = (Teste *) malloc (sizeof(Teste));
        novo_ponteiro -> palavra = (char *)malloc(strlen(text) + 1);
        strcpy(novo_ponteiro -> palavra, text);
        novo_ponteiro -> next = NULL;
        return novo_ponteiro;
}  

// Insere um novo elemento em uma lista com link único
// Nota - entradas duplicadas não são verificadas
void InsereLista(Teste **inicio, Teste *novo_ponteiro){

	Teste **rastreador = inicio;

	while((*rastreador) && 
		  strcmp((*rastreador)->palavra, novo_ponteiro -> palavra) < 1){
		rastreador = &(*rastreador)->next;
	}

	novo_ponteiro -> next = *rastreador;
	*rastreador = novo_ponteiro;
}

// Exclui o primeiro elemento da lista cujo campo do item corresponde ao texto fornecido
// NOTA!! solicitações de exclusão de elementos que não estão na lista são silenciosamente ignoradas :-)
void RemoveLista(Teste **inicio, char *text){

	BOOL present = FALSE;
	Teste *old;
	Teste **rastreador = inicio;
	
	while((*rastreador) && !(present = (strcmp(text,(*rastreador)->palavra) == 0 )  ))
		rastreador = &(*rastreador)->next;

	if(present){
		old = *rastreador;
		*rastreador = (*rastreador)->next;
		free(old -> palavra); 	 // liberar espaço usado pela string de texto
		free(old); 				// libera o restante do elemento da lista
	}
}

void ImprimirLista(Teste **inicio){

	Teste **rastreador = inicio;
	while (*rastreador) {
		printf("%s \n",(*rastreador)->palavra);
		rastreador = &(*rastreador)->next;
	}
}

int main(int argc, char **argv){

        InsereLista(&start, NovoElemento("chips"));
        InsereLista(&start, NovoElemento("wine"));
        InsereLista(&start, NovoElemento("burgers"));
        InsereLista(&start, NovoElemento("beer"));
        InsereLista(&start, NovoElemento("pizza"));
        InsereLista(&start, NovoElemento("zucchini"));
        InsereLista(&start, NovoElemento("burgers"));
        InsereLista(&start, NovoElemento("slaw"));
        printf("\Lista Inicial\n");
        ImprimirLista (&start);
        RemoveLista(&start, "pizza");
        RemoveLista(&start, "zucchini");
        RemoveLista(&start, "burgers");
        printf("\nLista Alterada\n");
        ImprimirLista(&start);              
}