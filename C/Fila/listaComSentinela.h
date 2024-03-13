// Nome: Lucas Gabriel de Oliveira Costa
// Disciplina: Estruturas de Dados I
// Exercicio_8

#ifndef EXERCICIO_8_LISTACOMSENTINELA_H
#define EXERCICIO_8_LISTACOMSENTINELA_H

#include "aluno.h"

typedef struct lista Lista;

Lista* inicializaLista();
void inserirNaLista(Lista* lista, Aluno* aluno);
Aluno* retirarDaLista(Lista* lista, int posicao);
void imprimirLista(Lista* lista);
void liberarLista(Lista* lista);

#endif //EXERCICIO_8_LISTACOMSENTINELA_H
