all: main.o fila.o pilha.o
	@gcc main.o fila.o pilha.o -o main
	
main.o: main.c
	@gcc main.c -c
	
fila.o: fila.c
	@gcc fila.c -c
    
pilha.o: pilha.c
	@gcc pilha.c -c
	
run:
	@./main
