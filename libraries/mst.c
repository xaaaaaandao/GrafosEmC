#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "busca.h"
#include "opcao.h"
#include "matriz.h"
#include "mst.h"

int maiorPeso(Lista *l){
	int maior, maiorFinal = -1;
	No *auxiliar = l -> primeiro;
	noAdjacente* auxiliarAdjacente;
	while(auxiliar != NULL){
		maior = auxiliar -> adjacente -> primeiro -> peso;
		auxiliarAdjacente = auxiliar -> adjacente -> primeiro -> proximo;
		while(auxiliarAdjacente != NULL){
			if(maior < auxiliarAdjacente -> peso){
				maior = auxiliarAdjacente -> peso;
			}
			auxiliarAdjacente = auxiliarAdjacente -> proximo;
		}
		if((maiorFinal == -1) || (maior > maiorFinal)){
			maiorFinal = maior;
		}
		auxiliar = auxiliar -> proximo;
	}
	return maiorFinal;
}

int menorPeso(Lista *l){
	int menor, menorFinal = -1;
	No *auxiliar = l -> primeiro;
	noAdjacente* auxiliarAdjacente;
	while(auxiliar != NULL){
		menor = auxiliar -> adjacente -> primeiro -> peso;
		auxiliarAdjacente = auxiliar -> adjacente -> primeiro -> proximo;
		while(auxiliarAdjacente != NULL){
			if(menor > auxiliarAdjacente -> peso){
				menor = auxiliarAdjacente -> peso;
			}
			auxiliarAdjacente = auxiliarAdjacente -> proximo;
		}
		if((menorFinal == -1) || (menor < menorFinal)){
			menorFinal = menor;
		}
		auxiliar = auxiliar -> proximo;
	}
	return menorFinal;
}


Lista *MST_Kruskal(Lista *l){
	Lista *resultado = (Lista*) malloc (sizeof(Lista));
	int i, j, origem, destino, troca;
	int menor = menorPeso(l), maior = maiorPeso(l);
	No *auxiliar = l -> primeiro, *auxiliarResposta;
	noAdjacente* auxiliarAdjacente;
	int **matriz = (int**) malloc ((l -> tamanho - 1) * sizeof(int*));
	
	for(i = 0; i < (l -> tamanho - 1); i++){
		matriz[i] = (int*) malloc ((l -> tamanho - 1) * sizeof(int)); //Aloca um Vetor de Inteiros para cada posição do Vetor de Ponteiros.
 	}

	inicializarLista(resultado);
	
	while(auxiliar != NULL){
		if(menor == maior + 1)
			break;
		origem, destino = 0;
		auxiliarAdjacente = auxiliar -> adjacente -> primeiro;
		while(auxiliarAdjacente != NULL){
			if(menor == auxiliarAdjacente -> peso){
				origem = auxiliar -> id;
				destino = auxiliarAdjacente -> id;
				auxiliar = l -> primeiro;
				break;
			}
			auxiliarAdjacente = auxiliarAdjacente -> proximo;
		}
		if(auxiliar -> proximo == NULL){
			menor++;
			auxiliar = l -> primeiro;
		} else if(origem, destino > 0){
			printf("origem: %d\n", origem);
					printf("destino: %d\n\n", destino);
					
			if(destino < origem){
				troca = destino;
				destino = origem;
				origem = troca;
			}
			printf("dorigem: %d\n", origem);
			printf("ddestino: %d\n", destino);
					
			if(vaziaLista(resultado)){
				for(i = 0; i < l -> tamanho - 1; i++)
					inserirLista(resultado);

				auxiliarResposta = resultado -> primeiro;
				insereAresta(resultado, origem, destino, grafoDirigido, menor);
			} else {
				//falta verficar o ciclo
			}
			removeAresta(l, origem, destino);
			removeAresta(l, destino, origem);
		}
		auxiliar = auxiliar -> proximo;
	}
	imprimirLista(resultado);
}