#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"
#include "exercicios.h"

/**
* A função inicializarMatriz(int **matriz, int tamanho)
* inicializa a matriz de adjacência com 0;
@param matriz, é um arranjo bidimensional de inteiros com a matriz da adjacência;
@param tamanho, é um inteiro com o tamanho da matriz da adjacência;
@return void, retorna nada.
*/
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

/**
* A função matrizAdjacencia(Lista *l, bool tipoGrafo)
* converte a lista de adjacência convertendo para a matriz 
* de adjacência verificando se o grafo dirigido ou não dirigido;
@param l, é do tipo Lista que contem os vértices existentes;
@param tipoGrafo, é um booleano se o grafo dirigido ou não dirigido;
@return matrizAdjacencia, retorna um arranjo bidimensional da matriz de adjacência.
*/
int **matrizAdjacencia(Lista *l, bool tipoGrafo){
	No *auxiliar = l -> primeiro;
	noAdjacente *auxiliarAdjacente;
	int numeroVertice = nVertice(l) + 1;
	int **matrizAdjacencia = (int**) malloc (numeroVertice * sizeof(int*));
	int i, j;
	for(i = 0; i < numeroVertice; i++){
		matrizAdjacencia[i] = (int*) malloc (numeroVertice * sizeof(int)); //Aloca um Vetor de Inteiros para cada posição do Vetor de Ponteiros.
 	}
 	inicializarMatriz(matrizAdjacencia, numeroVertice);
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
 	return matrizAdjacencia;
}

/**
* A função imprimirMatrizAdjacencia(Lista *l, bool tipoGrafo)
* converte a lista de adjacência convertendo para a matriz 
* de adjacência verificando se o grafo dirigido ou não dirigido, e por
* fim, imprime ela;
@param l, é do tipo Lista que contem os vértices existentes;
@param tipoGrafo, é um booleano se o grafo dirigido ou não dirigido;
@return void, retorna nada.
*/
void imprimirMatrizAdjacencia(Lista *l, bool tipoGrafo){
	No *auxiliar = l -> primeiro;
	noAdjacente *auxiliarAdjacente;
	int numeroVertice = nVertice(l) + 1;
	int **matrizAdjacencia = (int**) malloc (numeroVertice * sizeof(int*));
	int i, j;
	for(i = 0; i < numeroVertice; i++){
		matrizAdjacencia[i] = (int*) malloc (numeroVertice * sizeof(int)); //Aloca um Vetor de Inteiros para cada posição do Vetor de Ponteiros.
 	}
 	inicializarMatriz(matrizAdjacencia, numeroVertice);
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
 	for(i = 0; i < numeroVertice; i++){
 		for(j = 0; j < numeroVertice; j++){
 			printf("%d  ", matrizAdjacencia[i][j]);
 		}
 		printf("\n");
 	}
}