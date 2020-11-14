#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

const int MAX = 10;

bool Empty(Pilha *pilha);
bool PUSH(Pilha *pilha, Aluno *item);
void POP(Pilha *pilha, Aluno *aluno);
void Listar(Pilha *pilha);
void Reset(Pilha *pilha);
bool Full(Pilha *pilha);

typedef struct Aluno{
    int ra;
    char nome[50];
}Aluno;

typedef struct Pilha{
    Aluno alunos[MAX];
    int topo;
    int base;
    int limite;
}Pilha;

int main(){

    return 0;
}

bool Empty(Pilha *pilha){
    return pilha -> topo == 0;
}

bool Full(Pilha *pilha){
    return pilha -> topo == MAX;
}

bool PUSH(Pilha *pilha, Aluno *item){
    if(!Full(pilha)){
        pilha -> alunos[pilha -> topo] = *item;
        pilha -> topo++;
        return true;
    }
    else
        return false;
}

void POP(Pilha *pilha, Aluno *aluno){
    if(pilha -> topo == 0)
        return;

    pilha -> topo--;
    *aluno = pilha -> alunos[pilha -> topo];
}

void Listar(Pilha *pilha){
    printf("\nListando...\n");
    while (!Empty(pilha)){
        Aluno aluno;
        POP(pilha, &alunos);
        printf("\n%i - %s", aluno -> ra, aluno -> nome );
    }
}

void Reset(Pilha *pilha){
    pilha -> topo = 0;
    pilha -> base = 0;
    pilha -> limite = MAX;
}
