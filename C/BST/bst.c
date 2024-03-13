//
// Created by Lucas Gabriel on 03/05/2022.
//

#include <stdlib.h>
#include "bst.h"

struct arvore {
    int chave;
    Arvore* esquerda;
    Arvore* direita;
};

Arvore* criarArvoreVazia(){
    return NULL;
}

Arvore* criarArvore(int chave){
    Arvore* arvore = (Arvore*) malloc (sizeof(Arvore));

    arvore->chave = chave;
    arvore->esquerda = NULL;
    arvore->direita = NULL;

    return arvore;
}

Arvore* inserirChave(Arvore* arvore, int chave){
    if(arvore == NULL){
        arvore = criarArvore(chave);
    }
    else if(chave < arvore->chave)
        arvore->esquerda = inserirChave(arvore->esquerda, chave);
    else
        arvore->direita = inserirChave(arvore->direita, chave);

    return arvore;
}

void liberarArvore(Arvore* arvore){

    if(arvore != NULL){
        liberarArvore(arvore->esquerda);
        liberarArvore(arvore->direita);
        free(arvore);
    }
}

static int comparaMax(int a, int b){
    if(a > b)
        return a;
    else
        return b;
}

int alturaBST(Arvore* arvore){
    if(arvore == NULL){
        return -1;
    }
    else {
        return 1 + comparaMax(alturaBST(arvore->esquerda), alturaBST(arvore->direita));
    }
}

int retornarChave(Arvore* arvore){
    return arvore->chave;
}

void rec_preorder(Arvore* arvore, void (*visit)(Arvore*)){

}

void rec_inorder(Arvore* arvore, void (*visit)(Arvore*)){

}

void rec_postorder(Arvore* arvore, void (*visit)(Arvore*)){

}