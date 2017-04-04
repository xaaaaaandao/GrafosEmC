#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "telas.h"
#include "opcao.h"

int main(){
	Lista *l = (Lista*) malloc (sizeof(Lista));
	inicializarLista(l);
	telaLimpa();
	opcaoGrafo();
	opcaoGrafoPonderado();
	opcaoPrincipal(l);
	return 0;
}