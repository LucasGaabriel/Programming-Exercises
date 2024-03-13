// Nome: Lucas Gabriel de Oliveira Costa
// Estruturas de Dados I
// Exercicio 5

#ifndef EXERCICIO_5_MATRIZ_H
#define EXERCICIO_5_MATRIZ_H

typedef struct matriz Matriz;

Matriz* inicializaMatriz (int nlinhas, int ncolunas);

void modificaElemento (Matriz* mat, int linha, int coluna, int elem);

int recuperaElemento(Matriz* mat, int linha, int coluna);

int recuperaNColunas (Matriz* mat);

int recuperaNLinhas (Matriz* mat);

Matriz* transposta (Matriz* mat);

Matriz* multiplicacao (Matriz* mat1, Matriz* mat2);

void imprimeMatriz(Matriz* mat);

void destroiMatriz(Matriz* mat);

#endif //EXERCICIO_5_MATRIZ_H
