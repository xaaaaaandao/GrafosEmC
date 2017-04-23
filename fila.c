#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "fila.h"

/* Operações da fila */
void inicializarFila(Fila *f){
	f -> inicio = NULL;
	f -> fim = NULL;
	f -> tamanho = 0;
}  

int vaziaFila(Fila *f){
	return (f -> inicio == NULL);
}  

void enfilerarFila(Fila *f, int id){
	noFila *auxiliar;
	auxiliar = (noFila *) malloc(sizeof(noFila));
	auxiliar -> id = id;
	auxiliar -> proximo  = NULL;
	if (vaziaFila(f)){
		f -> inicio = auxiliar;
		f -> fim = auxiliar;
	} else {
		f -> fim -> proximo = auxiliar;
		f -> fim = auxiliar;
	}
	f -> tamanho++;
}  

int desenfilerarFila(Fila *f){
	int id;
	noFila *auxiliar;
	if (vaziaFila(f)){
		return -1;
	}
	auxiliar = f -> inicio;
	id = f -> inicio -> id;
	f -> inicio = f -> inicio -> proximo;
	free(auxiliar);
	f -> tamanho--;
	return id;
}  

int tamanhoFila(Fila *f){
	return (f -> tamanho);
} 

void imprimirFila(Fila *f){
	noFila *auxiliar;
	auxiliar = f -> inicio;
	while (auxiliar != NULL){ 
		printf("%d ", auxiliar -> id);
		auxiliar = auxiliar -> proximo;
	}
	printf("\n");
}

bool existeFila(Fila *f, int vertice){
	noFila *auxiliar;
	auxiliar = f -> inicio;
	while (auxiliar != NULL){ 
		if(auxiliar -> id == vertice){
			return true;
		}
		auxiliar = auxiliar -> proximo;
	}
	return false;
}

void limpaFila(Fila *f){
	noFila *temporario, *atual;
	atual = f -> inicio;
	while(atual != NULL){
		temporario = atual -> proximo;
		free(atual);
		atual = temporario;
	}
	free(f);
}