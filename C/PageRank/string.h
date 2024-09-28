#ifndef STRING_H
#define STRING_H

#include <stdio.h>

typedef struct string String;

String *str_inicia();

String *str_cria(char *);

// Cria e converte char de maiusculas para minusculas.
String *str_cria_converte(char *);

String *str_concat(String *, String *);

int str_compara(String *, String *); // s1 > s2 ? 1 : -1; s1 == s2 return 0;
char *str_getStr(String *);

int str_getLen(String *);

void str_imprime(String *, FILE *);

void str_libera(String *);

#endif
