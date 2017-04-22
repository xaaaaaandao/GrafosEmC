#ifndef BUSCA_H
#define	BUSCA_H

#include "lista.h"
#include "fila.h"

int tempo;

bool BuscaEmProfundidade(Lista*, No*);
bool iniciarBuscaEmProfundidade(Lista*);
void buscaProfundidade(Lista*);
Fila *inicializaBuscaLargura(Lista*);
void preencheCorValorEnfilera(Lista*, int, Fila*, int, int);
void realizaBuscaLargura(Lista*, Fila*);
void buscaLargura(Lista*);

#endif /* BUSCA_H */