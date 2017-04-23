#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "opcao.h"
#include "telas.h"

/**
* A função exemploGrafoNaoDirigido(Lista *l) em que já definimos
* os vértices e arestas de um grafo não dirgido;
@param l, é do tipo Lista que contem os vértices existentes;
@return void, retorna nada.
*/
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
/*	for(i = 0; i < 8; i++){
		inserirLista(l);
	}
	insereAresta(l, 1, 2, grafoDirigido, 1);
	insereAresta(l, 1, 3, grafoDirigido, 1);
	insereAresta(l, 2, 3, grafoDirigido, 1);
	insereAresta(l, 2, 5, grafoDirigido, 1);
	insereAresta(l, 4, 5, grafoDirigido, 1);
	insereAresta(l, 5, 2, grafoDirigido, 1);
	insereAresta(l, 5, 4, grafoDirigido, 1);
	insereAresta(l, 5, 6, grafoDirigido, 1);
	insereAresta(l, 6, 7, grafoDirigido, 1);*/
}

/**
* A função exemploGrafoDirigido(Lista *l) em que já definimos
* os vértices e arestas de um grafo dirgido;
@param l, é do tipo Lista que contem os vértices existentes;
@return void, retorna nada.
*/
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
	/* Exemplo: retirar quando não tem ordenação topológica */
	//insereAresta(l, 4, 1, grafoDirigido, 1);
	insereAresta(l, 5, 4, grafoDirigido, 1);

}

/**
* A função removerFimAresta(listaAdjacente *l) em que
* removemos o último vértice da lista de adjacência.;
@param l, é do tipo listaAdjacedente que contem os vértices adjacentes existentes;
@return void, retorna nada.
*/
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

/**
* A função removerMeioAresta(listaAdjacente *l, int id) em que 
* removemos o vértice que está no meio da lista de adjacência;
@param l, é do tipo listaAdjacedente que contem os vértices adjacentes existentes;
@return void, retorna nada.
*/
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

/**
* A função removerInicioAresta(listaAdjacente *l) em que 
* removemos o vértice que está no início da lista de adjacência;
@param l, é do tipo listaAdjacedente que contem os vértices adjacentes existentes;
@return void, retorna nada.
*/
void removerInicioAresta(listaAdjacente* l){
	noAdjacente *auxiliar;
	auxiliar = l -> primeiro;
	l -> primeiro = l -> primeiro -> proximo;
	l -> primeiro -> anterior = NULL;
	free(auxiliar);
}

/**
* A função removeAresta(listaAdjacente *l, int origem, int destino) em que 
* removemos um vértice que está na lista de adjacência;
@param l, é do tipo Lista que contem os vértices existentes;
@param int, é do tipo inteiro é o vértice de origem a ser removido;
@param int, é do tipo inteiro é o vértice de destino a ser removido;
@return void, retorna nada.
*/
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

/**
* A função removerInicioVertice(Lista *l) em que 
* removemos um vértice que está no início da lista;
@param l, é do tipo Lista que contem os vértices existentes;
@return void, retorna nada.
*/
void removerInicioVertice(Lista *l){
	No *auxiliar;
	auxiliar = l -> primeiro;
	l -> primeiro = l -> primeiro -> proximo;
	free(auxiliar);
}

/**
* A função removerFimVertice(Lista *l) em que 
* removemos um vértice que está no fim da lista;
@param l, é do tipo Lista que contem os vértices existentes;
@return void, retorna nada.
*/
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

/**
* A função removerMeioVertice(Lista *l, int id) em que 
* removemos um vértice que está no meio da lista;
@param l, é do tipo Lista que contem os vértices existentes;
@param id, é do tipo inteiro que é o vértice a ser removido;
@return void, retorna nada.
*/
void removerMeioVertice(Lista *l, int id){
	No *atual = l -> primeiro, *anterior = l -> primeiro; 
	while(atual -> id != id){
		anterior = atual;
		atual = atual -> proximo;
	}
	anterior -> proximo = atual -> proximo;
	free(atual);
}

/**
* A função removeVertice(Lista *l, int id) em que 
* removemos um vértice que está na lista;
@param l, é do tipo Lista que contem os vértices existentes;
@param id, é do tipo inteiro que é o vértice a ser removido;
@return true ou false, retorna booleano true caso consiga remover ou false caso não consiga.
*/
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

/**
* A função existeAresta(Lista *l, int origem, int destino) em que 
* verificamos se existe uma aresta;
@param l, é do tipo Lista que contem os vértices existentes;
@param origem, é do tipo inteiro que é o vértice de origem da aresta;
@param destino, é do tipo inteiro que é o vértice de destino da aresta;
@return true ou false, retorna booleano true caso consiga exista ou false caso não exista.
*/
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

/**
* A função insereAresta(Lista *l, int origem, int destino, bool tipoGrafo, int peso) em que 
* inserimos uma aresta;
@param l, é do tipo Lista que contem os vértices existentes;
@param origem, é do tipo inteiro que é o vértice de origem da aresta;
@param destino, é do tipo inteiro que é o vértice de destino da aresta;
@param tipoGrafo, é do tipo booleano se o grafo é dirigido ou não dirigido;
@param peso, é do tipo inteiro que é o peso da aresta;
@return true ou false, retorna booleano true caso consiga adicionar ou false caso não adicionar.
*/
bool insereAresta(Lista *l, int origem, int destino, bool tipoGrafo, int peso){
	No *auxiliar = l -> primeiro;
	noAdjacente *auxiliarAdjacente;
	while(auxiliar != NULL){
		if(auxiliar -> id == origem){
			if(vaziaListaAdjacente(auxiliar -> adjacente)){
				if(grafoDirigido){
					inserirListaAdjacente(auxiliar -> adjacente, destino, peso);
				} else {
					inserirListaAdjacente(auxiliar -> adjacente, destino, peso);
					insereAresta(l, destino, origem, grafoDirigido, peso);
				}
				return true;
			} else {
				auxiliarAdjacente = auxiliar -> adjacente -> primeiro;
				while(auxiliarAdjacente != NULL){
					if(auxiliarAdjacente -> id == destino)
						return false;
					auxiliarAdjacente = auxiliarAdjacente -> proximo;
				}
				if(grafoDirigido){
					inserirListaAdjacente(auxiliar -> adjacente, destino, peso);
				} else {
					inserirListaAdjacente(auxiliar -> adjacente, destino, peso);
					insereAresta(l, destino, origem, grafoDirigido, peso);
				}	
				return true;		
			}
		}
		auxiliar = auxiliar -> proximo;
	}
	return false;
}

/**
* A função existeVeritce(Lista *l, int id) em que 
* verificamos se o vértice existe;
@param l, é do tipo Lista que contem os vértices existentes;
@param id, é do tipo inteiro que é o identificador vértice para verificar se ele existe;
@return true ou false, retorna booleano true caso exista ou false caso não exista.
*/
bool existeVertice(Lista *l, int id){
	No *auxiliar = l -> primeiro;
	while(auxiliar != NULL){
		if(auxiliar -> id == id)
			return true;
		auxiliar = auxiliar -> proximo;
	}
	return false;
}


/**
* A função limpaListaAdjacente(listaAdjacente *l) em que 
* limpamos a lista de adjacência;
@param l, é do tipo listaAdjacedente que contem os vértices adjacentes existentes;
@return void, retorna nada.
*/
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

/**
* A função limpaLista(Lista *l) em que 
* limpamos a lista de vértices;
@param l, é do tipo Lista que contem os vértices existentes;
@return void, retorna nada.
*/
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

/**
* A função limpaTodasLista(Lista *l) em que 
* limpamos a lista de vértices e a lista de adjacência;
@param l, é do tipo Lista que contem os vértices existentes;
@return void, retorna nada.
*/
void limpaTodasLista(Lista *l){
	No *auxiliar = l -> primeiro;
	while(auxiliar != NULL){
		limpaListaAdjacente(auxiliar -> adjacente);
		auxiliar = auxiliar -> proximo;
	}
	limpaLista(l);
	l = (Lista*) malloc (sizeof(Lista));
	inicializarLista(l);
}

/**
* A função inicializarListaAdjacente(listaAdjacente *l) em que 
* inicializamos a lista de vértices adjacência;
@param l, é do tipo listaAdjacencia que contem os vértices adjacentes existentes;
@return void, retorna nada.
*/
void inicializarListaAdjacente(listaAdjacente *l){
	l -> primeiro = NULL;
	l -> ultimo = NULL;
	l -> tamanho = 1;
}

/**
* A função inicializarLista(Lista *l) em que 
* inicializamos a lista de vértices;
@param l, é do tipo Lista que contem os vértices existentes;
@return void, retorna nada.
*/
void inicializarLista(Lista *l){
	l -> primeiro = NULL;
	l -> ultimo = NULL;
	l -> tamanho = 1;
}

/**
* A função vaziaListaAdjacente(listaAdjacente *l) em que 
* verificamos se  a lista de vértices adjacentes está vazia;
@param l, é do tipo listaAdjacente que contém os vértices adjacentes existentes;
@return inteiro, retorna 0 se está vazia ou qualquer outro valor caso tenha vértices.
*/
int vaziaListaAdjacente(listaAdjacente *l){
	return (l -> primeiro == NULL);
}  

/**
* A função vaziaLista(Lista *l) em que 
* verificamos se  a lista de vértices está vazia;
@param l, é do tipo Lista que contém os vértices existentes;
@return inteiro, retorna 0 se está vazia ou qualquer outro valor caso tenha vértices.
*/
int vaziaLista(Lista *l){
	return (l -> primeiro == NULL);
}  

/**
* A função inserirListaAdjacente(listaAdjacente *l) em que 
* inserimos os vértices adjacentes de forma ordenada;
@param l, é do tipo listaAdjacente que contem os vértices adjacentes existentes;
@param id, é do tipo inteiro é o identificar do vértice a ser adicionado;
@param inteiro, é do tipo inteiro que o valor do peso da aresta;
@return void, retorna nada.
*/
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

/**
* A função inserirLista(Lista *l) em que inserimos os vértices ;
@param l, é do tipo Lista que contem os vértices existentes;
@return void, retorna nada.
*/
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

/**
* A função inserirListaOrdenacaoTopologica(Lista *l, int id) em que inserimos os vértices
* em ordem topológica;
@param l, é do tipo Lista que contem os vértices existentes;
@param id, é do tipo inteiro que é o identificador do vértice adicionado;
@return void, retorna nada.
*/
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

/**
* A função getAdjacente(Lista *l, int id) em que procuramos um vértice
* e retornamos ele;
@param l, é do tipo Lista que contem os vértices existentes;
@param id, é do tipo inteiro que é o identificador do vértice a ser procurado;
@return no, retorna um nó da lista.
*/
No *getAdjacente(Lista *l, int id) {
	No *no = l -> primeiro;
	while (no -> id != id)
		no = no -> proximo; 
	return no;
}

/**
* A função tamanhoListaAdjacente(listaAdjacente *l) em que retornamos o 
* tamanho da lista de adjacência;
@param l, é do tipo listaAdjacente que contem os vértices adjacentes existentes;
@return inteiro, retorna o tamanho da lista.
*/
int tamanhoListaAdjacente(listaAdjacente *l){
	return (l -> tamanho);
}

/**
* A função tamanhoLista(Lista *l) em que retornamos o 
* tamanho da lista;
@param l, é do tipo listaAdjacente que contem os vértices adjacentes existentes;
@return inteiro, retorna o tamanho da lista.
*/
int tamanhoLista(Lista *l){
	return (l -> tamanho);
}

/**
* A função imprimirListaAdjacente(listaAdjacente *l, int id) em que imprimos 
* a lista de adjacência;
@param l, é do tipo listaAdjacente que contem os vértices adjacentes existentes;
@param id, é do tipo inteiro que contem o identificador do vértice de origem;
@return void, retorna nada.
*/
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

/**
* A função imprimirLista(Lista *l) em que imprimos 
* a lista de vértices e seu adjacentes;
@param l, é do tipo Lista que contem os vértices existentes;
@return void, retorna nada.
*/
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

/**
* A função imprimirListaTempo(Lista *l) em que imprimos 
* a lista de vértices com os tempos de descoberta e tempo de finalização;
@param l, é do tipo Lista que contem os vértices existentes;
@return void, retorna nada.
*/
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

/**
* A função imprimirListaOrdenacaoTopologica(Lista *l) em que imprimos 
* os vértices em ordem topológica;
@param l, é do tipo Lista que contem os vértices existentes;
@return void, retorna nada.
*/
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
    