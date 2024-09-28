// Nome: Lucas Gabriel de Oliveira Costa
// Disciplina: Estruturas de Dados I
// Trabalho 2 - O Compactador de Huffman

#include <stdio.h>
#include <stdlib.h>
#include "huffman.h"

int main(int argc, char* argv[]) {
    if(argc == 1){ //Se nenhum arquivo for passado como parametro na execucao do programa
        printf("Insira o nome do arquivo a ser descompactado!\n");
        exit(1);
    }

    if(argc > 2){ //Se mais de um arquivo for passado como parametro na execucao do programa
        printf("Apenas um arquivo por execucao!\n");
        exit(1);
    }

    descompactador(argv[1]); //Descompactador, passando como parametro o nome do arquivo a ser descompactado

    return 0;
}