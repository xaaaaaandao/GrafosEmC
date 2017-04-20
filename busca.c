#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "busca.h"
#include "telas.h"



int numeroFilho(Lista *l, int id){
	int numeroFilho = 0;
	No *auxiliar = l -> primeiro;	
	
	while(auxiliar != NULL){
		if(auxiliar -> pai == id)
			numeroFilho++;
		auxiliar = auxiliar -> proximo;
	}

	return numeroFilho;
}

void imprimeArvore(Lista *l){
	No *auxiliarPai = l -> primeiro;
	No *auxiliarFilho;	
	int nFilho;

	while(auxiliarPai != NULL){

		nFilho = numeroFilho(l, auxiliarPai -> id);
		
		//nó raíz e folha
		if(auxiliarPai -> pai == -1 & nFilho == 0){
			printf("%d raíz e folha ->", auxiliarPai -> id);

		//nó raíz e pai
		} else if(auxiliarPai -> pai == -1 & nFilho > 0){
			printf("%d raíz e pai ->", auxiliarPai -> id);			

		//pai de alguém 
		} else if (nFilho > 0) {
			printf("%d pai ->", auxiliarPai -> id);

		//é folha
		} else if (nFilho == 0){
			printf("%d é folha.\n", auxiliarPai -> id);					
		}

		auxiliarFilho = l -> primeiro;
		while(auxiliarFilho != NULL){
			if(auxiliarFilho -> pai == auxiliarPai -> id){
				if(nFilho == 1){
					printf(" %d.\n", auxiliarFilho -> id);					
				} else {
					printf(" %d,", auxiliarFilho -> id);
					nFilho--;
				}
			}
			auxiliarFilho = auxiliarFilho -> proximo;
		}

		auxiliarPai = auxiliarPai -> proximo;
	}
}

/* Operações da busca em profundidade */

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

bool iniciarBuscaEmProfundidade(Lista *l) {

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

	return ciclico;
}

void buscaProfundidade(Lista *l){
	bool ciclico = iniciarBuscaEmProfundidade(l);
	No *aux = l->primeiro;
	No *auxiliar;
	
	while(aux != NULL) {
		if(aux -> pai == -1)
			printf("Raíz e Pai: %d\n", aux -> id);
		else 
			printf("Pai: %d\n", aux -> id);
		auxiliar = l -> primeiro;
		while (auxiliar != NULL) {
			if (auxiliar -> pai == aux -> id)
				printf("Filho: %d\n", auxiliar -> id);
			auxiliar = auxiliar -> proximo;
		}
		aux = aux -> proximo;
	}

	telaBuscaEmProfundidade();

	imprimeArvore(l);
}

/* Operações da busca em largura */

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

	telaBuscaEmLargura();
	imprimeArvore(l);
}