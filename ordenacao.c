#include <stdio.h>
#include <stdlib.h>
#include "busca.h"
#include "lista.h"
#include "opcao.h"
#include "ordenacao.h"
#include "telas.h"

/**
* A função ordenacaoRealizarBuscaProfundidade(Lista *l, No *no, Lista *listaOrdenacaoTopologica)
* adicionamos cada vértice que é finalizado no início de uma lista, verificando seus adjacentes;
@param l, do tipo Lista que contém os vértices existentes;
@param no, do tipo No que contém o nó do vértice para verificar os adjacentes;
@param listaOrdenacaoTopologica, do tipo Lista que contém os vértices ordenados topologicamente;
@return void, retorna nada.
*/
void ordenacaoRealizarBuscaProfundidade(Lista *l, No *no, Lista *listaOrdenacaoTopologica) {
	static bool ciclico = false;
	tempoOrdenacao++;
	no -> tempoDescoberta = tempoOrdenacao;
	no -> cor = Cinza;
	noAdjacente *aux = no -> adjacente -> primeiro;
	No *auxiliar;
	while (aux != NULL) {
		auxiliar = getAdjacente(l, aux -> id);
		if (auxiliar -> cor == Branco) {
			auxiliar -> pai = no -> id;
			ordenacaoRealizarBuscaProfundidade(l, auxiliar, listaOrdenacaoTopologica);
		} 
		aux = aux -> proximo;
	}
	no -> cor = Preto;
	tempoOrdenacao++;
	no -> tempoFinalizacao = tempoOrdenacao;
	insereListaOrdenacaoTopologica(listaOrdenacaoTopologica, no -> id);
}

/**
* A função ordenacaoIniciarBuscaProfundidade(Lista *l, Lista *listaOrdenacaoTopologica)
* adicionamos cada vértice que é finalizado no início de uma lista;
@param l, do tipo Lista que contém os vértices existentes;
@param listaOrdenacaoTopologica, do tipo Lista que contém os vértices ordenados topologicamente;
@return void, retorna nada.
*/
void ordenacaoIniciarBuscaProfundidade(Lista *l, Lista *listaOrdenacaoTopologica) {
	No *auxiliar = l -> primeiro;
	while(auxiliar != NULL){
		auxiliar -> cor = Branco;
		auxiliar -> tempoDescoberta = -1;
		auxiliar -> tempoFinalizacao = -1;
		auxiliar -> pai = -1;
		auxiliar = auxiliar -> proximo;
	}
	auxiliar = l -> primeiro;
	while(auxiliar != NULL){
		if (auxiliar -> cor == Branco) {
			ordenacaoRealizarBuscaProfundidade(l, auxiliar, listaOrdenacaoTopologica);
		}
		auxiliar = auxiliar -> proximo;
	}	
}

/**
* A função ordenacaoTopologica(Lista *l) verifica se o grafo é dirigido
* e tem ciclico ou aciclico;
@param l, do tipo Lista que contém os vértices existentes;
@return void, retorna nada.
*/
void ordenacaoTopologica(Lista *l){
	//É aciclico
	if(iniciarBuscaEmProfundidade(l) == false && grafoDirigido){
		tempoOrdenacao = 0;
		Lista *listaOrdenacaoTopologica = (Lista*) malloc (sizeof(Lista));
		inicializarLista(listaOrdenacaoTopologica);
		ordenacaoIniciarBuscaProfundidade(l, listaOrdenacaoTopologica);
		printf("      ");
		imprimirListaOrdenacaoTopologica(listaOrdenacaoTopologica);
		printf("\n");
	} else {
		telaOrdenacaoTopologicaCiclico();
	}
}