#include <stdio.h>

typedef struct fila{
    TipoFila *pFirst;
    TipoFila *pLast;
}SFila;

typedef struct nodo{
    SProduto info;
    struct TipoFila *pNext;
}TipoFila;

typedef struct produto{
    int cod;
    char nome[40];
    float preco;
}SProduto;

SFila *RESET(SFila *pOldFila);
void PUSH(SFila *pFila, SProduto *pProd);
int POP(SFila *pFila, SProduto *pProd);
void imprimirFila(SFila *pFila);

int main(){

    return 0;
}

SFila *RESET(SFila *pOldFila){

    if(pOldFila)
        Clear(pOldFila);

    SFila *pFila;

    pFila = (SFila *) malloc (sizeof(SFila));
    pFila -> pFirst = NULL;
    pFila -> pLast = NULL;

    return pFila;
}~

void PUSH(SFila *pFila, SProduto *pProd){

    TipoFila **pNovo;

    pNovo = (TipoFila *) malloc (sizeof(TipoFila));

    pNovo -> info = pProd;
    pNovo -> pNext = NULL;

    if(pFile -> pLast != NULL)
        pFila -> pLast -> pNext = pNovo;
    else
        pFila -> pFirst = pNovo;

    pFila -> pLast = pNovo;
}

int POP(SFila *pFila, SProduto *pProd){

    TipoFila *pNodo;

    if(pFila -> pFirst == NULL){
        puts("Fila Vazia!");
        return 0;
    }
    else
    pNodo = pFila -> pFirst;
    *pProd = pFila -> pFirst -> info;
    pFila -> pFirst = pFila -> pFirst -> pNext;

    if(pFila -> pFirst == NULL)
        pFila -> pLast = NULL;

    free(pNodo);

    return 1;
}

void imprimirFila(SFila *pFila){

    TipoFila *pNodo;

    if(pFila -> pFirst == NULL)
        puts("Fila Vazia!!");
    else
        for(pNodo = pFila -> pFirst; pNodo != NULL; pNodo = pNodo -> pNext){
            printf("Nome %s cod = %d preço = %3.2f", pNodo -> info.nome, pNodo -> info.cod, pNodo -> info.preco);
        }
}