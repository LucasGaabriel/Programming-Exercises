// Nome: Lucas Gabriel de Oliveira Costa
// Disciplina: Estruturas de Dados I
// Exercicio_8

#ifndef EXERCICIO_8_FILA_H
#define EXERCICIO_8_FILA_H

#include "aluno.h"

typedef struct fila Fila;

Fila* inicializaFila(void);
void inserirNaFila(Fila* fila, Aluno* aluno); //Sempre ao final da fila
Aluno* retirarDaFila(Fila* fila); //Sempre do inicio da fila
void imprimirFila(Fila* fila);
void liberarFila(Fila* fila);

#endif //EXERCICIO_8_FILA_H
