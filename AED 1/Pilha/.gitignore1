/*
Faça um programa que armazene a informação de várias
pessoas numa pilha.
O programa deve possuir um menu:
– 0: Insere pessoa
– 1: Deleta pessoa do topo
– 2: Deleta pessoa por nome
– 3: Limpa a pilha
– 4: Lista na tela as pessoas
– 5: Sair do programa
*/

// #include <stdio.h>
// #include <string.h>

// typedef struct pessoa {
//     char nome[30];
//     int idade;
// }Pessoa;

#include<stdio.h>
#include<stdlib.h>

#define MAX 10

typedef struct Pilha{
    int dados[MAX];
    int topo;
}pilha;

void reset(pilha *pi);

int empty(pilha *pi);

int full(pilha *pi);

void push(pilha *pi, int num);

int pop(pilha *pi);

void topo(pilha *pi);

int main()
{
    pilha *pi = (pilha *)malloc(sizeof(pilha));   

    reset(pi);

    int aux;

    aux = pop(pi);

    push(pi,10);
    push(pi, 20);
    push(pi, 30);

    aux = pop(pi);
    printf("%d removido!\n", aux);
    aux = pop(pi);
    printf("%d removido!\n", aux);
    aux = pop(pi);
    printf("%d removido!\n", aux);
    aux = pop(pi);

    push(pi,40);
    push(pi, 50);
    push(pi, 60);
    push(pi,70);

    aux = pop(pi);
    printf("%d removido!\n", aux);
    aux = pop(pi);
    printf("%d removido!\n", aux);
    aux = pop(pi);
    printf("%d removido!\n", aux);

    topo(pi);

    return 0;
    system("pause");
}

void reset(pilha *pi)
{   
    pi->topo = -1;

}

int empty(pilha *pi)
{
    if(pi->topo == -1){
        return 1;
    }else{
        return 0;
    }
}

int full(pilha *pi)
{
    if(pi->topo == MAX-1){
        return 1;
    }else{
        return 0;
    }
}

void push(pilha *pi, int num)
{
    if(full(pi) == 1){
        printf("pilha esta cheia!\n");
    }else{
        pi->topo++;
        pi->dados[pi->topo] = num;
    }
}

int pop(pilha *pi)
{
    int aux;
    if(empty(pi) == 1){
        printf("pilha vazia!\n");
    }else{
        aux = pi->dados[pi->topo];
        pi->topo--;
        return aux;
    }
}

void topo(pilha *pi)
{
    if(empty(pi) == 1){
        printf("pilha vazia!\n");
    }else{
        printf("\n%d no topo!\n", pi->dados[pi->topo]);
    }
}
