//  Nome: Lucas Gabriel de Oliveira Costa
//  Disciplina: Estruturas de Dados I
//  Exercicio 12

#ifndef EXERCICIO_12_LISTAGENERICA_H
#define EXERCICIO_12_LISTAGENERICA_H

#include "aluno.h"

typedef struct listaGenerica ListaGenerica;

ListaGenerica* inicializaLista();
void inserirNaLista(ListaGenerica* lista, void* item);
void retirarDaLista(ListaGenerica* lista, int (*callback)(void*, void*), void* chave);
int percorrerNaLista(ListaGenerica* lista, int (*callback)(void*, void*), void* dado);
void liberarLista(ListaGenerica* lista);

#endif //EXERCICIO_12_LISTAGENERICA_H
