#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void Reset(Pilha *pilha);
bool Empty(Pilha *pilha){
bool PUSH(Pilha *pilha, Aluno *item);
void POP(Pilha *pilha, Aluno *aluno);

struct Aluno{
    int ra;
    char nome[50];
};

struct Pilha{
    Aluno *alunos;
    int *topo;
    int *base;
    int limite;
};

int main(){

    return 0;
}

void Reset(Pilha *pilha){
    pilha -> alunos = NULL;
    pilha -> topo = NULL;
    pilha -> base = NULL;
    pilha -> limite = 0;
}

bool Empty(Pilha *pilha){
    return pilha -> topo == NULL;
}

bool PUSH(Pilha *pilha, Aluno *item){
    Aluno *alunos;

    pilha -> limite++;
    alunos = (Aluno *) malloc (sizeof (Aluno) *pilha -> limite);
    if(!alunos){
        printf("Erro de alocacao de Memoria!");
        return;
    }
    CopiaPilha(alunos, pilha -> limite, pilha -> alunos, pilha -> limite -1);
    if(pilha -> alunos)
        free(pilha -> alunos);
        pilha -> alunos;
    
    pilha -> alunos[pilha -> limite - 1] = *item;
    pilha -> topo = &pilha -> alunos [pilha -> limite];
    pilha -> base = pilha -> alunos;

    return true;
}

void POP(Pilha *pilha, Aluno *aluno){
    if(Empty(pilha))
        return;

    aluno = pilha -> topo;

    Aluno *alunos;
    pilha -> limite--;

    if(pilha -> limite == 0){
        free(pilha -> alunos);
        Reset(pilha);
        return;
    }

    size_t size = sizeof(Aluno) * pilha -> limite;
    alunos = (Aluno *) malloc(size);

    if(!alunos){
        printf("Erro ao alocar memoria!");
        return;
    }

    CopiaPilha(alunos, pilha -> limite, pilha -> alunos, pilha -> limite + 1);
    free(plha -> alunos);
    pilha -> alunos = alunos;
    pilha -> topo = &pilha -> alunos[pilha -> limite -1];
    pilha -> base = pilha -> alunos;
}