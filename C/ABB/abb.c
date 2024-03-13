// Nome: Lucas Gabriel de Oliveira Costa
// Disciplina: Estruturas de Dados I
// Exercicio 10

#include <stdio.h>
#include <stdlib.h>
#include "abb.h"

struct arvore {
    Aluno* aluno;
    Arvore* esquerda;
    Arvore* direita;
};

Arvore* criaAbb(Aluno* aluno){
    Arvore* arvore = (Arvore*) malloc (sizeof(Arvore));

    arvore->aluno = aluno;
    arvore->esquerda = NULL;
    arvore->direita = NULL;

    return arvore;
}

void imprimeAbb(Arvore* arvore){
    if(arvore != NULL){
        imprimeAbb(arvore->esquerda);
        imprimeAluno(arvore->aluno);
        imprimeAbb(arvore->direita);
    }
}

Arvore* buscaAbb(Arvore* arvore, int matricula){
    if(arvore == NULL){
        return NULL;
    }

    if(matricula < retornaMatricula(arvore->aluno))
        return buscaAbb(arvore->esquerda, matricula);
    else if(matricula > retornaMatricula(arvore->aluno))
        return buscaAbb(arvore->direita, matricula);
    else
        return arvore;
}

Arvore* inserirAbb(Arvore* arvore, Aluno* aluno){
    if(arvore == NULL){
        arvore = criaAbb(aluno);
    }
    else if(retornaMatricula(aluno) < retornaMatricula(arvore->aluno))
        arvore->esquerda = inserirAbb(arvore->esquerda, aluno);
    else
        arvore->direita = inserirAbb(arvore->direita, aluno);

    return arvore;
}

Arvore* retirarAbb(Arvore* arvore, int matricula){
    if(arvore == NULL)
        return NULL;
    else if(matricula < retornaMatricula(arvore->aluno))
        arvore->esquerda = retirarAbb(arvore->esquerda, matricula);
    else if(matricula > retornaMatricula(arvore->aluno))
        arvore->direita = retirarAbb(arvore->direita, matricula);
    else {
        if(arvore->esquerda == NULL && arvore->direita == NULL){ // No folha
            free(arvore);
            arvore = NULL;
        }
        else if(arvore->esquerda == NULL){ // Filho somente a direita
            Arvore* aux = arvore;
            arvore = arvore->direita;
            free(aux);
        }
        else if(arvore->direita == NULL){ // Filho somente a esquerda
            Arvore* aux = arvore;
            arvore = arvore->esquerda;
            free(aux);
        }
        else{ // 2 Filhos

            //Busca antecessor
            Arvore* antecessor = arvore->esquerda;
            while(antecessor->direita != NULL)
                antecessor = antecessor->direita;

            //Troca os Alunos
            Aluno* aux = arvore->aluno;
            arvore->aluno = antecessor->aluno;
            antecessor->aluno = aux;

            arvore->esquerda = retirarAbb(arvore->esquerda, matricula);
        }
    }

    return arvore;
}

void liberarAbb(Arvore* arvore){
    if(arvore != NULL){
        liberarAbb(arvore->esquerda);
        liberarAbb(arvore->direita);
        free(arvore);
    }
}
