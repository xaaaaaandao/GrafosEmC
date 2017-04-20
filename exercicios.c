#include <stdio.h>
#include <stdlib.h>
#include "exercicios.h"
#include "matriz.h"
#include "opcao.h"
#include "telas.h"

/**
	Exercício 1A.
	-> Podemos modelar sendo que o vértice seriamos nós, e as arestas seria quando enviamos
	as "cartas" para o próximo destino assinar até chegar o professor.
**/

/**
	Exercício 1B.
	-> Aplicar a busca em largura para cada vértice.
**/


/**
	Exercício 2.
**/
void matrizAdjacenciaToListaAdjacencia(Lista *l){
	Lista *listaNaoDirigida = (Lista*) malloc (sizeof(Lista));
	inicializarLista(listaNaoDirigida);

	int numeroVertice = nVertice(l);
	int **matriz = (int**) malloc (numeroVertice * sizeof(int*));
	int i, j;
	
	for(i = 0; i < numeroVertice; i++){
		matriz[i] = (int*) malloc (numeroVertice * sizeof(int)); //Aloca um Vetor de Inteiros para cada posição do Vetor de Ponteiros.
 	}

 	matriz = matrizAdjacencia(l, grafoDirigido);

	

 	for(i = 0; i < numeroVertice; i++)
 		inserirLista(listaNaoDirigida);

	for(i = 1; i < numeroVertice + 1; i++){
		for(j = 1; j < numeroVertice + 1; j++){
			if(matriz[i][j] == 1){
				if(i != j)
					insereAresta(listaNaoDirigida, i, j, false, 1);
			}
		}
	}

	telaLimpa();
	telaMatrizAdjacencia();
	for(i = 0; i < numeroVertice + 1; i++){
		for(j = 0; j < numeroVertice + 1; j++){
			printf("%d ", matriz[i][j]);
		}
		printf("\n");
	}

	telaListaAdjacencia();
	imprimirLista(listaNaoDirigida);
}

/**
	Exercício 3 pintando ele de duas cores.
**/

/**
	Exercício 4 já temos uma função que desenvolve isso.
**/

/**
	Exercício 5 usar busca em profundidade para verificar se os filhos tem algum adjacente 
**/

/**
	Exercício 6.
**/
int nAresta(Lista *l){
	No *auxiliar = l -> primeiro;
	noAdjacente *auxiliarAdjacente;
	int numeroAresta = 0;
	
	while(auxiliar != NULL){
		auxiliarAdjacente = auxiliar -> adjacente -> primeiro;
		while(auxiliarAdjacente != NULL){
			numeroAresta++;
			auxiliarAdjacente = auxiliarAdjacente -> proximo;
		}
		auxiliar = auxiliar -> proximo;
	}

	return numeroAresta/2;
}

int nVertice(Lista *l){
	No *auxiliar = l -> primeiro;
	int numeroVertice = 0;
	
	while(auxiliar != NULL){
		numeroVertice++;
		auxiliar = auxiliar -> proximo;
	}

	return numeroVertice;
}

void comparaVerticeAresta(Lista *l, int n){
	int numeroVertice = nVertice(l);
	int numeroAresta = nAresta(l);
	
	if(n > numeroVertice)
		telaNMaiorNVertice();
	else if(n == numeroVertice)
		telaNIgualNVertice();
	else if(n < numeroVertice)
		telaNMenorNVertice();

	if(n > numeroAresta)
		telaNMaiorNAresta();
	else if(n == numeroAresta)
		telaNIgualNAresta();
	else if(n < numeroAresta)
		telaNMenorNAresta();
}

/**
	Exercício 7.
**/