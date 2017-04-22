#include <stdio.h>
#include <stdlib.h>
#include "busca.h"
#include "lista.h"
#include "opcao.h"
#include "ordenacao.h"
#include "telas.h"

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