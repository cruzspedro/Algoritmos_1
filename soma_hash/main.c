/*
Somas - Hash com lista dinamica
Giancarlo Malfate Caprino, nUSP: 12725025
Henrique Gualberto Marques, nUSP: 13692380
Pedro Henrique Cruz da Silva, nUSP: 11833236
Rafael Scalon Peres Conti, nUSP: 11871181 
*/


#include "hash.h"
#include <stdio.h>
#include <stdlib.h>


int main(void) {
    int N, M; // numero de elemento do conjunto A e de consultas
    int consulta; // variavel que recebe o numero da consulta

    scanf("%d", &N); // recebe N

    int numeros[N];
    t_hash *tabela_hash[N]; // tabela hash
    criar_hash(tabela_hash, N); // inicia lista "tabela hash"

    for(int i = 0; i < N; i++) {
        scanf("%d", &numeros[i]);
        inserir(tabela_hash, numeros[i], N); // insercao dos numeros do conjunto A na tabela hash
    }

    scanf("%d", &M); // recebe M

    for(int i = 0; i < M; i++) {
        scanf("%d", &consulta); // leitura das consultas

        if(buscar_soma(tabela_hash, N, consulta) == ENCONTRADO) {
            printf("S\n"); // se os dois numeros somados resultam na consulta
        } else {
            printf("N\n"); // se nao
        }
    }
    apagar_hash(tabela_hash, N); // libera espaco alocado da lista "tabela hash"

    return 0;
}