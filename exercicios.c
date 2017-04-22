#include <stdio.h>
#include <stdlib.h>
#include "busca.h"
#include "exercicios.h"
#include "fila.h"
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
	int i, j, numeroVertice = nVertice(l);
	int **matriz = (int**) malloc (numeroVertice * sizeof(int*));
	inicializarLista(listaNaoDirigida);
	for(i = 0; i < numeroVertice; i++){
		matriz[i] = (int*) malloc (numeroVertice * sizeof(int)); //Aloca um Vetor de Inteiros para cada posição do Vetor de Ponteiros.
 	}
 	matriz = matrizAdjacencia(l, grafoDirigido);
 	for(i = 0; i < numeroVertice; i++){
 		inserirLista(listaNaoDirigida);
 	}
	for(i = 1; i < numeroVertice + 1; i++){
		for(j = 1; j < numeroVertice + 1; j++){
			if(matriz[i][j] == 1){
				if(i != j){
					insereAresta(listaNaoDirigida, i, j, false, 1);
				}
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
Fila *inicializaBiPartido(Lista *l){
	Fila *f = (Fila*) malloc (sizeof(Fila));
	No *auxiliar = l -> primeiro;
	inicializarFila(f);
	while(auxiliar != NULL){
		auxiliar -> cor = Branco;
		auxiliar = auxiliar -> proximo;
	}
	l -> primeiro -> cor = Vermelho;
	enfilerarFila(f, l -> primeiro -> id);
	return f;
}

bool preencheAdjacente(Lista *l, int cor, int id, Fila *f){
	No *auxiliar = l -> primeiro;
	while(auxiliar != NULL){
		if(auxiliar -> id == id){
			if(auxiliar -> cor == Branco){
				if(cor == VERTICEVERMELHO){
					auxiliar -> cor = Amarelo;
				} else if(cor == VERTICEAMARELO){
					auxiliar -> cor = Vermelho;
				}
				enfilerarFila(f, id);
			} else if(auxiliar -> cor == cor){
				return false;
			} else if(((auxiliar -> cor == Vermelho) && (cor ==VERTICEAMARELO)) || ((auxiliar -> cor == Vermelho) && (cor ==VERTICEAMARELO))){
				return true;
			}
		}
		auxiliar = auxiliar -> proximo;
	}
	return true;
}

bool realizaTesteBiPartido(Lista *l, Fila *f){
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
					if(preencheAdjacente(l, auxiliar -> cor, auxiliarAdjacente -> id, f) == false){
						return false;	
					}
					auxiliarAdjacente = auxiliarAdjacente -> proximo;
				}
				break;
			}
			auxiliar = auxiliar -> proximo;
		}
		auxiliar -> cor = Preto;
	}
	return true;
}

void ehBiPartido(Lista *l){
	Fila *fila = inicializaBiPartido(l);
	if(realizaTesteBiPartido(l , fila)){
		telaGrafoBiPartido();
	} else  {
		telaGrafoNaoBiPartido();
	}
}

/**
	Exercício 4 já temos uma função que desenvolve isso.
**/

/**
	Exercício 5 usar busca em profundidade para verificar se os filhos tem algum adjacente 
**/
int valorTempoDescoberta(Lista *l, int id){
	No *auxiliar = l -> primeiro;
	while(auxiliar != NULL){
		if(auxiliar -> id == id){
			return auxiliar -> tempoDescoberta;
		}
		auxiliar = auxiliar -> proximo;
	}
	return -1;
}

bool verificaFilhos(Lista *l, int id, int tempoDescoberta){
	No *auxiliar = l -> primeiro;
	noAdjacente *auxiliarAdjacente;
	while(auxiliar != NULL){
		if(auxiliar -> id == id){
			auxiliarAdjacente = auxiliar -> adjacente -> primeiro;
			while(auxiliarAdjacente != NULL){
				if(auxiliar -> tempoDescoberta > valorTempoDescoberta(l, auxiliarAdjacente -> id)){
					return true;
				}
				auxiliarAdjacente = auxiliarAdjacente -> proximo;
			}
		}
		auxiliar = auxiliar -> proximo;
	}
	return false;
}

bool descendenteArestaRetorno(Lista *l, int id){
	buscaProfundidade(l);
	telaLimpa();
	No *auxiliar = l -> primeiro;
	int tempoDescoberta, tempoFinalizacao;
	while(auxiliar != NULL){
		if(auxiliar -> id == id){
			if(auxiliar -> pai == -1){
				return false;
			} else {			
				tempoDescoberta = auxiliar -> tempoDescoberta;
				tempoFinalizacao = auxiliar -> tempoFinalizacao;
				break;	
			}
		}
		auxiliar = auxiliar -> proximo;
	}
	auxiliar = l -> primeiro;
	while(auxiliar != NULL){
		if(auxiliar -> tempoDescoberta > tempoDescoberta && auxiliar -> tempoFinalizacao < tempoFinalizacao){
			if(vaziaListaAdjacente(auxiliar -> adjacente)){
				break;
			}
			if(verificaFilhos(l, auxiliar -> id, tempoDescoberta)){
				return true;
			}
		}
		auxiliar = auxiliar -> proximo;
	}
	return false;
}

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
	if(n > numeroVertice){
		telaNMaiorNVertice();
	} else if(n == numeroVertice){
		telaNIgualNVertice();
	} else if(n < numeroVertice){
		telaNMenorNVertice();
	}
	if(n > numeroAresta){
		telaNMaiorNAresta();
	} else if(n == numeroAresta){
		telaNIgualNAresta();
	} else if(n < numeroAresta){
		telaNMenorNAresta();
	}
}

/**
	Exercício 7 já temos uma função que desenvolve isso.
**/
