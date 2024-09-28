#include "vPagina.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX_INICIAL 20

struct vPag {
    Pagina **pags;
    int len;
    int max;
};

vPagina *vPag_inicia() {
    vPagina *v = (vPagina *) malloc(sizeof(vPagina));
    v->len = 0;
    v->max = MAX_INICIAL;
    v->pags = (Pagina **) malloc(sizeof(Pagina *) * v->max);
    return v;
}

void vPag_insere(vPagina *p, Pagina *pag) {
    if (!p || !pag)
        printf("ERRO\n\n\n\n\n\n");
    if (p->len >= p->max) {
        p->max *= 2;
        p->pags = (Pagina **) realloc(p->pags, sizeof(Pagina *) * p->max);
    }
    p->pags[p->len++] = pag;
}

// Soma o valor D a pagina no indice dado.
void vPag_pag_somaD(vPagina *p, double d, int i) { pag_somaD(p->pags[i], d); }

// Soma o valor D a todas paginas do vetor.
void vPag_allPag_somaD(vPagina *p, double d) {
    for (int i = 0; i < p->len; i++)
        pag_somaD(p->pags[i], d);
}

void vPag_resetaValue(vPagina *p) {
    for (int i = 0; i < p->len; i++)
        pag_resetaValue(p->pags[i]);
}

// Retorna todas paginas p, que p->len == len.
vPagina *vPag_comparaValue(vPagina *p, int len) {
    vPagina *v = vPag_inicia();
    for (int i = 0; i < p->len; i++)
        if (len == (int) pag_value(p->pags[i]))
            vPag_insere(v, p->pags[i]);
    return v;
}

Pagina **vPag_pags(vPagina *p) { return p->pags; }

int vPag_len(vPagina *p) { return p->len; }

String *vPag_pag_str(vPagina *p, int i) { return pag_str(p->pags[i]); }

double vPag_pag_value(vPagina *p, int i) { return pag_value(p->pags[i]); }

void vPag_imprime(vPagina *p, FILE *out) {
    if (!p)
        return;
 
    for (int i = 0; i < p->len; i++) {
        pag_imprime(p->pags[i], out);
        fprintf(out, " ");
    }

    fprintf(out, "\n");
    fprintf(out, "pr:");

    for (int i = 0; i < p->len; i++) {
        fprintf(out, "%lf", pag_value(p->pags[i]));
        fprintf(out, " ");
    }
    fprintf(out, "\n");
}


void vPag_libera_mantemPags(vPagina *p) {
    if (!p)
        return;

    free(p->pags);
    free(p);
}

void vPag_libera(vPagina *p) {
    if (!p)
        return;
    for (int i = 0; i < p->len; i++)
        pag_libera(p->pags[i]);
    free(p->pags);
    free(p);
}

int compPag(const void *p1, const void *p2) {
    
    Pagina*pag1 = *(Pagina **)p1;
    Pagina*pag2 = *(Pagina **)p2;

    if (pag_value(pag1) < pag_value(pag2)) {
        return 1;
    } else if (pag_value(pag1) > pag_value(pag2)) {
        return -1;
    } else {
        return pag_compara(pag1, pag2);
    }
    
    //return ( pag_value(*(Pagina **)p1) < pag_value(*(Pagina **)p2));
}