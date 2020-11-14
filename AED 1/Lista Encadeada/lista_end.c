#include <stdio.h>
#include <stdlib.h>

typedef struct dado{
    int cod;
    char nome[40];
    float preco;
}SDado;

typedef struct nodo{
    SDado info;
    struct SNodo *pNext; 
}SNodo;

typedef struct lista{
    SNodo *pFirst
}SLista;

void Reset(SLista *pLista);
int PUSH(SLista *pLista, SNodo *pNodo, unsigned int nIndex);
int POP(SLista *pLista, SNodo *pNodo, unsigned int nIndex);
void Clear(SLista *pLista);

int main(){

    return 0;
}

void Reset(SLista *pLista){
    Clear(pLista);

    pLista = (SLista *) malloc (sizeof(SLista));
}

int PUSH(SLista *pLista, SNodo *pNodo, unsigned int nIndex){

    SNodo *pAtual, *pAnterior;
    int nPos;

    if(pLista -> pFirst == NULL && nIndex != 0)                   // testa se tem una lista
        return 0;
    else if(pLista -> pFirst == NULL && nIndex == 0){            //indice 0 com a lista vazia
        pLista -> pFirst = pNodo;
        pLista -> pFirst -> pNext = NULL;
        return 1;
    }
    else if(nIndex == 0){                                        // indice continua 0 + já tem elemento na lista
        pNodo -> pNext = pLista -> pFirst;
        pLista -> pFirst = pNodo;
        return 1;
    }
    
    pAtual = pLista -> pFirst;

    for(nPos = 0; nPos <= nIndex && pAtual != NULL; nPos++){     // insere no meio da lista
        pAnterior = pAtual;
        pAtual = pAtual -> pNext;
    }

    if(!pAtual)
        return 0;                                                 //erro index não existe

    pNodo -> pNext = pAtual;
    pAnterior -> pNext = pNodo;

    return 1;
}

int POP(SLista *pLista, SNodo *pNodo, unsigned int nIndex){

    SNodo *pAtual, *pAnterior;
    int nPos;

    if(pLista -> pFirst == NULL)                   // testa se tem elementos na lista
        return 0;
    
    if(nIndex == 0){
        pNodo = pLista -> pFirst;
        pLista -> pFirst = pLista -> pFirst -> pNext;
        return 1;
    }

    pAtual = pLista -> pFirst;

    for(nPos = 0; nPos < nIndex && pAtual != NULL; nPos++){
        pAnterior = pAtual;
        pAtual = pAtual -> pNext;
    }

    if(!pAtual)
        return 0;
    
    pAnterior -> pNext = pAtual -> pNext;
    pNodo = pAtual;

    return 1;
}

void Clear(SLista *pLista){


}