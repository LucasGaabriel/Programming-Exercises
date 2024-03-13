// Nome: Lucas Gabriel de Oliveira Costa
// Disciplina: Estruturas de Dados I
// Exercicio_6

#ifndef EXERCICIO_6_ALUNO_H
#define EXERCICIO_6_ALUNO_H

typedef struct aluno Aluno;

Aluno* inicializaAluno(char* nome, int matricula, float cr);
void imprimeAluno(Aluno* aluno);
char* retornaNomeAluno(Aluno* aluno);
int retornaMatricula(Aluno* aluno);
float retornaCR(Aluno* aluno);
void liberaAluno(Aluno* aluno);

#endif //EXERCICIO_6_ALUNO_H
