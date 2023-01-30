/*
Giancarlo Malfate Caprino, nUSP: 12725025
Henrique Gualberto Marques, nUSP: 13692380
Pedro Henrique Cruz da Silva, nUSP: 11833236
Rafael Scalon Peres Conti, nUSP: 11871181 
*/

#include "AVL.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Funcao basica para retornar o maior dentre 2 valores
static int maior(int a, int b) {
	if (a > b)
    {
        return a;
    }
    else return b;
}

//definindo as rotacoes
//As nomenclaturas sao referentes as insercoes feitas. ex: LL -> duas insercoes a esquerda (left)
static void rotacao_LL(t_avl *avl) {

    //no auxiliar
	t_apontador no;

    //rotacao LL, isto eh, rotacao à direita 
    no = (*avl)->esq;
    (*avl)->esq = no->dir;
    no->dir = *avl;
    //atualizando alturas
    (*avl)-> altura = maior(retornar_altura(&(*avl)->esq), retornar_altura(&(*avl)->dir)) + 1;
    no->altura = maior(retornar_altura(&no->esq), (*avl)->altura) + 1;

    //atualizando a nova raiz da subarvore
    (*avl) = no;

}

static void rotacao_RR(t_avl *avl) {

    //no auxiliar
    t_apontador no;

    //rotacao RR, isto eh, rotacao à esquerda
    no = (*avl)->dir;
    (*avl)->dir = no->esq;
    no->esq = *avl;

    //atualizando alturas
    (*avl)->altura = maior(retornar_altura(&(*avl)->esq), retornar_altura(&(*avl)->dir)) + 1;
    no->altura = maior(retornar_altura(&no->dir), (*avl)->altura) + 1;
    (*avl) = no;
}

//rotacao RR + rotacao LL
static void rotacao_LR(t_avl *avl) {

	rotacao_RR(&(*avl)->esq);
    rotacao_LL(avl);

}

//Rotacao LL + rotacao RR
static void rotacao_RL(t_avl *avl) {
	rotacao_LL(&(*avl)->dir);
    rotacao_RR(avl);
}

//Inicializa uma AVL
void criar(t_avl *avl) {
	*avl = NULL;
}

//funcao que cria uma raiz ao inserir um novo elemento em folha ou arvore vazia
static int criar_raiz(t_avl *avl, t_elemento elemento){

	*avl = (t_avl) malloc(sizeof(t_no));
	if (*avl == NULL)
		return ERRO_CHEIA;
	
	(*avl)->esq = NULL;
	(*avl)->dir = NULL;
	(*avl)->elemento = elemento;
	(*avl)->altura= 0;

	return SUCESSO;

}

//retorna, caso encontre, a altura da raiz da subarvore indicada
int retornar_altura(t_avl *avl) {
    if ((*avl) == NULL)
        return NAO_ENCONTROU;
    else{
        return (*avl)->altura;
    }
}

// fator de balanceamento = altura do filho a esquerda - altura do filho a direita
int checar_fator_de_balanceamento(t_avl *avl) {
    if ((*avl) == NULL)
        return 0;
    else{ 
        return retornar_altura(&(*avl)->esq) - retornar_altura(&(*avl)->dir);
    }
}

//funcao recursiva que insere e verifica o fator de balanceamento dos nos envolvidos
int inserir(t_avl *avl, t_elemento elemento) {

    //se nao houver nenhum valor, i.e, arvore vazia ou no folha
	if ((*avl)==NULL) {
		return criar_raiz(avl, elemento);
	}
/*
    if(elemento.chave == 773593376) {
        printf("chave = %d   chave do no atual = %d\n", elemento.chave, (*avl)->elemento.chave);
        printf("%d\n", elemento.chave == (*avl)->elemento.chave);
    }
*/
	//se ja houver o elemento, desconsiderar a acao
	if ((*avl)->elemento.chave == elemento.chave) {
        printf("Contatinho ja inserido\n");
		return JA_EXISTE;
	} else {

        //caso a chave seja menor, vai pra esquerda
		if (elemento.chave < (*avl)->elemento.chave) {
			inserir(&(*avl)->esq, elemento);
			(*avl)->altura= maior((*avl)->altura,
						retornar_altura(&(*avl)->esq) + 1);
		} else { //caso seja maior, vai pra direita
			inserir(&(*avl)->dir, elemento);
			(*avl)->altura= maior((*avl)->altura,
						retornar_altura(&(*avl)->dir) + 1);
		}
	}

    //balanceamento
	int fb = checar_fator_de_balanceamento(avl);

    //insercao a esquerda
	if (fb >= 2) {

		int fb_filho = checar_fator_de_balanceamento(&(*avl)->esq);

        //novamente a esquerda
		if (fb_filho >=0) {
			rotacao_LL(avl);
}   //ou a direita
    else {
			rotacao_LR(avl);
		}
      //insercao a direita
	} else if (fb <= -2) { 

		int fb_filho = checar_fator_de_balanceamento(&(*avl)->dir);

        //novamente a direita
		if (fb_filho <= 0) {
			rotacao_RR(avl);
		}
        //ou a esquerda 
        else {
			rotacao_RL(avl);
		}

	}

    return SUCESSO;

}

//funcao para pesquisar um elemento pela chave, desta vez retornando o proprio elemento
t_elemento pesquisar(t_avl *avl, int chave) {

	if ((*avl)==NULL) {
		t_elemento resultado;
		resultado.chave = NAO_ENCONTROU;
		return resultado;
	}
    //caso encontre
	if ((*avl)->elemento.chave == chave) {
		return (*avl)->elemento;
	} else {
        //se a chave for menor, procura na esquerda
		if (chave < (*avl)->elemento.chave) {
			return pesquisar(&(*avl)->esq, chave);
		} else { // se for maior, procura na direita
			return pesquisar(&(*avl)->dir, chave);
		}

	}

}

//Funcao que procura um elemento pela chave e, caso encontre, troca o telefone antigo pelo novo
int alterar(t_avl *avl, int chave, t_telefone novo_telefone){
    //caso n encontre
    if ((*avl)==NULL) {
		printf("Operacao invalida: contatinho nao encontrado\n");
        return 1;
	}
    //caso encontre
	if ((*avl)->elemento.chave == chave) {
		(*avl)->elemento.telefone = novo_telefone;
        return 0;
	} else {
        //se a chave for menor, procura na esquerda
		if (chave < (*avl)->elemento.chave) {
			return alterar(&(*avl)->esq, chave, novo_telefone);
		} else { // se for maior, procura na direita
			return alterar(&(*avl)->dir, chave, novo_telefone);
		}
	}
}

//Funcao que procura o menor valor dentro da subarvore indicada. Funciona como funcao auxiliar da remocao
static t_apontador procurar_menor(t_avl *avl){
	t_apontador (aux1);
 	t_apontador (aux2);
    (aux1) = (*avl);
    (aux2) = (aux1)->esq;
    while((aux2) != NULL){
        (aux1) = (aux2);
        (aux2) = (aux1)->esq;
    }
    return (aux1);
}

//Funcao que remove um elemento da avl, balanceando-a no processo
int remover(t_avl *avl, int chave) {
    if((*avl) == NULL){
        printf("Operacao invalida: contatinho nao encontrado\n");
        return NAO_ENCONTROU;
    }
    if(chave < (*avl)->elemento.chave){
        remover(&(*avl)->esq, chave);
        if(checar_fator_de_balanceamento(&(*avl)) < -1){
            if(checar_fator_de_balanceamento(&(*avl)->dir) <= 0){
                rotacao_RR(&(*avl));
            }
            else{
                rotacao_RL(&(*avl));
            }
        }
        (*avl)->altura = maior(retornar_altura(&(*avl)->esq), retornar_altura(&(*avl)->dir)) + 1;
    }
    else if(chave > (*avl)->elemento.chave){
        remover(&(*avl)->dir, chave);
        if(checar_fator_de_balanceamento(&(*avl)) > 1){
            if(checar_fator_de_balanceamento(&(*avl)->esq) >= 0){
                rotacao_LL(&(*avl));
            }
            else{
                rotacao_LR(&(*avl));
            }
        }
        (*avl)->altura = maior(retornar_altura(&(*avl)->esq), retornar_altura(&(*avl)->dir)) + 1;
    }
    else if(chave == (*avl)->elemento.chave){
        if((*avl)->dir == NULL || (*avl)->esq == NULL){
            if((*avl)->esq == NULL){
                (*avl) = (*avl)->dir;
            }
            else{
                (*avl) = (*avl)->esq;
            }
        }
        else{
            t_apontador aux;
            (aux) = procurar_menor(&(*avl)->dir);
            (*avl)->elemento = (aux)->elemento;
            remover(&(*avl)->dir, (*avl)->elemento.chave);
            if(checar_fator_de_balanceamento(&(*avl)) > 1){
                if(checar_fator_de_balanceamento(&(*avl)->esq) >= 0){
                    rotacao_LL(&(*avl));
                }
                else{
                    rotacao_LR(&(*avl));
                }
            }
        }   
    }
}

//funcao que libera a AVL ao fim do programa
void liberar(t_avl *avl){
    if((*avl) == NULL){
        return;
    }
    liberar(&(*avl)->esq);
    liberar(&(*avl)->dir);
    free(*avl);
}