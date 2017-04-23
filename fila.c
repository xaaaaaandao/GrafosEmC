#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "fila.h"

/**
* A função inicializarFila(Fila *f) em que inicializa uma fila;
@param f, é do tipo Fila que contém os identificador dos vértices;
@return void, retorna nada.
*/
void inicializarFila(Fila *f){
	f -> inicio = NULL;
	f -> fim = NULL;
	f -> tamanho = 0;
}  

/**
* A função vaziaFila(Fila *f) em que verifica se a fila é vazia;
@param f, é do tipo Fila que contém os identificador dos vértices;
@return inteiro, retorna zero está vazia ou qualquer outro valor caso exista algum elemento.
*/
int vaziaFila(Fila *f){
	return (f -> inicio == NULL);
}  

/**
* A função enfilerarFila(Fila *f) em que insere o identificador de 
* um vértice no fim da fila;
@param f, é do tipo Fila que contém os identificador dos vértices;
@param id, é do tipo inteiro é o identificador do vértice;
@return void, retorna nada.
*/
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

/**
* A função desenfilerarFila(Fila *f) em que retiramos
* da fila um vértice do começo da fila;
@param f, é do tipo Fila que contém os identificador dos vértices;
@return id, retorna um inteiro que é o identificador do vértice.
*/
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

/**
* A função tamanhoFila(Fila *f) em que retornamos o tamanho da fila;
@param f, é do tipo Fila que contém os identificador dos vértices;
@return inteiro, retorna que é o tamanho da fila.
*/
int tamanhoFila(Fila *f){
	return (f -> tamanho);
} 

/**
* A função imprimirFila(Fila *f) em que imprimos a fila;
@param f, é do tipo Fila que contém os identificador dos vértices;
@return void, retorna nada.
*/
void imprimirFila(Fila *f){
	noFila *auxiliar;
	auxiliar = f -> inicio;
	while (auxiliar != NULL){ 
		printf("%d ", auxiliar -> id);
		auxiliar = auxiliar -> proximo;
	}
	printf("\n");
}

/**
* A função existeFila(Fila *f) em que verificamos
* se tal vértice está na fila;
@param f, é do tipo Fila que contém os identificador dos vértices;
@param vertice, é do tipo inteiro que é identificador do vértice a ser procurado;
@return true ou false, retorna true caso exista ou false caso não exista.
*/
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

/**
* A função limpaFila(Fila *f) em que limpa a fila;
@param f, é do tipo Fila que contém os identificador dos vértices;
@return void, retorna nada.
*/
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