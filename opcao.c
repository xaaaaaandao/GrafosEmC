#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "busca.h"
#include "matriz.h"
#include "opcao.h"
#include "telas.h"

bool grafoDirigido;
bool grafoPonderado;

/* Sai do programa */

void sairPrograma(){
	exit(1);
}

/* Vértice de origem da aresta */
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

/* Vértice de destino da aresta */
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

/* Peso da aresta */
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

/* Adiciona uma nova aresta */
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
			//printf("Origem: %d\n", verticeOrigem);
			//printf("Destino: %d\n", verticeDestino);	
		} else {
			//quando existea a aresta
			telaLimpa();
			telaArestaExistente();
		}
	}
}

/* Verifica qual vértice remover */
void opcaoRemoveVertice(Lista *l){
	int id;
	telaRemoverVertice();
	scanf(" %d", &id);
	if(vaziaLista(l)){
		telaLimpa();
		telaSemVertice();
	} else if(existeVertice(l, id)){
		removeVertice(l, id);
		telaLimpa();
		telaVerticeRemovido();
	} else {
		telaLimpa();
		telaErro();
		opcaoRemoveVertice(l);
	}
}

/* Verifica qual aresta quer remover */
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
			opcaoSecundario(l);
		}
	}
}

/* Verifica se é um grafo dirigido ou não */
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

/* Verificar se é grafo ponderado ou não */
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

/* Verificar se quer usar os exemplos */
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
			opcaoSecundario(l);
			break;
	}
}

/* Verifica se deseja continuar ou sair */
void opcaoSecundario(Lista *l){
	int opcao;
	telaContinuar();
	scanf(" %d", &opcao);
	switch(opcao){
		case 1:
			telaLimpa();
			opcaoPrincipal(l);
			break;
		case 2:
			sairPrograma();
			break;	
		default:
			telaLimpa();		
			telaErro();
			opcaoSecundario(l);
			break;
	}
}

/* Chama as demais funções */
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
			opcaoSecundario(l);
			break;
		case 2:
			opcaoAresta(l);
			opcaoSecundario(l);
			break;
		case 3:
			telaLimpa();
			if(vaziaLista(l)){
				telaSemVertice();
			} else {
				telaMatrizAdjacencia();
				imprimirMatrizAdjacencia(l, grafoPonderado);
			}
			opcaoSecundario(l);
			break;	
		case 4:
			telaLimpa();
			if(vaziaLista(l)){
				telaSemVertice();
			} else {
				telaListaAdjacencia();
				imprimirLista(l);
			}
			opcaoSecundario(l);
			break;	
		case 5:
			telaLimpa();
			opcaoCarregarArquivo(l);
			opcaoSecundario(l);
			break;	
		case 6:
			telaLimpa();
			if(vaziaLista(l)){
				telaSemVertice();
			} else {
				opcaoRemoveVertice(l);
			}
			opcaoSecundario(l);
			break;
		case 7:
			telaLimpa();
			if(vaziaLista(l)){
				telaSemVertice();
			} else {
				opcaoRemoveAresta(l);
			}
			opcaoSecundario(l);
			break;		
		case 8:
			telaLimpa();
			if(vaziaLista(l)){
				telaSemVertice();
			} else {
				buscaLargura(l);	
			}
			opcaoSecundario(l);
			break;	
		case 9:
			telaLimpa();
			if(vaziaLista(l)){
				telaSemVertice();
			} else {
				buscaProfundidade(l);
			}
			opcaoSecundario(l);
			break;	
		case 10:
			telaLimpa();
			if(vaziaLista(l)){
				telaSemVertice();
			} else {
				printf("Ordenação topológica\n");
			}
			opcaoSecundario(l);
			break;	
		case 11:
			telaLimpa();
			if(vaziaLista(l)){
				telaSemVertice();
			} else if(inicializaBuscaLargura(l)){
				telaGrafoCiclico();
			} else {
				telaGrafoAciclico();
			}
			opcaoSecundario(l);
			break;
		case 12:
			sairPrograma();
			break;	
		default:
			telaLimpa();		
			telaErro();
			opcaoPrincipal(l);
			break;
	}
}