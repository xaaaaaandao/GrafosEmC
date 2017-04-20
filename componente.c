#include <stdio.h>
#include <stdlib.h>
#include "busca.h"
#include "exercicios.h"
#include "lista.h"
#include "matriz.h"
#include "opcao.h"

void matrizTranspota(int** matrizOrigem, int **matrizDestino, int tamanho){
	int i, j;
	for(i = 0; i < tamanho; i++){
		for(j = 0; j < tamanho; j++){
			matrizDestino[i][j] = matrizOrigem[i][j];
		}
	}
	for(i = 1; i < tamanho; i++){
		for(j = 1; j < tamanho; j++){
			matrizDestino[i][j] = matrizOrigem[j][i];
		}
	}
}

void listaTransposta(Lista *l, int **matriz, int tamanho){
	int i, j;
	for(i = 0; i < tamanho - 1; i++)
		inserirLista(l);
	for(i = 1; i < tamanho; i++){
		for(j = 1; j < tamanho; j++){
			if(matriz[i][j] == 1)
				insereAresta(l, i, j, grafoDirigido, 1);
		}
	}
}

void componenteFortementeConexa(Lista *l){
	Lista *lTransposta = (Lista*) malloc (sizeof(Lista));
	inicializarLista(lTransposta);
	int numeroVertice = nVertice(l) + 1;
	int **matriz = (int**) malloc (numeroVertice * sizeof(int*));
	int **matrizDestino = (int**) malloc (numeroVertice * sizeof(int*));	
	int i, j;
	for(i = 0; i < numeroVertice; i++){
		matriz[i] = (int*) malloc (numeroVertice * sizeof(int)); //Aloca um Vetor de Inteiros para cada posição do Vetor de Ponteiros.
		matrizDestino[i] = (int*) malloc (numeroVertice * sizeof(int));
 	}
	
	iniciarBuscaEmProfundidade(l);
	matriz = matrizAdjacencia(l, grafoDirigido);
	matrizTranspota(matriz, matrizDestino, numeroVertice);
	for(i = 0; i < numeroVertice; i++){
		for(j = 0; j < numeroVertice; j++){
			printf("%d ", matrizDestino[i][j]);
		}
		printf("\n");
	}
	listaTransposta(lTransposta, matrizDestino, numeroVertice);
	imprimirLista(lTransposta);
}