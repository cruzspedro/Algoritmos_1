//pila ou filha
//Giancarlo Malfate Caprino, nUSP: 12725025
//Henrique Gualberto Marques, nUSP: 13692380
//Pedro Henrique Cruz da Silva, nUSP: 11833236
//Rafael Scalon Peres Conti, nUSP: 11871181

#ifndef FILA_H
#define FILA_H

//MENSAGENS DE RETURN
#define NAO_ENCONTROU -1
#define ERRO_CHEIA 0
#define SUCESSO 1

////definicoes de tipos:
typedef int t_chave;

typedef struct t_elemento{
	t_chave chave;
} t_elemento;

typedef struct t_no *t_apontador;
typedef struct t_no {
	t_elemento elemento;
	t_apontador proximo;
} t_no;

typedef struct {
	t_apontador primeiro;
	t_apontador ultimo;
} t_fila;

//listando as funcoes a serem implementadas no fila.c
void criar_fila(t_fila *fila);
int enfileirar(t_fila *fila, t_elemento elemento);
int desenfileirar(t_fila *fila);
void limpa_fila(t_fila *fila);

#endif
