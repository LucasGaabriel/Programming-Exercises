// Nome: Lucas Gabriel de Oliveira Costa
// Disciplina: Estruturas de Dados I
// Exercicio_8

#include <stdio.h>
#include <stdlib.h>
#include "listaComSentinela.h"

typedef struct celula Celula;

struct celula {
    Aluno* aluno;
    Celula* proxima;
};

struct lista {
    Celula* primeira;
    Celula* ultima;
};

Lista* inicializaLista(){
    Lista* lista = (Lista*) malloc (sizeof(Lista));

    lista->primeira = NULL;
    lista->ultima = NULL;

    return lista;
}

//Insere no final da lista
void inserirNaLista(Lista* lista, Aluno* aluno){
    Celula* nova = (Celula*) malloc (sizeof(Celula));
    nova->aluno = aluno;

    if(lista->primeira == NULL){
        lista->primeira = nova;
        lista->ultima = nova;
    }
    else{
        lista->ultima->proxima = nova;
        lista->ultima = nova;
    }

    nova->proxima = NULL;
}

Aluno* retirarDaLista(Lista* lista, int posicao){ //Posicao iniciando em 0
    Celula* aux = lista->primeira;
    Celula* anterior = NULL;

    for(int i=0; i<posicao && aux != NULL; i++){
        anterior = aux;
        aux = aux->proxima;
    }

    if(aux == NULL) {
        return NULL;
    }

    //Unico elemento
    if(aux == lista->primeira && aux == lista->ultima){
        lista->primeira = NULL;
        lista->ultima = NULL;
    }//Se for o primeiro
    else if(aux == lista->primeira){
        lista->primeira = aux->proxima;
    }//Se for o ultimo
    else if(aux == lista->ultima){
        lista->ultima = anterior;
        anterior->proxima = NULL;
    }
    else {//Caso comum
        anterior->proxima = aux->proxima;
    }

    Aluno* aluno = aux->aluno;
    free(aux);

    return aluno;
}

void imprimirLista(Lista* lista){
    Celula* aux = lista->primeira;

    while(aux != NULL){
        imprimeAluno(aux->aluno);
        aux = aux->proxima;
    }
    printf("\n");
}

void liberarLista(Lista* lista){
    Celula* aux = lista->primeira;
    Celula* prox;

    while(aux != NULL){
        prox = aux->proxima;
        free(aux);
        aux = prox;
    }

    free(lista);
}