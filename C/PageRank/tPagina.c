#include <stdio.h>
#include <stdlib.h>
#include "tPagina.h"

#define RED   true
#define BLACK false

struct nodePagina {
    Pagina *pag;
    bool color;
    tPagina *l;
    tPagina *r;
};

tPagina *tPag_inicia() {
    return NULL;
}

Pagina *tPag_busca(tPagina *t, Pagina *chave) {
    if (!t) return NULL;
    int cmp = pag_compara(chave, t->pag);
    if (cmp > 0) return tPag_busca(t->r, chave);
    else if (cmp < 0) return tPag_busca(t->l, chave);
    else /* cmp == 0 */ return t->pag;                 // Search hit
}

bool isRed(tPagina *t) {
    if (t == NULL) return BLACK;
    return t->color;   //RED == true
}

tPagina *rotate_left(tPagina *t) {
    tPagina *x = t->r;
    t->r = x->l;
    x->l = t;
    x->color = x->l->color;
    x->l->color = RED;
    return x;
}

tPagina *rotate_right(tPagina *t) {
    tPagina *x = t->l;
    t->l = x->r;
    x->r = t;
    x->color = x->r->color;
    x->r->color = RED;
    return x;
}

void flip_colors(tPagina *t) {
    t->color = RED;
    t->l->color = BLACK;
    t->r->color = BLACK;
}

tPagina *tPag_insere(tPagina *t, Pagina *chave) {
    if (!t) {
        t = (tPagina *) malloc(sizeof(tPagina));
        t->pag = chave;
        t->color = RED;
        t->l = t->r = NULL;
        return t;
    }
    int cmp = pag_compara(chave, t->pag); //printf("CMP:: %d\n", cmp);
    if (cmp > 0) t->r = tPag_insere(t->r, chave);
    else if (cmp < 0) t->l = tPag_insere(t->l, chave);

    // lean left.
    if (isRed(t->r) && !isRed(t->l)) t = rotate_left(t);
    // Balance 4-node.
    if (isRed(t->l) && isRed(t->l->l)) t = rotate_right(t);
    // Split 4-node.
    if (isRed(t->l) && isRed(t->r)) flip_colors(t);

    return t;
}

void tPag_parse_vPag(tPagina *t, vPagina *p) {
    if (!t) return;
    vPag_insere(p, t->pag);
    tPag_parse_vPag(t->l, p);
    tPag_parse_vPag(t->r, p);
}

// Insere Paginas from 'orig' to 'dest'
tPagina *tPag_cpy(tPagina *dest, tPagina *orig) {
    if (!orig) return NULL;
    dest = tPag_insere(dest, orig->pag);
    tPag_cpy(dest, orig->l);
    tPag_cpy(dest, orig->r);
    return dest;
}

int tPag_altura(tPagina *t) {
    if (!t) return -1;
    int l = tPag_altura(t->l) + 1;
    int r = tPag_altura(t->r) + 1;
    return (l >= r) ? l : r;
}

void tPag_imprime(tPagina *t, FILE *out) {
    printf("<");
    if (t) {
        pag_imprime(t->pag, out); //fprintf(out, ", %d, ", isRed(t));
        tPag_imprime(t->l, out);
        tPag_imprime(t->r, out);
    }
    printf(">");
}

void tPag_libera(tPagina *t) {
    if (!t) return;
    tPag_libera(t->l);
    tPag_libera(t->r);
    free(t);
}
