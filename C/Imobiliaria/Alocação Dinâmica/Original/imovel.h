#ifndef TP2_IMOVEL_H
    #define TP2_IMOVEL_H

    #include <stdio.h>
    #include "triangular.h"
    #include "retangular.h"
    #include "trapezoidal.h"
    #include "casa.h"
    #include "apartamento.h"

    #define nomeProprietario 50
    #define nomeTipo 7

    typedef union {
        tTriangular triang;
        tRetangular retang;
        tTrapezoidal trapez;
        tCasa casa;
        tApartamento apto;
    } tCategoria;

    typedef struct {
        tCategoria categoria;
        char tipo[nomeTipo];
        unsigned int identificador;
        char *proprietario;
        float preco;
        float area;
    } tImovel;

    void lerTipo(FILE *, tImovel *);
    void lerIdentificador(FILE *, tImovel *);
    char* inicializaProprietario(char *);
    void liberaProprietario(tImovel *);
    void lerProprietario(FILE *, tImovel *);
    int comparaPreco(tImovel *, tImovel *);
    int comparaQuartos(tImovel *, tImovel *);
    int comparaArea(tImovel *, tImovel *);
    float calculaArea(tImovel);

#endif //TP2_IMOVEL_H
