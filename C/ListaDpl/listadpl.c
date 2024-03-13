// Nome: Lucas Gabriel de Oliveira Costa
// Estruturas de Dados I
// Exercicio 5

#include <stdio.h>
#include <stdlib.h>
#include "listadpl.h"

struct lista {
    Matriz* matriz;
    Lista* proxima;
    Lista* anterior;
};

Lista* inicializaLista(){
    return NULL;
}

Lista* inserirNaLista(Lista* lista, Matriz* matriz){
    Lista* nova = (Lista*) malloc (sizeof(Lista));

    nova->matriz = matriz;
    nova->proxima = lista;
    nova->anterior = NULL;

    if(lista != NULL)
        lista->anterior = nova;

    return nova;
}

Lista* retirarDaLista(Lista* lista, int posicao){ //Posicao inicia em 1
    Lista* aux = lista;

    if(posicao == 0)
        return lista;

    for(int i=1; i<posicao && aux != NULL; i++){
        aux = aux->proxima;
    }

    if(aux == NULL)
        return lista;

    //Unico elemento
    if(lista->proxima == NULL && lista->anterior == NULL){
        lista = NULL;
    }//Se for o primeiro
    else if(aux == lista){
        lista = aux->proxima;
    }//Se for o ultimo
    else if(aux->proxima == NULL){
        aux->anterior->proxima = NULL;
    }
    else {//Caso comum
        aux->anterior->proxima = aux->proxima;
        aux->proxima->anterior = aux->anterior;
    }

    free(aux);

    return lista;
}

void imprimirLista(Lista* lista){
    Lista* aux = lista;
    int i = 1;
    while(aux != NULL){
        printf("Matriz %d:\n", i);
        imprimeMatriz(aux->matriz);

        aux = aux->proxima;
        i++;
    }
}

void liberarLista(Lista* lista){
    Lista* aux = lista;
    Lista* prox;

    while(aux != NULL){
        prox = aux->proxima;
        free(aux);
        aux = prox;
    }
}
