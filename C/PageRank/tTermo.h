#ifndef RBT_TERMO_H
#define RBT_TERMO_H

#include <stdio.h>
#include <stdbool.h>
#include "termo.h"
#include "pagina.h"

typedef struct nodeTermo tTermo;

tTermo *tTermo_inicia();

Termo *tTermo_busca(tTermo *, Termo *chave);

tTermo *tTermo_insere(tTermo *, Termo *);

int tTermo_altura(tTermo *);

//void tTermo_termo_insere(tTermo* t, Pagina* pag);
void tTermo_imprime(tTermo *, FILE *);

void tTermo_libera(tTermo *);

#endif
