#ifndef INDEX_H
#define INDEX_H

#include <stdio.h>
#include "string.h"
#include "pagina.h"
#include "termo.h"
#include "vPagina.h"
#include "tTermo.h"

typedef struct index Index;

Index *index_inicia();

Index *index_leitura(char *dir);

vPagina *index_consulta(Index *, char *line);

vPagina *index_vPag(Index *);

void index_imprime(Index *, FILE *);

void index_libera(Index *);

// size_t getline (char ** dest, size_t * n, FILE * stream);  -1 caso erro.
/* char* strtok(char* origem, char* DELIM);  NULL caso erro.
 *       strtok(NULL, char* DELIM); a partir da segunda chamada.
*/

#endif
