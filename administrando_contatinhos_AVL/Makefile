all: main.o AVL.o
	@gcc main.o AVL.o -o main
	
main.o: main.c
	@gcc main.c -c
	
AVL.o: AVL.c
	@gcc AVL.c -c
	
run:
	@./main

zip:
	zip -r trab.zip *