/*
•Continuar a sua implementação da Agenda do slide 28 da semana 1 dentro dos mesmo parâmetros, mas incluir o seguinte.
•Imprimir de forma ordenada usando uma fila ordenada
  –O usuário escolhe um parâmetro de ordenação e uma fila ordenada é criada
  –Depois o programa imprime na tela o conteúdo da fila
•Implementar a base de dados da agenda usando lista duplamente ligada
  –Somente essa base de dados pode ficar fora do buffer principal, ou seja, pode usar um malloc para cada nodo.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>                       

typedef struct agenda{
    char nome[20];                            // conteudo que estará dentro da agenda
    int idade;
}agenda_p;

typedef struct elemento{
    agenda_p dados;
    struct elemento *prox;
}Elemento;

typedef struct fila{
    Elemento *inicio;
    Elemento *final;
}Fila;

typedef struct variaveis{
    int opcao,i,k,contador,j,auxIdade;                 // variaveis usadas no codigo
    char auxNome[20];
}var;

void *pBuffer;                                 //criando um buffer na memoria  
var *inicio;                                  //ponteiro que vou acessar as structs
Fila *fi;
agenda_p *p_agenda;

void insere ();
void imprime();
void buscar ();
void excluir ();
Fila* RESET();
int PUSH(agenda_p inicio);
void imprime_Fila();
void insertionSort(int formaOrda);
void CLEAR();

int main(){

    if((pBuffer = (var *)malloc(sizeof(var)))== NULL){              // verificando se existe memoria disponivel
        printf("Memoria insuficiente!!");
        exit(1);
}

    p_agenda = pBuffer;               // copiando as informações para o ponteiro 
    fi = RESET();
    inicio -> contador = 0;         // inicializando os 2 contadores em 0
    inicio -> k = 0;                // k vai ser usado no código como uma flag
    inicio -> j = 0;                // j vai ser usado no código como uma flag

    do{
        printf("\t\t*** AGENDA ***\n\n\t 1 - Inserir nome\n\t 2 - Excluir nomes\n\t 3 - Buscar nome\n\t 4 - Imprimir nomes\n\t 5 - Imprimir ordenadamente usando fila\n\t 0 - Sair\n");
        printf("\nDigite a opcao desejada: ");
        scanf("%d", &inicio -> opcao);
        printf("\n");

        switch (inicio -> opcao){
            case 1:
                insere();
            break;
            case 2:
                excluir();
            break;
            case 3:
                buscar();
            break;
            case 4:
                imprime();
            break;
            case 5:
                printf("Como deseja ordenar a Fila?\n 1 - Alfabetica\n 2 - Numerica\n");
                scanf("%d", &inicio -> opcao);
                imprime_Fila();
            break;
            default:
                free(pBuffer);
                exit(1);
                CLEAR();
            }
        } while( (inicio -> opcao) != 0);
    return 0;    
}

void insere (){
        agenda_p *nome;         																	// ponteiro para armazenar os dados da agenda (nome)

	    if((pBuffer = (agenda_p *)realloc(pBuffer,sizeof(var) + sizeof(agenda_p) + (inicio -> contador * sizeof(agenda_p)))) == NULL){           
			printf("Memoria indisponivel");
            exit(1);                																// testando se há espaço na memoria. 
        }

        nome = pBuffer + sizeof(var) + (inicio -> contador * sizeof(agenda_p)) ;   					 // a agenda recebe um espaço para a inserção de dados

        printf("Digite um nome: ");
        scanf("%s", nome -> nome);
        printf("Digite a idade: ");
        scanf("%d", &nome -> idade);

        inicio -> contador++;               											// após salvar o primeiro nome o contador é incrementado
}

void imprime(){
        agenda_p *nome;

    nome = pBuffer + sizeof(var);      										 //adicionando a variavel nome ao buffer
    printf("Nomes inseridos na agenda:\n");
	for(inicio -> i = 0; inicio -> i < inicio -> contador; inicio -> i++){    //percorre toda agenda imprimindo os nomes
		printf("%s\n", nome -> nome);
        printf("%d\n", nome ->idade);
		nome++;
		}
	printf("\n");
}

void buscar (){
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
                printf("Idade: %d\n", nome -> idade);
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

void excluir(){
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

Fila* RESET(){
    
    Fila *fi = (Fila *) malloc(sizeof(Fila));

    if( fi != NULL){
        fi -> final = NULL;
        fi -> inicio = NULL;
    }
    printf("Fila criada!!");
    return fi;
}

void CLEAR(){
    if(fi != NULL){
        Elemento* no;
        while (fi -> inicio != NULL){
            no = fi -> inicio;
            fi -> inicio = fi -> inicio -> prox;
            free(no);
        }
        free(fi);
    }
    printf("Fila Liberada da Memória!!");
}
 
int PUSH(agenda_p inicio){                                 //agen = dados da agenda
    if(fi == NULL)
        return 0;

    Elemento *no = (Elemento *) malloc (sizeof(Elemento));

    if(no == NULL)
        return 0;

    no -> dados = inicio;
    no -> prox = NULL;

    if(fi -> final == NULL)                                 //fila vazia
        fi -> inicio = no;
    else
        fi -> final -> prox = no;

    fi -> final = no;

    return 1;
}

int POP(agenda_p info){
    if(fi == NULL)
        return 0;
    if(fi -> final == NULL)
        return 0;
    
    Elemento *no = fi -> inicio;
    
    fi -> inicio = fi -> inicio -> prox;
    info = fi -> inicio -> dados;
    if(fi -> inicio == NULL)                                       //fila ficou vazia
        fi -> final = NULL;
    free(no);

    return 1;
}

void imprime_Fila(){
    Elemento *no;

    if (fi -> inicio == NULL){
        printf("\nFila Vazia!\n");
        return;
    }
    else{
        insertionSort(inicio -> opcao);
        for(no = fi -> inicio; no != NULL; no = no -> prox)
            printf("\nNome %s Idade = %d", no -> dados.nome, no-> dados.idade);
    }
}