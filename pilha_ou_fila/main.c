//pila ou filha
//Giancarlo Malfate Caprino, nUSP: 12725025
//Henrique Gualberto Marques, nUSP: 13692380
//Pedro Henrique Cruz da Silva, nUSP: 11833236
//Rafael Scalon Peres Conti, nUSP: 11871181

#include<stdio.h>
#include<stdlib.h>
#include"fila.h"
#include"pilha.h"

int main(){
    int quant_teste;
    scanf("%d", &quant_teste); //recebe a quantidade de testes
    int quant_op;
    char op;
    t_elemento elemento;
    
    /*
    flag_pilha: responsavel por verificar a possibilidade de ser pilha (0 se houve operacao que fere a pilha, 1 se pode ser pilha) - LIFO
    flag_fila: responsavel por verificar a possibilidade de ser fila (0 se houve operacao que fere a fila, 1 se pode ser fila) - FIFO
    Para ser pilha (flag_pilha = 1, flag_fila = 0)
    Para ser fila (flag_pilha = 0, flag_fila = 1)
    Indefinido (pode ser qualquer um dos dois, logo: flag_pilha = 1, flag_fila = 1)
    Impossivel (nao pode ser nenhum dos dois, logo: flag_pilha = 0, flag_fila = 0)
    */
    
    int flag_pilha, flag_fila; //0 ou 1;

    //for para percorrer todas as linhas da entrada (testes)
    for(int i = 0; i < quant_teste; i++){
        //flags recebem valor 1 para iniciar o teste (pois a cada teste podemos ter tanto uma pilha quanto uma fila)
        flag_fila = 1;
        flag_pilha = 1;
        scanf("%d ", &quant_op); //recebe a quantidade de operacoes
        
        //criamos tanto a pilha quanto a fila para realizar cada teste
        t_fila fila;
        criar_fila(&fila);
        
        t_pilha pilha;
        criar_pilha(&pilha);

        for(int j = 0; j < quant_op; j++){//realizamos as operacoes
            scanf("%c %d ", &op, &elemento.chave); //lemos a operacao e a chave
            if(op == 'i'){ //inserir
                enfileirar(&fila, elemento); //apara a fila
                empilhar(&pilha, elemento); //para a pilha
            } else if(op == 'r'){ //remover
                int testa_fila = desenfileirar(&fila); //recebe o elemento desenfileirado (respeitando FIFO)
                if(testa_fila != elemento.chave){ //se o elemento desenfileirado for diferendo do elemento lido
                    flag_fila = 0;
                }

                int testa_pilha = desempilhar(&pilha); //recebe o elemento desempilhado (respeitando LIFO)
                if(testa_pilha != elemento.chave){ //se o elemento desempilado for diferendo do elemento lido
                    flag_pilha = 0;
                }
            }
        }
        //limpa a fila e a pilha antes de iniciar uma nova rodada de testes
        limpa_fila(&fila);
        limpa_pilha(&pilha);

        //tratamento de saidas (seguindo a logica apresentada):
        /*
        Para ser pilha (flag_pilha = 1, flag_fila = 0)
        Para ser fila (flag_pilha = 0, flag_fila = 1)
        Indefinido (pode ser qualquer um dos dois, logo: flag_pilha = 1, flag_fila = 1)
        Impossivel (nao pode ser nenhum dos dois, logo: flag_pilha = 0, flag_fila = 0)
        */
        if(flag_pilha == 0 && flag_fila == 1){
            printf("fila\n");
        } else if(flag_pilha == 1 && flag_fila == 0){
            printf("pilha\n");
        } else if(flag_pilha == 1 && flag_fila == 1){
            printf("indefinido\n");
        } else if(flag_pilha == 0 && flag_fila == 0){
            printf("impossivel\n");
        }
    }
    return 0;
}
