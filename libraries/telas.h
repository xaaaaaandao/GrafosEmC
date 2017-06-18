#ifndef TELAS_H
#define	TELAS_H

/* Definindo alguns valores */
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

/* Protótipo das funções */
void telaLimpa();
void telaGrafoDeveDirigido();
void telaGrafoResetado();
void telaPaiETempos();
void telaDescedenteTemArestaRetorno();
void telaDescedenteNaoTemArestaRetorno();
void telaGrafoBiPartido();
void telaGrafoNaoBiPartido();
void telaOrdenacaoTopologica();
void telaOrdenacaoTopologicaCiclico();
void telaComponenteFortementeConexa();
void telaGrafoAciclico();
void telaGrafoCiclico();
void telaBuscaEmProfundidade();
void telaBuscaEmLargura();
void telaExemploGrafoDirigido();
void telaExemploGrafoNaoDirigido();
void telaVerticeRemovido();
void telaArestaRemovido();	
void telaErro();
void telaCFCDirigido();
void telaErroGrafoNaoDirigido();
void telaListaAdjacencia();
void telaMatrizAdjacencia();
void telaArestaExistente();
void telaSemVertice();
void telaSemAresta();
void telaArestaAdicionado();
void telaGrafoEhDirigido();
void telaGrafoEhNaoDirigido();
void telaGrafoEhPonderado();
void telaGrafoEhNaoPonderado();
void telaVerticeAdicionado(int);
void telaGrauMaximo(int);
void telaQtdComponenteFConexa(int);
void telaNMaiorNVertice();
void telaNIgualNVertice();
void telaNMenorNVertice();
void telaNIgualNAresta();
void telaNMaiorNAresta();
void telaNMenorNAresta();
void telaValorN();
void telaRemoverVertice();
void telaPesoAresta();
void telaArestaOrigem();
void telaArestaDestino();
void telaVertice();
void telaExercicio();
void telaGrafo();
void telaGrafoPonderado();
void telaPrincipal();
void telaExemploCarregaArquivo();

#endif /* TELAS_H */