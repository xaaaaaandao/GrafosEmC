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
Fila *inicializaGrauMaximo(Lista *l, int id){
	Fila *f = (Fila*) malloc (sizeof(Fila));
	No *auxiliar = l -> primeiro;
	inicializarFila(f);
	while(auxiliar != NULL){
		auxiliar -> cor = Branco;
		auxiliar -> tempoDescoberta = -1;
		auxiliar -> pai = -1;
		auxiliar = auxiliar -> proximo;
	}
	auxiliar = l -> primeiro;
	while(auxiliar != NULL){
		if(auxiliar -> id == id){
			auxiliar -> cor = Cinza;
			auxiliar -> tempoDescoberta = 0;
			auxiliar -> pai = -1;
		}
		auxiliar = auxiliar -> proximo;
	}
	enfilerarFila(f, id);
	return f;
}

void preencheCor(Lista *l, int id, Fila *f, int tempoDescoberta, int pai){
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

void realizaGrauMaximo(Lista *l, Fila *f){
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
					preencheCor(l, auxiliarAdjacente -> id, f, auxiliar -> tempoDescoberta, id);
					auxiliarAdjacente = auxiliarAdjacente -> proximo;
				}
				break;
			}
			auxiliar = auxiliar -> proximo;
		}
		auxiliar -> cor = Preto;
	}
}

void copiaLista(Lista *original, Lista *copia){
	int i, n = nVertice(original);
	No *auxiliar = original -> primeiro;
	noAdjacente *auxiliarAdjacente;
	for(i = 0; i < n; i++){
		inserirLista(copia);
	}
	while(auxiliar != NULL){
		auxiliarAdjacente = auxiliar -> adjacente -> primeiro;
		while(auxiliarAdjacente != NULL){
			insereAresta(copia, auxiliar -> id, auxiliarAdjacente -> id, grafoDirigido, auxiliarAdjacente -> peso);
			auxiliarAdjacente = auxiliarAdjacente -> proximo;
		}
		auxiliar = auxiliar -> proximo;
	}
}

int posicaoMaior(int **matriz, int n, int destino){
	int i, j = 1, maior = -1;
	for(i = 1; i < n; i++){
		if(matriz[j][i] > maior && i != destino){
			maior = i;
		}
	}
	return maior;
}

int existeCaminho(int **matriz, int n, int posicao, int destino){
	int i, j;
	for(i = 1; i < n; i++){
		if(i == destino){
			if(matriz[posicao][i] == 0){
				return 0;
			} else {
				return matriz[posicao][i];
			}
		}
	}
}

void grauMaximo(Lista *l, int id){
	int i, j, k, posicao, n = nVertice(l) + 1, maior = -1;
	Lista *copia = (Lista*) malloc (sizeof(Lista));
	Fila *filaBuscaLargura;
	No *auxiliar = l -> primeiro, *colocaMatriz;
	int **matriz = (int**) malloc (n * sizeof(int*));
	for(i = 0; i < n; i++){
		matriz[i] = (int*) malloc (n * sizeof(int)); //Aloca um Vetor de Inteiros para cada posição do Vetor de Ponteiros.
 	}
	inicializarMatriz(matriz, n);
	inicializarLista(copia);
	copiaLista(l, copia);
	while(auxiliar != NULL){
		filaBuscaLargura = inicializaGrauMaximo(l, auxiliar -> id);
		realizaGrauMaximo(l , filaBuscaLargura);
		colocaMatriz = l -> primeiro;
		while(colocaMatriz != NULL){
			if(colocaMatriz -> tempoDescoberta == -1){
				matriz[auxiliar -> id][colocaMatriz -> id] = 0;
			} else {
				matriz[auxiliar -> id][colocaMatriz -> id] = colocaMatriz -> tempoDescoberta;
			}
			colocaMatriz = colocaMatriz -> proximo;
		}
		l = copia;
		limpaFila(filaBuscaLargura);
		filaBuscaLargura = (Fila*) malloc (sizeof(Fila));
		auxiliar = auxiliar -> proximo;
	}
	/*for(i = 0; i  < n; i++){
		for(j = 0; j < n; j++){
			printf("%d ", matriz[i][j]);
		}
		printf("\n");
	}*/
	//matriz[3][8] = 0;
	k = 1;
	maior = -1;
	int grau, existeValor;
	while(k < n){
		posicao = posicaoMaior(matriz, n, id);
		//printf("posicao: %d\n", posicao);
		existeValor = existeCaminho(matriz, n, posicao, id);
		//printf("existeValor: %d\n", existeValor);
		while(existeValor == 0){
			matriz[k][posicao] = 0;
			posicao = posicaoMaior(matriz, n, id);
			//printf("posicao: %d\n", posicao);
			existeValor = existeCaminho(matriz, n, posicao, id);
			//printf("existeValor: %d\n", existeValor);
		}
		grau = matriz[k][posicao] + existeValor;
		if(grau > maior){
			maior = grau;
			//printf("k: %d\n", k);
			//printf("posicao: %d\n", posicao);
		}
		k++;
	}
	printf("maior: %d\n", maior);
}

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
