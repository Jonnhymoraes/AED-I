/*
Faça um programa que lê n números decimais (n fornecido pelo
usuário), armazenando-os em um vetor. Logo após, uma função deve
retirar os números duplicados que eventualmente possam existir neste
vetor, deixando apenas uma ocorrência de cada número. Ao final, o vetor
resultante deve ser impresso na tela.
*/

#include <stdio.h>
#include <stdlib.h>

 void Duplicados(int vetor[],int num);

 int main(){

 	int n, i;
 	
 	printf("Digite o tamanho do vetor: ");
 	scanf("%d",&n);
	
    int vet[n];
	printf("\nVetor:\n");
 	
 	for (i = 0; i < n; i++)
 	 	scanf("%d", &vet[i]);
 	
 	Duplicados(vet,n);
 	
 	return 0;
 }
 
 void Duplicados(int vetor[],int n){
	
	int vetor_final[n];
	int cont = 0, i, j, k = 0; 

	for(i = 0; i < n; i++){              		//percorre o vetor
 		for(j = i+1 ; j < n; j++){
			if(vetor[i] == vetor[j]){			//compara se tem numeros iguais, se tiver incrementa o contador
				cont++;
			}
 		}
		if(cont < 1){								//se tiver numero repetido esses numeros vão para o vetor final
			vetor_final[k] = vetor[i];
			k++;
		}	
		cont = 0 ;
 	}
 	printf("\nVetor sem repeticoes\n");
 	for (i = 0; i < k; i++){
 		printf("%d\t",vetor_final[i]);
    }
}