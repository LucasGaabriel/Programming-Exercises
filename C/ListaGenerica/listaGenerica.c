//  Nome: Lucas Gabriel de Oliveira Costa
//  Disciplina: Estruturas de Dados I
//  Exercicio 12

#include <stdio.h>
#include <stdlib.h>
#include "listaGenerica.h"

typedef struct celula Celula;

struct listaGenerica {
    Celula* primeira;
    Celula* ultima;
};

struct celula {
    void* item;
    Celula* proxima;
};

ListaGenerica* inicializaLista(){
    ListaGenerica* lista = (ListaGenerica*) malloc (sizeof(ListaGenerica));

    lista->primeira = NULL;
    lista->ultima = NULL;

    return lista;
}

//Insere no final da lista
void inserirNaLista(ListaGenerica* lista, void* item){
    Celula* nova = (Celula*) malloc (sizeof(Celula));
    nova->item = item;

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

void retirarDaLista(ListaGenerica* lista, int (*callback)(void*, void*), void* chave){
    Celula* aux = lista->primeira;
    Celula* anterior = NULL;

    while(aux != NULL && callback(aux->item, chave)){
        anterior = aux;
        aux = aux->proxima;
    }

    if(aux == NULL) {
        return;
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
    }//Caso comum
    else {
        anterior->proxima = aux->proxima;
    }

    free(aux);
}

int percorrerNaLista(ListaGenerica* lista, int (*callback)(void*, void*), void* dado){
    Celula* aux = lista->primeira;

    while(aux != NULL){

        if(!callback(aux->item, dado))
            return 0;

        aux = aux->proxima;
    }

    return 1;
}

void liberarLista(ListaGenerica* lista){
    Celula* aux = lista->primeira;
    Celula* prox;

    while(aux != NULL){
        prox = aux->proxima;
        free(aux);
        aux = prox;
    }

    free(lista);
}