#ifndef TP2_APARTAMENTO_H
    #define TP2_APARTAMENTO_H

    #include <stdio.h>

    typedef struct {
        unsigned int quartos;
        unsigned int vagas;
        unsigned int andar;
        float areaConstruida;
        unsigned int precoMetroQuadradoAreaConstruida;
        char lazer;
        unsigned int numeroAndares;
    } tApartamento;

    float calculaPrecoApartamento(tApartamento *);
    void lerApartamento(FILE *, tApartamento *);

#endif //TP2_APARTAMENTO_H
