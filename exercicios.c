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
**/
/**
* A função inicializaGrauMaximo(Lista *l, int id) em que 
* inicializamos a fila da busca em largura
* em que pintamos todos os vértices de branco, e inicializamos os
* tempo descoberta, finalização e pai, por fim passamos o id do vértice que vai ser
* enfilerado na fila;
@param l, é do tipo Lista que contém os vértices existentes;
@param id, é do tipo inteiro o identificador a ser enfilerado;
@return f, retorna a fila inicializada.
*/
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

/**
* A função preencheCor(Lista *l, int id, Fila *f, int tempoDescoberta, int pai)
* em que verificamos o vértice adjacente de um determinado vértice, pintamos
* enfileramos ele na fila; 
@param l, é do tipo Lista que contém os vértices existentes;
@param id, é do tipo inteiro que contém o vértice a ser procurado;
@param f, é do tipo Fila que contém os vértices enfilerados;
@param tempoDescoberta, é do tipo inteiro que é o tempo de descoberta;
@param pai, é do tipo inteiro que é o pai daquele vértice;
@return void, retorna nada.
*/
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

/**
* A função realizaGrauMaximo(Lista *l, Fila *f)
* em que desenfileramos da fila os vértices e chamamos as demais funções
* para pintar e descobrir o tempo de descoberta;
@param l, é do tipo Lista que contém os vértices existentes;
@param f, é do tipo Fila que contém os vértices enfilerados;
@return void, retorna nada.
*/
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

/**
* A função copiaLista(Lista *original, Lista *copia)
* em que iremos fazer uma cópia da lista original;
@param l, é do tipo Lista que contém os vértices existentes;
@param copia, é do tipo Lista que contém os vértices existentes que é uma cópia;
@return void, retorna nada.
*/
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

/**
* A função posicaoMaior(int **matriz, int n, int destino)
* em que verificamos o maior elemento daquele linha;
@param matriz, é um arranjo bidimensional de inteiros com o caminho para um determinado vértice;
@param n, é um inteiro que é o tamanho da matriz;
@param destino, é um inteiro que é o identificador do vértice que está sendo procurado;
@return maior, retorna o maior elemento daquela linha da matriz.
*/
int posicaoMaior(int **matriz, int k, int n, int destino){
	int i, j = k, maior = -1;
	for(i = 1; i < n; i++){
		if(matriz[j][i] > maior && i != destino){
			maior = i;
		}
	}
	return maior;
}


/**
* A função existeCaminho(int **matriz, int n, int posicao, int destino)
* em que tentamos achar se existe um caminho;
@param matriz, é um arranjo bidimensional de inteiros com o caminho para um determinado vértice;
@param n, é um inteiro que é o tamanho da matriz;
@param destino, é um inteiro que é o identificador do vértice que está sendo procurado;
@return maior, retorna o maior elemento daquela linha da matriz.
*/
int existeCaminho(int **matriz, int n, int posicao, int destino){
	if(matriz[posicao][destino] == 0){
		return 0;
	} else {
		return matriz[posicao][destino];
	}
}

/**
* A função grauMaximo(Lista *l, int id) em que tentamos achar um grau máximo
* de todos os vértices até uma determinado destino;
@param l, é do tipo Lista que contém os vértices existentes;
@param id, é um inteiro que é o identificador do vértice que está sendo procurado;
@return void, retorna nada.
*/
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
	/*
	for(i = 0; i  < n; i++){
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
		if(k != id){
			//printf("%d\n", k);		
			posicao = posicaoMaior(matriz, k, n, id);
			//printf("posicao: %d\n", posicao);
			existeValor = existeCaminho(matriz, n, posicao, id);
			//printf("existeValor: %d\n", existeValor);
			while(existeValor == 0){
				matriz[k][posicao] = 0;
				posicao = posicaoMaior(matriz, k, n, id);
				//printf("posicao: %d\n", posicao);
				existeValor = existeCaminho(matriz, n, posicao, id);
				//printf("existeValor: %d\n", existeValor);
			}
			grau = matriz[k][posicao] + existeValor;
			if(grau > maior){
				maior = grau;
			}	
		}
		k++;
	}
	telaGrauMaximo(maior);
}

/**
	Exercício 2.
**/
/**
* A função matrizAdjacenciaToListaAdjacencia(Lista *l, int id)
* em que convertemos uma matriz de adjacência de um grafo dirigido
* para uma lista não dirigia;
@param l, é do tipo Lista que contém os vértices existentes;
@return void, retorna nada.
*/
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
					insereAresta(listaNaoDirigida, j, i, false, 1);
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
/**
* A função inicializaBiPartido(Lista *l) inicializamos a fila 
* que nem da busca em largura em que pintamos todos os vértices de Branco,
* e depois disso enfileramos o primeiro vértice e enfileramos;
@param l, é do tipo Lista que contém os vértices existentes;
@return f, retorna Fila já inicializada.
*/
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

/**
* A função preencheAdjacente(Lista *l) pintamos os vértices
* adjacente para verificar se podemos considerar o bipartido;
@param l, é do tipo Lista que contém os vértices existentes;
@param cor, é do tipo inteiro que é a cor a ser verificada;
@param id, é do tipo inteiro que é o identificador ser procurado;
@param f, é do tipo Fila que irá enfilerar os vértices;
@return true ou false, retorna true se conseguiu pintar ou false caso não consiga.
*/
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

/**
* A função realizaTesteBiPartido(Lista *l, Fila *f) em que pintamos 
* todos os vértices que estão na fila;
@param l, é do tipo Lista que contém os vértices existentes;
@param f, é do tipo Fila que contém os vértices enfilerados;
@return true ou false, retorna true se conseguiu pintar ou false caso não consiga.
*/
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

/**
* A função ehBiPartido(Lista *l) em que verificamos
* caso é possível verificar se é bi partido ou não;
@param l, é do tipo Lista que contém os vértices existentes;
@return void, retorna nada.
*/
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
/**
* A função valorTempoDescoberta(Lista *l, int id) em que verificamos
* o tempo de descoberta de um determinado vértice;
@param l, é do tipo Lista que contém os vértices existentes;
@param id, é do tipo inteiro que é o identificador do vértice a ser procurado;
@return inteiro, retorna o tempo de descoberta.
*/
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

/**
* A função verificaFilhos(Lista *l, int id, int tempoDescoberta)
* em que comparamos dois tempos de descoberta;
@param l, é do tipo Lista que contém os vértices existentes;
@param id, é do tipo inteiro que é o identificador do vértice a ser procurado;
@param tempoDescoberta, é do tipo inteiro que é o tempo de descoberta;
@return true ou false, retorna true caso o tempo de descoberta seja maior ou false caso não seja maior.
*/
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

/**
* A função descedenteArestaRetorno(Lista *l, int id)
* em que verificamos se os descendentes de tal vértice tem uma aresta de retorno;
@param l, é do tipo Lista que contém os vértices existentes;
@param id, é do tipo inteiro que é o identificador do vértice a ser procurado;
@return true ou false, retorna true caso o descendente tem aresta de retorno ou false caso não tenha a aresta de retorno.
*/
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
/**
* A função nAresta(Lista *l) em que verificamos 
* a quantidade de aresta de um grafo;
@param l, é do tipo Lista que contém os vértices existentes;
@return numeroAresta, retorna tem o número de arestas.
*/
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
	if(grafoDirigido){
		return numeroAresta;
	} else {
		return numeroAresta/2;
	}
}

/**
* A função nVertice(Lista *l) em que verificamos 
* a quantidade de vértices de um grafo;
@param l, é do tipo Lista que contém os vértices existentes;
@return numeroVertice, retorna tem o número de vértices.
*/
int nVertice(Lista *l){
	No *auxiliar = l -> primeiro;
	int numeroVertice = 0;
	while(auxiliar != NULL){
		numeroVertice++;
		auxiliar = auxiliar -> proximo;
	}
	return numeroVertice;
}

/**
* A função comparaVerticeAresta(Lista *l, int n) em que verificamos 
* se o número de aresta e vértices é maior igual ou igual a n;
@param l, é do tipo Lista que contém os vértices existentes;
@param n, é do tipo inteiro valor a ser comparado;
@return void, retorna nada.
*/
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
