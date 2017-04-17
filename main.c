#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "opcao.h"
#include "telas.h"

int main(){
	Lista *l = (Lista*) malloc (sizeof(Lista));
	inicializarLista(l);
	telaLimpa();
	opcaoGrafo();
	opcaoGrafoPonderado();
	opcaoPrincipal(l);
	return 0;
}