// Nome: Lucas Gabriel de Oliveira Costa
// Estruturas de Dados I
// Exercicio 5

#ifndef EXERCICIO_5_LISTADPL_H
#define EXERCICIO_5_LISTADPL_H

#include "matriz.h"

typedef struct lista Lista;

Lista* inicializaLista();

Lista* inserirNaLista(Lista* lista, Matriz* matriz);

Lista* retirarDaLista(Lista* lista, int posicao);

void imprimirLista(Lista* lista);

void liberarLista(Lista* lista);

#endif //EXERCICIO_5_LISTADPL_H
