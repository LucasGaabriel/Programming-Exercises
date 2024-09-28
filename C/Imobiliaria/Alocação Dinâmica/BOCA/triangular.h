#ifndef TP2_TRIANGULAR_H
    #define TP2_TRIANGULAR_H

    #include <stdio.h>

    typedef struct {
        char solo;
        unsigned int precoMetroQuadradoTerreno;
        float base;
        float altura;
    } tTriangular;

    float calculaAreaTriangular(tTriangular *);
    float calculaPrecoTriangular(tTriangular *);
    void lerTriangular(FILE *, tTriangular *);

#endif //TP2_TRIANGULAR_H
