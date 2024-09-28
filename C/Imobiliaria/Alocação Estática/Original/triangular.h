#ifndef _TRIANGULAR
    #define _TRIANGULAR

    typedef struct {
        char solo;
        int precoMetroQuadradoTerreno;
        float base;
        float altura;
    } tTriangular;

    float calculaAreaTriangular(tTriangular *);
    float calculaPrecoTriangular(tTriangular *);
    void lerTriangular(FILE *, tTriangular *);

#endif