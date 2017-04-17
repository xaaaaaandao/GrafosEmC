#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

/* Operações de matriz */

void inicializarMatriz(int **matriz, int tamanho){
	int i, j;
	for(i = 0; i < tamanho; i++){
		for(j = 0; j < tamanho; j++)
			matriz[i][j] = 0;
	}
	for(i = 0; i < tamanho; i++){
		matriz[0][i] = i;
	}
	for(i = 0; i < tamanho; i++){
		matriz[i][0] = i;
	}
}

void imprimirMatrizAdjacencia(Lista *l, bool tipoGrafo){
	No *auxiliar = l -> primeiro;
	noAdjacente *auxiliarAdjacente;
	int **matrizAdjacencia = (int**) malloc (l -> tamanho * sizeof(int*));
	int i, j;
	for(i = 0; i < l -> tamanho; i++){
		matrizAdjacencia[i] = (int*) malloc (l -> tamanho * sizeof(int)); //Aloca um Vetor de Inteiros para cada posição do Vetor de Ponteiros.
 	}
 	inicializarMatriz(matrizAdjacencia, l -> tamanho);
 	while(auxiliar != NULL){
 		auxiliarAdjacente = auxiliar -> adjacente -> primeiro;
 		while(auxiliarAdjacente != NULL){
 			if(tipoGrafo){
 				matrizAdjacencia[auxiliar -> id][auxiliarAdjacente -> id] = auxiliarAdjacente -> peso;	
 			} else {
				matrizAdjacencia[auxiliar -> id][auxiliarAdjacente -> id] = 1;	 				
 			}
 			auxiliarAdjacente = auxiliarAdjacente -> proximo;
 		}
 		auxiliar = auxiliar -> proximo;
 	}
 	for(i = 0; i < l -> tamanho; i++){
 		for(j = 0; j < l -> tamanho; j++){
 			printf("%d  ", matrizAdjacencia[i][j]);
 		}
 		printf("\n");
 	}
}