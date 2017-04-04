all:
	gcc matriz.c -c
	gcc lista.c -c
	gcc telas.c -c
	gcc opcao.c -c
	gcc main.c -o main matriz.o lista.o telas.o opcao.o 
	./main