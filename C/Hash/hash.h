//  Nome: Lucas Gabriel de Oliveira Costa
//  Disciplina: Estruturas de Dados I
//  Exercicio 11

#ifndef EXERCICIO_11_HASH_H
#define EXERCICIO_11_HASH_H

#include "palavra.h"

typedef struct hash Hash;

Hash* inicializaHash(int tamanho);
Palavra* acessa(Hash* hash, char* palavra);
void imprimeHash(Hash* hash);
void liberaHash(Hash* hash);

#endif //EXERCICIO_11_HASH_H
