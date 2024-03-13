// Nome: Lucas Gabriel de Oliveira Costa
// Disciplina: Estruturas de Dados I
// Exercicio_8

#include <stdio.h>
#include <stdlib.h>
#include "fila.h"
#include "listaComSentinela.h"

struct fila{
    Lista* lista;
};

Fila* inicializaFila(void){
    Fila* fila = (Fila*) malloc (sizeof(Fila));
    fila->lista = inicializaLista();

    return fila;
}

void inserirNaFila(Fila* fila, Aluno* aluno) {
    inserirNaLista(fila->lista, aluno);
}

Aluno* retirarDaFila(Fila* fila) {
    Aluno* aluno = retirarDaLista(fila->lista, 0);

    if(aluno == NULL){
        printf("Fila Vazia!\n\n");
    }

    return aluno;
}

void imprimirFila(Fila* fila){
    imprimirLista(fila->lista);
}

void liberarFila(Fila* fila){
    liberarLista(fila->lista);
    free(fila);
}