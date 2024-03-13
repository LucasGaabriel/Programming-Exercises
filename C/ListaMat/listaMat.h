// Nome: Lucas Gabriel de Oliveira Costa
// Estruturas de Dados I
// Exercicio 4

#ifndef EXERCICIO_4_LISTAMAT_H
#define EXERCICIO_4_LISTAMAT_H

#include "matriz.h"

typedef struct lista Lista;

Lista* inicializaLista();

void inserirNaLista(Lista* lista, Matriz* matriz);

void retirarDaLista(Lista* lista, int posicao);

void imprimirLista(Lista* lista);

void liberarLista(Lista* lista);

#endif //EXERCICIO_4_LISTAMAT_H
