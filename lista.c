#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "opcao.h"
#include "telas.h"

/* Carregar arquivos */

void exemploGrafoNaoDirigido(Lista *l){
	int i;
	grafoDirigido = false;
	grafoPonderado = false;
	for(i = 0; i < 8; i++){
		inserirLista(l);
	}
	insereAresta(l, 1, 6, grafoDirigido, 1);
	insereAresta(l, 1, 4, grafoDirigido, 1);
	insereAresta(l, 2, 3, grafoDirigido, 1);
	insereAresta(l, 2, 6, grafoDirigido, 1);
	insereAresta(l, 2, 7, grafoDirigido, 1);
	insereAresta(l, 3, 7, grafoDirigido, 1);
	insereAresta(l, 3, 8, grafoDirigido, 1);
	insereAresta(l, 4, 5, grafoDirigido, 1);
	insereAresta(l, 6, 7, grafoDirigido, 1);
	insereAresta(l, 7, 8, grafoDirigido, 1);
}

void exemploGrafoDirigido(Lista *l){
	int i;
	for(i = 0; i < 6; i++){
		inserirLista(l);
	}
	grafoDirigido = true;
	grafoPonderado = false;
	insereAresta(l, 1, 2, grafoDirigido, 1);
	insereAresta(l, 2, 5, grafoDirigido, 1);
	insereAresta(l, 3, 5, grafoDirigido, 1);
	insereAresta(l, 3, 6, grafoDirigido, 1);
	/* Exemplo: retirar quando não tem ordenação topológica
	insereAresta(l, 4, 1, grafoDirigido, 1); */
	insereAresta(l, 5, 4, grafoDirigido, 1);
}

/* Operações de lista */
void removerFimAresta(listaAdjacente *l){
	noAdjacente *ultimo = l -> primeiro, *penultimo = l -> primeiro;			 
	while(ultimo -> proximo != NULL){
		penultimo = ultimo;
		ultimo = ultimo->proximo;
	}	
	penultimo -> proximo = NULL;
	l -> ultimo = penultimo;
	free(ultimo);
}

void removerMeioAresta(listaAdjacente *l, int id){
	noAdjacente *atual = l -> primeiro;
	noAdjacente *anterior = l -> primeiro;
	noAdjacente *proximo, *auxiliar;
	atual = l -> primeiro;		 
	while(atual -> id != id){
		anterior = atual;
		atual = atual -> proximo;
	}
	auxiliar = l -> primeiro;
	while(auxiliar != NULL){
		if(auxiliar -> anterior == atual){
			proximo = auxiliar;
			break;
		}
		auxiliar = auxiliar -> proximo;
	}
	anterior -> proximo = atual -> proximo;
	proximo -> anterior = anterior;
	free(atual);
}

void removerInicioAresta(listaAdjacente* l){
	noAdjacente *auxiliar;
	auxiliar = l -> primeiro;
	l -> primeiro = l -> primeiro -> proximo;
	l -> primeiro -> anterior = NULL;
	free(auxiliar);
}

void removeAresta(Lista *l, int origem, int destino){
	bool achouDestino;
	listaAdjacente *adjacente;
	noAdjacente *auxiliarAdjacente;
	No *auxiliar = l -> primeiro;
	while(auxiliar != NULL){
		if(auxiliar -> id == origem){
			auxiliarAdjacente = auxiliar -> adjacente -> primeiro;
			while(auxiliarAdjacente != NULL){
				if(auxiliarAdjacente -> id == destino){
					achouDestino = true;
					break;
				}
				auxiliarAdjacente = auxiliarAdjacente -> proximo;
			}
			if(achouDestino){
				break;
			}
		}
		auxiliar = auxiliar -> proximo;
	}
	if(auxiliarAdjacente -> anterior == NULL && auxiliarAdjacente -> proximo == NULL){
		free(auxiliarAdjacente);
		auxiliar -> adjacente = (listaAdjacente*) malloc (sizeof(listaAdjacente));
		inicializarListaAdjacente(auxiliar -> adjacente);
	} else if(auxiliarAdjacente -> anterior == NULL){
		removerInicioAresta(auxiliar -> adjacente);
	} else if(auxiliarAdjacente -> proximo == NULL){
		removerFimAresta(auxiliar -> adjacente);
	} else {
		removerMeioAresta(auxiliar -> adjacente, destino);
	}
}


void removerInicioVertice(Lista *l){
	No *auxiliar;
	auxiliar = l -> primeiro;
	l -> primeiro = l -> primeiro -> proximo;
	free(auxiliar);
}


void removerFimVertice(Lista *l){
	No *ultimo = l -> primeiro, *penultimo = l -> primeiro;
	while(ultimo->proximo != NULL){
		penultimo = ultimo;
		ultimo = ultimo->proximo;
	}
	penultimo->proximo = NULL;
	l -> ultimo = penultimo;
	free(ultimo);
}

void removerMeioVertice(Lista *l, int id){
	No *atual = l -> primeiro, *anterior = l -> primeiro; 
	while(atual -> id != id){
		anterior = atual;
		atual = atual -> proximo;
	}
	anterior -> proximo = atual -> proximo;
	free(atual);
}

bool removeVertice(Lista *l, int id){
	No *auxiliar = l -> primeiro;
	while(auxiliar != NULL){
		if(auxiliar -> id == id){
			limpaListaAdjacente(auxiliar -> adjacente);
			break;
		}
		auxiliar = auxiliar -> proximo;
	}
	if(auxiliar == l -> primeiro){
		removerInicioVertice(l);		
	} else if (auxiliar -> proximo == NULL){
		removerFimVertice(l);
	} else {
		removerMeioVertice(l, id);
	}
}

bool existeAresta(Lista *l, int origem, int destino){
	No *auxiliar = l -> primeiro;
	noAdjacente *auxiliarAdjacente;
	while(auxiliar != NULL){
		if(auxiliar -> id == origem){
			auxiliarAdjacente = auxiliar -> adjacente ->  primeiro;
			while(auxiliarAdjacente != NULL){
				if(auxiliarAdjacente -> id == destino){
					return true;
				}
				auxiliarAdjacente = auxiliarAdjacente -> proximo;
			}
			return false;
		}
		auxiliar = auxiliar -> proximo;
	}
	return false;
}

bool insereAresta(Lista *l, int origem, int destino, bool tipoGrafo, int peso){
	No *auxiliar = l -> primeiro;
	noAdjacente *auxiliarAdjacente;
	while(auxiliar != NULL){
		if(auxiliar -> id == origem){
			if(vaziaListaAdjacente(auxiliar -> adjacente)){
				if(tipoGrafo){
					inserirListaAdjacente(auxiliar -> adjacente, destino, peso);
				} else {
					inserirListaAdjacente(auxiliar -> adjacente, destino, peso);
					insereAresta(l, destino, origem, tipoGrafo, peso);
				}
				return true;
			} else {
				auxiliarAdjacente = auxiliar -> adjacente -> primeiro;
				while(auxiliarAdjacente != NULL){
					if(auxiliarAdjacente -> id == destino)
						return false;
					auxiliarAdjacente = auxiliarAdjacente -> proximo;
				}
				if(tipoGrafo){
					inserirListaAdjacente(auxiliar -> adjacente, destino, peso);
				} else {
					inserirListaAdjacente(auxiliar -> adjacente, destino, peso);
					insereAresta(l, destino, origem, tipoGrafo, peso);
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
	novoNo -> adjacente = (listaAdjacente*) malloc (sizeof(listaAdjacente));
	inicializarListaAdjacente(novoNo -> adjacente);
	if (vaziaLista(l)){
		l -> primeiro = novoNo;
		l -> ultimo = novoNo;
	} else {
		l -> ultimo -> proximo = novoNo;
		l -> ultimo = novoNo;
	}
	l -> tamanho++;
}

void insereListaOrdenacaoTopologica(Lista *l, int id){
	No *novoNo = (No*) malloc (sizeof(No));
	novoNo -> id = id;
	novoNo -> proximo = NULL;
	novoNo -> adjacente = (listaAdjacente*) malloc (sizeof(listaAdjacente));
	inicializarListaAdjacente(novoNo -> adjacente);
	if (vaziaLista(l)){
		l -> primeiro = novoNo;
		l -> ultimo = novoNo;
	} else {
		novoNo -> proximo = l -> primeiro;
		l -> primeiro = novoNo;
	}
	l -> tamanho++;
}

No *getAdjacente(Lista *l, int id) {
	No *no = l -> primeiro;
	while (no -> id != id)
		no = no -> proximo; 
	return no;
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
			imprimirListaAdjacente(auxiliar -> adjacente, auxiliar -> id);
			auxiliar = auxiliar -> proximo;
		}
	}    
}

void imprimirListaTempo(Lista *l){
	if (vaziaLista(l)){
		printf("Empty list!\n");
	} else {
		No *auxiliar;
		auxiliar = l -> primeiro;
		while (auxiliar != NULL){ 
			printf("Pai: %d\n", auxiliar -> pai);
			printf("Id: %d\n", auxiliar -> id);
			printf("tempoDescoberta: %d\n", auxiliar -> tempoDescoberta);
			printf("tempoFinalizacao: %d\n\n", auxiliar -> tempoFinalizacao);
			auxiliar = auxiliar -> proximo;
		}
	}    
}

void imprimirListaOrdenacaoTopologica(Lista *l){
	if (vaziaLista(l)){
		printf("Empty list!\n");
	} else {
		No *auxiliar;
		auxiliar = l -> primeiro;
		while (auxiliar != NULL){ 
			printf("%d ", auxiliar -> id);
			auxiliar = auxiliar -> proximo;
		}
		printf("\n");
	}    
}
    