//pila ou filha
//Giancarlo Malfate Caprino, nUSP: 12725025
//Henrique Gualberto Marques, nUSP: 13692380
//Pedro Henrique Cruz da Silva, nUSP: 11833236
//Rafael Scalon Peres Conti, nUSP: 11871181

#include "fila.h"
#include <stdio.h>
#include <stdlib.h>

//variavel estatica para acompanhar a quantidade de nos
static int num_nos;

void criar_fila(t_fila *fila) {
	fila->primeiro = NULL;
	fila->ultimo = NULL;
	num_nos = 0;
}

int vazia(t_fila *fila) { //testa se a fila e' vazia (primeiro e ultimo apontado para NULL)
	if(fila->primeiro == NULL &&
		fila->ultimo == NULL)
		return 1;
	else
		return 0;
}

int enfileirar(t_fila *fila, t_elemento elemento) { //insere elemento no fim da fila

	t_apontador novo = (t_apontador) malloc(sizeof(t_no));
	if (novo == NULL) //caso a memoria esteja cheia
		return ERRO_CHEIA;
	
	novo->elemento = elemento;
	novo->proximo = NULL;
	//caso a fila esteja vazia
	if (vazia(fila)) {
		fila->primeiro = novo;
	} else { //caso a fila nao esteja vazia
		fila->ultimo->proximo = novo;
	}
	fila->ultimo = novo;
	num_nos++; //atualiza o numero de nos

	return SUCESSO;

}

int desenfileirar(t_fila *fila) {

	if (vazia(fila)) //caso a fila esteja vazia
		return NAO_ENCONTROU;

	if (fila->primeiro == fila->ultimo) // caso a fila seja unitaria
		fila->ultimo = NULL;

	t_apontador aux = fila->primeiro;
	int valor = aux->elemento.chave;
	fila->primeiro = fila->primeiro->proximo;
	free(aux);

	num_nos--; //atualiza o numero de nos

	return valor; //retorna o valor (para poder ser comparado)

}

void limpa_fila(t_fila *fila){
	//limpa a fila, desenfileirando todos os elementos 1 a 1
	for(int i = num_nos; i > 0; i--){
		desenfileirar(fila);
	}
}
