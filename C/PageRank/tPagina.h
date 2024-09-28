#ifndef RBT_PAGINA_H
#define RBT_PAGINA_H

#include <stdio.h>
#include <stdbool.h>
#include "vPagina.h"
#include "pagina.h"

typedef struct nodePagina tPagina;

tPagina *tPag_inicia();

Pagina *tPag_busca(tPagina *, Pagina *chave);

tPagina *tPag_insere(tPagina *, Pagina *);

void tPag_parse_vPag(tPagina *, vPagina *);

// Insere Paginas from 'orig' to 'dest'
tPagina *tPag_cpy(tPagina *, tPagina *);

int tPag_altura(tPagina *);

//void tPag_Pagina_insere(tPagina* t, Pagina* pag);
void tPag_imprime(tPagina *, FILE *);

void tPag_libera(tPagina *);

#endif
