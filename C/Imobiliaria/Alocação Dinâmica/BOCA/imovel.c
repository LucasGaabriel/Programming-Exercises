#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "imovel.h"

//Faz a leitura do tipo do Imovel
void lerTipo(FILE *f, tImovel *im){
    fscanf(f, "%s\n", im->tipo);
}

//Faz a leitura do Identificador do Imovel
void lerIdentificador(FILE *f, tImovel *im){
    fscanf(f, "%d\n", &im->identificador);
}

//Aloca espaco para o nome do Proprietario e retorna o ponteiro
char* inicializaProprietario(char *nome){
    char *aux = (char *) malloc (sizeof(char) * strlen(nome) + 1);
    strcpy(aux, nome);

    return aux;
}

//Libera a area alocada para o proprietario
void liberaProprietario(tImovel *im){
    free(im->proprietario);
}

//Faz a Leitura do Proprietario do Imovel
void lerProprietario(FILE *f, tImovel *im){
    char nome[nomeProprietario];

    fscanf(f, "%[^\n]\n", nome);

    im->proprietario = inicializaProprietario(nome);
}

//Compara Preco dos Imoveis
int comparaPreco(tImovel *im1, tImovel *im2){
    if(im1->preco > im2->preco){
        return 1;
    }
    if(im1->preco == im2->preco && im1->identificador > im2->identificador){
        return 1;
    }
    return 0;
}

//Compara Quantidade de Quarto das Casas
int comparaQuartos(tImovel *im1, tImovel *im2){
    if(im1->categoria.casa.quartos < im2->categoria.casa.quartos){
        return 1;
    }
    if(im1->categoria.casa.quartos == im2->categoria.casa.quartos && im1->identificador < im2->identificador){
        return 1;
    }
    return 0;
}

//Compara a Area dos Imoveis
int comparaArea(tImovel *im1, tImovel *im2){
    if( im1->area < im2->area ){
        return 1;
    }
    if( im1->area == im2->area && im1->identificador < im2->identificador ){
        return 1;
    }
    return 0;
}

//Calculo da Area para cada Tipo de Terreno
float calculaArea(tImovel im){
    if(!strcmp(im.tipo, "triang")){
        return (im.categoria.triang.base * im.categoria.triang.altura)/2;
    }
    else if(!strcmp(im.tipo, "retang")){
        return im.categoria.retang.lado1 * im.categoria.retang.lado2;
    }
    else if(!strcmp(im.tipo, "trapez")){
        return (((im.categoria.trapez.base1 + im.categoria.trapez.base2) * im.categoria.trapez.altura) / 2);
    }
    else if(!strcmp(im.tipo, "casa")){
        return im.categoria.casa.areaPavimento*im.categoria.casa.pavimentos;
    }
    return 0;
}
