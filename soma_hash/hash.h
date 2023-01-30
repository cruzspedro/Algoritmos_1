/*
Somas - Hash com lista dinamica
Giancarlo Malfate Caprino, nUSP: 12725025
Henrique Gualberto Marques, nUSP: 13692380
Pedro Henrique Cruz da Silva, nUSP: 11833236
Rafael Scalon Peres Conti, nUSP: 11871181 
*/


#ifndef HASH_H
#define HASH_H


// DEFINICOES DE MENSAGENS
#define ENCONTRADO 1
#define NAO_ENCONTRADO 0


// definicoes de estrutura da hash - lista dinamica
typedef int t_chave;
typedef struct t_hash *t_apontador; // tipo apontador da hash
// estrutura da hash
typedef struct t_hash {
  t_chave valor; // valor do elemento na hash
  t_apontador proximo; // apontador para o proximo da lista hash
} t_hash;


// lista de funcoes a serem implementadas no hash.c
// de tratamento
void apagar_hash(t_hash **tabela_hash, int tam);
void criar_hash(t_hash **tabela_hash, int tam);
// operacionais
int buscar_soma(t_hash **tabela_hash, int tam, int soma);
void inserir(t_hash **tabela_hash, t_chave valor, int tam);


#endif