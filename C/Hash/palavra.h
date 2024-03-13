//  Nome: Lucas Gabriel de Oliveira Costa
//  Disciplina: Estruturas de Dados I
//  Exercicio 11

#ifndef EXERCICIO_11_PALAVRA_H
#define EXERCICIO_11_PALAVRA_H

typedef struct palavra Palavra;

Palavra* inicializaPalavra(char* string);
char* retornaString(Palavra* palavra);
void incrementaOcorrencia(Palavra* palavra);
int retornaOcorrencias(Palavra* palavra);
Palavra* buscaPalavra(Palavra* palavra, char* string);
Palavra* inserePalavraNaLista(Palavra* lista, Palavra* palavra);
int retornaQuantidadeDePalavrasLista(Palavra* lista);
void imprimeLista(Palavra* lista);
void liberaListaPalavra(Palavra* lista);

#endif //EXERCICIO_11_PALAVRA_H
