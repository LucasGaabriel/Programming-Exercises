#ifndef _CASA
    #define _CASA

    typedef struct {
        int quartos;
        int vagas;
        int pavimentos;
        float areaPavimento;
        int precoMetroQuadradoAreaPavimento;
        float areaLivre;
        int precoMetroQuadradoAreaLivre;
    } tCasa;

    float calculaAreaConstruida(tCasa *);
    float calculaPrecoCasa(tCasa *);
    void lerCasa(FILE *, tCasa *);

#endif