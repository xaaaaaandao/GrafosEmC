#ifndef FILA_H
#define FILA_H

/* Definindo algumas estruturas */
typedef struct noFila{
	int id;
	struct noFila *proximo;
} noFila;

typedef struct Fila{
	noFila *inicio, *fim;
	int tamanho;
} Fila;

/* Protótipo das funções */
void inicializarFila(Fila*);
int vaziaFila(Fila*);
void enfilerarFila(Fila*, int);
int desenfilerarFila(Fila*);
int tamanhoFila(Fila*);
void imprimirFila(Fila*);
bool existeFila(Fila *, int);
void limpaFila(Fila*);

#endif /* FILA_H */
