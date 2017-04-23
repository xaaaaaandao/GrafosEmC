#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "busca.h"
#include "telas.h"

/**
* A função numeroFilho(Lista *l, int id) em que dado um vértice 
* verificamos a quantidade de vértices adjacentes existente;
@param l, é do tipo Lista que contém os vértices existentes;
@param id, é um inteiro com o identificador do vértice a ser verificado o filho;
@return numeroFilho, retorna um inteiro com número de filhos de um vértice.
*/
int numeroFilho(Lista *l, int id){
	int numeroFilho = 0;
	No *auxiliar = l -> primeiro;	
	while(auxiliar != NULL){
		if(auxiliar -> pai == id){
			numeroFilho++;
		}
		auxiliar = auxiliar -> proximo;
	}
	return numeroFilho;
}

/**
* A função imprimeArevore(Lista *l, int id) em que imprimimos
* a árvore com base nos pais que foram achados na busca;
@param l, é do tipo Lista que contém os vértices existentes;
@return void, retorna nada.
*/
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
		} else if (nFilho > 0){
			printf("%d pai ->", auxiliarPai -> id);
		//é folha
		} else if (nFilho == 0){
			printf("%d é folha.\n", auxiliarPai -> id);					
			printf("============================\n");
		}
		auxiliarFilho = l -> primeiro;
		while(auxiliarFilho != NULL){
			if(auxiliarFilho -> pai == auxiliarPai -> id){
				if(nFilho == 1){
					printf(" %d.\n", auxiliarFilho -> id);
					printf("============================\n");
				} else {
					printf(" %d,", auxiliarFilho -> id);
					nFilho--;
				}
			}
			auxiliarFilho = auxiliarFilho -> proximo;
		}
		printf("\n");
		auxiliarPai = auxiliarPai -> proximo;
	}
}

/**
* A função BuscaEmProfundidade(Lista *l, No *no) em que  
* verificamos os adjacentes de um determinado vértice;
@param l, é do tipo Lista que contém os vértices existentes;
@param no, é um tipo No com vértice a ser verificado seus adjacentes;
@return ciclico, retorna true se é aciclico ou false se é aciclico.
*/
bool BuscaEmProfundidade(Lista *l, No *no) {
	static bool ciclico = false;
	tempo++;
	no -> tempoDescoberta = tempo;
	no -> cor = Cinza;
	noAdjacente *auxiliarAdjacente = no -> adjacente -> primeiro;
	No *auxiliar;
	while (auxiliarAdjacente != NULL) {
		auxiliar = getAdjacente(l, auxiliarAdjacente -> id);
		if (auxiliar -> cor == Branco) {
			auxiliar -> pai = no -> id;
			BuscaEmProfundidade(l, auxiliar);
		} else if (auxiliar -> cor == Cinza){
			ciclico = true;
		}
		auxiliarAdjacente = auxiliarAdjacente -> proximo;
	}
	no -> cor = Preto;
	tempo++;
	no -> tempoFinalizacao = tempo;
	return ciclico;
}

/**
* A função iniciarBuscaEmProfundidade(Lista *l) em que pintamos
* todos os vértices, incializamos com os tempos, e depois disso chamamos todos os vértices
* para que todos os vértices sejam procurados;
@param l, é do tipo Lista que contém os vértices existentes;
@return ciclico, retorna true se é aciclico ou false se é aciclico.
*/
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
		if (auxiliar -> cor == Branco){
			ciclico = BuscaEmProfundidade(l, auxiliar);
		}
		auxiliar = auxiliar -> proximo;
	}	
	return ciclico;
}

/**
* A função buscaEmProfundidade(Lista *l) em que chamamos 
* as demais funções de busca em profundidade e após isso imprimimos a árvore;
@param l, é do tipo Lista que contém os vértices existentes;
@return void, retorna nada.
*/
void buscaProfundidade(Lista *l){
	tempo = 0;
	iniciarBuscaEmProfundidade(l);
	telaBuscaEmProfundidade();
	imprimeArvore(l);
}

/**
* A função inicializaBuscaLargura(Lista *l) em que 
* inicializamos a fila da busca em largura
* em que pintamos todos os vértices de branco, e inicializamos os
* tempo descoberta, finalização e pai;
@param l, é do tipo Lista que contém os vértices existentes;
@return f, retorna a fila inicializada.
*/
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

/**
* A função preencheCorValorEnfilera(Lista *l, int id, Fila *f, int tempoDescoberta, int pai)
* em que verificamos o vértice adjacente de um determinado vértice, pintamos
* enfileramos ele na fila; 
@param l, é do tipo Lista que contém os vértices existentes;
@param id, é do tipo inteiro que contém o vértice a ser procurado;
@param f, é do tipo Fila que contém os vértices enfilerados;
@param tempoDescoberta, é do tipo inteiro que é o tempo de descoberta;
@param pai, é do tipo inteiro que é o pai daquele vértice;
@return void, retorna nada.
*/
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

/**
* A função realizaBuscaLargura(Lista *l, Fila *f)
* em que desenfileramos da fila os vértices e chamamos as demais funções
* para pintar e descobrir o tempo de descoberta;
@param l, é do tipo Lista que contém os vértices existentes;
@param f, é do tipo Fila que contém os vértices enfilerados;
@return void, retorna nada.
*/
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

/**
* A função buscaLargura(Lista *l) em que chamamos as demais
* funções para realizar a busca em largura;
@param l, é do tipo Lista que contém os vértices existentes;
@return void, retorna nada.
*/
void buscaLargura(Lista *l){
	Fila *filaBuscaLargura = inicializaBuscaLargura(l);
	realizaBuscaLargura(l , filaBuscaLargura);
	telaBuscaEmLargura();
	imprimeArvore(l);
}