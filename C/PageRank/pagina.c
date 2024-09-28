#include <stdio.h>
#include <stdlib.h>
#include "pagina.h"

struct pagina {
    String *str;
    double value;
};

Pagina *pag_cria(char *str) {
    Pagina *p = (Pagina *) malloc(sizeof(Pagina));
    p->str = str_cria(str);
    p->value = 0;
    return p;
}

int pag_compara(Pagina *p, Pagina *q) {
    return str_compara(p->str, q->str);
}

void pag_somaD(Pagina *p, double value) {
    p->value += value;
}

void pag_resetaValue(Pagina *p) {
    p->value = 0.0;
}

String *pag_str(Pagina *p) {
    return p->str;
}

double pag_value(Pagina *p) {
    return p->value;
}

void pag_imprime(Pagina *p, FILE *out) {
    str_imprime(p->str, out);
    //fprintf(out,", Value: %d; ", (int)p->value);
}

void pag_libera(Pagina *p) {
    str_libera(p->str);
    free(p);
}
