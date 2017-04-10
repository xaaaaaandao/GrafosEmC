#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "matriz.h"
#include "opcao.h"
#include "telas.h"

bool grafoDirigido;
bool grafoPonderado;

void sairPrograma(){
	exit(1);
}

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
	}
}

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
	}
}

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

int opcaoPesoAresta(){
	int opcao;
	telaPesoAresta();
	scanf(" %d", &opcao);
	if(opcao > 0){
		return opcao;
	} else {
		telaLimpa();
		telaErro();
		opcaoPesoAresta();
	}
}

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
		} else {
			telaLimpa();
			telaSemAresta();
			opcaoSecundario(l);
		}
	}
}

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
	}
}

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
			printf("Carregar arquivo\n");
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
			sairPrograma();
			break;	
		default:
			telaLimpa();		
			telaErro();
			opcaoPrincipal(l);
	}
}