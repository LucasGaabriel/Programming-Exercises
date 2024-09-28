//Nome: Lucas Gabriel de Oliveira Costa
//Matrícula: 2019109482
//Disciplina: Estruturas de Dados II

#ifndef ITEM_H
#define ITEM_H

typedef struct {
    int id;           // Identificador do Nó
    double value;     // Valor associado ao Nó
} Item;

#define id(A)           (A.id)                          // Retorna Identificador do Nó
#define value(A)        (A.value)                       // Retorna Valor do Nó
#define more(A, B)      (value(A) > value(B))           // Compara Nós por Valor
#define exch(A, B)      { Item t = A; A = B; B = t; }   // Troca Dois Nós

//Cria um Item com 'id' e 'value'
Item make_item(int id, double value);

#endif