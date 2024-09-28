#ifndef PAGINA_H
#define PAGINA_H

#include <stdio.h>
#include "string.h"

typedef struct pagina Pagina;

Pagina *pag_cria(char *);

int pag_compara(Pagina *, Pagina *);

void pag_somaD(Pagina *, double d);

void pag_resetaValue(Pagina *);

String *pag_str(Pagina *);

double pag_value(Pagina *);

void pag_imprime(Pagina *, FILE *);

void pag_libera(Pagina *);

#endif
