#ifndef MATRIZ_H
#define	MATRIZ_H

#include <stdbool.h>
#include "lista.h"

void inicializarMatriz();
int **matrizAdjacencia(Lista*, bool);
void imprimirMatrizAdjacencia(Lista*, bool);


#endif /* MATRIZ_H */