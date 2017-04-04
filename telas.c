#include <stdio.h>
#include <stdlib.h>
#include "telas.h"

void telaLimpa(){
	system("clear");
}

void telaPesoAresta(){
	printf("╔══════════════════════════════╗\n");
	printf("║ Digite o peso da sua aresta  ║\n");
	printf("╚══════════════════════════════╝\n");
}

void telaErro(){
	printf(ANSI_COLOR_RED "╔══════════════════════════════╗\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_RED "║        Opção errada!!        ║\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_RED "╚══════════════════════════════╝\n" ANSI_COLOR_RESET);
}

void telaErroGrafoNaoDirigido(){
	printf(ANSI_COLOR_RED "╔════════════════════════════════════════════════════════════════╗\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_RED "║ O vértice não pode voltar para si mesmo no grafo não-dirigido! ║\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_RED "╚════════════════════════════════════════════════════════════════╝\n" ANSI_COLOR_RESET);
}

void telaListaAdjacencia(){
	printf(ANSI_COLOR_GREEN "╔══════════════════════╗\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_GREEN "║ Lista de adjacência! ║\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_GREEN "╚══════════════════════╝\n" ANSI_COLOR_RESET);
}

void telaMatrizAdjacencia(){
	printf(ANSI_COLOR_GREEN "╔═══════════════════════╗\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_GREEN "║ Matriz de adjacência! ║\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_GREEN "╚═══════════════════════╝\n" ANSI_COLOR_RESET);
}

void telaArestaExistente(){
	printf(ANSI_COLOR_RED "╔══════════════════════╗\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_RED "║ Aresta já existente! ║\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_RED "╚══════════════════════╝\n" ANSI_COLOR_RESET);
}

void telaSemVertice(){
	printf(ANSI_COLOR_RED "╔══════════════════════╗\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_RED "║ Não existe vértices! ║\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_RED "╚══════════════════════╝\n" ANSI_COLOR_RESET);
}

void telaArestaAdicionado(){
	printf(ANSI_COLOR_GREEN "╔════════════════════════════════╗\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_GREEN "║ Aresta adicionada com sucesso! ║\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_GREEN "╚════════════════════════════════╝\n" ANSI_COLOR_RESET);
}

void telaGrafoEhDirigido(){
	printf(ANSI_COLOR_GREEN "╔═══════════════════════════════╗\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_GREEN "║ Você escolheu grafo dirigido! ║\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_GREEN "╚═══════════════════════════════╝\n" ANSI_COLOR_RESET);
}

void telaGrafoEhNaoDirigido(){
	printf(ANSI_COLOR_GREEN "╔═══════════════════════════════════╗\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_GREEN "║ Você escolheu grafo não-dirigido! ║\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_GREEN "╚═══════════════════════════════════╝\n" ANSI_COLOR_RESET);
}

void telaGrafoEhPonderado(){
	printf(ANSI_COLOR_GREEN "╔════════════════════════════════╗\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_GREEN "║ Você escolheu grafo ponderado! ║\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_GREEN "╚════════════════════════════════╝\n" ANSI_COLOR_RESET);
}

void telaGrafoEhNaoPonderado(){
	printf(ANSI_COLOR_GREEN "╔════════════════════════════════════╗\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_GREEN "║ Você escolheu grafo não-ponderado! ║\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_GREEN "╚════════════════════════════════════╝\n" ANSI_COLOR_RESET);
}

void telaArestaOrigem(){
	printf("╔════════════════════════════╗\n");
	printf("║ Digite o vértice de origem ║\n");
	printf("╚════════════════════════════╝\n");
	printf("> ");
}

void telaArestaDestino(){
	printf("╔═════════════════════════════╗\n");
	printf("║ Digite o vértice de destino ║\n");
	printf("╚═════════════════════════════╝\n");
	printf("> ");
}

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

void telaContinuar(){
	printf("╔══════════════════════════════╗\n");
	printf("║   Escolha a opção desejada   ║\n");
	printf("╠══════════════════════════════╣\n");
	printf("║ 1 - Continuar                ║\n");
	printf("║ 2 - Sair                     ║\n");
	printf("╚══════════════════════════════╝\n");
	printf("╔══════════════════════════════╗\n");
	printf("║   Digite a opção desejada:   ║\n");
	printf("╚══════════════════════════════╝\n");
	printf("> ");
}

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

void telaPrincipal(){
	printf("╔══════════════════════════════╗\n");
	printf("║   Escolha a opção desejada   ║\n");
	printf("╠══════════════════════════════╣\n");
	printf("║ 1 - Inserir vértice          ║\n");
	printf("║ 2 - Inserir aresta           ║\n");
	printf("║ 3 - Matriz de adjacência     ║\n");
	printf("║ 4 - Lista de adjacência      ║\n");
	printf("║ 5 - Carregar arquivo         ║\n");
	printf("║ 6 - Sair                     ║\n");
	printf("╚══════════════════════════════╝\n");
	printf("╔══════════════════════════════╗\n");
	printf("║   Digite a opção desejada:   ║\n");
	printf("╚══════════════════════════════╝\n");
	printf("> ");
}

