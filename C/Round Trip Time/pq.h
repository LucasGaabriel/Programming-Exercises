//Nome: Lucas Gabriel de Oliveira Costa
//Matrícula: 2019109482
//Disciplina: Estruturas de Dados II

#ifndef PQ_H
#define PQ_H

#include <stdbool.h>
#include "item.h"

typedef struct priorityQueue PriorityQueue;

PriorityQueue* PQ_init(int maxN); // cria uma min PQ com capacidade maxN
void PQ_insert(PriorityQueue*, Item);   // Insere Item na PQ. A maior prioridade é a do Item com menor campo 'value'
Item PQ_delmin(PriorityQueue*);       // Remove Item com menor campo 'value' da PQ
void PQ_decrease_key(PriorityQueue*, int id, double value); // Muda a prioridade do nó com identificador 'id' para 'value'
Item PQ_min(PriorityQueue*);          // Retorna Item com menor campo 'value' da PQ
bool PQ_empty(PriorityQueue*);        // Retorna True se a PQ não tem elementos
int  PQ_size(PriorityQueue*);         // Número de elementos na PQ
void PQ_finish(PriorityQueue*);       // Libera memória

#endif