// Nome: Lucas Gabriel de Oliveira Costa
// Disciplina: Estruturas de Dados I
// Exercicio_9

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"

struct aluno {
    char* nome;
    int matricula;
    float cr;
};

Aluno* inicializaAluno(char* nome, int matricula, float cr){
    Aluno* aluno = (Aluno*) malloc (sizeof(Aluno));

    aluno->nome = strdup(nome);
    aluno->matricula = matricula;
    aluno->cr = cr;

    return aluno;
}

void imprimeAluno(Aluno* aluno){
    printf("Nome: %s, Matricula: %d, CR: %.2f\n", aluno->nome, aluno->matricula, aluno->cr);
}

char* retornaNomeAluno(Aluno* aluno){
    return aluno->nome;
}

int retornaMatricula(Aluno* aluno){
    return aluno->matricula;
}

float retornaCR(Aluno* aluno){
    return aluno->cr;
}

void liberaAluno(Aluno* aluno){
    free(aluno->nome);
    free(aluno);
}
