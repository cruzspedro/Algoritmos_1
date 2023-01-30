all: main.o hash.o
	@gcc main.o hash.o -o main
	
main.o: main.c
	@gcc main.c -c
	
hash.o: hash.c
	@gcc hash.c -c
	
run:
	@./main

zip:
	zip -r trab.zip *