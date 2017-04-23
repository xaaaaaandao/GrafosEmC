#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "busca.h"
#include "componente.h"
#include "exercicios.h"
#include "matriz.h"
#include "opcao.h"
#include "ordenacao.h"
#include "telas.h"

/**
* A função sairPrograma() mensagem para terminar o programa;
@param nenhum, não recebe nenhum parâmetro;
@return void, retorna nada.
*/
void sairPrograma(){
	exit(1);
}

/**
* A função opcaoArestaOrigem(Lista *l) pega o valor de origem da aresta,
* verificando se ele existe;
@param l, do tipo Lista que contém os vértices existentes;
@return opcao, retorna um inteiro com o vértice de origem da aresta.
*/
int opcaoArestaOrigem(Lista *l){
	int opcao;
	telaArestaOrigem();
	scanf(" %d", &opcao);
	if(existeVertice(l, opcao)){
		return opcao;
	} else {
		telaLimpa();		
		telaErro();
		opcaoArestaOrigem(l);
	}
}

/**
* A função opcaoArestaDestino(Lista *l) pega o valor de origem da destino,
* verificando se ele existe;
@param l, do tipo Lista que contém os vértices existentes;
@return opcao, retorna um inteiro com o vértice de destino da aresta.
*/
int opcaoArestaDestino(Lista *l){
	int opcao;
	telaArestaDestino();
	scanf(" %d", &opcao);
	if(existeVertice(l, opcao)){
		return opcao;
	} else {
		telaLimpa();		
		telaErro();
		opcaoArestaDestino(l);
	}	
}

/**
* A função opcaoPesoAresta() pega o peso de uma aresta,
* verificando se o valor é válido;
@param nenhum, não recebe nenhum parâmetro;
@return opcao, retorna um inteiro com o peso da aresta.
*/
int opcaoPesoAresta(){
	int opcao;
	telaPesoAresta();
	scanf(" %d", &opcao);
	if(opcao >= 1){
		return opcao;
	} else {
		telaLimpa();
		telaErro();
		opcaoPesoAresta();
	}
}

/**
* A função opcaoAresta(Lista *l) verifica se a aresta existente,
* se o grafo é dirigido ou não dirigido, se existem vértices;
@param l, do tipo Lista que contém os vértices existentes;
@return void, retorna nada.
*/
void opcaoAresta(Lista *l){
	//quando não tem vértices
	if(vaziaLista(l)){
		telaLimpa();
		telaSemVertice();
	} else {
		//quando tem vértices
		telaLimpa();
		int verticeOrigem = opcaoArestaOrigem(l);
		telaLimpa();
		int verticeDestino = opcaoArestaDestino(l);
		int peso;
		//grafo é ponderado
		if(grafoPonderado){
			peso = opcaoPesoAresta();
		} else {
			peso = 1;
		}
		//quando a aresta não existe
		if((verticeOrigem == verticeDestino) && (grafoDirigido == false)){
			telaLimpa();
			telaErroGrafoNaoDirigido();
		} else if(insereAresta(l, verticeOrigem, verticeDestino, grafoDirigido, peso)){
			telaLimpa();
			telaArestaAdicionado();	
		} else {
			//quando existea a aresta
			telaLimpa();
			telaArestaExistente();
		}
	}
}

/**
* A função opcaoRemoveVertice(Lista *l) verifica se a aresta existente,
* se o grafo é dirigido ou não dirigido, se existem vértices;
@param l, do tipo Lista que contém os vértices existentes;
@return void, retorna nada.
*/
void opcaoRemoveVertice(Lista *l){
	int id;
	telaRemoverVertice();
	scanf(" %d", &id);
	if(vaziaLista(l)){
		telaLimpa();
		telaSemVertice();
	} else if(existeVertice(l, id)){
		removeVertice(l, id);
		No *auxiliar = l -> primeiro;
		while(auxiliar != NULL){
			if(existeAresta(l, auxiliar -> id, id)){
				removeAresta(l, auxiliar -> id, id);
			}
			auxiliar = auxiliar -> proximo;
		}
		telaLimpa();
		telaVerticeRemovido();
	} else {
		telaLimpa();
		telaErro();
		opcaoRemoveVertice(l);
	}
}

/**
* A função opcaoRemoveAresta(Lista *l) verifica se a aresta existente,
* se o grafo é dirigido ou não dirigido, se existem vértices;
@param l, do tipo Lista que contém os vértices existentes;
@return void, retorna nada.
*/
void opcaoRemoveAresta(Lista *l){
	if(vaziaLista(l)){
		telaLimpa();
		telaSemVertice();
	} else {
		//quando tem vértices
		telaLimpa();
		int verticeOrigem = opcaoArestaOrigem(l);
		telaLimpa();
		int verticeDestino = opcaoArestaDestino(l);
		if(existeAresta(l, verticeOrigem, verticeDestino)){
			if(grafoDirigido){
				removeAresta(l, verticeOrigem, verticeDestino);
			} else {
				removeAresta(l, verticeOrigem, verticeDestino);
				removeAresta(l, verticeDestino, verticeOrigem);
			}
			telaLimpa();
			telaArestaRemovido();
		} else {
			telaLimpa();
			telaSemAresta();
			opcaoPrincipal(l);
		}
	}
}

/**
* A função opcaoGrafo() verifica se o grafo é dirigido
* ou não dirigido;
@param nenhum, não recebe nenhum parâmetro;
@return void, retorna nada.
*/
void opcaoGrafo(){
	int opcao;
	telaGrafo();
	scanf(" %d", &opcao);
	switch(opcao){
		case 1:
			telaLimpa();
			grafoDirigido = true;
			telaGrafoEhDirigido();
			break;
		case 2:
			telaLimpa();
			grafoDirigido = false;
			telaGrafoEhNaoDirigido();
			break;
		case 3:
			sairPrograma();
			break;	
		default:
			telaLimpa();		
			telaErro();
			opcaoGrafo();
			break;
	}
}

/**
* A função opcaoGrafoPonderado() verifica se o grafo é ponderado
* ou não ponderado;
@param nenhum, não recebe nenhum parâmetro;
@return void, retorna nada.
*/
void opcaoGrafoPonderado(){
	int opcao;
	telaGrafoPonderado();
	scanf(" %d", &opcao);
	switch(opcao){
		case 1:
			telaLimpa();
			grafoPonderado = true;
			telaGrafoEhPonderado();
			break;
		case 2:
			telaLimpa();
			grafoPonderado = false;
			telaGrafoEhNaoPonderado();
			break;
		case 3:
			sairPrograma();
			break;	
		default:
			telaLimpa();		
			telaErro();
			opcaoGrafoPonderado();
			break;
	}
}

/**
* A função opcaoCarregarArquivo(Lista *l) escolhe se o exemplo
* é grafo dirigido ou não dirigido;
@param l, do tipo Lista que contém os vértices existentes;
@return void, retorna nada.
*/
void opcaoCarregarArquivo(Lista *l){
	int opcao;
	telaExemploCarregaArquivo();
	scanf(" %d", &opcao);
	switch(opcao){
		case 1:
			telaLimpa();
			telaExemploGrafoDirigido();
			exemploGrafoDirigido(l);
			break;
		case 2:
			telaLimpa();
			telaExemploGrafoNaoDirigido();
			exemploGrafoNaoDirigido(l);
			break;
		case 3:
			sairPrograma();
			break;	
		default:
			telaLimpa();		
			telaErro();
			opcaoPrincipal(l);
			break;
	}
}

/**
* A função opcaoValorN() escolhe o valor de N a ser comparado;
@param nenhum, não recebe nenhum parâmetro;
@return valor, retorna um inteiro com o valor de N.
*/
int opcaoValorN(){
	int valor;
	telaValorN();
	scanf(" %d", &valor);
	if(valor > -1){
		return valor;
	} else {
		telaLimpa();
		telaErro();
		opcaoValorN();
	}
}


/**
* A função opcaoVertice(Lista *l) escolhe o identificador do vértice;
@param l, do tipo Lista que contém os vértices existentes;
@return vertice, retorna um inteiro com o valor do identificador do vértice.
*/
int opcaoVertice(Lista *l){
	int vertice;
	telaVertice();
	scanf(" %d", &vertice);
	if(existeVertice(l, vertice)){
		return vertice;
	} else {
		telaLimpa();
		telaErro();
		opcaoVertice(l);
	}
}

/**
* A função opcaoExercicio(Lista *l) escolhe qual função deve ser executada;
@param l, do tipo Lista que contém os vértices existentes;
@return void, retorna nada.
*/
void opcaoExercicio(Lista *l){
	int opcao;
	telaExercicio();
	scanf(" %d", &opcao);
	switch(opcao){
		case 1:
			telaLimpa();
			if(vaziaLista(l)){
				telaSemVertice();
			} else {
				grauMaximo(l, opcaoVertice(l));	
			}
			opcaoPrincipal(l);
			break;
		case 2:
			telaLimpa();
			//se for dirigido
			if(grafoDirigido){
				matrizAdjacenciaToListaAdjacencia(l);	
			} else {
				telaGrafoDeveDirigido();
			}
			opcaoPrincipal(l);
			break;	
		case 3:
			telaLimpa();
			ehBiPartido(l);
			opcaoPrincipal(l);
			break;	
		case 4:
			telaLimpa();
			if(iniciarBuscaEmProfundidade(l)){
				telaGrafoCiclico();
			} else {
				telaGrafoAciclico();
			}
			opcaoPrincipal(l);
			break;	
		case 5:
			telaLimpa();
			if(descendenteArestaRetorno(l, opcaoVertice(l))){
				telaDescedenteTemArestaRetorno();
			} else {
				telaDescedenteNaoTemArestaRetorno();
			}
			opcaoPrincipal(l);
			break;
		case 6:
			telaLimpa();
			comparaVerticeAresta(l, opcaoValorN());
			opcaoPrincipal(l);
			break;		
		case 7:
			telaLimpa();
			if(vaziaLista(l)){
				telaSemVertice();
			} else if(grafoDirigido == false){
				telaCFCDirigido();
			} else {
				telaComponenteFortementeConexa();
				componenteFortementeConexa(l);
			}
			opcaoPrincipal(l);
			break;	
		case 8:
			sairPrograma();
			break;	
		default:
			telaLimpa();		
			telaErro();
			opcaoPrincipal(l);
			break;
	}
}

/**
* A função opcaoPrincipal(Lista *l) escolhe qual função deve ser executada;
@param l, do tipo Lista que contém os vértices existentes;
@return void, retorna nada.
*/
void opcaoPrincipal(Lista *l){
	int opcao;
	telaPrincipal();
	scanf(" %d", &opcao);
	switch(opcao){
		case 1:
			inserirLista(l);
			imprimirLista(l);
			telaLimpa();
			telaVerticeAdicionado(l -> tamanho - 1);
			opcaoPrincipal(l);
			break;
		case 2:
			opcaoAresta(l);
			opcaoPrincipal(l);
			break;
		case 3:
			telaLimpa();
			if(vaziaLista(l)){
				telaSemVertice();
			} else {
				telaMatrizAdjacencia();
				imprimirMatrizAdjacencia(l, grafoPonderado);
			}
			opcaoPrincipal(l);
			break;	
		case 4:
			telaLimpa();
			if(vaziaLista(l)){
				telaSemVertice();
			} else {
				telaListaAdjacencia();
				imprimirLista(l);
			}
			opcaoPrincipal(l);
			break;	
		case 5:
			telaLimpa();
			opcaoCarregarArquivo(l);
			opcaoPrincipal(l);
			break;	
		case 6:
			telaLimpa();
			if(vaziaLista(l)){
				telaSemVertice();
			} else {
				opcaoRemoveVertice(l);
			}
			opcaoPrincipal(l);
			break;
		case 7:
			telaLimpa();
			if(vaziaLista(l)){
				telaSemVertice();
			} else {
				opcaoRemoveAresta(l);
			}
			opcaoPrincipal(l);
			break;		
		case 8:
			telaLimpa();
			if(vaziaLista(l)){
				telaSemVertice();
			} else {
				buscaLargura(l);
				imprimirListaTempo(l);	
			}
			opcaoPrincipal(l);
			break;	
		case 9:
			telaLimpa();
			if(vaziaLista(l)){
				telaSemVertice();
			} else {
				buscaProfundidade(l);
			}
			opcaoPrincipal(l);
			break;	
		case 10:
			telaLimpa();
			if(vaziaLista(l)){
				telaSemVertice();
			} else {
				telaOrdenacaoTopologica();
				ordenacaoTopologica(l);
			}
			opcaoPrincipal(l);
			break;	
		case 11:
			telaLimpa();
			if(vaziaLista(l)){
				telaSemVertice();
			} else if(iniciarBuscaEmProfundidade(l)){
				telaGrafoCiclico();
			} else {
				telaGrafoAciclico();
			}
			opcaoPrincipal(l);
			break;
		case 12:
			telaLimpa();
			if(vaziaLista(l)){
				telaSemVertice();
			} else if(grafoDirigido == false){
				telaCFCDirigido();
			} else {
				telaComponenteFortementeConexa();
				componenteFortementeConexa(l);
			}
			opcaoPrincipal(l);
			break;
		case 13:
			telaLimpa();
			if(vaziaLista(l)){
				telaSemVertice();
			} else {
				opcaoExercicio(l);
			}
			opcaoPrincipal(l);
			break;			
		case 14:
			telaLimpa();
			if(vaziaLista(l)){
				telaSemVertice();
			} else {
				telaPaiETempos();
				imprimirListaTempo(l);
			}
			opcaoPrincipal(l);
			break;	
		case 15:
			telaLimpa();
			if(vaziaLista(l)){
				telaSemVertice();
			} else {
				opcaoGrafo();
				opcaoGrafoPonderado();
				telaGrafoResetado();
				limpaTodasLista(l);
			}
			opcaoPrincipal(l);
			break;	
		case 16:
			sairPrograma();
			break;	
		default:
			telaLimpa();		
			telaErro();
			opcaoPrincipal(l);
			break;
	}
}