#include <stdlib.h>
#include "identificadores.h"

//Aloca espaco para os Identificadores Necessarios
void inicializaIdentificadores(tIdentificadores *ident, int num){
    ident->identificadores = (int *) malloc (sizeof(int) * num);
    ident->numIdent = num;
}

//Libera o espaco alocado para os Identificadores
void liberaIdentificadores(tIdentificadores *ident){
    free(ident->identificadores);
}
