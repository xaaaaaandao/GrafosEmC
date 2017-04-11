#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "fila.h"
#include <stdbool.h>


bool BuscaEmProfundidade(Lista *l, No *no) {

	static int tempo = 0;
	static bool ciclico = false;

	tempo++;
	no -> tempoDescoberta = tempo;
	no -> cor = Cinza;

	noAdjacente *aux = no -> adjacente -> primeiro;
	No *auxiliar;

	while (aux != NULL) {
		auxiliar = getAdjacente(l, aux -> id);
		if (auxiliar -> cor == Branco) {
			auxiliar -> pai = no -> id;
			BuscaEmProfundidade(l, auxiliar);
		} else if (auxiliar -> cor == Cinza){
			ciclico = true;
		}
		aux = aux -> proximo;
	}

	no -> cor = Preto;
	tempo++;
	no -> tempoFinalizacao = tempo;

	return ciclico;
}

void iniciarBuscaEmProfundidade(Lista *l) {

	No *auxiliar = l -> primeiro;
	bool ciclico;

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
			ciclico = BuscaEmProfundidade(l, auxiliar);
		}
		auxiliar = auxiliar -> proximo;
	}	

	auxiliar = l -> primeiro;

	while(auxiliar != NULL){
		
		printf("\nid: %d\n", auxiliar -> id);
		printf("pai: %d\n", auxiliar -> pai);
		printf("tempo Descoberta: %d\n", auxiliar -> tempoDescoberta);
		printf("tempo Finalizacao: %d\n", auxiliar -> tempoFinalizacao);
		printf("cor: %d\n", auxiliar -> cor);

		auxiliar = auxiliar -> proximo;
	}	

	if (ciclico) 
		printf("Grafo Ciclico\n");
	else
		printf("Grafo Aciclico\n");

}

Fila *inicializaBuscaLargura(Lista *l){
	Fila *f = (Fila*) malloc (sizeof(Fila));
	No *auxiliar = l -> primeiro;

	inicializarFila(f);

	while(auxiliar != NULL){
		auxiliar -> cor = Branco;
		auxiliar -> tempoDescoberta = -1;
		auxiliar -> pai = -1;
		auxiliar = auxiliar -> proximo;
	}

	l -> primeiro -> cor = Cinza;
	l -> primeiro -> tempoDescoberta = 0;
	l -> primeiro -> pai = -1;
	
	enfilerarFila(f, l -> primeiro -> id);
	return f;
}

//coloca os valores e enfilerar
void preencheCorValorEnfilera(Lista *l, int id, Fila *f, int tempoDescoberta, int pai){
	No *auxiliar = l -> primeiro;
	while(auxiliar != NULL){
		if(auxiliar -> id == id && auxiliar -> cor == Branco){
			auxiliar -> pai = pai;
			auxiliar -> cor = Cinza;
			auxiliar -> tempoDescoberta = tempoDescoberta + 1;
			enfilerarFila(f, id);
		}
		auxiliar = auxiliar -> proximo;
	}
}


void realizaBuscaLargura(Lista *l, Fila *f){
	No *auxiliar;
	noAdjacente *auxiliarAdjacente;
	int id;
	while(!vaziaFila(f)){
		id = desenfilerarFila(f);
		auxiliar = l -> primeiro;
		while(auxiliar != NULL){
			if(auxiliar -> id == id){
				auxiliarAdjacente = auxiliar -> adjacente -> primeiro;
				while(auxiliarAdjacente != NULL){
					preencheCorValorEnfilera(l, auxiliarAdjacente -> id, f, auxiliar -> tempoDescoberta, id);
					auxiliarAdjacente = auxiliarAdjacente -> proximo;
				}
				break;
			}
			auxiliar = auxiliar -> proximo;
		}
		auxiliar -> cor = Preto;
	}
}

void buscaLargura(Lista *l){
	Fila *filaBuscaLargura = inicializaBuscaLargura(l);
	realizaBuscaLargura(l , filaBuscaLargura);
	No *auxiliar = l -> primeiro;
	while(auxiliar != NULL){
		printf("id: %d\n", auxiliar -> id);
		printf("pai: %d\n", auxiliar -> pai);
		printf("tempoDescoberta: %d\n", auxiliar -> tempoDescoberta);
		printf("cor: %d\n\n", auxiliar -> cor);
		auxiliar = auxiliar -> proximo;
	}
}