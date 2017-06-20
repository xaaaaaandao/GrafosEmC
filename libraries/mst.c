#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
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

No *extrairMenor(Lista *grafo, Lista *copia){
	int menor = copia -> primeiro -> chave;
	No *auxiliarCopia = copia -> primeiro -> proximo;
	No *auxiliar = grafo -> primeiro -> proximo;
	No *resposta = copia -> primeiro;
	while((auxiliar != NULL) && (auxiliarCopia != NULL)){
		if(menor > auxiliarCopia -> chave){
			menor = auxiliarCopia -> chave;
			resposta = auxiliarCopia;
		}
		auxiliar = auxiliar -> proximo;
		auxiliarCopia = auxiliarCopia -> proximo;
	}
	return resposta;
}


No *retornaNo(Lista *grafo, int id){
	No *auxiliar = grafo -> primeiro;
	while(auxiliar != NULL){
		if(auxiliar -> id == id){
			return auxiliar;
		}
		auxiliar = auxiliar -> proximo;
	}
	return NULL;
}


bool existeNo(Lista *copia, int id){
	No *auxiliar = copia -> primeiro;
	while(auxiliar != NULL){
		if(auxiliar -> id == id){
			return true;
		}
		auxiliar = auxiliar -> proximo;
	}
	return false;
}

void MST_Prim(){
	int i = 0;
	Lista *grafo = (Lista*) malloc (sizeof(Lista));
	Lista *copia = (Lista*) malloc (sizeof(Lista));
	No *auxiliar, *auxiliarCopia, *menor;
	noAdjacente* auxiliarAdjacente;
	
	inicializarLista(grafo);
	inicializarLista(copia);

	grafoDirigido = false;
	grafoPonderado = true;

	for(i = 0; i < 9; i++){
		inserirLista(grafo);
		inserirLista(copia);
	}

	insereAresta(grafo, 1, 2, grafoDirigido, 4);
	insereAresta(grafo, 1, 6, grafoDirigido, 8);
	insereAresta(grafo, 2, 3, grafoDirigido, 8);
	insereAresta(grafo, 2, 6, grafoDirigido, 11);
	insereAresta(grafo, 3, 4, grafoDirigido, 7);
	insereAresta(grafo, 3, 8, grafoDirigido, 4);
	insereAresta(grafo, 3, 9, grafoDirigido, 2);
	insereAresta(grafo, 4, 5, grafoDirigido, 9);
	insereAresta(grafo, 4, 8, grafoDirigido, 14);
	insereAresta(grafo, 5, 8, grafoDirigido, 10);
	insereAresta(grafo, 6, 7, grafoDirigido, 1);
	insereAresta(grafo, 6, 9, grafoDirigido, 7);
	insereAresta(grafo, 7, 8, grafoDirigido, 2);
	insereAresta(grafo, 7, 9, grafoDirigido, 6);

	auxiliar = grafo -> primeiro;
	while(auxiliar != NULL){
		auxiliar -> chave = INT_MAX;
		auxiliar -> pai = -1;
		auxiliar = auxiliar -> proximo;
	}

	auxiliarCopia = copia -> primeiro;
	while(auxiliarCopia != NULL){
		auxiliarCopia -> chave = INT_MAX;
		auxiliarCopia -> pai = -1;
		auxiliarCopia = auxiliarCopia -> proximo;
	}

	grafo -> primeiro -> chave = 0;
	copia -> primeiro -> chave = 0;

	while(!vaziaLista(copia)){
		menor = extrairMenor(grafo, copia);
		printf("%d\n", menor -> id);
		printf("%d\n", menor -> chave);
		No *atual = retornaNo(grafo, menor -> id);
		auxiliarAdjacente = atual -> adjacente -> primeiro;
		while(auxiliarAdjacente != NULL){
			No *atualAdjacente = retornaNo(grafo, auxiliarAdjacente -> id); 
			if((existeNo(copia, auxiliarAdjacente -> id)) && (auxiliarAdjacente -> peso < atualAdjacente -> chave)){
				atualAdjacente -> pai = atual -> id;
				atualAdjacente -> chave = auxiliarAdjacente -> peso;
				retornaNo(copia, auxiliarAdjacente -> id) -> chave  = auxiliarAdjacente -> peso;  
			}
			auxiliarAdjacente = auxiliarAdjacente -> proximo;
		}
		removeVertice(copia, menor -> id);
	}

	auxiliar = grafo -> primeiro;
	while(auxiliar != NULL){
		printf("pai: %d\n", auxiliar -> pai);	
		printf("id: %d\n\n", auxiliar -> id);
		auxiliar = auxiliar -> proximo;
	}
	return;
}


