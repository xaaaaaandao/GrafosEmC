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

No *menorEstimativa(Lista *grafo){
	int menor = grafo -> primeiro -> estimativa;
	No *auxiliar = grafo -> primeiro -> proximo;
	No *resposta = grafo -> primeiro;
	while(auxiliar != NULL){
		if(menor > auxiliar -> estimativa){
			menor = auxiliar -> estimativa;
			resposta = auxiliar;
		}
		auxiliar = auxiliar -> proximo;
	}
	return resposta;
}


void inserirDeterminadoVertice(Lista *l, int id, int pai){
	No *novoNo = (No*) malloc (sizeof(No));
	novoNo -> id = id;
	novoNo -> pai = pai;
	novoNo -> proximo = NULL;
	if (vaziaLista(l)){
		l -> primeiro = novoNo;
		l -> ultimo = novoNo;
	} else {
		l -> ultimo -> proximo = novoNo;
		l -> ultimo = novoNo;
	}
	l -> tamanho++;
}

void Dijkstra(){
	int i = 0;
	Lista *grafo = (Lista*) malloc (sizeof(Lista));
	Lista *copia = (Lista*) malloc (sizeof(Lista));
	Lista *resposta = (Lista*) malloc (sizeof(Lista));
	No *menor;
	
	inicializarLista(grafo);
	inicializarLista(copia);
	inicializarLista(resposta);
	
	grafoDirigido = true;
	grafoPonderado = true;

	for(i = 0; i < 5; i++){
		inserirLista(copia);
		inserirLista(grafo);
		inserirLista(resposta);
	}
	
	insereAresta(grafo, 1, 2, grafoDirigido, 10);
	insereAresta(grafo, 1, 4, grafoDirigido, 5);
	insereAresta(grafo, 2, 3, grafoDirigido, 1);
	insereAresta(grafo, 2, 4, grafoDirigido, 2);
	insereAresta(grafo, 3, 5, grafoDirigido, 4);
	insereAresta(grafo, 4, 2, grafoDirigido, 3);
	insereAresta(grafo, 4, 5, grafoDirigido, 2);
	insereAresta(grafo, 4, 3, grafoDirigido, 9);
	insereAresta(grafo, 5, 3, grafoDirigido, 6);
	
	inicializaSingleSource(grafo);
	inicializaSingleSource(copia);
	inicializaSingleSource(resposta);

	while(vaziaLista(grafo) == false){
		menor = menorEstimativa(grafo);
		noAdjacente *auxiliarAdjacente = menor -> adjacente -> primeiro;
		while(auxiliarAdjacente != NULL){
			relaxamento(menor, retornaNo(grafo, auxiliarAdjacente -> id), auxiliarAdjacente -> peso);
			retornaNo(resposta, auxiliarAdjacente -> id) -> pai = menor -> id;
			auxiliarAdjacente = auxiliarAdjacente -> proximo;
		}
		//printf("pai: %d\n", grafo -> primeiro -> pai);
		//printf("id: %d\n", grafo -> primeiro -> id);
		//exit(1);
		removeVertice(grafo, menor -> id);
	}

	No *auxiliar = resposta -> primeiro;
	while(auxiliar != NULL){
		printf("pai: %d\n", auxiliar -> pai);
		printf("id: %d\n", auxiliar -> id);
		auxiliar = auxiliar -> proximo;
	}
}
