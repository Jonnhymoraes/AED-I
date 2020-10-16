#include <stdio.h>
#include <stdlib.h>
#include <string.h>                       

typedef struct agenda{
    char nome[20];                         // conteudo que estará dentro da agenda
}agenda_p;

typedef struct variaveis{
    int opcao,i,k,contador,j;                 // variaveis usadas no codigo
}var;

void *pBuffer;  //criando um buffer na memoria  

void insere (var *inicio);
void imprime(var *inicio);
void buscar (var *inicio);
void excluir (var *inicio);

int main(){

    var *inicio;                    //ponteiro que vou acessar as structs

    if((pBuffer = (var *)malloc(sizeof(var)))== NULL){   // verificando se existe memoria disponivel
        printf("Memoria insuficiente!!");
        exit(1);
}

    inicio = pBuffer;               // copiando as informações para o ponteiro 
    inicio -> contador = 0;         // inicializando os 2 contadores em 0
    inicio -> k = 0;                // k vai ser usado no código como uma flag
    inicio -> j = 0;                // j vai ser usado no código como uma flag

    do{
        printf("\t\t*** AGENDA ***\n\n\t 1 - Inserir nome\n\t 2 - Excluir nomes\n\t 3 - Buscar nome\n\t 4 - Imprimir nomes\n\t 0 - Sair\n");
        printf("\nDigite a opcao desejada: ");
        scanf("%d", &inicio -> opcao);
        printf("\n");

        switch (inicio -> opcao){
            case 1:
                insere(inicio);
            break;
            case 2:
                excluir(inicio);
            break;
            case 3:
                buscar(inicio);
            break;
            case 4:
                imprime(inicio);
            break;
            default:
                free(pBuffer);
                exit(1);
            }
        } while( (inicio -> opcao) != 0);
    return 0;    
}

void insere (var *inicio){
        agenda_p *nome;         // variavel para armazenar o nome

	    if((pBuffer = (agenda_p *)realloc(pBuffer,sizeof(var) + sizeof(agenda_p) + (inicio->contador * sizeof(agenda_p))))== NULL){            printf("Memoria indisponivel");
            exit(1);                // testando se há espaço na memoria. 
        }

        nome = pBuffer + sizeof(var) + (inicio->contador * sizeof(agenda_p)) ;    // a agenda recebe um nome na posição destinada

        printf("Digite um nome: ");
        scanf("%s", nome -> nome);

        inicio -> contador++;               // após salvar o primeiro nome o contador é incrementado
}

void imprime(var *inicio){
        agenda_p *nome;

    nome = pBuffer + sizeof(var);       //adicionando a variavel nome ao buffer
    printf("Nomes inseridos na agenda:\n");
	for(inicio -> i = 0; inicio -> i < inicio -> contador; inicio -> i++){    //percorre toda agenda imprimindo os nomes
		printf("%s\n", nome -> nome);
		nome++;
		}
	printf("\n");
}

void buscar (var *inicio){
        agenda_p *nomeAux, *nome;

        nome = pBuffer + sizeof (var);      //adicionando a variavel nome ao buffer

        if((nomeAux = (agenda_p *) calloc(1, sizeof(agenda_p))) == NULL){  //verificando disponibilidade de memoria
            printf("Memoria indisponivel!");
            exit(1);
        }
        printf("Digite o nome que deseja pesquisar: ");               //o nome vai ser inserido na variavel auxiliar q aponta para nome na strcut
        scanf("%s", nomeAux -> nome);
        printf("\n");

        for(inicio -> i=0; inicio ->i < inicio -> contador; inicio -> i++){    //percorrendo toda a agenda
            if((strcmp(nomeAux -> nome, nome -> nome)) == 0){                   //teste para verificação do nome digitado com o nome já existente na agenda
                printf("Nome encontrado!!\n");
                printf("%s\n", nome -> nome);                                   //depois de encontrado printa na tela
                nome++;                                                         //incrementa a variavel nome e a flag k
                inicio -> k++;
            }
            else
                nome++;                                                         //se não achar incrementa o nome
            }
            if(inicio -> k == 0){                                               //se k que tem papel de uma flag for igual a 0 o nome não existe na agenda
                printf("Nome inexistente na agenda. \n");
            }
            printf("\n");
            inicio -> k = 0;                                                    //retorna o valor inicial da flag para novas consultas  
            free(nomeAux);                                                      //libera da memoria a variavel auxiliar do nome
}

void excluir(var *inicio){
    agenda_p *nomeAux, *nome;

        nome = pBuffer + sizeof (var);      //adicionando a variavel nome ao buffer

        printf("Digite o nome que deseja excluir: ");               //o nome vai ser inserido na variavel auxiliar q aponta para nome na strcut
        scanf("%s", nomeAux -> nome);
        printf("\n");

        for(inicio -> i=0; inicio ->i < inicio -> contador; inicio -> i++){    //percorrendo toda a agenda
            if((strcmp(nomeAux -> nome, nome -> nome)) == 0){                   //teste para verificação do nome digitado com o nome já existente na agenda
                printf("Nome excluido!!\n");                                  
                inicio -> contador--;                                          //decrementa a variavel contador e incrementa a flag j
                inicio -> j++;
            }
            else
                inicio -> contador--;                                           //se não achar decrementa o contador
            }
            if(inicio -> j == 0){                                               //se j que tem papel de uma flag for igual a 0 o nome não existe na agenda
                printf("Nome inexistente na agenda. \n");
            }
            printf("\n");
            inicio -> j = 0;                                                    //retorna o valor inicial da flag para novas consultas  
            free(nomeAux);                                                      //libera da memoria a variavel auxiliar do nome
}