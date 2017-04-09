#ifndef LISTA_H
#define	LISTA_H

#include <stdbool.h>

typedef struct noadjacente{
	int id;
	int peso;
	struct noadjacente *anterior;
	struct noadjacente *proximo;
}noAdjacente;

typedef struct{
	noAdjacente *primeiro, *ultimo;
	int tamanho;
}listaAdjacente;

typedef struct no{
	int id;
	listaAdjacente *adjacente; 
	struct no *proximo;
}No;

typedef struct{
	No *primeiro, *ultimo;
	int tamanho;
}Lista;

void removerInicioVertice(Lista*);
bool existeAresta(Lista*, int, int);
bool removeVertice(Lista*, int);
bool insereAresta(Lista*, int, int, bool, int);
void limpaListaAdjacente(listaAdjacente*);
void limpaLista(Lista*);
void inicializarListaAdjacente(listaAdjacente*);
void inicializarLista(Lista*);
int vaziaListaAdjacente(listaAdjacente*);
int vaziaLista(Lista*);
void inserirListaAdjacente(listaAdjacente*, int, int);
void inserirLista(Lista*);
int tamanhoListaAdjacente(listaAdjacente*);
int tamanhoLista(Lista*);
void imprimirListaAdjacente(listaAdjacente*, int);
void imprimirLista(Lista*);


#endif /* LISTA_H */