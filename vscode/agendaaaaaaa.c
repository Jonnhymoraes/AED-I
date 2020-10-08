#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct agenda{
	char nome[30];
	struct agenda *prox;       // ponteiro apontando para próxima posição
}agenda;

void apagar(agenda *inicio);
void imprime(agenda *inicio);
void insere(agenda *p);
agenda *criar(void);
int menu (void);

int main(){

	int opcao;		
	agenda *lista;

	lista = criar();	//criando a agenda

	for(; ; ){
		opcao = menu();
		switch (opcao){
			case 1:
			insere(lista);
			break;
			case 2:
			imprime(lista);
			break;
			case 3:
			apagar(lista);
			break;
			case 4:
			exit(0);
			break;
		}
	}
return 0;
}

agenda *criar(void){
	agenda *iniciar;
	iniciar = (agenda*) malloc(sizeof (agenda));  //alocando memoria para todos os campos da agenda
	iniciar -> prox = NULL;							//ponteiro apontando para a próxima posição (Null)
return iniciar;
}

int menu (void){
	
	int n = 0;
	do{
		printf("\t\t\n***** AGENDA *****\n\n\t 1 - Inserir nome\n\t 2 - Imprimir nomes\n\t 3 - Apagar nome\n\t 4 - Sair\n");
		printf("\nDigite a opcao que deseja: ");
		scanf("%d", &n);
	} while(n <= 0 || n > 4);
return n;
}

void insere(agenda *p){
	
	agenda *info;								// criando um ponteiro para acessar a agenda
	info = (agenda *) malloc(sizeof(agenda));	// alocando memoria para inserir o nome
	printf("Insira o nome: ");
	scanf("%s", info -> nome);

	info ->prox = p -> prox;			// redefinindo as posições do ponteiro
	p -> prox = info;
}

void imprime(agenda *inicio){

	agenda *p;													// variavel para acessar a agenda
	for(p = inicio -> prox; p != NULL; p = p -> prox){			// p aponta para o inicio da agenda enquanto é diferente de vazia
	printf("\nNome: %s\n", p -> nome);							// imprime todos os nomes da agenda
	printf("\n******************\n");
	}
}	

void apagar(agenda *inicio){
	
	char pessoa[30];							// variavel para coletar o nome que deseja excluir
	agenda *p, *q;								// criando 2 ponteiros

	printf("Nome que deseja excluir: ");
	scanf("%s", pessoa);
	
	p = inicio;									// ponteiro p recebe a informação que está no inicio
	q = inicio -> prox;                         //
	while((q != NULL) && (strcmp (q -> nome, pessoa) != 0)){
		p = q;
		q = q -> prox;
	}
	if (q != NULL){
		p -> prox = q -> prox;
		free(q);
		printf("\t\n Nome Removido!!\n");
	}
	else
		printf("\t\nNome inexistente!!\n");	
}