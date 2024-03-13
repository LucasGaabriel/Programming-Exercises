// Nome: Lucas Gabriel de Oliveira Costa
// Estruturas de Dados I
// Exercicio 4

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "listaMat.h"

void geraMatrizAleatoria(Matriz* matriz){

    for(int i=0; i<recuperaNLinhas(matriz); i++){
        for(int j=0; j< recuperaNColunas(matriz); j++){
            modificaElemento(matriz, i, j, rand()%50);
        }
    }
}

int main() {
    Matriz* matriz1 = inicializaMatriz(3, 3);
    Matriz* matriz2 = inicializaMatriz(4, 4);
    Matriz* matriz3 = inicializaMatriz(4, 5);
    Matriz* matriz4 = inicializaMatriz(3, 4);

    srand(time(NULL));
    geraMatrizAleatoria(matriz1);
    geraMatrizAleatoria(matriz2);
    geraMatrizAleatoria(matriz3);
    geraMatrizAleatoria(matriz4);

    Lista* lista1 = inicializaLista();

    inserirNaLista(lista1, matriz1);
    inserirNaLista(lista1, matriz2);
    inserirNaLista(lista1, matriz3);
    inserirNaLista(lista1, matriz4);

    Lista* lista2 = inicializaLista();

    Matriz* transposta1 = transposta(matriz1);
    Matriz* transposta2 = transposta(matriz2);
    Matriz* transposta3 = transposta(matriz3);
    Matriz* transposta4 = transposta(matriz4);

    inserirNaLista(lista2, transposta1);
    inserirNaLista(lista2, transposta2);
    inserirNaLista(lista2, transposta3);
    inserirNaLista(lista2, transposta4);

    printf("(LISTA 1)\n");
    imprimirLista(lista1);
    printf("(LISTA 2)\n");
    imprimirLista(lista2);

    retirarDaLista(lista1, 1);
    retirarDaLista(lista1, 2);
    retirarDaLista(lista2, 4);
    retirarDaLista(lista2, 2);

    printf("---Depois de retirar algumas matrizes---\n");

    printf("(LISTA 1)\n");
    imprimirLista(lista1);
    printf("(LISTA 2)\n");
    imprimirLista(lista2);

    printf("---Inserindo as matrizes novamente nas listas---\n");

    inserirNaLista(lista1, matriz1);
    inserirNaLista(lista1, matriz3);
    inserirNaLista(lista2, transposta4);
    inserirNaLista(lista2, transposta2);

    printf("(LISTA 1)\n");
    imprimirLista(lista1);
    printf("(LISTA 2)\n");
    imprimirLista(lista2);

    liberarLista(lista1);
    liberarLista(lista2);

    destroiMatriz(matriz1);
    destroiMatriz(matriz2);
    destroiMatriz(matriz3);
    destroiMatriz(matriz4);

    destroiMatriz(transposta1);
    destroiMatriz(transposta2);
    destroiMatriz(transposta3);
    destroiMatriz(transposta4);

    return 0;
}
