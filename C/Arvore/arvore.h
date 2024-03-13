// Nome: Lucas Gabriel de Oliveira Costa
// Disciplina: Estruturas de Dados I
// Exercicio_9

#ifndef EXERCICIO_9_ARVORE_H
#define EXERCICIO_9_ARVORE_H

#include "aluno.h"

typedef struct arvore Arvore;

Arvore* criaArvoreVazia(void);
Arvore* criaArvore(Aluno* aluno, Arvore* sae, Arvore* sad);
Arvore* retornaPai(Arvore* arvore, Aluno* aluno);
int arvoreVazia(Arvore* arvore);
int pertence(Arvore* arvore, char* nome);
int folhas(Arvore* arvore);
int ocorrencias(Arvore* arvore, Aluno* aluno);
int altura(Arvore* arvore);
void imprimeArvore(Arvore* arvore);
void liberaArvore(Arvore* arvore);
Aluno* retornaAlunoDoNo(Arvore* arvore);

#endif //EXERCICIO_9_ARVORE_H
