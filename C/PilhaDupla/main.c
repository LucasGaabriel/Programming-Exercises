//  Nome: Lucas Gabriel de Oliveira Costa
//  Disciplina: Estruturas de Dados I
//  Exercicio 7

#include <stdio.h>
#include "pilhaDupla.h"

int main() {
    PilhaDupla* pilha = inicializaPilha();

    int inteiro1 = 10, inteiro2 = 20, inteiro3 = 30, inteiro4 = 40;

    printf("*** Pilha Dupla de Inteiros ***\n\n");

    push(pilha, &inteiro1, 0);
    push(pilha, &inteiro2, 0);
    push(pilha, &inteiro3, 0);
    push(pilha, &inteiro4, 0);

    printf("Inserindo os elementos em AMBAS as Pilhas:\n");
    imprimePilha(pilha);

    pop(pilha, 0);
    pop(pilha, 0);
    pop(pilha, 0);
    pop(pilha, 0);

    printf("Removendo os elementos de AMBAS as Pilhas:\n");
    imprimePilha(pilha);

    printf("Tentativa de Remover elementos na Pilha1 vazia:\n");
    pop(pilha, 1);
    printf("Tentativa de Remover elementos na Pilha2 vazia:\n");
    pop(pilha, 2);
    printf("Tentativa de Remover elementos em ambas as Pilhas vazias:\n");
    pop(pilha, 0);

    push(pilha, &inteiro1, 1);
    push(pilha, &inteiro2, 2);
    push(pilha, &inteiro3, 1);
    push(pilha, &inteiro4, 2);

    push(pilha, &inteiro1, 2);
    push(pilha, &inteiro2, 1);
    push(pilha, &inteiro3, 2);
    push(pilha, &inteiro4, 1);

    printf("Inserindo nas pilhas alternadamente:\n");
    imprimePilha(pilha);

    pop(pilha, 1);
    pop(pilha, 2);
    pop(pilha, 0);

    printf("Removendo dois elementos de cada pilha:\n");
    imprimePilha(pilha);

    printf("Testando o Limite da Pilha:\n");

    for(int i=0; i < maxTam/2; i++){
        push(pilha, &i, 0);
    }

    liberaPilha(pilha);
    return 0;
}
