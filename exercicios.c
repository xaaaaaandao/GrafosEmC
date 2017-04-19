#include <stdio.h>
#include "exercicios.h"
#include "telas.h"

//Se eu usar a busca em profundidade eu vou ter um resultado, se eu usar a busca em largura outro, qual usar?
int grauSaida(Lista *l, int id){
	int grau = 0;
	No *auxiliar = l -> primeiro;
	noAdjacente *auxiliarAdjacente;

	while(auxiliar != NULL){
		if(auxiliar -> id == id){
			auxiliarAdjacente = auxiliar -> adjacente -> primeiro;
			while(auxiliarAdjacente != NULL){
				grau++;
				auxiliarAdjacente = auxiliarAdjacente -> proximo;
			}
			return grau;
		}
		auxiliar = auxiliar -> proximo;
	}
	return -1;
}

int grauEntrada(Lista *l, int id){
	int grau = 0;
	No *auxiliar = l -> primeiro;
	noAdjacente *auxiliarAdjacente;

	while(auxiliar != NULL){
		if(auxiliar -> id == id){
			auxiliarAdjacente = auxiliar -> adjacente -> primeiro;
			while(auxiliarAdjacente != NULL){
				grau++;
				auxiliarAdjacente = auxiliarAdjacente -> proximo;
			}
			return grau;
		}
		auxiliar = auxiliar -> proximo;
	}
	return -1;
}

int grauMaximo(Lista *l, int origem, int destino){

}

/**
	Exercício 4 já temos uma função que desenvolve isso.
**/

//exercício 7
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