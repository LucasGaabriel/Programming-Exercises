//  Nome: Lucas Gabriel de Oliveira Costa
//  Disciplina: Estruturas de Dados I
//  Exercicio 12

#ifndef EXERCICIO_12_LISTAALUNOS_H
#define EXERCICIO_12_LISTAALUNOS_H

#include "listaGenerica.h"
#include "aluno.h"

void retiraAluno(ListaGenerica* lista, int matricula);
int pertenceAluno(ListaGenerica* lista, int matricula);
void imprimeListaAlunos(ListaGenerica* lista);
float mediaTurma(ListaGenerica* lista);

#endif //EXERCICIO_12_LISTAALUNOS_H
