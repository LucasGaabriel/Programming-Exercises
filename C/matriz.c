// Nome: Lucas Gabriel de Oliveira Costa
// Disciplina: Estruturas de Dados I
// Exercicio_3

#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

struct matriz{
    int **matriz;
    int nLinhas;
    int nColunas;
};

Matriz* inicializaMatriz (int nlinhas, int ncolunas){
    Matriz* matriz = (Matriz*) malloc (sizeof(Matriz));

    matriz->matriz = (int**) malloc (sizeof(int*) * nlinhas);

    for(int i=0; i < nlinhas; i++){
        matriz->matriz[i] = (int*) malloc (sizeof(int) * ncolunas);
    }

    matriz->nLinhas = nlinhas;
    matriz->nColunas = ncolunas;

    return matriz;
}

void modificaElemento (Matriz* mat, int linha, int coluna, int elem){
    mat->matriz[linha][coluna] = elem;
}

int recuperaElemento(Matriz* mat, int linha, int coluna){
    return mat->matriz[linha][coluna];
}

int recuperaNColunas (Matriz* mat){
    return mat->nColunas;
}

int recuperaNLinhas (Matriz* mat){
    return mat->nLinhas;
}

Matriz* transposta (Matriz* mat){
    Matriz* transposta = inicializaMatriz(mat->nColunas, mat->nLinhas);

    for(int i=0; i<recuperaNLinhas(mat); i++){
        for(int j=0; j<recuperaNColunas(mat); j++){
            transposta->matriz[j][i] = recuperaElemento(mat, i, j);
        }
    }

    return transposta;
}

Matriz* multiplicacao (Matriz* mat1, Matriz* mat2){
    Matriz* mult = inicializaMatriz(mat1->nLinhas, mat2->nColunas);

    int result;

    for(int i=0; i<mult->nLinhas; i++){
        for(int j=0; j<mult->nColunas; j++){
            result = 0;
            for(int k=0; k<mat2->nLinhas; k++)
                result += mat1->matriz[i][k] * mat2->matriz[k][j];

            mult->matriz[i][j] = result;
        }
    }

    return mult;
}

void imprimeMatriz(Matriz* mat){
    for(int i=0; i<mat->nLinhas; i++){
        for(int j=0; j<mat->nColunas; j++){
            printf("%d ", mat->matriz[i][j]);
        }
        printf("\n");
    }

    printf("\n");
}

void destroiMatriz(Matriz* mat){

    for(int i=0; i<mat->nLinhas; i++){
        free(mat->matriz[i]);
    }

    free(mat->matriz);
    free(mat);
}