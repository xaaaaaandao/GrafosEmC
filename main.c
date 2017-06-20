#include <stdio.h>
#include <stdlib.h>
#include "libraries/lista.h"
#include "libraries/opcao.h"
#include "libraries/telas.h"
#include "libraries/mst.h"
#include "libraries/fonteunica.h"
#include "libraries/todosospares.h"

int main(){
	/*Lista *l = (Lista*) malloc (sizeof(Lista));
	inicializarLista(l);
	telaLimpa();
	opcaoGrafo();
	opcaoGrafoPonderado();
	opcaoPrincipal(l);*/
	//MST_Prim();
	//bellmanFord();
	//Dijkstra();
	floyd();
	return 0;
}
