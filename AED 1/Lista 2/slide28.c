/*
Faça um programa que armazene a informação de várias
pessoas.
• O programa só deve sair quando o usuário disser que não
deseja mais entrar com os dados de outra pessoa.
• Antes de sair o programa deve apresentar, de forma
organizada, os dados de todas as pessoas.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pessoa {
	char nome[30];
	int idade;
	int altura;
	struct pessoa *proximo;
} Pessoa;

Pessoa* insere(Pessoa *inicio);
void imprime(Pessoa *inicio);
int menu();

int main(){

	int escolha;
	Pessoa *inicio;
	
	inicio = (Pessoa *) malloc(sizeof (Pessoa));  //alocando memoria para todos os campos da agenda
	inicio -> proximo = NULL;		

	for (;;) {
		escolha = menu();
		switch (escolha) {
		case 1:
			insere(inicio);
			break;
		case 2:
			imprime(inicio);
			printf("\nFIM DA LISTA!! \n");
			exit(0);
			break;
		default:
		free(inicio);
		exit(1);
		}
	}
	return 0;
}

int menu(){
	int c = 0;
	do {
		printf("\t\t-----CADASTRO DE PESSOAS-----\n\n\t 1 - Adicionar nomes\n\t 2 - Parar de adicionar nomes \n\n\t");
        printf("Digite a opcao que deseja: ");
		scanf("%d", &c);
	} while (c <= 0 || c > 2);
	return c;
}

Pessoa* insere(Pessoa *inicio){
	    
		if(inicio != NULL){									//verifica se há espaço disponivel
        Pessoa *novo, *aux;								
        aux = inicio;										//ponteiro auxiliar recebe os campos do cadastro
        novo = (Pessoa *) malloc(sizeof(Pessoa));			// ponteiro novo aloca memoria para novas informações
        if(novo != NULL){
            printf("Insira o nome da pessoa: ");
            scanf("%s", &novo->nome);
            printf("Insira a idade: ");
            scanf("%d", &novo->idade);
            printf("Insira a altura (em cm): ");
            scanf("%d", &novo->altura);
            novo-> proximo = NULL;

            while(aux->proximo != NULL)
                aux = aux -> proximo;						// auxiliar vai apontar para a proxima posição
           		aux -> proximo = novo;						// a proxima posição vão estar os novos dados do cadastro
        }
		else
            printf("Impossiver armazenar! ");
    	}
		else
        printf("Impossivel armazenar");

return NULL;
}

void imprime(Pessoa *inicio){
	Pessoa *info;													
	
	info = inicio;

	if(info -> proximo != NULL){						//verifica se a agenda não ta vazia
		info = info -> proximo;
		while(info != NULL){			
		printf("\nNome: %s\n", info -> nome);							
        printf("Idade: %d\n", info -> idade);
        printf("Altura: %d\n", info -> altura);
		printf("############################\n");
		info = info -> proximo;						//percorre todo o cadastro de contatos
		}
	}
	else
		printf("Agenda vazia!!");
}