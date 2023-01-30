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

// funcao que cria a lista "tabela hash"
void criar_hash(t_hash **tabela_hash, int tam) {
    for(int i = 0; i < tam; i++) {
        tabela_hash[i] = NULL; // inicializa a tabela hash com "vazio"
    }
}

// funcao que apaga a lista "tabela hash" e libera o espaco alocado
void apagar_hash(t_hash **tabela_hash, int tam) {
    t_apontador P; // aponta para a chave/elemento da tabela
    t_apontador aux = NULL; // iniciado

    for (int i = 0; i < tam; i++) {
        P = tabela_hash[i]; // comeca no primeiro elemento da tabela
        
        while (P != NULL) { // desaloca elemento da tabela e torna seu proximo o primeiro
            aux = P->proximo;
            free(P);
            P = aux;
        }
        free(aux);
    }
}


// funcao interna que calcula o indice da tabela hash
static int indice_hash(t_hash **tabela_hash, t_chave valor, int tam){
    int indice = valor % tam; // hash modular

    return indice;
}

// funcao que faz a consulta e analisa se existem dois numeros na tabela hash que satisfazem a soma
// tratamento de colisoes via enderecamento externo
int buscar_soma(t_hash **tabela_hash, int tam, int soma) {
    int resultado, indice;
    t_apontador P,P2; // apontadores da lista

    for(int i = 0; i < tam; i++) {
        P = tabela_hash[i]; // aponta para a chave/elemento da tabela que faz parte da diferenca

        while(P) { // enquanto P nao vazio
            resultado = (soma - P->valor); // valor procurado
            indice = indice_hash(tabela_hash, resultado, tam); // posicao do valor procurado na tabela hash(se existir)
            if(indice >= 0){ 
                P2 = tabela_hash[indice]; // aponta para a chave/elemento diferenca da tabela
                while(P2) { // enquanto P2 nao vazio
                    if(P2->valor == resultado){ // encontrado se existir (retorna 1)
                        return ENCONTRADO;
                    }
                    P2 = P2->proximo;
                } 
            }
            P = P->proximo;
        }
    } 
    return NAO_ENCONTRADO; // caso nao seja encontrado (retorna 0)
}         

// funcao que insere o numero na lista "tabela hash"
void inserir(t_hash **tabela_hash, t_chave valor, int tam) {
    int indice;
    t_apontador novo_elemento; // aponta para a chave/elemento a ser inserido na tabela hash
	novo_elemento = (t_apontador) malloc(sizeof(t_hash)); // aloca o apontador

    indice = indice_hash(tabela_hash, valor, tam); // posicao do valor a ser inserido na tabela hash
    
    novo_elemento->valor = valor; // novo primeiro
    novo_elemento->proximo = tabela_hash[indice]; // antigo primeiro agora proximo
    tabela_hash[indice] = novo_elemento; // o novo elemento é inserido na sua posicao linear da lista
}