#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "telas.h"

bool existeAresta(Lista *l, int origem, int destino, bool tipoGrafo, int peso){
	No *auxiliar = l -> primeiro;
	noAdjacente *auxiliarAdjacente;
	while(auxiliar != NULL){
		if(auxiliar -> id == origem){
			if(vaziaListaAdjacente(auxiliar -> l)){
				if(tipoGrafo){
					inserirListaAdjacente(auxiliar -> l, destino, peso);
				} else {
					inserirListaAdjacente(auxiliar -> l, destino, peso);
					existeAresta(l, destino, origem, tipoGrafo, peso);
				}
				return true;
			} else {
				auxiliarAdjacente = auxiliar -> l -> primeiro;
				while(auxiliarAdjacente != NULL){
					if(auxiliarAdjacente -> id == destino)
						return false;
					auxiliarAdjacente = auxiliarAdjacente -> proximo;
				}
				if(tipoGrafo){
					inserirListaAdjacente(auxiliar -> l, destino, peso);
				} else {
					inserirListaAdjacente(auxiliar -> l, destino, peso);
					existeAresta(l, destino, origem, tipoGrafo, peso);
				}	
				return true;		
			}
		}
		auxiliar = auxiliar -> proximo;
	}
	return false;
}

bool existeVertice(Lista *l, int id){
	No *auxiliar = l -> primeiro;
	while(auxiliar != NULL){
		if(auxiliar -> id == id)
			return true;
		auxiliar = auxiliar -> proximo;
	}
	return false;
}

void limpaListaAdjacente(listaAdjacente *l){
	noAdjacente *temporario, *atual;
	atual = l -> primeiro;
	while(atual != NULL){
		temporario = atual -> proximo;
		free(atual);
		atual = temporario;
	}
	free(l);
}

void limpaLista(Lista *l){
	No *temporario, *atual;
	atual = l -> primeiro;
	while(atual != NULL){
		temporario = atual -> proximo;
		free(atual);
		atual = temporario;
	}
	free(l);
}

void inicializarListaAdjacente(listaAdjacente *l){
	l -> primeiro = NULL;
	l -> ultimo = NULL;
	l -> tamanho = 1;
}

void inicializarLista(Lista *l){
	l -> primeiro = NULL;
	l -> ultimo = NULL;
	l -> tamanho = 1;
}

int vaziaListaAdjacente(listaAdjacente *l){
	return (l -> primeiro == NULL);
}  

int vaziaLista(Lista *l){
	return (l -> primeiro == NULL);
}  

void inserirListaAdjacente(listaAdjacente *l, int id, int peso){

	bool flag = true;

	noAdjacente *novoNo = (noAdjacente*) malloc (sizeof(noAdjacente));
	novoNo -> id = id;
	novoNo -> peso = peso;
	novoNo -> anterior = NULL;
	novoNo -> proximo = NULL;
	
	noAdjacente *aux = (noAdjacente*) malloc (sizeof(noAdjacente));

	if (vaziaListaAdjacente(l)){
		l -> primeiro = novoNo;
		l -> ultimo = novoNo;
	} else {
		aux = l -> primeiro;

		while(aux -> proximo != NULL) {
			if (id < aux -> id) {
				if (aux != l -> primeiro) {
					novoNo -> proximo = aux;
					novoNo -> anterior = aux -> anterior;
					aux -> anterior -> proximo = novoNo;
					aux -> anterior = novoNo;
					flag = false;
					break;
				} else {
					break;
				}
			}

			aux = aux -> proximo;
		}

		if (flag) {
			if (aux == l -> primeiro) {
				if (id < aux -> id) {
					novoNo -> proximo = aux;
					aux -> anterior = novoNo;
					l -> primeiro = novoNo;
				} else if (id > aux -> id) {
					novoNo -> anterior = aux;
					aux -> proximo = novoNo;
					l -> ultimo = novoNo;
				}
			} else if (aux == l -> ultimo) {
				if (id < aux -> id) {					
					novoNo -> proximo = aux;			
					novoNo -> anterior = aux -> anterior;
					aux -> anterior -> proximo = novoNo;
					aux -> anterior = novoNo;
				} else if (id > aux -> id) {
					novoNo -> anterior = aux;
					aux -> proximo = novoNo;
					l -> ultimo = novoNo;
				}
			}
		}

	}
	
	l -> tamanho++;
}

void inserirLista(Lista *l){
	No *novoNo = (No*) malloc (sizeof(No));
	novoNo -> id = l -> tamanho;
	novoNo -> proximo = NULL;
	
	novoNo -> l = (listaAdjacente*) malloc (sizeof(listaAdjacente));
	inicializarListaAdjacente(novoNo -> l);

	if (vaziaLista(l)){
		l -> primeiro = novoNo;
		l -> ultimo = novoNo;
	} else {
		l -> ultimo -> proximo = novoNo;
		l -> ultimo = novoNo;
	}
	
	l -> tamanho++;
}

int tamanhoListaAdjacente(listaAdjacente *l){
	return (l -> tamanho);
}

int tamanhoLista(Lista *l){
	return (l -> tamanho);
}

void imprimirListaAdjacente(listaAdjacente *l, int id){
	if (vaziaListaAdjacente(l)){
		printf("Não tem adjacentes!\n");
	} else {
		noAdjacente *auxiliar;
		auxiliar = l -> primeiro;
		while (auxiliar != NULL){ 
			printf("-> %d é adjacente ao %d e seu peso é %d.\n", id, auxiliar -> id, auxiliar -> peso);
			auxiliar = auxiliar -> proximo;
		}
	}    
}

void imprimirLista(Lista *l){
	if (vaziaLista(l)){
		printf("Empty list!\n");
	} else {
		No *auxiliar;
		auxiliar = l -> primeiro;
		while (auxiliar != NULL){ 
			printf("Id: %d\n", auxiliar -> id);
			imprimirListaAdjacente(auxiliar -> l, auxiliar -> id);
			auxiliar = auxiliar -> proximo;
		}
	}    
}

    