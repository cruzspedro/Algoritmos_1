/*
Giancarlo Malfate Caprino, nUSP: 12725025
Henrique Gualberto Marques, nUSP: 13692380
Pedro Henrique Cruz da Silva, nUSP: 11833236
Rafael Scalon Peres Conti, nUSP: 11871181 
*/

#ifndef AVL_H
#define AVL_H

//MENSAGENS DE RETURN
#define JA_EXISTE -2
#define NAO_ENCONTROU -1
#define ERRO_CHEIA 0
#define SUCESSO 1

//definicoes de tipo
typedef long unsigned t_telefone;
typedef struct {
	t_telefone telefone;
	int chave;
} t_elemento;
typedef struct t_no* t_apontador;
typedef struct t_no {
	t_elemento elemento;
	t_apontador esq, dir;
	int altura;
} t_no;

typedef t_apontador t_avl;

//lista de funcoes a serem implementadas no AVL.c
void criar(t_avl *avl);
int retornar_altura(t_avl *avl);
int checar_fator_de_balanceamento(t_avl *avl);
int alterar(t_avl *avl, int chave, t_telefone novo_telefone);
int inserir(t_avl *avl, t_elemento elemento);
t_elemento pesquisar(t_avl *avl, int chave);
int remover(t_avl *avl, int chave);
void liberar(t_avl *avl);

#endif