#ifndef COMPONENTE_H
#define	COMPONENTE_H

/* Bibliotecas necessárias */
#include "lista.h"

/* Protótipos das funções */
void matrizTranspota(int**, int**, int);
void listaTransposta(Lista*, int**, int);
void ordemDecrescenteFinalizacao(Lista*, int, int[]);
void componenteFortementeConexa(Lista*);

#endif /* COMPONENTE_H */