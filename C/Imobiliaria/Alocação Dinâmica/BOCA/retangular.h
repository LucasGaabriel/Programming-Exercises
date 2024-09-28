#ifndef TP2_RETANGULAR_H
    #define TP2_RETANGULAR_H

    #include <stdio.h>

    typedef struct {
        char solo;
        unsigned int precoMetroQuadradoTerreno;
        float lado1;
        float lado2;
    } tRetangular;

    float calculaAreaRetangular(tRetangular *);
    float calculaPrecoRetangular(tRetangular *);
    void lerRetangular(FILE *, tRetangular *);

#endif //TP2_RETANGULAR_H
