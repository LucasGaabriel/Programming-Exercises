// Nome: Lucas Gabriel de Oliveira Costa
// Estruturas de Dados I
// Exercicio 5

#include <stdio.h>
#include "listadpl.h"

#define qtdLinhas 3
#define qtdColunas 3

void geraValoresMatriz(Matriz* matriz, int seed){

    for(int i=0; i<recuperaNLinhas(matriz); i++){
        for(int j=0; j< recuperaNColunas(matriz); j++){
            modificaElemento(matriz, i, j, (i+j+seed));
        }
    }
}

int main() {
    Matriz* matriz1 = inicializaMatriz(qtdLinhas, qtdColunas);
    Matriz* matriz2 = inicializaMatriz(qtdLinhas, qtdColunas);
    Matriz* matriz3 = inicializaMatriz(qtdLinhas, qtdColunas);

    geraValoresMatriz(matriz1, 1);
    geraValoresMatriz(matriz2, 2);
    geraValoresMatriz(matriz3, 3);

    Lista* lista = inicializaLista();

    lista = inserirNaLista(lista, matriz1);
    lista = inserirNaLista(lista, matriz2);
    lista = inserirNaLista(lista, matriz3);

    printf("Imprimindo Lista Inicial:\n");
    imprimirLista(lista);

    printf("Retirando a PRIMEIRA Matriz da Lista:\n");
    lista = retirarDaLista(lista, 1);
    imprimirLista(lista);

    printf("Inserindo novamente a Matriz na Lista:\n");
    lista = inserirNaLista(lista, matriz3);
    imprimirLista(lista);

    printf("Retirando a ULTIMA Matriz da Lista:\n");
    lista = retirarDaLista(lista, 3);
    imprimirLista(lista);

    printf("Inserindo novamente a Matriz na Lista:\n");
    lista = inserirNaLista(lista, matriz1);
    imprimirLista(lista);

    printf("Retirando a Matriz do MEIO da Lista:\n");
    lista = retirarDaLista(lista, 2);
    imprimirLista(lista);

    printf("Inserindo novamente a Matriz na Lista:\n");
    lista = inserirNaLista(lista, matriz3);
    imprimirLista(lista);

    printf("Tentando retirar posicoes invalidas da Lista:\n");
    lista = retirarDaLista(lista, 0);
    lista = retirarDaLista(lista, 4);
    lista = retirarDaLista(lista, 5);
    imprimirLista(lista);

    liberarLista(lista);
    destroiMatriz(matriz1);
    destroiMatriz(matriz2);
    destroiMatriz(matriz3);

    return 0;
}
