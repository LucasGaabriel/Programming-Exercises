//  Nome: Lucas Gabriel de Oliveira Costa
//  Disciplina: Estruturas de Dados I
//  Exercicio 7

#ifndef EXERCICIO_7_PILHADUPLA_H
#define EXERCICIO_7_PILHADUPLA_H
#define maxTam 1000

typedef struct pilhaDupla PilhaDupla;
typedef int tipoItem;

PilhaDupla* inicializaPilha();
void push(PilhaDupla* pilha, tipoItem* item, int inserirNaPilha);
void pop(PilhaDupla* pilha, int retirarDaPilha);
void imprimePilha(PilhaDupla* pilha);
void liberaPilha(PilhaDupla* pilha);

#endif //EXERCICIO_7_PILHADUPLA_H
