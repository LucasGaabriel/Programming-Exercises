#include <stdio.h>
#include <stdlib.h>
#include "tTermo.h"

#define RED   true
#define BLACK false

struct nodeTermo {
    Termo *termo;
    bool color;
    tTermo *l;
    tTermo *r;
};

tTermo *tTermo_inicia() {
    return NULL;
}

Termo *tTermo_busca(tTermo *t, Termo *chave) {
    if (!t) return NULL;
    int cmp = termo_compara(chave, t->termo);
    if (cmp > 0) return tTermo_busca(t->r, chave);
    else if (cmp < 0) return tTermo_busca(t->l, chave);
    else /* cmp == 0 */ return t->termo;                 // Search hit
}

bool RBT_isRed(tTermo *t) {
    if (t == NULL) return BLACK;
    return t->color;   //RED == true
}

tTermo *RBT_rotate_left(tTermo *t) {
    tTermo *x = t->r;
    t->r = x->l;
    x->l = t;
    x->color = x->l->color;
    x->l->color = RED;
    return x;
}

tTermo *RBT_rotate_right(tTermo *t) {
    tTermo *x = t->l;
    t->l = x->r;
    x->r = t;
    x->color = x->r->color;
    x->r->color = RED;
    return x;
}

void RBT_flip_colors(tTermo *t) {
    t->color = RED;
    t->l->color = BLACK;
    t->r->color = BLACK;
}

tTermo *tTermo_insere(tTermo *t, Termo *chave) {
    if (!t) {
        t = (tTermo *) malloc(sizeof(tTermo));
        t->termo = chave;
        t->color = RED;
        t->l = t->r = NULL;
        return t;
    }
    int cmp = termo_compara(chave, t->termo);
    if (cmp > 0) t->r = tTermo_insere(t->r, chave);
    else if (cmp < 0) t->l = tTermo_insere(t->l, chave);
    else {
        termo_atualiza(t->termo, chave);
        termo_libera(chave);
        //return t;
    }

    // lean left.
    if (RBT_isRed(t->r) && !RBT_isRed(t->l)) t = RBT_rotate_left(t);
    // Balance 4-node.
    if (RBT_isRed(t->l) && RBT_isRed(t->l->l)) t = RBT_rotate_right(t);
    // Split 4-node.
    if (RBT_isRed(t->l) && RBT_isRed(t->r)) RBT_flip_colors(t);

    return t;
}

int tTermo_altura(tTermo *t) {
    if (!t) return -1;
    int l = tTermo_altura(t->l) + 1;
    int r = tTermo_altura(t->r) + 1;
    return (l >= r) ? l : r;
}

/*void tTermo_termo_insere(tTermo* t, Pagina* pag) {
  if(!t) return;
  if(!pag) printf("ERRO tTermo\n");
  tTermo_termo_insere(t->l, pag);
  tTermo_termo_insere(t->r, pag);
  termo_insere(t->termo, pag);
}*/
void tTermo_imprime(tTermo *t, FILE *out) {
    printf("<");
    if (t) {
        termo_imprime(t->termo, out); //fprintf(out, ", %d, ", RBT_isRed(t));
        tTermo_imprime(t->l, out);
        tTermo_imprime(t->r, out);
    }
    printf(">");
}

void tTermo_libera(tTermo *t) {
    if (!t) return;
    tTermo_libera(t->l);
    tTermo_libera(t->r);
    termo_libera(t->termo);
    free(t);
}
