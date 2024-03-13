// Nome: Lucas Gabriel de Oliveira Costa
// Disciplina: Estruturas de Dados I
// Exercicio_6

#ifndef EXERCICIO_6_LISTAHET_H
#define EXERCICIO_6_LISTAHET_H

#include "aluno.h"
#include "professor.h"

typedef struct lista Lista;

Lista* inicializaLista();
void inserirAlunoNaLista(Lista* lista, Aluno* aluno);
void inserirProfessorNaLista(Lista* lista, Professor* professor);
void retirarDaLista(Lista* lista, char* nome);
void imprimirLista(Lista* lista);
float valorChurrasco(Lista* lista);
void liberarLista(Lista* lista);

#endif //EXERCICIO_6_LISTAHET_H
