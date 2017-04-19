all:
	gcc matriz.c -c
	gcc lista.c -c
	gcc telas.c -c
	gcc opcao.c -c
	gcc busca.c -c
	gcc fila.c -c
	gcc exercicios.c -c
	gcc main.c -o main matriz.o lista.o telas.o opcao.o busca.o fila.o exercicios.o
	./main

compile:
	gcc matriz.c -c
	gcc lista.c -c
	gcc telas.c -c
	gcc opcao.c -c
	gcc busca.c -c
	gcc fila.c -c
	gcc exercicios.c -c
	gcc main.c -o main matriz.o lista.o telas.o opcao.o busca.o fila.o exercicios.o