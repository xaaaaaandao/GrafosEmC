#ifndef EXERCICIOS_H
#define	EXERCICIOS_H

/* Definindo alguns valores */
#define VERTICEVERMELHO 4
#define VERTICEAMARELO 5

/* Bibliotecas necessárias */
#include "fila.h"
#include "lista.h"

/* Protótipo das funções */
Fila *inicializaGrauMaximo(Lista*, int);
void preencheCor(Lista*, int, Fila *, int, int);
void realizaGrauMaximo(Lista*, Fila *);
void copiaLista(Lista*, Lista *);
int posicaoMaior(int **, int, int, int);
int existeCaminho(int **, int, int, int);
void grauMaximo(Lista*, int);
void matrizAdjacenciaToListaAdjacencia(Lista*);
Fila *inicializaBiPartido(Lista*);
bool preencheAdjacente(Lista*, int, int, Fila*);
bool realizaTesteBiPartido(Lista*, Fila*);
void ehBiPartido(Lista*);
int valorTempoDescoberta(Lista*, int);
bool verificaFilhos(Lista*, int, int);
bool descendenteArestaRetorno(Lista *, int);
int nAresta(Lista*);
int nVertice(Lista*);
void comparaVerticeAresta(Lista*, int);

#endif /* EXERCICIOS_H */
