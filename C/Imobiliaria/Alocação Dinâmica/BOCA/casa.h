#ifndef TP2_CASA_H
    #define TP2_CASA_H

    #include <stdio.h>

    typedef struct {
        unsigned int quartos;
        unsigned int vagas;
        unsigned int pavimentos;
        float areaPavimento;
        unsigned int precoMetroQuadradoAreaPavimento;
        float areaLivre;
        unsigned int precoMetroQuadradoAreaLivre;
    } tCasa;

    float calculaPrecoCasa(tCasa *);
    void lerCasa(FILE *, tCasa *);

#endif //TP2_CASA_H
