//  Nome: Lucas Gabriel de Oliveira Costa
//  Disciplina: Estruturas de Dados I
//  Exercicio 12

#include <stdio.h>
#include <stdlib.h>
#include "listaAlunos.h"

/********** FUNÇOES DE CALLBACK **********/

typedef struct {
    float crTotal;
    int qtd;
} calculoCR;

static int acumula(void* aluno, void* dado){
    calculoCR* CR = (calculoCR*)dado;

    CR->crTotal += retornaCR(aluno);
    CR->qtd++;

    return 1;
}

static int imprime(void* aluno, void* dado){
    imprimeAluno(aluno);

    return 1;
}

static int comparaMatricula(void* aluno, void* matricula){
    Aluno* alunoAux = (Aluno*)aluno;
    int* matriculaAux = (int*)matricula;

    if(retornaMatricula(alunoAux) == *matriculaAux)
        return 0;
    else
        return 1;
}

/*****************************************/

void retiraAluno(ListaGenerica* lista, int matricula){
    retirarDaLista(lista, comparaMatricula, &matricula);
}

int pertenceAluno(ListaGenerica* lista, int matricula){
    return percorrerNaLista(lista, comparaMatricula, &matricula);
}

void imprimeListaAlunos(ListaGenerica* lista){
    percorrerNaLista(lista, imprime, NULL);
}

float mediaTurma(ListaGenerica* lista){
    calculoCR* CR = (calculoCR*) malloc (sizeof(calculoCR));

    CR->crTotal = 0;
    CR->qtd = 0;

    percorrerNaLista(lista, acumula, CR);

    float media = CR->crTotal / CR->qtd;

    free(CR);

    return media;
}