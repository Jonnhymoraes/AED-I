#include <stdio.h>
#include <stdlib.h>
//#define MAX 10;

typedef struct Lista_estatica {
    int matricula;
    char nome[30];
    float n1,n2,n3;
}lista;

typedef struct lista{
    int qtd;                                          //quantidade de elementos da lista
    struct Lista_estatica dados [3];                 //tamanho máximo da lista
}Lista;

Lista* criar_lista();
void libera_lista(Lista* li);
int tamanho_lista(Lista* li);
int lista_cheia(Lista* li);
int lista_vazia(Lista* li);
int insere_final(Lista* li, struct lista num );
int insere_inicio(Lista* li, struct lista num);

int main(){

    int x;
    Lista* li; // criando variável para ter acesso a lista

    li = criar_lista();
    x = tamanho_lista(li);
  ///  x = lista_vazia(Lista* li);
        if(lista_vazia(li))
    x= insere_final(li, dados_lista);
    x= insere_inicio(li, dados_lista);

return 0;
}

Lista* criar_lista(){
    Lista *li;

    li = (Lista*) malloc(sizeof(struct lista)); //alocando memória do ponteiro que faz referência a struct
    if(li != NULL)
        li-> qtd = 0;
return li;        
}

void libera_lista(Lista* li){
    free(li);
}

int tamanho_lista(Lista* li){
    if(li== NULL)
        return -1;
    else
        return li -> qtd;
}

int lista_cheia(Lista* li){
    if(li == NULL)
        return -1;
    else
        return (li -> qtd == 3);
}

int lista_vazia(Lista* li){
    if(li == NULL)
        return -1;
    else
        return (li -> qtd == 0);    
}

int insere_final(Lista* li, struct lista num ){
    if(li == NULL)
        return 0;
    if (lista_cheia (li))
        return 0;
    li -> dados[li -> qtd] = num;        //posição do vetor dados recebe o dado al
    li -> qtd++;                        //incrementa qtd
    return 1;
}

int insere_inicio(Lista* li, struct lista num){
    if (li == NULL)
        return 0;
    if (lista_cheia(li))
        return 0;
    int i;
                                                    // acontece do último para o primeiro para ñ sobrescrever

    for(i=li -> qtd-1; i>=0; i--)                   // qtd-1 é o final da lista
        li -> dados[i+1] = li -> dados[i];          // empurra os dados para frente (posição da frente recebe a anterior)
    li -> dados[0] = num;                            // insere dados no início da lista
    li -> qtd++;                                    // incrementa qtd (tamanho)
    return 1;
}
