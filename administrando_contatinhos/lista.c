//Administrando contatinhos
//Giancarlo Malfate Caprino, nUSP: 12725025
//Henrique Gualberto Marques, nUSP: 13692380
//Pedro Henrique Cruz da Silva, nUSP: 11833236
//Rafael Scalon Peres Conti, nUSP: 11871181 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

void criar(t_lista *lista){
    lista->primeiro = NULL;
}

static t_apontador pesquisa_pos(t_lista *lista, t_chave *chave){

    t_apontador P = lista->primeiro;
    //se a lista for vazia, retorna NULL
    if(P == NULL){
	return NULL;
    }
    while(P != NULL) {
	/*strcmp retorna 0 quando as duas strings de entrada sao iguais (e' case sensitive)
	Entao usamos !strcmp() para que, quando as strings forem iguais tenhamos valor 1 (para entrar no if)*/
	if (!strcmp(P->elemento.nome, chave)){
		return P;
	}
	P = P->proximo;
    }
    //se percorreu toda a lista e nao encontrou o elemento, return NULL
    return NULL;
}

t_elemento pesquisar(t_lista *lista, t_chave *chave){
    //chama a funcao static pesquisa_pos e realiza seus operacoes com base em seu retorno
    t_apontador P = pesquisa_pos(lista, chave);
    
    if (P->elemento.nome == NULL) //se pesquisa_pos retornou NULL, o contatinho nao foi encontrado
    printf("Contatinho nao encontrado\n");
    else { //senao, printamos a mensagem padrao e o telefone do contatinho encontrado
    printf("Contatinho encontrado: telefone %u \n", P->elemento.telefone); 
  }
}

int inserir(t_lista *lista, t_elemento elemento){
    //procuramos por um elemento com a mesma chave que o elemento que desejamos inserir:
    if(pesquisa_pos(lista, elemento.nome) == NULL){ //se nao houver um elemento com a mesma chave
	t_apontador novo = (t_apontador) malloc(sizeof(t_no));
	if (novo == NULL){ //caso a memoria esteja cheia
		return MEMORIA_CHEIA;
	}
	
	//processo para alocar o novo elemento (assume o papel de primeiro)
	novo->elemento = elemento;
	novo->proximo = lista->primeiro;
	lista->primeiro = novo;

	return SUCESSO;
	    
    }else{ //caso a chave do elemento que desejamos inserir ja' tenha sido alocada
	return ELEMENTO_REPETIDO;
    }
}

int remover(t_lista *lista, t_chave *chave){
    t_apontador P = lista->primeiro;
    if(P == NULL){//se a lista estiver vazia
	return ELEMENTO_NAO_ENCONTRADO;
    }
	
    //usamos strcmp --- retorna 0 quando duas strings sao iguais
    if(strcmp(P->elemento.nome, chave) == 0){//elemento a ser removido e' o primeiro da lista 
	lista->primeiro = lista->primeiro->proximo;
	free(P);
	return SUCESSO;	    
    }

    while(P->proximo != NULL){ //percorremos a lista ate seu fim (NULL)
	if(strcmp(P->proximo->elemento.nome, chave) == 0){//caso o elemento seja encontrado
		t_apontador auxiliar = P->proximo;
		P->proximo = P->proximo->proximo;
		free(auxiliar);
		return SUCESSO;
	}
	P = P->proximo; //percorremos a lista
    }
    //caso o elemento nao seja encontrado apos percorrer toda a lista
    return ELEMENTO_NAO_ENCONTRADO;
}

int alterar(t_lista *lista, t_chave *chave, t_telefone novo_telefone){
    //chama a funcao static pesquisa_pos e realiza seus operacoes com base em seu retorno
    t_apontador P = pesquisa_pos(lista, chave);
    if(P == NULL){ //elemento nao encontrado (nao podemos alterar)
	return ELEMENTO_NAO_ENCONTRADO;
    } else{//alteramos o telefone como requisitado
	P-> elemento.telefone = novo_telefone; 
    }
}

void liberar(t_lista *lista) {
    //percorre a lista desalocando todos os elementos (utilizado para finalizar o programa)
    t_apontador P = lista->primeiro;

    t_apontador aux = NULL;
	
    while (P!=NULL) {
        aux = P->proximo;
        free(P);
        P = aux;
    }
    free(aux);
}
