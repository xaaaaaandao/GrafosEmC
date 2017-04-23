#include <stdio.h>
#include <stdlib.h>
#include "telas.h"

/**
* A função telaLimpa() limpa tela do console;
@param nenhum, não recebe nenhum parâmetro;
@return void, retorna nada.
*/
void telaLimpa(){
	system("clear");
}

/**
* A função telaGrafodirigido() mensagem para sinalizar que o grafo deve ser dirigido;
@param nenhum, não recebe nenhum parâmetro;
@return void, retorna nada.
*/
void telaGrafoDeveDirigido(){
	printf(ANSI_COLOR_GREEN "╔════════════════════════════╗\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_GREEN "║ O grafo deve ser dirigido! ║\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_GREEN "╚════════════════════════════╝\n" ANSI_COLOR_RESET);
}

/**
* A função telaGrafoResetado() mensagem para sinalizar que o grafo foi resetado;
@param nenhum, não recebe nenhum parâmetro;
@return void, retorna nada.
*/
void telaGrafoResetado(){
	printf(ANSI_COLOR_GREEN "╔═════════════════╗\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_GREEN "║ Grafo resetado! ║\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_GREEN "╚═════════════════╝\n" ANSI_COLOR_RESET);
}

/**
* A função telaPaiETempos() mensagem para sinalizar que está sendo mostrados
* os tempos de descoberta e finalização e o pai;
@param nenhum, não recebe nenhum parâmetro;
@return void, retorna nada.
*/
void telaPaiETempos(){
	printf(ANSI_COLOR_GREEN "╔══════════════╗\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_GREEN "║ Pai e tempos ║\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_GREEN "╚══════════════╝\n" ANSI_COLOR_RESET);
}

/**
* A função telaDescendenteTemArestaRetorno() mensagem para sinalizar que o descendente
* tem uma aresta de retorno;
@param nenhum, não recebe nenhum parâmetro;
@return void, retorna nada.
*/
void telaDescedenteTemArestaRetorno(){
	printf(ANSI_COLOR_GREEN "╔════════════════════════════════════════════════════════════╗\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_GREEN "║ O descendente tem uma aresta de retorno para um ancestral! ║\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_GREEN "╚════════════════════════════════════════════════════════════╝\n" ANSI_COLOR_RESET);
}

/**
* A função telaDescendenteNaoTemArestaRetorno() mensagem para sinalizar que o descendente não
* tem uma aresta de retorno;
@param nenhum, não recebe nenhum parâmetro;
@return void, retorna nada.
*/
void telaDescedenteNaoTemArestaRetorno(){
	printf(ANSI_COLOR_RED "╔════════════════════════════════════════════════════════════════╗\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_RED "║ O descendente não tem uma aresta de retorno para um ancestral! ║\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_RED "╚════════════════════════════════════════════════════════════════╝\n" ANSI_COLOR_RESET);
}

/**
* A função telaGrafoBiPartido() mensagem para sinalizar que o grafo
* é bi-partido;
@param nenhum, não recebe nenhum parâmetro;
@return void, retorna nada.
*/
void telaGrafoBiPartido(){
	printf(ANSI_COLOR_GREEN "╔═══════════════════════╗\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_GREEN "║ O Grafo é Bi-partido! ║\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_GREEN "╚═══════════════════════╝\n" ANSI_COLOR_RESET);
}

/**
* A função telaGrafoNaoBiPartido() mensagem para sinalizar que o grafo
* não é bi-partido;
@param nenhum, não recebe nenhum parâmetro;
@return void, retorna nada.
*/
void telaGrafoNaoBiPartido(){
	printf(ANSI_COLOR_RED "╔═══════════════════════════╗\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_RED "║ O Grafo não é Bi-partido! ║\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_RED "╚═══════════════════════════╝\n" ANSI_COLOR_RESET);
}

/**
* A função telaOrdenacaoTopologica() mensagem para sinalizar que a ordenação
* topológica dado um grafo;
@param nenhum, não recebe nenhum parâmetro;
@return void, retorna nada.
*/
void telaOrdenacaoTopologica(){
	printf(ANSI_COLOR_GREEN "╔═══════════════════════╗\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_GREEN "║ Ordenação topológica! ║\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_GREEN "╚═══════════════════════╝\n" ANSI_COLOR_RESET);
}

/**
* A função telaOrdenacaoTopologicaCiclico() mensagem para sinalizar que o grafo
* tem que ser aciclico para realizar a ordenação topológica;
@param nenhum, não recebe nenhum parâmetro;
@return void, retorna nada.
*/
void telaOrdenacaoTopologicaCiclico(){
	printf(ANSI_COLOR_RED "╔════════════════════════════════════════════╗\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_RED "║ Ordenação topológica só pode ser aciclico! ║\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_RED "╚════════════════════════════════════════════╝\n" ANSI_COLOR_RESET);
}

/**
* A função telaComponenteFortementeConexa() mensagem para sinalizar que se executou
* a opção componente fortemente conexa;
@param nenhum, não recebe nenhum parâmetro;
@return void, retorna nada.
*/
void telaComponenteFortementeConexa(){
	printf(ANSI_COLOR_GREEN "╔═══════════════════════════════╗\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_GREEN "║ Componente fortemente conexa! ║\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_GREEN "╚═══════════════════════════════╝\n" ANSI_COLOR_RESET);
}

/**
* A função telaGrafoAciclico() mensagem para sinalizar que o grafo 
* é aciclico;
@param nenhum, não recebe nenhum parâmetro;
@return void, retorna nada.
*/
void telaGrafoAciclico(){
	printf(ANSI_COLOR_GREEN "╔═════════════════╗\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_GREEN "║ Grafo aciclico! ║\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_GREEN "╚═════════════════╝\n" ANSI_COLOR_RESET);
}

/**
* A função telaGrafoCiclico() mensagem para sinalizar que o grafo 
* é ciclico;
@param nenhum, não recebe nenhum parâmetro;
@return void, retorna nada.
*/
void telaGrafoCiclico(){
	printf(ANSI_COLOR_GREEN "╔════════════════╗\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_GREEN "║ Grafo ciclico! ║\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_GREEN "╚════════════════╝\n" ANSI_COLOR_RESET);
}

/**
* A função telaBuscaEmProfundidade() mensagem para sinalizar que está
* sendo executado a busca em profundidade;
@param nenhum, não recebe nenhum parâmetro;
@return void, retorna nada.
*/
void telaBuscaEmProfundidade(){
	printf(ANSI_COLOR_GREEN "╔════════════════════════╗\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_GREEN "║ Busca em Profundidade! ║\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_GREEN "╚════════════════════════╝\n" ANSI_COLOR_RESET);
}

/**
* A função telaBuscaEmLargura() mensagem para sinalizar que está
* sendo executado a busca em largura;
@param nenhum, não recebe nenhum parâmetro;
@return void, retorna nada.
*/
void telaBuscaEmLargura(){
	printf(ANSI_COLOR_GREEN "╔═══════════════════╗\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_GREEN "║ Busca em Largura! ║\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_GREEN "╚═══════════════════╝\n" ANSI_COLOR_RESET);
}

/**
* A função telaExemplGrafoDirigido() mensagem para sinalizar que foi adicionado
* um grafo dirigido;
@param nenhum, não recebe nenhum parâmetro;
@return void, retorna nada.
*/
void telaExemploGrafoDirigido(){
	printf(ANSI_COLOR_GREEN "╔═══════════════════════════════════════╗\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_GREEN "║ Exemplo de Grafo dirigido adicionado! ║\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_GREEN "╚═══════════════════════════════════════╝\n" ANSI_COLOR_RESET);
}

/**
* A função telaExemplGrafoNaoDirigido() mensagem para sinalizar que foi adicionado
* um grafo não dirigido;
@param nenhum, não recebe nenhum parâmetro;
@return void, retorna nada.
*/
void telaExemploGrafoNaoDirigido(){
	printf(ANSI_COLOR_GREEN "╔═══════════════════════════════════════════╗\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_GREEN "║ Exemplo de Grafo não-dirigido adicionado! ║\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_GREEN "╚═══════════════════════════════════════════╝\n" ANSI_COLOR_RESET);
}

/**
* A função telaVerticeRemovido() mensagem para sinalizar que um 
* vértice foi removido com sucesso;
@param nenhum, não recebe nenhum parâmetro;
@return void, retorna nada.
*/
void telaVerticeRemovido(){
	printf(ANSI_COLOR_GREEN "╔═══════════════════════════════╗\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_GREEN "║ Vértice removido com sucesso! ║\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_GREEN "╚═══════════════════════════════╝\n" ANSI_COLOR_RESET);
}

/**
* A função telaArestaRemovido() mensagem para sinalizar que uma
* aresta foi removido com sucesso;
@param nenhum, não recebe nenhum parâmetro;
@return void, retorna nada.
*/
void telaArestaRemovido(){
	printf(ANSI_COLOR_GREEN "╔══════════════════════════════╗\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_GREEN "║ Aresta removida com sucesso! ║\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_GREEN "╚══════════════════════════════╝\n" ANSI_COLOR_RESET);
}

/**
* A função telaErro() mensagem para sinalizar que você digitou a opção errada;
@param nenhum, não recebe nenhum parâmetro;
@return void, retorna nada.
*/
void telaErro(){
	printf(ANSI_COLOR_RED "╔══════════════════════════════╗\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_RED "║        Opção errada!!        ║\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_RED "╚══════════════════════════════╝\n" ANSI_COLOR_RESET);
}

/**
* A função telaCFCDirigido() mensagem para sinalizar que a componente fortemente
* conexa deve ser grafo dirigido;
@param nenhum, não recebe nenhum parâmetro;
@return void, retorna nada.
*/
void telaCFCDirigido(){
	printf(ANSI_COLOR_RED "╔═══════════════════════════════════════════════════════╗\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_RED "║ Componente Fortemente Conexa deve ser grafo dirigido! ║\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_RED "╚═══════════════════════════════════════════════════════╝\n" ANSI_COLOR_RESET);
}

/**
* A função telaErroGrafoNaoDirigido() mensagem para sinalizar que em grafo não dirigido
* um vértice não pode ter uma aresta para voltar para ele mesmo;
@param nenhum, não recebe nenhum parâmetro;
@return void, retorna nada.
*/
void telaErroGrafoNaoDirigido(){
	printf(ANSI_COLOR_RED "╔════════════════════════════════════════════════════════════════╗\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_RED "║ O vértice não pode voltar para si mesmo no grafo não-dirigido! ║\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_RED "╚════════════════════════════════════════════════════════════════╝\n" ANSI_COLOR_RESET);
}

/**
* A função telaListaAdjacencia() mensagem para sinalizar que está
* sendo executado a lista de adjacência;
@param nenhum, não recebe nenhum parâmetro;
@return void, retorna nada.
*/
void telaListaAdjacencia(){
	printf(ANSI_COLOR_GREEN "╔══════════════════════╗\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_GREEN "║ Lista de adjacência! ║\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_GREEN "╚══════════════════════╝\n" ANSI_COLOR_RESET);
}

/**
* A função telaMatrizAdjacencia() mensagem para sinalizar que está
* sendo executado a matriz de adjacência;
@param nenhum, não recebe nenhum parâmetro;
@return void, retorna nada.
*/
void telaMatrizAdjacencia(){
	printf(ANSI_COLOR_GREEN "╔═══════════════════════╗\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_GREEN "║ Matriz de adjacência! ║\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_GREEN "╚═══════════════════════╝\n" ANSI_COLOR_RESET);
}

/**
* A função telaArestaExistente() mensagem para sinalizar que aresta
* já existe;
@param nenhum, não recebe nenhum parâmetro;
@return void, retorna nada.
*/
void telaArestaExistente(){
	printf(ANSI_COLOR_RED "╔══════════════════════╗\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_RED "║ Aresta já existente! ║\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_RED "╚══════════════════════╝\n" ANSI_COLOR_RESET);
}

/**
* A função telaSemVertice() mensagem para sinalizar que
* não existem vértices;
@param nenhum, não recebe nenhum parâmetro;
@return void, retorna nada.
*/
void telaSemVertice(){
	printf(ANSI_COLOR_RED "╔══════════════════════╗\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_RED "║ Não existe vértices! ║\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_RED "╚══════════════════════╝\n" ANSI_COLOR_RESET);
}

/**
* A função telaSemAresta() mensagem para sinalizar que
* essa aresta não existe;
@param nenhum, não recebe nenhum parâmetro;
@return void, retorna nada.
*/
void telaSemAresta(){
	printf(ANSI_COLOR_RED "╔═════════════════════════╗\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_RED "║ Não existe essa aresta! ║\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_RED "╚═════════════════════════╝\n" ANSI_COLOR_RESET);
}

/**
* A função telaArestaAdicionado() mensagem para sinalizar que
* aresta foi adicionada com sucesso;
@param nenhum, não recebe nenhum parâmetro;
@return void, retorna nada.
*/
void telaArestaAdicionado(){
	printf(ANSI_COLOR_GREEN "╔════════════════════════════════╗\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_GREEN "║ Aresta adicionada com sucesso! ║\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_GREEN "╚════════════════════════════════╝\n" ANSI_COLOR_RESET);
}

/**
* A função telaGrafoEhDirigido() mensagem para sinalizar que
* o grafo é dirigido;
@param nenhum, não recebe nenhum parâmetro;
@return void, retorna nada.
*/
void telaGrafoEhDirigido(){
	printf(ANSI_COLOR_GREEN "╔═══════════════════════════════╗\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_GREEN "║ Você escolheu grafo dirigido! ║\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_GREEN "╚═══════════════════════════════╝\n" ANSI_COLOR_RESET);
}

/**
* A função telaGrafoEhNaoDirigido() mensagem para sinalizar que
* o grafo é não dirigido;
@param nenhum, não recebe nenhum parâmetro;
@return void, retorna nada.
*/
void telaGrafoEhNaoDirigido(){
	printf(ANSI_COLOR_GREEN "╔═══════════════════════════════════╗\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_GREEN "║ Você escolheu grafo não-dirigido! ║\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_GREEN "╚═══════════════════════════════════╝\n" ANSI_COLOR_RESET);
}

/**
* A função telaGrafoEhPonderado() mensagem para sinalizar que
* o grafo é ponderado;
@param nenhum, não recebe nenhum parâmetro;
@return void, retorna nada.
*/
void telaGrafoEhPonderado(){
	printf(ANSI_COLOR_GREEN "╔════════════════════════════════╗\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_GREEN "║ Você escolheu grafo ponderado! ║\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_GREEN "╚════════════════════════════════╝\n" ANSI_COLOR_RESET);
}

/**
* A função telaGrafoEhNaoPonderado() mensagem para sinalizar que
* o grafo é não ponderado;
@param nenhum, não recebe nenhum parâmetro;
@return void, retorna nada.
*/
void telaGrafoEhNaoPonderado(){
	printf(ANSI_COLOR_GREEN "╔════════════════════════════════════╗\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_GREEN "║ Você escolheu grafo não-ponderado! ║\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_GREEN "╚════════════════════════════════════╝\n" ANSI_COLOR_RESET);
}

/**
* A função telaVerticeAdicionado(int id) mensagem para sinalizar que
* o tal vértice foi adicionado;
@param id, é um inteiro com um número do identificador do vértice;
@return void, retorna nada.
*/
void telaVerticeAdicionado(int id){
	if(id < 10){
		printf(ANSI_COLOR_GREEN "╔═════════════════════════════════════════╗\n" ANSI_COLOR_RESET);
		printf(ANSI_COLOR_GREEN "║ O vértice %d foi adicionado com sucesso! ║\n" ANSI_COLOR_RESET, id);
		printf(ANSI_COLOR_GREEN "╚═════════════════════════════════════════╝\n" ANSI_COLOR_RESET);		
	} else if(id < 100){
		printf(ANSI_COLOR_GREEN "╔══════════════════════════════════════════╗\n" ANSI_COLOR_RESET);
		printf(ANSI_COLOR_GREEN "║ O vértice %d foi adicionado com sucesso! ║\n" ANSI_COLOR_RESET, id);
		printf(ANSI_COLOR_GREEN "╚══════════════════════════════════════════╝\n" ANSI_COLOR_RESET);		
	} else if(id < 1000){
		printf(ANSI_COLOR_GREEN "╔═══════════════════════════════════════════╗\n" ANSI_COLOR_RESET);
		printf(ANSI_COLOR_GREEN "║ O vértice %d foi adicionado com sucesso! ║\n" ANSI_COLOR_RESET, id);
		printf(ANSI_COLOR_GREEN "╚═══════════════════════════════════════════╝\n" ANSI_COLOR_RESET);				
	} else if(id < 10000){
		printf(ANSI_COLOR_GREEN "╔════════════════════════════════════════════╗\n" ANSI_COLOR_RESET);
		printf(ANSI_COLOR_GREEN "║ O vértice %d foi adicionado com sucesso! ║\n" ANSI_COLOR_RESET, id);
		printf(ANSI_COLOR_GREEN "╚════════════════════════════════════════════╝\n" ANSI_COLOR_RESET);				
	}
}

/**
* A função telaGrauMaximo(int grau) mensagem para sinalizar que
* grau máximo que tem em um grafo;
@param grau, é um inteiro com o grau máximo de um grafo;
@return void, retorna nada.
*/
void telaGrauMaximo(int grau){
	if(grau < 10){
		printf(ANSI_COLOR_GREEN "╔════════════════════╗\n" ANSI_COLOR_RESET);
		printf(ANSI_COLOR_GREEN "║ O grau máximo é: %d ║\n" ANSI_COLOR_RESET, grau);
		printf(ANSI_COLOR_GREEN "╚════════════════════╝\n" ANSI_COLOR_RESET);		
	} else if(grau < 100){
		printf(ANSI_COLOR_GREEN "╔═════════════════════╗\n" ANSI_COLOR_RESET);
		printf(ANSI_COLOR_GREEN "║ O grau máximo é: %d ║\n" ANSI_COLOR_RESET, grau);
		printf(ANSI_COLOR_GREEN "╚═════════════════════╝\n" ANSI_COLOR_RESET);		
	} else if(grau < 1000){
		printf(ANSI_COLOR_GREEN "╔══════════════════════╗\n" ANSI_COLOR_RESET);
		printf(ANSI_COLOR_GREEN "║ O grau máximo é: %d ║\n" ANSI_COLOR_RESET, grau);
		printf(ANSI_COLOR_GREEN "╚══════════════════════╝\n" ANSI_COLOR_RESET);				
	} else if(grau < 10000){
		printf(ANSI_COLOR_GREEN "╔═══════════════════════╗\n" ANSI_COLOR_RESET);
		printf(ANSI_COLOR_GREEN "║ O grau máximo é: %d ║\n" ANSI_COLOR_RESET, grau);
		printf(ANSI_COLOR_GREEN "╚═══════════════════════╝\n" ANSI_COLOR_RESET);				
	}
}

/**
* A função telaQtdComponenteConexa(int quantidade) mensagem para sinalizar quantas
* componente fortemente conexa tem em um grafo;
@param quantidade, é um inteiro com a quantidade de componentes fortemente conexa;
@return void, retorna nada.
*/
void telaQtdComponenteFConexa(int quantidade){
	if(quantidade < 10){
		printf(ANSI_COLOR_GREEN "╔════════════════════════════════════════════════════╗\n" ANSI_COLOR_RESET);
		printf(ANSI_COLOR_GREEN "║ A quantidade de componente fortemente conexa é: %d! ║\n" ANSI_COLOR_RESET, quantidade);
		printf(ANSI_COLOR_GREEN "╚════════════════════════════════════════════════════╝\n" ANSI_COLOR_RESET);		
	} else if(quantidade < 100){
		printf(ANSI_COLOR_GREEN "╔═════════════════════════════════════════════════════╗\n" ANSI_COLOR_RESET);
		printf(ANSI_COLOR_GREEN "║ A quantidade de componente fortemente conexa é: %d! ║\n" ANSI_COLOR_RESET, quantidade);
		printf(ANSI_COLOR_GREEN "╚═════════════════════════════════════════════════════╝\n" ANSI_COLOR_RESET);		
	} else if(quantidade < 1000){
		printf(ANSI_COLOR_GREEN "╔══════════════════════════════════════════════════════╗\n" ANSI_COLOR_RESET);
		printf(ANSI_COLOR_GREEN "║ A quantidade de componente fortemente conexa é: %d! ║\n" ANSI_COLOR_RESET, quantidade);
		printf(ANSI_COLOR_GREEN "╚══════════════════════════════════════════════════════╝\n" ANSI_COLOR_RESET);				
	} else if(quantidade < 10000){
		printf(ANSI_COLOR_GREEN "╔═══════════════════════════════════════════════════════╗\n" ANSI_COLOR_RESET);
		printf(ANSI_COLOR_GREEN "║ A quantidade de componente fortemente conexa é: %d! ║\n" ANSI_COLOR_RESET, quantidade);
		printf(ANSI_COLOR_GREEN "╚═══════════════════════════════════════════════════════╝\n" ANSI_COLOR_RESET);				
	}
}

/**
* A função telaNMaiorNVertice() mensagem para sinalizar que
* N é maior que N vértices;
@param nenhum, não recebe nenhum parâmetro;
@return void, retorna nada.
*/
void telaNMaiorNVertice(){
	printf(ANSI_COLOR_GREEN "╔═════════════════════════════════════╗\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_GREEN "║ N é maior que o número de vértices! ║\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_GREEN "╚═════════════════════════════════════╝\n" ANSI_COLOR_RESET);		
}

/**
* A função telaNIgualNVertice() mensagem para sinalizar que
* N que é igual a N vértices;
@param nenhum, não recebe nenhum parâmetro;
@return void, retorna nada.
*/
void telaNIgualNVertice(){
	printf("╔══════════════════════════════════╗\n");
	printf("║ N é igual ao número de vértices! ║\n");
	printf("╚══════════════════════════════════╝\n");		
}

/**
* A função telaNMenorNVertice() mensagem para sinalizar que
* N é menor que N vértices;
@param nenhum, não recebe nenhum parâmetro;
@return void, retorna nada.
*/
void telaNMenorNVertice(){
	printf(ANSI_COLOR_RED "╔═════════════════════════════════════╗\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_RED "║ N é menor que o número de vértices! ║\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_RED "╚═════════════════════════════════════╝\n" ANSI_COLOR_RESET);		
}

/**
* A função telaNIgualNAresta() mensagem para sinalizar que
* N que é igual a N aresta;
@param nenhum, não recebe nenhum parâmetro;
@return void, retorna nada.
*/
void telaNIgualNAresta(){
	printf("╔════════════════════════════════╗\n");
	printf("║ N é igual ao número de aretas! ║\n");
	printf("╚════════════════════════════════╝\n");		
}

/**
* A função telaNMaiorNAresta() mensagem para sinalizar que
* N é maior que N aresta;
@param nenhum, não recebe nenhum parâmetro;
@return void, retorna nada.
*/
void telaNMaiorNAresta(){
	printf(ANSI_COLOR_GREEN "╔════════════════════════════════════╗\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_GREEN "║ N é maior que o número de arestas! ║\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_GREEN "╚════════════════════════════════════╝\n" ANSI_COLOR_RESET);			
}

/**
* A função telaNMenorNAresta() mensagem para sinalizar que
* N é menor que N aresta;
@param nenhum, não recebe nenhum parâmetro;
@return void, retorna nada.
*/
void telaNMenorNAresta(){
	printf(ANSI_COLOR_RED "╔════════════════════════════════════╗\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_RED "║ N é menor que o número de arestas! ║\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_RED "╚════════════════════════════════════╝\n" ANSI_COLOR_RESET);			
}

/**
* A função telaValorN() mensagem para solicitar um valor de N;
@param nenhum, não recebe nenhum parâmetro;
@return void, retorna nada.
*/
void telaValorN(){
	printf("╔═════════════════════╗\n");
	printf("║ Digite o valor de N ║\n");
	printf("╚═════════════════════╝\n");
	printf("> ");
}

/**
* A função telaRemoverVertice() mensagem para solicitar o identificador do vértice a ser removido;
@param nenhum, não recebe nenhum parâmetro;
@return void, retorna nada.
*/
void telaRemoverVertice(){
	printf("╔═══════════════════════════════════════╗\n");
	printf("║ Digite o id do vértice a ser removido ║\n");
	printf("╚═══════════════════════════════════════╝\n");
	printf("> ");
}

/**
* A função telaPesoAresta() mensagem para solicitar o peso da aresta;
@param nenhum, não recebe nenhum parâmetro;
@return void, retorna nada.
*/
void telaPesoAresta(){
	printf("╔══════════════════════════════╗\n");
	printf("║ Digite o peso da sua aresta  ║\n");
	printf("╚══════════════════════════════╝\n");
	printf("> ");
}

/**
* A função telaArestaOrigem() mensagem para solicitar aresta de origem;
@param nenhum, não recebe nenhum parâmetro;
@return void, retorna nada.
*/
void telaArestaOrigem(){
	printf("╔════════════════════════════╗\n");
	printf("║ Digite o vértice de origem ║\n");
	printf("╚════════════════════════════╝\n");
	printf("> ");
}

/**
* A função telaArestaDestino() mensagem para solicitar aresta de destino;
@param nenhum, não recebe nenhum parâmetro;
@return void, retorna nada.
*/
void telaArestaDestino(){
	printf("╔═════════════════════════════╗\n");
	printf("║ Digite o vértice de destino ║\n");
	printf("╚═════════════════════════════╝\n");
	printf("> ");
}

/**
* A função telaVertice() mensagem para solicitar o identifcador de um vértice;
@param nenhum, não recebe nenhum parâmetro;
@return void, retorna nada.
*/
void telaVertice(){
	printf("╔═══════════════════╗\n");
	printf("║ Digite um vértice ║\n");
	printf("╚═══════════════════╝\n");
	printf("> ");
}

/**
* A função telaExercicio() mensagem para solicitar uma das opções;
@param nenhum, não recebe nenhum parâmetro;
@return void, retorna nada.
*/
void telaExercicio(){
	printf("╔══════════════════════════════════╗\n");
	printf("║     Escolha a opção desejada     ║\n");
	printf("╠══════════════════════════════════╣\n");
	printf("║ 1 - Grau máximo (1B)             ║\n");
	printf("║ 2 - Dirigido -> Não-dirigido (2) ║\n");
	printf("║ 3 - Grafo Bi-partido (3)         ║\n");
	printf("║ 4 - Ciclico | Acicilico (4)      ║\n");
	printf("║ 5 - Ancestral | Descendente (5)  ║\n");
	printf("║ 6 - Nº aresta | vértice (6)      ║\n");
	printf("║ 7 - Nº compoentes f. conexas (7) ║\n");
	printf("║ 8 - Sair                         ║\n");
	printf("╚══════════════════════════════════╝\n");
	printf("╔══════════════════════════════════════════╗\n");
	printf("║         Digite a opção desejada:         ║\n");
	printf("╚══════════════════════════════════════════╝\n");
	printf("> ");
}

/**
* A função telaGrafo() mensagem para solicitar uma das opções;
@param nenhum, não recebe nenhum parâmetro;
@return void, retorna nada.
*/
void telaGrafo(){
	printf("╔══════════════════════════════╗\n");
	printf("║   Escolha a opção desejada   ║\n");
	printf("╠══════════════════════════════╣\n");
	printf("║ 1 - Grafo dirigido           ║\n");
	printf("║ 2 - Grafo não-dirigido       ║\n");
	printf("║ 3 - Sair                     ║\n");
	printf("╚══════════════════════════════╝\n");
	printf("╔══════════════════════════════╗\n");
	printf("║   Digite a opção desejada:   ║\n");
	printf("╚══════════════════════════════╝\n");
	printf("> ");
}

/**
* A função telaGrafoPonderado() mensagem para solicitar uma das opções;
@param nenhum, não recebe nenhum parâmetro;
@return void, retorna nada.
*/
void telaGrafoPonderado(){
	printf("╔══════════════════════════════╗\n");
	printf("║   Escolha a opção desejada   ║\n");
	printf("╠══════════════════════════════╣\n");
	printf("║ 1 - Grafo ponderado          ║\n");
	printf("║ 2 - Grafo não-ponderado      ║\n");
	printf("║ 3 - Sair                     ║\n");
	printf("╚══════════════════════════════╝\n");
	printf("╔══════════════════════════════╗\n");
	printf("║   Digite a opção desejada:   ║\n");
	printf("╚══════════════════════════════╝\n");
	printf("> ");
}

/**
* A função telaPrincipal() mensagem para solicitar uma das opções;
@param nenhum, não recebe nenhum parâmetro;
@return void, retorna nada.
*/
void telaPrincipal(){
	printf("╔════════════════════════════════╗\n");
	printf("║    Escolha a opção desejada    ║\n");
	printf("╠════════════════════════════════╣\n");
	printf("║ 1 - Inserir vértice            ║\n");
	printf("║ 2 - Inserir aresta             ║\n");
	printf("║ 3 - Matriz de adjacência       ║\n");
	printf("║ 4 - Lista de adjacência        ║\n");
	printf("║ 5 - Carregar arquivo           ║\n");
	printf("║ 6 - Remover vértice            ║\n");
	printf("║ 7 - Remover aresta             ║\n");
	printf("║ 8 - Busca em largura           ║\n");
	printf("║ 9 - Busca em profundidade      ║\n");
	printf("║10 - Ordenação topológica       ║\n");
	printf("║11 - Grafo ciclico ou aciclico  ║\n");
	printf("║12 - Componente fortmente conexa║\n");
	printf("║13 - Exercícios                 ║\n");
	printf("║14 - Imprimir tempo e pai       ║\n");
	printf("║15 - Resetar grafos             ║\n");
	printf("║16 - Sair                       ║\n");
	printf("╚════════════════════════════════╝\n");
	printf("╔══════════════════════════════╗\n");
	printf("║   Digite a opção desejada:   ║\n");
	printf("╚══════════════════════════════╝\n");
	printf("> ");
}

/**
* A função telaExemploCarregaArquivo() mensagem para solicitar uma das opções;
@param nenhum, não recebe nenhum parâmetro;
@return void, retorna nada.
*/
void telaExemploCarregaArquivo(){
	printf("╔════════════════════════════════╗\n");
	printf("║    Escolha a opção desejada    ║\n");
	printf("╠════════════════════════════════╣\n");
	printf("║ 1 - Exemplo grafo dirigido     ║\n");
	printf("║ 2 - Exemplo grafo não-dirigido ║\n");
	printf("║ 3 - Sair                       ║\n");
	printf("╚════════════════════════════════╝\n");
	printf("╔════════════════════════════════╗\n");
	printf("║    Digite a opção desejada:    ║\n");
	printf("╚════════════════════════════════╝\n");
	printf("> ");
}
