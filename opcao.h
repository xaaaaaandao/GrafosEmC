#ifndef OPCAO_H
#define	OPCAO_H

/* Bibliotecas necessárias */
#include "lista.h"

/* Variáveis globais */
bool grafoDirigido;
bool grafoPonderado;

/* Protótipo das funções */
void sairPrograma();
int opcaoArestaOrigem(Lista*);
int opcaoArestaDestino(Lista*);
int opcaoPesoAresta();
void opcaoAresta(Lista*);
void opcaoRemoveVertice(Lista*);
void opcaoRemoveAresta(Lista*);
void opcaoGrafo();
void opcaoGrafoPonderado();
void opcaoCarregarArquivo(Lista*);
int opcaoValorN();
int opcaoVertice(Lista*);
void opcaoExercicio(Lista*);
void opcaoPrincipal(Lista*);

#endif /* OPCAO_H */