// Nome: Lucas Gabriel de Oliveira Costa
// Disciplina: Estruturas de Dados I
// Exercicio_9

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"

struct arvore {
    Aluno* aluno;
    Arvore* esquerda;
    Arvore* direita;
};

Arvore* criaArvoreVazia(void){
    return NULL;
}

Arvore* criaArvore(Aluno* aluno, Arvore* sae, Arvore* sad){
    Arvore* arvore = (Arvore*) malloc (sizeof(Arvore));

    arvore->aluno = aluno;
    arvore->esquerda = sae;
    arvore->direita = sad;

    return arvore;
}

Arvore* retornaPai(Arvore* arvore, Aluno* aluno){
    if(arvoreVazia(arvore)){
        return NULL;
    }

    if(arvore->esquerda && !strcmp(retornaNomeAluno(arvore->esquerda->aluno), retornaNomeAluno(aluno)) ||
        arvore->direita && !strcmp(retornaNomeAluno(arvore->direita->aluno), retornaNomeAluno(aluno)))
            return arvore;

    Arvore* aux = retornaPai(arvore->esquerda, aluno);

    if(aux == NULL)
        aux = retornaPai(arvore->direita, aluno);

    return aux;
}

int arvoreVazia(Arvore* arvore){
    if(!arvore){
        return 1;
    }
    else {
        return 0;
    }
}

int pertence(Arvore* arvore, char* nome){
    if(arvoreVazia(arvore)){
        return 0;
    }
    else{
        return !strcmp(retornaNomeAluno(arvore->aluno),nome) || pertence(arvore->esquerda, nome) || pertence(arvore->direita, nome);
    }
}

int folhas(Arvore* arvore){
    if(!arvore->esquerda && !arvore->direita)
        return 1;
    else if(arvore->esquerda && !arvore->direita)
        return folhas(arvore->esquerda);
    else if(!arvore->esquerda && arvore->direita)
        return folhas(arvore->direita);
    else
        return folhas(arvore->esquerda) + folhas(arvore->direita);
}

int ocorrencias(Arvore* arvore, Aluno* aluno){
    if(arvoreVazia(arvore)){
        return 0;
    }

    if(!strcmp(retornaNomeAluno(arvore->aluno), retornaNomeAluno(aluno))){
        return 1 + ocorrencias(arvore->esquerda, aluno) + ocorrencias(arvore->direita, aluno);
    }
    else{
        return ocorrencias(arvore->esquerda, aluno) + ocorrencias(arvore->direita, aluno);
    }
}

static int comparaMax(int a, int b){
    if(a > b){
        return a;
    }
    return b;
}

int altura(Arvore* arvore){
    if(!arvore){
        return -1;
    }
    else{
        return 1 + comparaMax(altura(arvore->esquerda), altura(arvore->direita));
    }
}

void imprimeArvore(Arvore* arvore){
    printf("<");
    if(arvore){
        printf("%s", retornaNomeAluno(arvore->aluno));
        imprimeArvore(arvore->esquerda);
        imprimeArvore(arvore->direita);
    }
    printf(">");
}

void liberaArvore(Arvore* arvore){
    if(arvoreVazia(arvore)){
        return;
    }
    else{
        liberaArvore(arvore->esquerda);
        liberaArvore(arvore->direita);
        free(arvore);
    }
}

Aluno* retornaAlunoDoNo(Arvore* arvore){
    return arvore->aluno;
}