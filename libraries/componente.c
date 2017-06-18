#include <stdio.h>
#include <stdlib.h>
#include "busca.h"
#include "componente.h"
#include "exercicios.h"
#include "matriz.h"
#include "opcao.h"
#include "telas.h"

/**
* A função matrizTransposta(int **matrizOrigem, int **matrizDestino, int tamanho)
* em que fazemos a tranposta de um dado vértice;
@param matrizOrigem, é um arranjo bidimensional de inteiros é a matriz que vai ser tranposta;
@param matrizDestino, é um arranjo bidimensional de inteiros é matriz tranpsota;
@param tamanho, é um inteiro com o tamanho da matriz;
@return void, retorna nada.
*/
void matrizTranspota(int** matrizOrigem, int **matrizDestino, int tamanho){
	int i, j;
	for(i = 0; i < tamanho; i++){
		for(j = 0; j < tamanho; j++){
			matrizDestino[i][j] = matrizOrigem[i][j];
		}
	}
	for(i = 1; i < tamanho; i++){
		for(j = 1; j < tamanho; j++){
			matrizDestino[i][j] = matrizOrigem[j][i];
		}
	}
}

/**
* A função listaTransposta(Lista *l, int **matriz, int tamanho)
* em que pegamos a matriz que foi tranposta e convertemos na nossa lista que contém os vértices;
@param l, é do tipo Lista que contém os existentes;
@param matrizDestino, é um arranjo bidimensional de inteiros é matriz tranpsota;
@param tamanho, é um inteiro com o tamanho da matriz;
@return void, retorna nada.
*/
void listaTransposta(Lista *l, int **matriz, int tamanho){
	int i, j;
	for(i = 0; i < tamanho - 1; i++)
		inserirLista(l);
	for(i = 1; i < tamanho; i++){
		for(j = 1; j < tamanho; j++){
			if(matriz[i][j] >= 1){
				insereAresta(l, i, j, grafoDirigido, 1);
			}
		}
	}
}

/**
* A função ordemDecrescente(Lista *l, int numeroVertice, int vetorID[])
* colocamos em uma vetor a ordem decrescente de tempo de finalização
* os identificadores dos vértices;
@param l, é do tipo Lista que contém os vértices existentes;
@param numeroVertice, é um inteiro com a quantidade de vértices;
@param vetorId, é um arranjo unidimensional  de inteiro com os identificadores em ordem decrescente;
@return void, retorna nada.
*/
void ordemDecrescenteFinalizacao(Lista *l, int numeroVertice, int vetorID[]){
	Lista *lAuxiliar = (Lista*) malloc (sizeof(Lista));
	No *auxiliar = l -> primeiro, *auxiliarCopia, *auxiliarZerado;
	int n = numeroVertice - 1, maior = -1, i, j = 0;
	inicializarLista(lAuxiliar);
	for(i = 0; i < numeroVertice - 1; i++)
		inserirLista(lAuxiliar); 
	auxiliarCopia = lAuxiliar -> primeiro;
	while(auxiliar != NULL){
		auxiliarCopia -> pai = auxiliar -> pai;
		auxiliarCopia -> tempoDescoberta = auxiliar -> tempoDescoberta;
		auxiliarCopia -> tempoFinalizacao = auxiliar -> tempoFinalizacao;
		auxiliarCopia -> cor = auxiliar -> cor;
		auxiliar = auxiliar -> proximo;
		auxiliarCopia = auxiliarCopia -> proximo;
	}
	while(n > 0){
		auxiliarCopia = lAuxiliar -> primeiro;
		while(auxiliarCopia != NULL){
			if(auxiliarCopia -> tempoFinalizacao > maior){
				maior = auxiliarCopia -> tempoFinalizacao;
				auxiliarZerado = auxiliarCopia;
			}
			auxiliarCopia = auxiliarCopia -> proximo;
		}
		auxiliarZerado -> tempoFinalizacao = -1;
		vetorID[j] = auxiliarZerado -> id;
		j++;
		maior = -1;
		n--;
	}
}

/**
* A função componenteFortementeConexa(Lista *l) em que realizamos
* a busca em profundidade, grafo transposto e chamamos a busca em 
* profundidade passando no grafo transposto em ordem decrescente.
@param l, é do tipo Lista que contém os vértices existentes;
@return void, retorna nada.
*/
void componenteFortementeConexa(Lista *l){
	Lista *lTransposta = (Lista*) malloc (sizeof(Lista));
	No *auxiliar;
	int i, j, numeroPai = 0, numeroVertice = nVertice(l) + 1, vetorID[numeroVertice];
	int **matriz = (int**) malloc (numeroVertice * sizeof(int*));
	int **matrizDestino = (int**) malloc (numeroVertice * sizeof(int*));	
	inicializarLista(lTransposta);	
	for(i = 0; i < numeroVertice; i++){
		matriz[i] = (int*) malloc (numeroVertice * sizeof(int)); //Aloca um Vetor de Inteiros para cada posição do Vetor de Ponteiros.
		matrizDestino[i] = (int*) malloc (numeroVertice * sizeof(int));
 	}
	buscaProfundidade(l);
	ordemDecrescenteFinalizacao(l, numeroVertice, vetorID);
	matriz = matrizAdjacencia(l, grafoDirigido);
	matrizTranspota(matriz, matrizDestino, numeroVertice);
	listaTransposta(lTransposta, matrizDestino, numeroVertice);
	auxiliar = lTransposta -> primeiro;
	while(auxiliar != NULL){
		auxiliar -> cor = Branco;
		auxiliar -> tempoDescoberta = -1;
		auxiliar -> tempoFinalizacao = -1;
		auxiliar -> pai = -1;
		auxiliar = auxiliar -> proximo;
	}
	//imprimirLista(lTransposta);
	//exit(1);
	tempo = 0;
	for(i = 0; i < numeroVertice - 1; i++){
		//printf("-> %d \n", vetorID[i]);
		auxiliar = lTransposta -> primeiro;
		while(auxiliar != NULL){
			//printf("vetorID[i]: %d\n", vetorID[i]);
			//printf("auxiliar -> id %d\n", auxiliar -> id);
			//printf("auxiliar -> cor: %d\n\n", auxiliar -> cor);
			if(vetorID[i] == auxiliar -> id && auxiliar -> cor == Branco){
				BuscaEmProfundidade(lTransposta, auxiliar);
			}
			auxiliar = auxiliar -> proximo;
		}		
	}
	auxiliar = lTransposta -> primeiro;
	numeroPai = 0;
	while(auxiliar != NULL){
		if(auxiliar -> pai == -1){
			numeroPai++;
		}
		auxiliar = auxiliar -> proximo;
	}
	telaLimpa();
	telaQtdComponenteFConexa(numeroPai);	

	//exit(1);
}