// Nome: Lucas Gabriel de Oliveira Costa
// Disciplina: Estruturas de Dados I
// Trabalho 2 - O Compactador de Huffman

#include <stdio.h>
#include <stdlib.h>
#include "listaArvores.h"

typedef struct celula Celula;

struct listaArvores {
    Celula* primeira;
    Celula* ultima;
};

struct celula {
    Arvore* arvore;
    Celula* proxima;
};

ListaArvores* inicializaLista(){
    ListaArvores* lista = (ListaArvores*) malloc (sizeof(ListaArvores));

    lista->primeira = NULL;
    lista->ultima = NULL;

    return lista;
}

void inserirNoFinalDaLista(ListaArvores* lista, Arvore* arvore){
    Celula* nova = (Celula*) malloc (sizeof(Celula));
    nova->arvore = arvore;

    if(lista->primeira == NULL){ //Se a lista estiver vazia
        lista->primeira = nova;
        lista->ultima = nova;
    }
    else{ //Se a lista nao estiver vazia
        lista->ultima->proxima = nova;
        lista->ultima = nova;
    }

    nova->proxima = NULL;
}

void inserirNaListaOrdenadoPorPeso(ListaArvores* lista, Arvore* arvore){
    Celula* aux = lista->primeira;
    Celula* anterior = NULL;

    Celula* nova = (Celula*) malloc (sizeof(Celula));
    nova->arvore = arvore;

    //Busca a posicao correta para colocar a nova arvore, de forma a manter a lista ordenada por peso
    while(aux != NULL && retornaPeso(nova->arvore) >= retornaPeso(aux->arvore)){
        anterior = aux;
        aux = aux->proxima;
    }

    if(lista->primeira == NULL && lista->ultima == NULL){ //Se lista vazia
        lista->primeira = nova;
        nova->proxima = NULL;
        lista->ultima = nova;
    }
    else if(aux == lista->primeira){ //Inserir na Primeira Posicao
        lista->primeira = nova;
        nova->proxima = aux;
    }
    else if(aux == NULL){ //Inserir na Ultima Posicao
        anterior->proxima = nova;
        nova->proxima = NULL;
        lista->ultima = nova;
    }
    else { //Caso comum
        anterior->proxima = nova;
        nova->proxima = aux;
    }
}

void retirarDaListaSemLiberarArvore(ListaArvores* lista, Arvore* arvore){
    Celula* aux = lista->primeira;
    Celula* anterior = NULL;

    //Busca a arvore a ser retirada
    while(aux != NULL && aux->arvore != arvore){
        anterior = aux;
        aux = aux->proxima;
    }

    //Se nao encontrar a arvore, pode sair da funcao
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

void imprimirLista(ListaArvores* lista){
    Celula* aux = lista->primeira;

    while(aux != NULL){
        imprimeArvore(aux->arvore);
        printf("\n");
        aux = aux->proxima;
    }
}

void liberarLista(ListaArvores* lista){
    Celula* aux = lista->primeira;
    Celula* prox;

    while(aux != NULL){
        prox = aux->proxima;
        liberaArvore(aux->arvore);
        free(aux);
        aux = prox;
    }

    free(lista);
}

void ordenarListaCrescente(ListaArvores* lista){
    Celula* aux;
    Celula* anterior = NULL;

    int troca = 1;

    //Continua fazendo a ordenacao, até que a lista esteja completamente ordenada
    while (troca == 1) {
        troca = 0;

        aux = lista->primeira;

        while (aux->proxima != NULL) {

            if (retornaPeso(aux->arvore) > retornaPeso(aux->proxima->arvore)) {
                troca = 1; //Garante mais 1 checagem para verificar se a lista esta completamente ordenada

                if(aux == lista->primeira){ // Se for o primeiro item da lista
                    lista->primeira = aux->proxima;
                    aux->proxima = lista->primeira->proxima;
                    lista->primeira->proxima = aux;
                }
                else{ // Caso comum
                    anterior->proxima = aux->proxima;
                    aux->proxima = anterior->proxima->proxima;
                    anterior->proxima->proxima = aux;
                }
            }

            anterior = aux;

            if(aux->proxima != NULL)
                aux = aux->proxima;
        }
    }
}

Arvore* retornaArvoreDoIndice(ListaArvores* lista, int indice){
    Celula* aux = lista->primeira;
    int i=0;

    //Caminha pela lista ate chegar no indice escolhido ou chegar ao fim da lista
    while(i < indice && aux != NULL){
        aux = aux->proxima;
        i++;
    }

    //Se o indice for valido, retorna a arvore
    if(aux != NULL)
        return aux->arvore;
    else{ //Se o indice for invalido, retorna NULL
        return NULL;
    }
}

int retornaQuantidadeArvoresDaLista(ListaArvores* lista){
    Celula* aux = lista->primeira;
    int i = 0;

    //Caminha pela lista, incrementando a quantidade de arvores
    while(aux != NULL){
        i++;
        aux = aux->proxima;
    }

    return i;
}