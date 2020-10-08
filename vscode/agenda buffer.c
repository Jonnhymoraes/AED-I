#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct agenda{
	char nome[20];
//	int idade;
}agenda;

void insere(agenda *pAtual);
void imprime(agenda *pAtual);
void busca (char *nomeAux, agenda *pAtual, agenda *pInicio, int *qt, int *x);

int main(){

	void *pBuffer;
	int *qt, *opcao, *x;
	char *nomeAux;
	agenda *pInicio;
	agenda *pAtual;

	pBuffer=malloc(sizeof(int)*3 + sizeof(char)*20);
	qt=(int *)pBuffer;
	*qt=0;
	opcao=(int *)(qt+sizeof(int));
	x=(int *)(opcao+sizeof(int));
	*x=0;
	nomeAux=(char *)(x+sizeof(int));

	printf("\t\t***** AGENDA *****\n\n\t 1 - Inserir nome\n\t 2 - Listar nomes\n\t 3 - Buscar nome\n\t 0 - Sair\n");

	do{
		printf("\nDigite a Opcao: \n");
		scanf("%d", opcao);

		if(*opcao==1){
			*qt=(*qt+1);
			pBuffer = realloc(pBuffer, (sizeof(int)*3) + (sizeof(int)*20) + (sizeof(agenda) * (*qt)));
			qt=(int *)pBuffer;
			opcao=(int *)(qt+sizeof(int));
			x=(int *)(opcao+sizeof(int));
			*x=0;
			nomeAux=(char *)(x+(sizeof(int)*3));
			pInicio=(agenda *)(nomeAux+(sizeof(char)*20));
			pAtual=(pInicio)+(sizeof(agenda)* ((*qt)-1));

			insere(pAtual);
		}
		if(*opcao==2){
			pAtual=pInicio;
			for(*x=0;*x<*qt;(*x)++){
				imprime(pAtual);
				pAtual=pAtual+sizeof(agenda);
			}
		}
		if(*opcao==3){
			pInicio=(agenda *)((sizeof(int)*3)+(sizeof(char)*20)+(sizeof(agenda)*(*qt)));
			printf("Digite o nome que deseja buscar:\n");
			scanf("%s", nomeAux);
			busca(nomeAux, pAtual, pInicio, qt, x);
		}
	}while(*opcao!=0);

	free(pBuffer);

return 0;
}

void insere(agenda *pAtual){
	printf("Insira o nome: ");
	scanf("%s", (*pAtual).nome);
//	printf("Insira a idade: ");
//	scanf("%d", &(*pAtual).idade);
}

void imprime(agenda *pAtual){
	printf("\nNome: %s\n", pAtual->nome);
//	printf("Idade: %d\n", pAtual->idade);
	printf("\n******************\n");
}

void busca(char *nomeAux, agenda *pAtual, agenda *pInicio, int *qt, int *x){
	pAtual = pInicio;
	
	for(*x=0;*x<*qt;(*x)++){
		if(strcmp(pAtual->nome, nomeAux)==0){
			printf("Encontrado!\n");
			printf("Nome: %s\n", pAtual->nome);
//			printf("Idade: %d\n", pAtual->idade);
			break;
		}
		pAtual=pAtual+(sizeof(char)*20);
	}
	printf("Fim da Busca!\n");
}

