//pila ou filha
//Giancarlo Malfate Caprino, nUSP: 12725025
//Henrique Gualberto Marques, nUSP: 13692380
//Pedro Henrique Cruz da Silva, nUSP: 11833236
//Rafael Scalon Peres Conti, nUSP: 11871181

#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>

//variavel estatica para acompanhar a quantidade de nos
static int num_nos;

void criar_pilha(t_pilha *pilha) {
	pilha->topo = NULL;
	num_nos = 0;
}

int empilhar(t_pilha *pilha, t_elemento elemento) {

	t_apontador novo = (t_apontador) malloc(sizeof(t_no));
	if (novo == NULL) //se a memoria estiver cheia
		return ERRO_CHEIA;

	novo->elemento = elemento;

	novo->proximo = pilha->topo;
	pilha->topo = novo;
	
	num_nos++;//atualiza o numero de nos

	return SUCESSO;

}

int vazia_pilha(t_pilha *pilha) {
	if(pilha->topo == NULL)//se a pilha estiver vazia 
		return 1;
	else
		return 0;
}

int desempilhar(t_pilha *pilha) {

	if (vazia_pilha(pilha)) //se a pilha estiver vazia
		return NAO_ENCONTROU;

	t_apontador aux = pilha->topo;
	int valor = aux->elemento.chave;
	pilha->topo = pilha->topo->proximo;
	free(aux);

	num_nos--; //atualiza o numero de nos 

	return valor; //retorna o valor (para poder ser comparado)

}

void limpa_pilha(t_pilha *pilha){
	//limpa a pilha, desenpilhando todos os elementos 1 a 1
	for(int i = num_nos; i > 0; i--){
		desempilhar(pilha);
	}
}
