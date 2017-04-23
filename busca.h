#ifndef BUSCA_H
#define	BUSCA_H

/* Bibliotecas necessárias */
#include "lista.h"
#include "fila.h"

/* Variáveis globais */
int tempo;

/* Protótipo das funções */
int numeroFilho(Lista*, int);
void imprimeArvore(Lista*);
bool BuscaEmProfundidade(Lista*, No*);
bool iniciarBuscaEmProfundidade(Lista*);
void buscaProfundidade(Lista*);
Fila *inicializaBuscaLargura(Lista*);
void preencheCorValorEnfilera(Lista*, int, Fila*, int, int);
void realizaBuscaLargura(Lista*, Fila*);
void buscaLargura(Lista*);

#endif /* BUSCA_H */