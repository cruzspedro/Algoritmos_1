//Administrando contatinhos
//Giancarlo Malfate Caprino, nUSP: 12725025
//Henrique Gualberto Marques, nUSP: 13692380
//Pedro Henrique Cruz da Silva, nUSP: 11833236
//Rafael Scalon Peres Conti, nUSP: 11871181 

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "lista.h"

int main(){
    t_lista lista;
    criar(&lista);
    t_elemento elemento;
    t_elemento elemento_aux;
    t_elemento *elemento_x;
    //variavel para receber a operacao e um contador
    char op_entrada;
    int i = 0;
    
    while(i < 1000000000 && op_entrada != '0'){ //enquanto a operacao nao for 0 e nao chegar a 10^9 operacoes
        scanf(" %c", &op_entrada);
        //uso de switch para realizar as operacoes requisitadas
        switch (op_entrada){
            case 'I': //inserir novo contato
                scanf("%s", elemento.nome);
                scanf("%u", &elemento.telefone);
                if(inserir(&lista, elemento) == 0){ // 0 == ELEMENTO_REPETIDO
                    printf("Contatinho ja inserido\n");
                }
            break;

            case 'P': //pesquisar por um contato
                scanf("%s", elemento.nome);
                pesquisar(&lista, elemento.nome);
            break;

            case 'R': //remover um contato
                scanf("%s", elemento.nome);
                if(remover(&lista, elemento.nome) == -2){ //-2 == ELEMENTO_NAO_ENCONTRADO
                    printf("Operacao invalida: contatinho nao encontrado\n");
                }
            break;

            case 'A': //alterar um telefone
                scanf("%s", elemento.nome);
                scanf("%u", &elemento.telefone);
                if(alterar(&lista, elemento.nome, elemento.telefone) == -2){ //-2 == ELEMENTO_NAO_ENCONTRADO
                    printf("Operacao invalida: contatinho nao encontrado\n");
                }
            break;

            case '0': //sair do loop e finalizar o programa (para isso liberamos a memoria utilizando a funcao liberar())
                liberar(&lista); //desaloca todos os nos
            break;
        }
    }

    return 0;
}
