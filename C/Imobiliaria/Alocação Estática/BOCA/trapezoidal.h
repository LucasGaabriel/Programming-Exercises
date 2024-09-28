#ifndef _TRAPEZOIDAL
    #define _TRAPEZOIDAL

    typedef struct {
        char solo;
        int precoMetroQuadradoTerreno;
        float base1;
        float base2;
        float altura;
    } tTrapezoidal;

    float calculaAreaTrapezoidal(tTrapezoidal *);
    float calculaPrecoTrapezoidal(tTrapezoidal *);
    void lerTrapezoidal(FILE *, tTrapezoidal *);

#endif