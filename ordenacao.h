#ifndef ORDENACAO_H
#define	ORDENACAO_H

/* Bibliotecas necessárias */
#include "lista.h"

/* Variáveis globais */
int tempoOrdenacao;

/* Protótipo das funções */
void ordenacaoRealizarBuscaProfundidade(Lista*, No*, Lista*);
void ordenacaoIniciarBuscaProfundidade(Lista*, Lista*);
void ordenacaoTopologica(Lista*);

#endif /* ORDENACAO_H */