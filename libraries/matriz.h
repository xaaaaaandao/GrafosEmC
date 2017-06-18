#ifndef MATRIZ_H
#define	MATRIZ_H

/* Bibliotecas necessárias */
#include <stdbool.h>
#include "lista.h"

/* Protótipo das funções */
void inicializarMatriz();
int **matrizAdjacencia(Lista*, bool);
void imprimirMatrizAdjacencia(Lista*, bool);


#endif /* MATRIZ_H */