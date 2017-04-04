#ifndef TELAS_H
#define	TELAS_H

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

#include <stdbool.h>
#include "lista.h"

bool existeVertice(Lista*, int);
void telaLimpa();
void telaErro();
void telaPesoAresta();
void telaErroGrafoNaoDirigido();
void telaListaAdjacencia();
void telaMatrizAdjacencia();
void telaArestaExistente();
void telaSemVertice();
void telaArestaAdicionado();
void telaGrafoEhDirigido();
void telaGrafoEhNaoDirigido();
void telaGrafoEhPonderado();
void telaGrafoEhNaoPonderado();
void telaArestaOrigem();
void telaArestaDestino();
void telaVerticeAdicionado(int);
void telaContinuar();
void telaGrafo();
void telaGrafoPonderado();
void telaPrincipal();

#endif /* TELAS_H */