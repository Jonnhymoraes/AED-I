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

Pessoa *cria_lista(void);
Pessoa* insere(Pessoa *inicio);
void imprime(Pessoa *inicio);
int menu(void);

int posicao = 0;

int main(){
	int escolha;
	
	Pessoa *inicio;
	
	inicio = cria_lista();

	cria_lista();
	for (;;) {
		escolha = menu();
		switch (escolha) {
		case 1:
			insere(inicio);
			break;
		case 2:
			imprime(inicio);
			printf("******** FIM DA LISTA *********\n");
			exit(0);
			break;
		}
	}
	return 0;
}

Pessoa *cria_lista(void){
	Pessoa *iniciar;
	
	iniciar = (Pessoa *) malloc(sizeof (Pessoa));  //alocando memoria para todos os campos da agenda
	iniciar -> proximo = NULL;							//ponteiro apontando para a próxima posição (Null)
return iniciar;
}

int menu(void){
	int c = 0;
	do {
		printf("\t\t-----CADASTRO DE PESSOAS-----\n\n\t 1 - Adicionar nomes\n\t 2 - Parar de adicionar nomes \n\n\t");
        printf("Digite a opcao que deseja: ");
		scanf("%d", &c);
	} while (c <= 0 || c > 2);
	return c;
}

Pessoa* insere(Pessoa *inicio){
	Pessoa *info;
	
	info = (Pessoa *) malloc(sizeof(Pessoa));
	posicao++;
	
	if (info == NULL){
		printf("\nNao foi possivel alocar!!");
		exit(1);
	}
										
		
	printf("Insira o nome: ");
	scanf("%s", info -> nome);
    printf("Insira a idade: ");
    scanf("%d", info -> nome);
    printf("Insira a altura: ");
    scanf("%d", info -> nome);
	
	info->proximo=inicio->proximo;
	inicio->proximo = info;
	return inicio;
}

void imprime(Pessoa *inicio){
	Pessoa *info;													
	
	for(info = inicio -> proximo; info != NULL; info = info -> proximo){			
		printf("\nNome: %s\n", info -> nome);							
        printf("\nIdade: %d\n", info -> idade);
        printf("\nAltura: %d\n", info -> altura);
		}
}