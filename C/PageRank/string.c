#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "string.h"

#define TAM_INICL 50

struct string {
    char *str;
    int len;
};

String *str_inicia() {
    String *p = (String *) malloc(sizeof(String));
    p->len = 0;
    return p;
}

String *str_cria(char *str) {
    if (!str) return NULL;

    String *p = str_inicia();
    int i, j;

    for (i = 0; str[i] != '\0' && str[i] != '\n'; i++);
    p->len = i;
    p->str = (char *) malloc(sizeof(char) * (p->len));
    for (j = 0; j < i; j++) {
        p->str[j] = str[j];
    }
    //p->str[p->len++] = '\0';

    return p;
}

// Cria e converte maiusculo em minusculo se preciso
String *str_cria_converte(char *str) {
    if (!str) return NULL;

    String *p = str_inicia();
    int i, j;

    for (i = 0; str[i] != '\0' && str[i] != '\n'; i++);
    p->len = i;
    p->str = (char *) malloc(sizeof(char) * (p->len));
    for (j = 0; j < i; j++) {
        if (str[j] >= 'A' && str[j] <= 'Z')
            str[j] += 32;   // Converte Maiusculo em minusculo.
        p->str[j] = str[j];
    }
    //p->str[p->len++] = '\0';

    return p;
}

String *str_concat(String *p, String *q) {
    String *n = str_inicia();
    int i;
    int len = p->len + q->len;
    n->str = (char *) malloc(sizeof(char) * (len));

    for (i = 0; i < p->len; i++)
        n->str[n->len++] = p->str[i];
    for (int j = 0; i < len; i++, j++)
        n->str[n->len++] = q->str[j];
    n->str[n->len++] = '\0';

    return n;
}

int str_compara(String *s, String *t) {     // 1: se s > t, -1: se s < t, ou 0.
    int min = s->len < t->len ? s->len : t->len;
    for (int i = 0; i < min; i++) {
        if (s->str[i] < t->str[i]) { return -1; }
        if (s->str[i] > t->str[i]) { return 1; }
    }
    return s->len - t->len;
}

char *str_getStr(String *s) {
    return s->str;
}

int str_getLen(String *s) {
    return s->len;
}

void str_imprime(String *s, FILE *out) {
    if (!s) return;
    for (int i = 0; i < s->len; i++)
        fprintf(out, "%c", s->str[i]);
}

void str_libera(String *s) {
    free(s->str);
    free(s);
}
