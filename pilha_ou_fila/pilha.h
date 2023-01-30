//pila ou filha
//Giancarlo Malfate Caprino, nUSP: 12725025
//Henrique Gualberto Marques, nUSP: 13692380
//Pedro Henrique Cruz da Silva, nUSP: 11833236
//Rafael Scalon Peres Conti, nUSP: 11871181

#include "fila.h"

#ifndef PILHA_H
#define PILHA_H

//MENSAGENS DE RETURN
#define NAO_ENCONTROU -1
#define ERRO_CHEIA 0
#define SUCESSO 1

//Definicoes comentadas, porem utilizadas do fila.h (para evitar redundancia)
/*typedef int t_chave;

typedef struct t_elemento {
	t_chave chave;
} t_elemento;

typedef struct t_no *t_apontador;
typedef struct t_no {
	t_elemento elemento;
	t_apontador proximo;
} t_no;*/

typedef struct {
	t_apontador topo;
} t_pilha;

//listando as funcoes a serem implementadas no pilha.c
void criar_pilha(t_pilha *pilha);
int empilhar(t_pilha *pilha, t_elemento elemento);
int desempilhar(t_pilha *pilha);
int vazia_pilha(t_pilha *pilha);
void limpa_pilha(t_pilha *pilha);

#endif
