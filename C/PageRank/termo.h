#ifndef TERMO_H
#define TERMO_H

#include <stdio.h>
#include "string.h"
#include "tPagina.h"
#include "vPagina.h"
#include "pagina.h"

typedef struct termo Termo;

Termo *termo_cria(char *);

// Cria e converte char maiusculas em minusculas.
Termo *termo_cria_converte(char *);

void termo_insere(Termo *t, Pagina *pag);

int termo_compara(Termo *, Termo *);

String *termo_str(Termo *);

// Insere Paginas from tree Pagina to vector Pagina.
void termo_parse_vPag(Termo *, vPagina *);

// Insere Paginas from 'orig' to 'dest'.
void termo_atualiza(Termo *dest, Termo *orig);

void termo_imprime(Termo *, FILE *);

void termo_libera(Termo *);

#endif
