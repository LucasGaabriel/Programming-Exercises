// Nome: Lucas Gabriel de Oliveira Costa
// Disciplina: Estruturas de Dados I
// Trabalho 2 - O Compactador de Huffman

#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

struct arvore {
    unsigned char caracter;
    unsigned int peso;
    Arvore* esquerda;
    Arvore* direita;
};

Arvore* criaArvore(char caracter, unsigned int peso, Arvore* sae, Arvore* sad){
    Arvore* arvore = (Arvore*) malloc (sizeof(Arvore));

    arvore->caracter = caracter;
    arvore->peso = peso;
    arvore->esquerda = sae;
    arvore->direita = sad;

    return arvore;
}

Arvore* retornaSubarvoreEsquerda(Arvore* arvore){
    return arvore->esquerda;
}

Arvore* retornaSubarvoreDireita(Arvore* arvore){
    return arvore->direita;
}

unsigned char retornaCaracter(Arvore* arvore){
    return arvore->caracter;
}

unsigned int retornaPeso(Arvore* arvore){
    if(arvore)
        return arvore->peso;
    else
        return -1;
}

void imprimeArvore(Arvore* arvore){
    printf("<");
    if(arvore){
        printf("%c", arvore->caracter);
        imprimeArvore(arvore->esquerda);
        imprimeArvore(arvore->direita);
    }
    printf(">");
}

void liberaArvore(Arvore* arvore){
    if(!arvore){
        return;
    }
    else{
        liberaArvore(arvore->esquerda);
        liberaArvore(arvore->direita);
        free(arvore);
    }
}