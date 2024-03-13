// Nome: Lucas Gabriel de Oliveira Costa
// Disciplina: Estruturas de Dados I
// Exercicio_6

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "professor.h"

struct professor{
    char* nome;
    int siape;
    float salario;
};

Professor* inicializaProfessor(char* nome, int siape, float salario){
    Professor* professor = (Professor*) malloc (sizeof(Professor));

    professor->nome = strdup(nome);
    professor->siape = siape;
    professor->salario = salario;

    return professor;
}

void imprimeProfessor(Professor* professor){
    printf("Nome: %s, Siape: %d, Salario: %.2f\n", professor->nome, professor->siape, professor->salario);
}

char* retornaNomeProfessor(Professor* professor){
    return professor->nome;
}

int retornaSiape(Professor* professor){
    return professor->siape;
}

float retornaSalario(Professor* professor){
    return professor->salario;
}

void liberaProfessor(Professor* professor){
    free(professor->nome);
    free(professor);
}
