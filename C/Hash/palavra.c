//  Nome: Lucas Gabriel de Oliveira Costa
//  Disciplina: Estruturas de Dados I
//  Exercicio 11

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "palavra.h"

struct palavra {
    char* string;
    int ocorrencias;
    Palavra* proxima;
};

Palavra* inicializaPalavra(char* string){
    Palavra* palavra = (Palavra*) malloc (sizeof(Palavra));

    palavra->string = strdup(string);
    palavra->ocorrencias = 0;
    palavra->proxima = NULL;

    return palavra;
}

char* retornaString(Palavra* palavra){
    return palavra->string;
}

void incrementaOcorrencia(Palavra* palavra){
    palavra->ocorrencias++;
}

int retornaOcorrencias(Palavra* palavra){
    return palavra->ocorrencias;
}

Palavra* buscaPalavra(Palavra* palavra, char* string){
    Palavra* aux;

    for(aux = palavra; aux != NULL; aux = aux->proxima){
        if(strcmp(aux->string, string) == 0)
            return aux;
    }

    return NULL;
}

Palavra* inserePalavraNaLista(Palavra* lista, Palavra* palavra){
    palavra->proxima = lista;

    return palavra;
}

int retornaQuantidadeDePalavrasLista(Palavra* lista){
    int qtd = 0;

    for(Palavra* aux = lista; aux != NULL; aux = aux->proxima){
        qtd++;
    }

    return qtd;
}

void imprimeLista(Palavra* lista){
    Palavra* aux;

    for(aux = lista; aux != NULL; aux = aux->proxima){
        printf("Palavra: %s | Ocorrencias: %d\n", aux->string, aux->ocorrencias);
    }
}

void liberaListaPalavra(Palavra* lista){
    Palavra* prox;
    Palavra* aux = lista;

    while(aux != NULL){
        prox = aux->proxima;
        free(aux->string);
        free(aux);
        aux = prox;
    }
}