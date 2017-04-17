#ifndef FILA_H
#define FILA_H

typedef struct noFila{
	int id;
	struct noFila *proximo;
} noFila;

typedef struct Fila{
	noFila *inicio, *fim;
	int tamanho;
} Fila;

void inicializarFila(Fila*);
int vaziaFila(Fila*);
void enfilerarFila(Fila*, int);
int desenfilerarFila(Fila*);
int tamanhoFila(Fila*);
void imprimirFila(Fila*);

#endif /* FILA_H */
