// Nome: Lucas Gabriel de Oliveira Costa
// Estruturas de Dados I
// Exercicio 4

#include <stdio.h>
#include <stdlib.h>
#include "listaMat.h"

typedef struct celula Celula;

struct celula {
    Matriz* matriz;
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
void inserirNaLista(Lista* lista, Matriz* matriz){
    Celula* nova = (Celula*) malloc (sizeof(Celula));
    nova->matriz = matriz;

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

void retirarDaLista(Lista* lista, int posicao){ //Posicao iniciando em 1
    Celula* aux = lista->primeira;
    Celula* anterior = NULL;

    for(int i=1; i<posicao && aux != NULL; i++){
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
    }
    else {//Caso comum
        anterior->proxima = aux->proxima;
    }

    free(aux);
}

void imprimirLista(Lista* lista){
    Celula* aux = lista->primeira;
    int i = 1;
    while(aux != NULL){
        printf("Matriz %d:\n", i);
        imprimeMatriz(aux->matriz);

        aux = aux->proxima;
        i++;
    }
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
