#ifndef EXERCICIOS_H
#define	EXERCICIOS_H

#define VERTICEVERMELHO 4
#define VERTICEAMARELO 5

#include "lista.h"

void matrizAdjacenciaToListaAdjacencia(Lista*);
int nAresta(Lista*);
int nVertice(Lista*);
void comparaVerticeAresta(Lista*, int);
void ehBiPartido(Lista*);

#endif /* EXERCICIOS_H */