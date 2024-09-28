#ifndef VPAGINA_H
#define VPAGINA_H

#include <stdio.h>
#include "pagina.h"

typedef struct vPag vPagina;

vPagina *vPag_inicia();

void vPag_insere(vPagina *, Pagina *);

// Soma o valor D a pagina no indice dado.
void vPag_pag_somaD(vPagina *, double d, int indice);

// Soma o valor D a todas paginas do vetor.
void vPag_allPag_somaD(vPagina *, double d);

void vPag_resetaValue(vPagina *);

// Retorna todas paginas p, que p->len == len.
vPagina *vPag_comparaValue(vPagina *, int len);

// Retorna a String da pagina no indice dado.
String *vPag_pag_str(vPagina *, int indice);

// Retorna o value da pagina no indice dade.
double vPag_pag_value(vPagina *, int indice);

// Retorna o array de paginas.
Pagina **vPag_pags(vPagina *);

int vPag_len(vPagina *);

void vPag_imprime(vPagina *, FILE *out);

void vPag_libera_mantemPags(vPagina *p); // Nao libera as paginas.
void vPag_libera(vPagina *);       // Libera as paginas.
int compPag(const void *p1, const void *p2);

#endif
