#include <stdio.h>
#include <stdlib.h>
#include <string.h>                       

struct agenda{
    char nome[20];
    int idade;                                  // conteudo que estará dentro da agenda
};

struct elemento{
    agenda dados;
    struct elemento *prox;
    struct elemento *anterior;
};

typedef struct elemento Elem;
typedef strcut elemento* Lista;

int main(){
    Lista *li;


    return 0;
}

Lista* cria_lista(){
    Lista* li = (Lista *) malloc (sizeof(Lista));

    if(li != NULL)
        *li = NULL;
    return li;
}

void libera_lista(Lista* li){
    if(li != NULL){
        Elem* no;
        while((*li) != NULL){
            no = *li;
            *li = (*li) -> prox;
            free(no);
        }
        free(li);
    }
}

int tamanho_lista(Lista* li){
    if(li == NULL)
        return 0;
    Elem* no = *li;
    while(no != NULL){
        cont++;
        no = no -> prox;
    }
    return cont;
}

int insere_final(Lista* li, strcut agenda al){
    if(li == NULL)
        return 0;
    Elem *no = (Elem *) malloc(sizeof(Elem));
    if(no == NULL)
        return 0;
    no -> dados = al;
    no -> prox = NULL;
    if((*li) == NULL){                              //lista vazia: insere inicio
        no -> anterior = NULL;
        *li = no;
    }
    else{
        Elem *aux = *li;
        while(aux -> prox != NULL)
            aux = aux -> prox;
        aux -> prox = no;
        no -> anterior = aux;
    }
    return 1;
}

int lista_vazia(Lista* li){
    if(li == NULL)
        return 1;
    if(*li == NULL)
        return 1;
    return 0;
}

int insere_odenado(Lista* li, struct agenda al){
    if(li == NULL)
        return 0;
    Elem *no = (Elem *) malloc (sizeof(Elem));
    if(no == NULL)
        return 0;
    no -> dados = al;
    if(lista_vazia(li)){
        no -> prox = NULL;
        no -> anterior = NULL;
        *li = no;
        return 1;
    }
    else{
        Elem *ante, *atual = *li;
        while(atual != NULL && atual -> dados.idade < al.idade){
            ante = atual;
            atual = atual -> prox;
        }
        if(atual == *li){
            no -> anterior = NULL;
            (*li) -> anterior = no;
            no -> prox = (*li);
            *li = no;
        }
        else{
            no -> prox = ante -> prox;
            no -> anterior = ante;
            ante -> prox = no;
            if(atual != NULL)
                atual -> anterior = no;
        }
    }
    return 1;
}