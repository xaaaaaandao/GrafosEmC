#ifndef LISTA_H
#define	LISTA_H

/* Bibliotecas necessárias */
#include <stdbool.h>

/* Definindo enumerator */
enum coresVertices{Branco = 1, Cinza = 2, Preto = 3, Vermelho = 4, Amarelo = 5} Cores;

/* Definindo algumas estruturas */
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
	int pai;
	int tempoDescoberta;
	int tempoFinalizacao;
	enum coresVertices cor;
	int id;
	listaAdjacente *adjacente; 
	struct no *proximo;
}No;

typedef struct{
	No *primeiro, *ultimo;
	int tamanho;
}Lista;

/* Protótipo das funções */
void exemploGrafoNaoDirigido(Lista *l);
void exemploGrafoDirigido(Lista*);
void removerFimAresta(listaAdjacente *l);
void removerMeioAresta(listaAdjacente*, int);
void removerInicioAresta(listaAdjacente*);
void removeAresta(Lista*, int, int);
void removerInicioVertice(Lista*);
void removerFimVertice(Lista*);
void removerMeioVertice(Lista*, int);
bool removeVertice(Lista*, int);
bool existeAresta(Lista*, int, int);
bool insereAresta(Lista*, int, int, bool, int);
bool existeVertice(Lista*, int);
void limpaListaAdjacente(listaAdjacente*);
void limpaLista(Lista *l);
void limpaTodasLista(Lista*);
void inicializarListaAdjacente(listaAdjacente*);
void inicializarLista(Lista*);
int vaziaListaAdjacente(listaAdjacente*);
int vaziaLista(Lista*);
void inserirListaAdjacente(listaAdjacente*, int, int);
void inserirLista(Lista*);
void insereListaOrdenacaoTopologica(Lista*, int);
No *getAdjacente(Lista*, int);
int tamanhoListaAdjacente(listaAdjacente*);
int tamanhoLista(Lista*);
void imprimirListaAdjacente(listaAdjacente*, int);
void imprimirLista(Lista*);
void imprimirListaTempo(Lista*);
void imprimirListaOrdenacaoTopologica(Lista*);

#endif /* LISTA_H */