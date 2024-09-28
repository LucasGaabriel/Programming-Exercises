#ifndef _CATALOGO
    #define _CATALOGO
    #include <stdio.h>
    #include "triangular.h"
    #include "retangular.h"
    #include "trapezoidal.h"
    #include "casa.h"
    #include "apartamento.h"

    #define nProprietario 50
    #define tipoMax 7

    typedef union {
        tTriangular triang;
        tRetangular retang;
        tTrapezoidal trapez;
        tCasa casa;
        tApartamento apto;
    } tCategoria;

    typedef struct {
        tCategoria categoria;
        char tipo[tipoMax];
        int identificador;
        char proprietario[nProprietario];
        float preco;
    } tCatalogo;

    void lerTipo(FILE *, tCatalogo *);
    void lerIdentificador(FILE *, tCatalogo *);
    void lerProprietario(FILE *, tCatalogo *);
    
#endif