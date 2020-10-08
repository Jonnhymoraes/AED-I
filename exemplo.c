#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct end {
	char nome[100];
	char rua[100];
	char cidade[100];
	char estado[100];
	unsigned long int cep;
	struct end *prox;
};

typedef struct end end;
void insere(end * p);
void insere_fim(end * p);
void apaga_pelo_nome(end * p);
void imprime(end * p);
void ler_texto(end * p);
void gravar_texto(end * p);
int menu(void);
end *cria_lista(void);
void ler_string(char palavra[100], int tamanho);

int qtde;

int main()
{
	int escolha;
	end *info;

	info = cria_lista();

	for (;;) {
		escolha = menu();
		switch (escolha) {
		case 1:
			insere(info);
			break;
		case 2:
			insere_fim(info);
			break;
		case 3:
			apaga_pelo_nome(info);
			break;
		case 4:
			imprime(info);
			break;
		case 5:
			free(info);
			info = cria_lista();
			ler_texto(info);
			break;
		case 6:
			gravar_texto(info);
			break;
		case 7:
			exit(0);
			break;
		}
	}
	return 0;
}

end *cria_lista(void)
{
	end *start;
	start = (end *) malloc(sizeof(end));
	start->prox = NULL;
	return start;
}

int menu(void)
{
	int c = 0;
	do {
		printf("-- MENU:\n");
		printf("\t 1. Insere\n");
		printf("\t 2. Insere no fim da lista\n");
		printf("\t 3. Exclui pelo nome\n");
		printf("\t 4. Imprime todos\n");
		printf("\t 5. Ler do arquivo texto\n");
		printf("\t 6. Gravar no arquivo texto\n");
		printf("\t 7. Sair\n");
		printf("-- Digite sua escolha: ");
		scanf("%d", &c);
	} while (c <= 0 || c > 7);
	getchar();
	return c;
}

void ler_string(char palavra[100], int tamanho)
{
	int i = 0;
	char c;
	c = getchar();
	while ((c != '\n') && (i < tamanho)) {
		palavra[i++] = c;
		c = getchar();
	}
	palavra[i] = '\0';
	if (c != '\n') {
		c = getchar();
		while ((c != '\n') && (c != EOF)) {
			c = getchar();
		}
	}
}

void insere(end * p)
{
	end *nova;
	nova = (end *) malloc(sizeof(end));

	printf("\t Nome: ");
	ler_string(nova->nome, 100);
	printf("\t Rua: ");
	ler_string(nova->rua, 100);
	printf("\t Cidade: ");
	ler_string(nova->cidade, 100);
	printf("\t Estado: ");
	ler_string(nova->estado, 100);
	printf("\t CEP: ");
	scanf("%lu", &nova->cep);

	nova->prox = p->prox;
	p->prox = nova;

}

void insere_fim(end * p)
{
	end *nova, *fim;
	nova = (end *) malloc(sizeof(end));

	printf("\t Nome: ");
	ler_string(nova->nome, 100);
	printf("\t Rua: ");
	ler_string(nova->rua, 100);
	printf("\t Cidade: ");
	ler_string(nova->cidade, 100);
	printf("\t Estado: ");
	ler_string(nova->estado, 100);
	printf("\t CEP: ");
	scanf("%lu", &nova->cep);

	//acha o fim
	for (fim = p; fim->prox != NULL; fim = fim->prox) ;

	nova->prox = fim->prox;
	fim->prox = nova;

}

void apaga_pelo_nome(end * ini)
{
	char nome[100];
	end *p, *q;

	printf("Nome: ");
	ler_string(nome, 100);

	p = ini;
	q = ini->prox;
	while ((q != NULL) && (strcmp(q->nome, nome) != 0)) {
		p = q;
		q = q->prox;
	}
	if (q != NULL) {
		p->prox = q->prox;
		free(q);
		printf("\tNome %s removido.\n", nome);
	} else
		printf("\tNome %s inexistente.\n", nome);
}


void imprime(end * ini)
{
	end *p;
	for (p = ini->prox; p != NULL; p = p->prox) {
		printf("\t Nome: %s\n", p->nome);
		printf("\t Rua: %s\n", p->rua);
		printf("\t Cidade: %s\n", p->cidade);
		printf("\t Estado: %s\n", p->estado);
		printf("\t CEP: %lu\n", p->cep);
	}
}

 
void gravar_texto(end * ini)
{
	FILE *arquivo;
	end *p;

	arquivo = fopen("arquivo.txt", "w");
	for (p = ini->prox; p != NULL; p = p->prox) {
		fprintf(arquivo, "%s\n", p->nome);
		fprintf(arquivo, "%s\n", p->rua);
		fprintf(arquivo, "%s\n", p->cidade);
		fprintf(arquivo, "%s\n", p->estado);
		fprintf(arquivo, "%lu\n", p->cep);
	}
	fclose(arquivo);
}

void ler_texto(end * p)
{
	FILE *arquivo;
	char lixo;

	end *fim, *nova;

	nova = (end *) malloc(sizeof(end));

	arquivo = fopen("arquivo.txt", "r");

	fscanf(arquivo, "%[^\n]s", nova->nome);
	while (!feof(arquivo)) {
		fscanf(arquivo, "%c", &lixo);
		fscanf(arquivo, "%[^\n]s", nova->rua);
		fscanf(arquivo, "%c", &lixo);
		fscanf(arquivo, "%[^\n]s", nova->cidade);
		fscanf(arquivo, "%c", &lixo);
		fscanf(arquivo, "%[^\n]s", nova->estado);
		fscanf(arquivo, "%c", &lixo);
		fscanf(arquivo, "%lu", &nova->cep);
		fscanf(arquivo, "%c", &lixo);

		for (fim = p; fim->prox != NULL; fim = fim->prox) ;

		nova->prox = fim->prox;
		fim->prox = nova;

		nova = (end *) malloc(sizeof(end));

		fscanf(arquivo, "%[^\n]s", nova->nome);
	}

	fclose(arquivo);
}