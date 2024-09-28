//Nome: Lucas Gabriel de Oliveira Costa
//Matrícula: 2019109482
//Disciplina: Estruturas de Dados II

#include <stdio.h>
#include <stdlib.h>
#include "network.h"

int main(int argc, char* argv[]){
    if(argc != 3){
        printf("Argumentos do programa inválidos.\n");
        exit(EXIT_FAILURE);
    }

    //Cálculo das Inflações nos RTTs
    InflacaoRTTs(argv[1], argv[2]);

    return 0;
}
