/*
Giancarlo Malfate Caprino, nUSP: 12725025
Henrique Gualberto Marques, nUSP: 13692380
Pedro Henrique Cruz da Silva, nUSP: 11833236
Rafael Scalon Peres Conti, nUSP: 11871181 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "AVL.h"

/*void printaAVL(t_avl *avl){
    if((*avl) == NULL){
        return;
    }
    printaAVL(&(*avl)->esq);
    printf("%d\n", (*avl)->elemento.chave);
    printaAVL(&(*avl)->dir);
}
*/

//Funcao para transformar strings em inteiros (afim de realizar uma busca binaria por chaves na AVL)
int transforma(char* nome){
    int resultado = 0;
    int tam = strlen(nome);
    for (int i = 0; i < tam && i <= 10; i++)
    {
        resultado += ((long long int) (23*19*71*i*i*i+1)*nome[i]*nome[i]) % (1000000007);
        resultado %= (1000000007);
    }
    return resultado;
}

//Funcao principal na qual a AVL sera criada, os dados coletados e armazenados e as operacoes feitas
int main() {

    //Declaracao e criacao da AVL
    t_avl avl;
    criar(&avl);

    //Declaracao de variaveis que auxiliaram nas operacoes
    char* aux;
    aux = malloc(sizeof(char)*10);
    t_elemento elemento;
    
    //variavel que coleta a operação da vez
    char op;
    //variavel que conta o numero de operacoes ate entao
    while(op != '0'){
        scanf(" %c", &op);
        switch (op)
        {
        case 'I': //insercao
            scanf("%s", aux);
            elemento.chave = transforma(aux);
            scanf("%ld", &elemento.telefone);
            //printf("elemento = %d\n", elemento.chave);
            /*
            if (inserir(&avl, elemento) == JA_EXISTE)
            {
                printf("Contatinho ja inserido\n");
            }      */
            inserir(&avl, elemento);
            break;

        case 'P'://Pesquisar por um contato
            scanf("%s", aux);
            elemento = pesquisar(&avl, transforma(aux));
            if(elemento.chave == -1){
                printf("Contatinho nao encontrado\n");
            }
            else{
                printf("Contatinho encontrado: telefone %ld\n", elemento.telefone);
            }
            break;

        case 'A'://Alterar um numero
            scanf("%s", aux);
            elemento.chave = transforma(aux);
            scanf("%ld", &elemento.telefone);
            alterar(&(avl), elemento.chave, elemento.telefone);

            break;

        case 'R'://Remove um contatinho inserido previamente
            scanf("%s", aux);
            elemento.chave = transforma(aux);
            /*
            if(remover(&avl, elemento.chave) == -1){
                printf("Operacao invalida: contatinho nao encontrado\n");
            }*/
            remover(&avl, elemento.chave);
            break;
        
        case '0'://Interrompe o loop do código
            liberar(&avl);
            break;
        }
    }
    
	return 0;
}

/*

*/