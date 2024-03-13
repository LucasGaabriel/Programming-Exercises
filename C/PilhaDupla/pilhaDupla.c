//  Nome: Lucas Gabriel de Oliveira Costa
//  Disciplina: Estruturas de Dados I
//  Exercicio 7

#include <stdio.h>
#include <stdlib.h>
#include "pilhaDupla.h"

#define AMBAS 0
#define PILHA1 1
#define PILHA2 2

typedef struct {
    int topo, base;
}indicePilha;

struct pilhaDupla {
    tipoItem* item[maxTam];
    indicePilha pilha1, pilha2;
};

PilhaDupla* inicializaPilha(){
    PilhaDupla* p = (PilhaDupla*) malloc (sizeof (PilhaDupla));
    p->pilha1.base = 0;
    p->pilha1.topo = -1; //Cresce para a direita
    p->pilha2.base = maxTam -1;
    p->pilha2.topo = maxTam; //Cresce para a esquerda

    return p;
}

// Inteiro 'inserirNaPilha' define em quais Pilhas o item deve ser adicionado.
// 0 para Ambas as Pilhas, 1 para Pilha1, 2 para Pilha2;
void push(PilhaDupla* pilha, tipoItem* item, int inserirNaPilha){

    if(pilha == NULL || item == NULL){
        printf("Pilha ou Item invalidos!\n");
        return;
    }
    else if(pilha->pilha1.topo == pilha->pilha2.topo -1){
        printf("Pilha Cheia!\n");
        return;
    }

    if(inserirNaPilha == AMBAS){
        pilha->pilha1.topo++;
        pilha->pilha2.topo--;

        pilha->item[pilha->pilha1.topo] = item;
        pilha->item[pilha->pilha2.topo] = item;
    }
    else if(inserirNaPilha == PILHA1){
        pilha->pilha1.topo++;
        pilha->item[pilha->pilha1.topo] = item;
    }
    else if(inserirNaPilha == PILHA2){
        pilha->pilha2.topo--;
        pilha->item[pilha->pilha2.topo] = item;
    }
}

// Inteiro 'retirarDaPilha' define em quais Pilhas deve ser retirado um item.
// 0 para Ambas as Pilhas, 1 para Pilha1, 2 para Pilha2;
void pop(PilhaDupla* pilha, int retirarDaPilha){

    if(pilha == NULL){
        printf("Pilha Invalida!\n\n");
        return;
    }

    if(retirarDaPilha == AMBAS){
        if(pilha->pilha1.topo == -1 || pilha->pilha2.topo == maxTam){
            printf("Uma das Pilhas ou Ambas estao vazias!\n\n");
            return;
        }

        pilha->pilha1.topo--;
        pilha->pilha2.topo++;
    }
    else if(retirarDaPilha == PILHA1){
        if(pilha->pilha1.topo == -1){
            printf("Pilha 1 vazia!\n\n");
            return;
        }

        pilha->pilha1.topo--;
    }
    else if(retirarDaPilha == PILHA2){
        if(pilha->pilha2.topo == maxTam){
            printf("Pilha 2 vazia!\n\n");
            return;
        }

        pilha->pilha2.topo++;
    }
}

void imprimePilha(PilhaDupla* pilha){

    printf("Pilha 1:\n");
    for(int i=pilha->pilha1.topo; i >= pilha->pilha1.base; i--){
        printf("%d\n", *pilha->item[i]);
    }
    if(pilha->pilha1.topo == -1)
        printf("Pilha 1 vazia!\n");

    printf("\nPilha 2:\n");
    for(int i=pilha->pilha2.topo; i <= pilha->pilha2.base; i++){
        printf("%d\n", *pilha->item[i]);
    }
    if(pilha->pilha2.topo == maxTam)
        printf("Pilha 2 vazia!\n");

    printf("\n");
}

void liberaPilha(PilhaDupla* pilha){
    free(pilha);
}