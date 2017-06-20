#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "opcao.h"
#include "lista.h"
#include "mst.h"



void inicializaSingleSource(Lista *grafo){
	No *auxiliar = grafo -> primeiro;
	while(auxiliar != NULL){
		auxiliar -> estimativa = INT_MAX;
		auxiliar -> pai = -1;
		auxiliar = auxiliar -> proximo;
	}
	grafo -> primeiro -> estimativa = 0;
}

void relaxamento(No *x, No *y, int peso){
	if(y -> estimativa > (x -> estimativa + peso)){
		y -> estimativa = x -> estimativa + peso;
		//printf("X est: %d\n", x -> estimativa);
		//printf("y est: %d\n", y -> estimativa);
		//printf("peso: %d\n", peso);
		y -> pai = x -> id;
	}
}

void bellmanFord(){
	int i = 0;
	Lista *grafo = (Lista*) malloc (sizeof(Lista));
	
	inicializarLista(grafo);
	
	grafoDirigido = true;
	grafoPonderado = true;

	for(i = 0; i < 5; i++)
		inserirLista(grafo);
	
	insereAresta(grafo, 1, 2, grafoDirigido, 6);
	insereAresta(grafo, 1, 4, grafoDirigido, 7);
	insereAresta(grafo, 2, 3, grafoDirigido, 5);
	insereAresta(grafo, 2, 4, grafoDirigido, 8);
	insereAresta(grafo, 2, 5, grafoDirigido, -4);
	insereAresta(grafo, 3, 2, grafoDirigido, -2);
	insereAresta(grafo, 4, 3, grafoDirigido, -3);
	insereAresta(grafo, 4, 5, grafoDirigido, 9);
	insereAresta(grafo, 5, 3, grafoDirigido, 7);
	insereAresta(grafo, 5, 1, grafoDirigido, 2);
	
//	imprimirLista(grafo);

	inicializaSingleSource(grafo);

	for(i = 1; i < grafo -> tamanho - 1; i++){
		No *auxiliar = grafo -> primeiro;
		while(auxiliar != NULL){
			noAdjacente *auxiliarAdjacente = auxiliar -> adjacente -> primeiro;
			while(auxiliarAdjacente != NULL){
				//printf("id: %d\n", auxiliar -> id);
				//printf("fora: %d\n", auxiliarAdjacente -> id);
				//printf("peso: %d\n", auxiliarAdjacente -> peso);
				relaxamento(auxiliar, retornaNo(grafo, auxiliarAdjacente -> id), auxiliarAdjacente -> peso);
				auxiliarAdjacente = auxiliarAdjacente -> proximo;
			}
			//exit(1);
			auxiliar = auxiliar -> proximo;
		}
	}

	No *auxiliar = grafo -> primeiro;
	while(auxiliar != NULL){
		printf("pai: %d\n", auxiliar -> pai);
		printf("id: %d\n\n", auxiliar -> id);
		//printf("estimativa: %d\n", auxiliar -> estimativa);
		auxiliar = auxiliar -> proximo;
	}

}