#ifndef _RETANGULAR
    #define _RETANGULAR

    typedef struct {
        char solo;
        int precoMetroQuadradoTerreno;
        float lado1;
        float lado2;
    } tRetangular;

    float calculaAreaRetangular(tRetangular *);
    float calculaPrecoRetangular(tRetangular *);
    void lerRetangular(FILE *, tRetangular *);

#endif