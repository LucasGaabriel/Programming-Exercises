#ifndef TP2_TRAPEZOIDAL_H
    #define TP2_TRAPEZOIDAL_H

    #include <stdio.h>

    typedef struct {
        char solo;
        unsigned int precoMetroQuadradoTerreno;
        float base1;
        float base2;
        float altura;
    } tTrapezoidal;

    float calculaAreaTrapezoidal(tTrapezoidal *);
    float calculaPrecoTrapezoidal(tTrapezoidal *);
    void lerTrapezoidal(FILE *, tTrapezoidal *);

#endif //TP2_TRAPEZOIDAL_H
