#include <stdio.h>
#include <stdlib.h>
#include "telas.h"

/* Limpa a tela */
void telaLimpa(){
	system("clear");
}

/* Telas de mensagens */
void telaOrdenacaoTopologica(){
	printf(ANSI_COLOR_GREEN "╔═══════════════════════╗\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_GREEN "║ Ordenação topológica! ║\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_GREEN "╚═══════════════════════╝\n" ANSI_COLOR_RESET);
}

void telaOrdenacaoTopologicaCiclico(){
	printf(ANSI_COLOR_RED "╔════════════════════════════════════════════╗\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_RED "║ Ordenação topológica só pode ser aciclico! ║\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_RED "╚════════════════════════════════════════════╝\n" ANSI_COLOR_RESET);
}

void telaComponenteFortementeConexa(){
	printf(ANSI_COLOR_GREEN "╔═══════════════════════════════╗\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_GREEN "║ Componente fortemente conexa! ║\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_GREEN "╚═══════════════════════════════╝\n" ANSI_COLOR_RESET);
}

void telaGrafoAciclico(){
	printf(ANSI_COLOR_GREEN "╔═════════════════╗\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_GREEN "║ Grafo aciclico! ║\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_GREEN "╚═════════════════╝\n" ANSI_COLOR_RESET);
}

void telaGrafoCiclico(){
	printf(ANSI_COLOR_GREEN "╔════════════════╗\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_GREEN "║ Grafo ciclico! ║\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_GREEN "╚════════════════╝\n" ANSI_COLOR_RESET);
}

void telaBuscaEmProfundidade(){
	printf(ANSI_COLOR_GREEN "╔════════════════════════╗\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_GREEN "║ Busca em Profundidade! ║\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_GREEN "╚════════════════════════╝\n" ANSI_COLOR_RESET);
}

void telaBuscaEmLargura(){
	printf(ANSI_COLOR_GREEN "╔═══════════════════╗\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_GREEN "║ Busca em Largura! ║\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_GREEN "╚═══════════════════╝\n" ANSI_COLOR_RESET);
}

void telaExemploGrafoDirigido(){
	printf(ANSI_COLOR_GREEN "╔═══════════════════════════════════════╗\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_GREEN "║ Exemplo de Grafo dirigido adicionado! ║\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_GREEN "╚═══════════════════════════════════════╝\n" ANSI_COLOR_RESET);
}

void telaExemploGrafoNaoDirigido(){
	printf(ANSI_COLOR_GREEN "╔═══════════════════════════════════════════╗\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_GREEN "║ Exemplo de Grafo não-dirigido adicionado! ║\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_GREEN "╚═══════════════════════════════════════════╝\n" ANSI_COLOR_RESET);
}


void telaVerticeRemovido(){
	printf(ANSI_COLOR_GREEN "╔═══════════════════════════════╗\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_GREEN "║ Vértice removido com sucesso! ║\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_GREEN "╚═══════════════════════════════╝\n" ANSI_COLOR_RESET);
}

void telaArestaRemovido(){
	printf(ANSI_COLOR_GREEN "╔══════════════════════════════╗\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_GREEN "║ Aresta removida com sucesso! ║\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_GREEN "╚══════════════════════════════╝\n" ANSI_COLOR_RESET);
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

void telaSemAresta(){
	printf(ANSI_COLOR_RED "╔═════════════════════════╗\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_RED "║ Não existe essa aresta! ║\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_RED "╚═════════════════════════╝\n" ANSI_COLOR_RESET);
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

void telaNMaiorNVertice(){
	printf(ANSI_COLOR_GREEN "╔═════════════════════════════════════╗\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_GREEN "║ N é maior que o número de vértices! ║\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_GREEN "╚═════════════════════════════════════╝\n" ANSI_COLOR_RESET);		
}

void telaNIgualNVertice(){
	printf("╔══════════════════════════════════╗\n");
	printf("║ N é igual ao número de vértices! ║\n");
	printf("╚══════════════════════════════════╝\n");		
}

void telaNMenorNVertice(){
	printf(ANSI_COLOR_RED "╔═════════════════════════════════════╗\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_RED "║ N é menor que o número de vértices! ║\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_RED "╚═════════════════════════════════════╝\n" ANSI_COLOR_RESET);		
}

void telaNIgualNAresta(){
	printf("╔════════════════════════════════╗\n");
	printf("║ N é igual ao número de aretas! ║\n");
	printf("╚════════════════════════════════╝\n");		
}

void telaNMaiorNAresta(){
	printf(ANSI_COLOR_GREEN "╔════════════════════════════════════╗\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_GREEN "║ N é maior que o número de arestas! ║\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_GREEN "╚════════════════════════════════════╝\n" ANSI_COLOR_RESET);			
}

void telaNMenorNAresta(){
	printf(ANSI_COLOR_RED "╔════════════════════════════════════╗\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_RED "║ N é menor que o número de arestas! ║\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_RED "╚════════════════════════════════════╝\n" ANSI_COLOR_RESET);			
}

/* Telas de mensagem de valores */
void telaValorN(){
	printf("╔═════════════════════╗\n");
	printf("║ Digite o valor de N ║\n");
	printf("╚═════════════════════╝\n");
	printf("> ");
}

void telaRemoverVertice(){
	printf("╔═══════════════════════════════════════╗\n");
	printf("║ Digite o id do vértice a ser removido ║\n");
	printf("╚═══════════════════════════════════════╝\n");
	printf("> ");
}

void telaPesoAresta(){
	printf("╔══════════════════════════════╗\n");
	printf("║ Digite o peso da sua aresta  ║\n");
	printf("╚══════════════════════════════╝\n");
	printf("> ");
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
	printf("║14 - Sair                       ║\n");
	printf("╚════════════════════════════════╝\n");
	printf("╔══════════════════════════════╗\n");
	printf("║   Digite a opção desejada:   ║\n");
	printf("╚══════════════════════════════╝\n");
	printf("> ");
}

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
