#include <stdio.h>
#include <stdlib.h>
#include "termo.h"

struct termo {
    String *str;      // Termo em si.
    tPagina *tPag;    // Red-Black BST de paginas.
};

Termo *termo_cria(char *s) {
    Termo *p = (Termo *) malloc(sizeof(Termo));
    p->str = str_cria(s);
    p->tPag = tPag_inicia();
    return p;
}

Termo *termo_cria_converte(char *s) {
    Termo *p = (Termo *) malloc(sizeof(Termo));
    p->str = str_cria_converte(s);
    p->tPag = tPag_inicia();
    return p;
}


void termo_insere(Termo *t, Pagina *pag) {
    t->tPag = tPag_insere(t->tPag, pag);
}

int termo_compara(Termo *p, Termo *q) {
    return str_compara(p->str, q->str);
}

String *termo_str(Termo *p) {
    return p->str;
}

tPagina *termo_tPag(Termo *p) {
    return p->tPag;
}

// Parser tree Pagina to vector Pagina
void termo_parse_vPag(Termo *t, vPagina *p) {
    tPag_parse_vPag(t->tPag, p);
}

void termo_atualiza(Termo *dest, Termo *orig) {
    if (!dest || !orig) return;
    dest->tPag = tPag_cpy(dest->tPag, orig->tPag);
}

void termo_imprime(Termo *p, FILE *out) {
    str_imprime(p->str, out);
    /*fprintf(out, " (");
    tPag_imprime(p->tPag, out);
    fprintf(out, " )\n");*/
}

void termo_libera(Termo *p) {
    str_libera(p->str);
    tPag_libera(p->tPag);
    free(p);
}
