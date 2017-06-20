#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <string.h>
#include "busca.h"
#include "opcao.h"
#include "matriz.h"
#include "mst.h"

No *extrairMenor(Lista *grafo, Lista *copia){
	int menor = copia -> primeiro -> chave;
	No *auxiliarCopia = copia -> primeiro -> proximo;
	No *auxiliar = grafo -> primeiro -> proximo;
	No *resposta = copia -> primeiro;
	while((auxiliar != NULL) && (auxiliarCopia != NULL)){
		if(menor > auxiliarCopia -> chave){
			menor = auxiliarCopia -> chave;
			resposta = auxiliarCopia;
		}
		auxiliar = auxiliar -> proximo;
		auxiliarCopia = auxiliarCopia -> proximo;
	}
	return resposta;
}


No *retornaNo(Lista *grafo, int id){
	No *auxiliar = grafo -> primeiro;
	while(auxiliar != NULL){
		if(auxiliar -> id == id){
			return auxiliar;
		}
		auxiliar = auxiliar -> proximo;
	}
	return NULL;
}


bool existeNo(Lista *copia, int id){
	No *auxiliar = copia -> primeiro;
	while(auxiliar != NULL){
		if(auxiliar -> id == id){
			return true;
		}
		auxiliar = auxiliar -> proximo;
	}
	return false;
}

void MST_Prim(){
	int i = 0;
	Lista *grafo = (Lista*) malloc (sizeof(Lista));
	Lista *copia = (Lista*) malloc (sizeof(Lista));
	No *auxiliar, *auxiliarCopia, *menor;
	noAdjacente* auxiliarAdjacente;
	
	inicializarLista(grafo);
	inicializarLista(copia);

	grafoDirigido = false;
	grafoPonderado = true;

	for(i = 0; i < 9; i++){
		inserirLista(grafo);
		inserirLista(copia);
	}

	insereAresta(grafo, 1, 2, grafoDirigido, 4);
	insereAresta(grafo, 1, 6, grafoDirigido, 8);
	insereAresta(grafo, 2, 3, grafoDirigido, 8);
	insereAresta(grafo, 2, 6, grafoDirigido, 11);
	insereAresta(grafo, 3, 4, grafoDirigido, 7);
	insereAresta(grafo, 3, 8, grafoDirigido, 4);
	insereAresta(grafo, 3, 9, grafoDirigido, 2);
	insereAresta(grafo, 4, 5, grafoDirigido, 9);
	insereAresta(grafo, 4, 8, grafoDirigido, 14);
	insereAresta(grafo, 5, 8, grafoDirigido, 10);
	insereAresta(grafo, 6, 7, grafoDirigido, 1);
	insereAresta(grafo, 6, 9, grafoDirigido, 7);
	insereAresta(grafo, 7, 8, grafoDirigido, 2);
	insereAresta(grafo, 7, 9, grafoDirigido, 6);

	auxiliar = grafo -> primeiro;
	while(auxiliar != NULL){
		auxiliar -> chave = INT_MAX;
		auxiliar -> pai = -1;
		auxiliar = auxiliar -> proximo;
	}

	auxiliarCopia = copia -> primeiro;
	while(auxiliarCopia != NULL){
		auxiliarCopia -> chave = INT_MAX;
		auxiliarCopia -> pai = -1;
		auxiliarCopia = auxiliarCopia -> proximo;
	}

	grafo -> primeiro -> chave = 0;
	copia -> primeiro -> chave = 0;

	while(!vaziaLista(copia)){
		menor = extrairMenor(grafo, copia);
		printf("%d\n", menor -> id);
		printf("%d\n", menor -> chave);
		No *atual = retornaNo(grafo, menor -> id);
		auxiliarAdjacente = atual -> adjacente -> primeiro;
		while(auxiliarAdjacente != NULL){
			No *atualAdjacente = retornaNo(grafo, auxiliarAdjacente -> id); 
			if((existeNo(copia, auxiliarAdjacente -> id)) && (auxiliarAdjacente -> peso < atualAdjacente -> chave)){
				atualAdjacente -> pai = atual -> id;
				atualAdjacente -> chave = auxiliarAdjacente -> peso;
				retornaNo(copia, auxiliarAdjacente -> id) -> chave  = auxiliarAdjacente -> peso;  
			}
			auxiliarAdjacente = auxiliarAdjacente -> proximo;
		}
		removeVertice(copia, menor -> id);
	}

	auxiliar = grafo -> primeiro;
	while(auxiliar != NULL){
		printf("pai: %d\n", auxiliar -> pai);	
		printf("id: %d\n\n", auxiliar -> id);
		auxiliar = auxiliar -> proximo;
	}
	return;
}


