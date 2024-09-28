#include <stdio.h>
#include "casa.h"

//Faz o calculo do Preco de uma Casa
float calculaPrecoCasa(tCasa *c){
    //preço = preçoMetroQuadradoAreaConstruida * areaPavimento * numeroPavimentos + preçoMetroQuadradoAreaLivre * areaLivre
    return (c->precoMetroQuadradoAreaPavimento*c->areaPavimento*c->pavimentos+c->precoMetroQuadradoAreaLivre*c->areaLivre);
}

//Faz a leitura de um Imovel tipo 'Casa'
void lerCasa(FILE *f, tCasa *c){
    fscanf(f, "%d", &c->quartos);
    fscanf(f, "%d", &c->vagas);
    fscanf(f, "%d", &c->pavimentos);
    fscanf(f, "%f", &c->areaPavimento);
    fscanf(f, "%d", &c->precoMetroQuadradoAreaPavimento);
    fscanf(f, "%f", &c->areaLivre);
    fscanf(f, "%d", &c->precoMetroQuadradoAreaLivre);
}