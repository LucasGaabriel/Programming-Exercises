#include <stdio.h>
#include "apartamento.h"

//Verifica se o Apartamento possui Area de Lazer
float verificaLazer(tApartamento *a){
    if(a->lazer == 'S'){
        return 1.15;
    }
    else{
        return 1;
    }
}

//Faz o calculo do Preco do Apartamento
float calculaPrecoApartamento(tApartamento *a){
    //preço = preçoMetroQuadradoAreaConstruida * areaConstruida * (0,9 + andarApto / totalAndaresPrédio) * fatorLazer
    return (a->precoMetroQuadradoAreaConstruida*a->areaConstruida*(0.9 + (float)a->andar / a->numeroAndares)*verificaLazer(a));
}

//Faz a leitura de um Imovel tipo 'Apartamento'
void lerApartamento(FILE *f, tApartamento *a){
    fscanf(f, "%d\n", &a->quartos);
    fscanf(f, "%d\n", &a->vagas);
    fscanf(f, "%d\n", &a->andar);
    fscanf(f, "%f\n", &a->areaConstruida);
    fscanf(f, "%d\n", &a->precoMetroQuadradoAreaConstruida);
    fscanf(f, "%c\n", &a->lazer);
    fscanf(f, "%d\n", &a->numeroAndares);
}
