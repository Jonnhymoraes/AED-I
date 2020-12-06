#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

struct no{
	struct no *esq;
	struct no *dir;
	int valor;
};

typedef struct no No;

struct ArvAVL{
	struct no * raiz;
};

typedef struct ArvAVL tree;

void liberar_memoria_AVL ( No * No_ptr );
void liberar_memoria ( tree * tree_ptr );
tree * inicializar ( );
No * inicializar_No ( int valor );
int altura (  No *  No_ptr );
int fator_balenceamento (  No *  No_ptr );
No * rotacionar_esq_esq (  No *  No_ptr );
No * rotationar_esq_dir (  No *  No_ptr );
No * rotacionar_dir_esq (  No *  No_ptr );
No * rotacionar_dir_dir (  No *  No_ptr );
No * balancear_No ( No *  No_ptr );
void balancear_tree ( tree *  tree_ptr );
void inserir ( tree * tree_ptr, int valor );
int EhArvoreArvl(No* pRaiz);

void liberar_memoria_AVL ( No * No_ptr ){
	if ( No_ptr == NULL )
		return;

	liberar_memoria_AVL ( No_ptr -> esq );
	liberar_memoria_AVL ( No_ptr -> dir );

	free ( No_ptr );
}

void liberar_memoria ( tree * tree_ptr ){
	liberar_memoria_AVL ( tree_ptr -> raiz );
}

tree * inicializar ( ){
	tree * tree = NULL;

	if((tree = malloc (sizeof(tree))) == NULL){
		return NULL;
	}
	tree -> raiz = NULL;

	return tree;
}

No * inicializar_No (int valor){
	No * No_ptr;

	No_ptr = malloc (sizeof(No));
	if (No_ptr == NULL){
		printf( "O programa ficou sem memória\n" );
	}

	No_ptr -> esq = NULL;
	No_ptr -> dir = NULL;
	No_ptr -> valor = valor;

	return No_ptr;
}

int altura ( No *  No_ptr){
	int altura_esq = 0;
	int altura_dir = 0;

	if (No_ptr -> esq)
		altura_esq = altura ( No_ptr -> esq );

	if (No_ptr -> dir)
		altura_dir = altura (No_ptr -> dir);

	return fmax(altura_dir, altura_esq) + 1;
}

int fator_balenceamento ( No *  No_ptr){
	int fator = 0;

	if (No_ptr -> esq)
		fator += altura (No_ptr -> esq);

	if (No_ptr -> dir)
		fator -= altura (No_ptr -> dir);

	return fator;
}

No * rotacionar_esq_esq ( No *  No_ptr){
	No * temp_ptr = No_ptr;
	No * esq_ptr = temp_ptr -> esq;

	temp_ptr -> esq = esq_ptr -> dir;
	esq_ptr -> dir = temp_ptr;

	return esq_ptr;
}

No * rotationar_esq_dir ( No *  No_ptr){
	No *  temp_ptr = No_ptr;
	No * esq_ptr = temp_ptr -> esq;
	No * dir_ptr = esq_ptr -> dir;

	temp_ptr -> esq = dir_ptr -> dir;
	esq_ptr -> dir = dir_ptr -> esq;
	dir_ptr -> esq = esq_ptr;
	dir_ptr -> dir = temp_ptr;

	return dir_ptr;
}

No * rotacionar_dir_esq ( No *  No_ptr){
	No *  temp_ptr = No_ptr;
	No * dir_ptr = temp_ptr -> dir;
	No * esq_ptr = dir_ptr -> esq;

	temp_ptr -> dir = esq_ptr -> esq;
	dir_ptr -> esq = esq_ptr -> dir;
	esq_ptr -> dir = dir_ptr;
	esq_ptr -> esq = temp_ptr;

	return esq_ptr;
}

No * rotacionar_dir_dir ( No *  No_ptr){
	No *  temp_ptr = No_ptr;
	No * dir_ptr = temp_ptr -> dir;

	temp_ptr -> dir = dir_ptr -> esq;
	dir_ptr -> esq = temp_ptr;

	return dir_ptr;
}

No * balancear_No (No *  No_ptr){
	No * No_balanceado = NULL;

	if (No_ptr->esq)
		No_ptr -> esq = balancear_No ( No_ptr -> esq );

	if (No_ptr -> dir)
		No_ptr -> dir = balancear_No (No_ptr -> dir);

	int fator = fator_balenceamento (No_ptr);

	if (fator >= 2 ){
		/* pesando pra esquerda */

		if (fator_balenceamento(No_ptr -> esq) <= -1 )
			No_balanceado = rotationar_esq_dir(No_ptr);
		else
			No_balanceado = rotacionar_esq_esq (No_ptr);
	}
	else if (fator <= -2 ){
		/* pesando pra direita */

		if ( fator_balenceamento ( No_ptr->dir ) >= 1 )
			No_balanceado = rotacionar_dir_esq (No_ptr);
		else
			No_balanceado = rotacionar_dir_dir (No_ptr);
	}
	else{
		No_balanceado = No_ptr;
	}
	return No_balanceado;
}

void balancear_tree (tree *  tree_ptr){
	No * nova_raiz = NULL;

	nova_raiz = balancear_No (tree_ptr -> raiz);

	if (nova_raiz != tree_ptr -> raiz){
		tree_ptr -> raiz = nova_raiz;
	}
}

void inserir (tree * tree_ptr, int valor){
	No * novo_No_ptr = NULL;
	No * next_ptr = NULL;
	No * last_ptr = NULL;

	if (tree_ptr -> raiz == NULL){
		novo_No_ptr = inicializar_No ( valor );
		tree_ptr -> raiz = novo_No_ptr;
	}
	else{
		next_ptr = tree_ptr -> raiz;
		while (next_ptr != NULL){
			last_ptr = next_ptr;

			if (valor < next_ptr -> valor){
				next_ptr = next_ptr -> esq;
			}
			else if (valor > next_ptr -> valor){
				next_ptr = next_ptr -> dir;
			}
			else if ( valor == next_ptr -> valor){
				return;
			}
		}

	novo_No_ptr = inicializar_No (valor);

		if (valor < last_ptr -> valor)
			last_ptr -> esq = novo_No_ptr;

		if (valor > last_ptr -> valor)
			last_ptr -> dir = novo_No_ptr;
    }
	balancear_tree (tree_ptr);
}

void listar (No * No_ptr){
	if (No_ptr != NULL){
		printf ( "No = %d, altura = %d, FATBAL = %d\n", No_ptr -> valor, altura (No_ptr), fator_balenceamento (No_ptr));
		listar (No_ptr -> esq);
		listar (No_ptr -> dir);
	}
}

int EhArvoreArvl(No* pRaiz){
	int fb;
	
	if (pRaiz == NULL)
		return 1;
	if (!EhArvoreArvl(pRaiz -> esq))
		return 0;
	if (!EhArvoreArvl(pRaiz -> dir))
		return 0;
	fb = fator_balenceamento (pRaiz);
	if ( ( fb > 1 ) || ( fb < -1) )
		return 0;
	else
	return 1;
}

int main(){
	tree * arvore = inicializar() ;
	int op, valor,i, qtd;

	while (1){
		printf ( "------------------------------"
				 "\n| 1- Criar Arvore;"
				 "\n| 2- Listar;"
				 "\n| 3- Verificacao"
				 "\n| 0- Sair;"
				 "\n------------------------------"
				 "\n\n| Opcao: " );
		scanf("%d", &op );
		switch (op){
			case 0:
				liberar_memoria ( arvore );
				printf("Memoria Liberada!!");
				exit ( 0 );
				break;
			case 1:
				printf ( "\nInforme o numero de nos: " );
				scanf( "%d", &qtd );
				srand(time(0));
				for(i = 0; i < qtd; i++){
					valor = rand()% 100;
					inserir ( arvore, valor );
				}
				break;
			case 2:

				if ( arvore -> raiz == NULL ){
					printf ( "\n| Arvore vazia!\n\n" );
				}
				else{
					printf ( "\n" );
					listar ( arvore->raiz );
					printf ( "\n\n" );
				}
				break;
			case 3:
				if(EhArvoreArvl(arvore -> raiz) == 1)
					printf("Eh arvore AVL!!\n"); 
				else
					printf("Nao eh uma arvore AVL!!\n");
				break;
  			}
        }
    return 0;
}