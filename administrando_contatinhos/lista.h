//Administrando contatinhos
//Giancarlo Malfate Caprino, nUSP: 12725025
//Henrique Gualberto Marques, nUSP: 13692380
//Pedro Henrique Cruz da Silva, nUSP: 11833236
//Rafael Scalon Peres Conti, nUSP: 11871181 

#ifndef LISTA_H
#define LISTA_H
//MENSAGENS DE RETURN
#define ELEMENTO_NAO_ENCONTRADO -2;
#define MEMORIA_CHEIA -1;
#define ELEMENTO_REPETIDO 0;
#define SUCESSO 1;

//definicoes de tipos:
typedef char t_chave;
typedef unsigned int t_telefone;

typedef struct t_elemento {
	t_chave nome[10];
  	t_telefone telefone;
} t_elemento;

typedef struct t_no *t_apontador;
typedef struct t_no {
	t_elemento elemento;
	t_apontador proximo;
} t_no;

typedef struct {
	t_apontador primeiro;
} t_lista;

//listando as funcoes a serem implementadas no lista.c
void criar(t_lista *lista);
t_elemento pesquisar(t_lista *lista, t_chave *chave);
t_apontador pesquisa_ponteiro(t_lista *lista, t_chave *chave);
int inserir(t_lista *lista, t_elemento elemento);
int remover(t_lista *lista, t_chave *chave);
int alterar(t_lista *lista, t_chave *chave, t_telefone novo_telefone);
void liberar(t_lista *lista);

#endif
