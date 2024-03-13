//  Nome: Lucas Gabriel de Oliveira Costa
//  Disciplina: Estruturas de Dados I
//  Exercicio 11

#include <stdio.h>
#include "hash.h"

#define TamHash 127

#define qtdPalavras 50
#define TamMaxPalavras 100

int main() {
    Hash* hash = inicializaHash(TamHash);

    char palavras[qtdPalavras][TamMaxPalavras] = {"Estruturas", "Esturturas", "Dados", "Ddaos", "Oi", "Oi", "iO",
                                                  "curso", "ocurs", "osruc", "Hello", "World", "Hi", "Lucas", "Lucas",
                                                  "lucas", "teste", "teste", "teste"};

    for(int i=0; i<qtdPalavras && palavras[i][0] != '\0'; i++){
        Palavra* p = acessa(hash, palavras[i]);
        incrementaOcorrencia(p);
    }

    imprimeHash(hash);

    liberaHash(hash);

    return 0;
}
