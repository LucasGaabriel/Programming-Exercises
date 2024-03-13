// Nome: Lucas Gabriel de Oliveira Costa
// Disciplina: Estruturas de Dados I
// Exercicio_8

#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

#define TAM 5

struct fila{
    Aluno* alunos[TAM];
    int inicio;
    int n;
};

Fila* inicializaFila(void){
    Fila* fila = (Fila*) malloc (sizeof(Fila));
    fila->inicio = 0;
    fila->n = 0;

     return fila;
}

void inserirNaFila(Fila* fila, Aluno* aluno){
    if(fila == NULL || fila->n >= TAM){
        printf("Fila Invalida ou Cheia!\n\n");
        return;
    }

    int final = (fila->inicio + fila->n) % TAM;

    fila->alunos[final] = aluno;
    fila->n++;
}

Aluno* retirarDaFila(Fila* fila) {
    if(fila == NULL || fila->n == 0){
        printf("Fila Invalida ou Vazia!\n\n");
        return NULL;
    }

    Aluno* aluno = fila->alunos[fila->inicio];

    fila->inicio = (fila->inicio + 1) % TAM;
    fila->n--;

    return aluno;
}

void imprimirFila(Fila* fila){
    if(fila == NULL){
        printf("Fila Invalida!\n\n");
        return;
    }
    else if(fila->n == 0){
        printf("Fila Vazia!\n\n");
        return;
    }

    int posicao = 0;

    for(int i=0; i<fila->n; i++){
        posicao = (fila->inicio + i) % TAM;
        imprimeAluno(fila->alunos[posicao]);
    }

    printf("\n");
}

void liberarFila(Fila* fila){
    if(fila == NULL){
        printf("Fila Invalida!\n\n");
        return;
    }

    free(fila);
}
