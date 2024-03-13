// Nome: Lucas Gabriel de Oliveira Costa
// Disciplina: Estruturas de Dados I
// Exercicio 10

#ifndef EXERCICIO_10_ABB_H
#define EXERCICIO_10_ABB_H

#include "aluno.h"

typedef struct arvore Arvore;

Arvore* criaAbb(Aluno* aluno);
void imprimeAbb(Arvore* arvore);
Arvore* buscaAbb(Arvore* arvore, int matricula);
Arvore* inserirAbb(Arvore* arvore, Aluno* aluno);
Arvore* retirarAbb(Arvore* arvore, int matricula);
void liberarAbb(Arvore* arvore);

#endif //EXERCICIO_10_ABB_H
