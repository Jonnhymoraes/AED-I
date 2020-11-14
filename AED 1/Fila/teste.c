#include <stdio.h>
#include <stdlib.h>

struct aluno{
    int cod;
    char nome[40];
    float preco;
};

typedef struct elemento{
    struct aluno dados;
    struct Elemento *prox;
}Elemento;

typedef struct fila{
    Elemento *inicio;
    Elemento *final;
}Fila;

Fila* cria_Fila();
void libera_Fila(Fila* fi);
int tamanho_Fila(Fila* fi);
int Fila_vazia(Fila* fi);
int remove_Fila(Fila* fi);
int consulta_Fila(Fila* fi, struct aluno *al);
int insere_Fila(Fila* fi, struct aluno al);

int main(){
    int x,opcao;
    Fila *fi;
    struct aluno al,*y;

   do{
        printf("\t\t*** FILA ***\n\n\t 1 - Criar Fila\n\t 2 - Liberar Fila\n\t 3 - Tamanho da Fila\n\t 4 - Fila Vazia\n\t 5 - Remove fila\n\t 6 - Consulta Fila\n\t 7 - Insere fila\n\t 0 - Sair");
        printf("\nDigite a opcao desejada: ");
        scanf("%d", &opcao);
        printf("\n");

        switch (opcao){
            case 1:
                cria_Fila();
            break;
            case 2:
                libera_Fila(fi);
            break;
            case 3:
                tamanho_Fila(fi);
            break;
            case 4:
               Fila_vazia(fi);
            break;
            case 5:
                remove_Fila(fi);
            break;
            case 6:
                consulta_Fila(fi, y);
            break;
            case 7:
                insere_Fila(fi, al);
            break;
            default:
                exit(1);
            }
        } while( opcao != 0);
    return 0;    
}

Fila* cria_Fila(){
    
    Fila *fi = (Fila *) malloc(sizeof(Fila));

    if( fi != NULL){
        fi -> final = NULL;
        fi ->inicio = NULL;
    }
    printf("Fila criada!!");
    return fi;
}

void libera_Fila(Fila* fi){
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

int tamanho_Fila(Fila* fi){
    if(fi == NULL)
        return 0;
    
    int cont = 0;
    
    Elemento* no = fi -> inicio;
    while(no != NULL){
        cont++;
        no = no -> prox;
    }
    printf("Tamanho da fila: %d", cont);
    return cont;
}

int Fila_vazia(Fila* fi){
    if(fi == NULL)
        return 1;
    if(fi -> inicio == NULL)
        return 1;
    
    printf("A fila esta vazia!\n");
return 0;
}

int insere_Fila(Fila* fi, struct aluno al ){
    if(fi == NULL)
        return 0;

    Elemento *no = (Elemento *) malloc (sizeof(Elemento));

    if(no == NULL)
        return 0;

    no -> dados = al;
    no -> prox = NULL;

    if(fi -> final == NULL)                     //fila vazia
        fi -> inicio = no;
    else
        fi -> final -> prox = no;

    fi -> final = no;

    return 1;
}

int remove_Fila(Fila* fi){
    if(fi == NULL)
        return 0;
    if(fi -> final == NULL)
        return 0;
    
    Elemento *no = fi -> inicio;
    fi -> inicio = fi -> inicio -> prox;
    if(fi -> inicio == NULL)                                       //fila ficou vazia
        fi-> final = NULL;
    free(no);

    return 1;
}

int consulta_Fila(Fila* fi, struct aluno *al){
    if(fi == NULL)
        return 0;
    if(fi -> inicio == NULL)                                    // fila vazia
        return 0;
    *al = fi -> inicio -> dados;

    return 1;
}