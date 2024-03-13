// Nome: Lucas Gabriel de Oliveira Costa
// Disciplina: Estruturas de Dados I
// Exercicio_6

#ifndef EXERCICIO_6_PROFESSOR_H
#define EXERCICIO_6_PROFESSOR_H

typedef struct professor Professor;

Professor* inicializaProfessor(char* nome, int siape, float salario);
void imprimeProfessor(Professor* professor);
char* retornaNomeProfessor(Professor* professor);
int retornaSiape(Professor* professor);
float retornaSalario(Professor* professor);
void liberaProfessor(Professor* professor);

#endif //EXERCICIO_6_PROFESSOR_H
