#include <stdio.h>
#include <stdlib.h>
#include "busca.h"
#include "exercicios.h"
#include "lista.h"
#include "matriz.h"
#include "opcao.h"

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

void listaTransposta(Lista *l, int **matriz, int tamanho){
	int i, j;
	for(i = 0; i < tamanho - 1; i++)
		inserirLista(l);
	for(i = 1; i < tamanho; i++){
		for(j = 1; j < tamanho; j++){
			if(matriz[i][j] == 1)
				insereAresta(l, i, j, grafoDirigido, 1);
		}
	}
}

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
		//printf("tempoFinalizacao: %d\n", maior);
		//printf("id: %d\n", auxiliarZerado -> id);
		maior = -1;
		n--;
	}
}

void componenteFortementeConexa(Lista *l){
	Lista *lTransposta = (Lista*) malloc (sizeof(Lista));
	No *auxiliar;
	inicializarLista(lTransposta);
	int numeroVertice = nVertice(l) + 1;
	int **matriz = (int**) malloc (numeroVertice * sizeof(int*));
	int **matrizDestino = (int**) malloc (numeroVertice * sizeof(int*));	
	int i, j;
	int vetorID[numeroVertice];
	int numeroPai = 0;
	
	//pego a matriz
	for(i = 0; i < numeroVertice; i++){
		matriz[i] = (int*) malloc (numeroVertice * sizeof(int)); //Aloca um Vetor de Inteiros para cada posição do Vetor de Ponteiros.
		matrizDestino[i] = (int*) malloc (numeroVertice * sizeof(int));
 	}
	
	//inicializo a busca em profundidade
	buscaProfundidade(l);
	//ordeno a busca em profundidade em tempo de finalização
	ordemDecrescenteFinalizacao(l, numeroVertice, vetorID);

	//faço a transposta dela
	matriz = matrizAdjacencia(l, grafoDirigido);
	matrizTranspota(matriz, matrizDestino, numeroVertice);

	//pego a matriz transposta e coloco essa matriz nunma lista
	listaTransposta(lTransposta, matrizDestino, numeroVertice);

	//Realizo a busca em profundidade
	auxiliar = lTransposta -> primeiro;
	while(auxiliar != NULL){
		auxiliar -> cor = Branco;
		auxiliar -> tempoDescoberta = -1;
		auxiliar -> tempoFinalizacao = -1;
		auxiliar -> pai = -1;
		auxiliar = auxiliar -> proximo;
	}

	tempo = 0;
	//pegar os tempos de finalizacao
	for(i = 0; i < numeroVertice - 1; i++){
		auxiliar = lTransposta -> primeiro;
		while(auxiliar != NULL){
			if(vetorID[i] == auxiliar -> id && auxiliar -> cor == Branco){
				BuscaEmProfundidade(lTransposta, auxiliar);
			}
			auxiliar = auxiliar -> proximo;
		}
		
	}

	auxiliar = lTransposta -> primeiro;
	while(auxiliar != NULL){
		if(auxiliar -> pai == -1){
			numeroPai++;
		}
		auxiliar = auxiliar -> proximo;
	}
	
	printf("número de componentes fortemente conexas %d\n", numeroPai);
	//imprimirListaTempo(lTransposta);
}