#ifndef _APARTAMENTO
    #define _APARTAMENTO

    typedef struct {
        int quartos;
        int vagas;
        int andar;
        float areaConstruida;
        int precoMetroQuadradoAreaConstruida;
        char lazer;
        int numeroAndares;
    } tApartamento;

    float calculaPrecoApartamento(tApartamento *);
    void lerApartamento(FILE *, tApartamento *);

#endif