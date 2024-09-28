#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "espec.h"

//Leitura dos Dados Relativos, referentes ao arquivo "espec.txt"
void lerDadosRelativos(tEspec *e){
    FILE *file;
    char espec_path[150];
    scanf("%s", espec_path);
    
    file = fopen(espec_path, "r");

    if(!file){
        printf("Nao foi possivel abrir o arquivo 'espec.txt'. Encerrando o programa.\n");
        exit (1);
    }

    fscanf(file, "%d", &e->imoveisCaros);
    fscanf(file, "%d", &e->menoresArgilosos);
    fscanf(file, "%f", &e->areaLimite);
    fscanf(file, "%f", &e->precoLimite);
    fscanf(file, "%d", &e->i);
    fscanf(file, "%d", &e->j);
    fscanf(file, "%d", &e->k);
}

//Guarda num vetor os Identificadores referentes ao Item A)
void imoveisMaisCaros(tImobiliaria *im, tEspec *e, tIdentificadores *imoveisCaros){
    int i, j;
    //numeroImoveis = parteInteira (percentualLido*totalImoveis/100)
    int numeroImoveis = (int)(e->imoveisCaros*im->numImoveis/100); //Numero de Identificadores a serem apresentados

    ordenarCatalogo(im, comparaPreco);

    for(i=im->numImoveis-numeroImoveis+1, j=1; i<=im->numImoveis; i++, j++){ //Copia todos os identificadores necessarios para um vetor especifico
        imoveisCaros->identificadores[j] = im->imoveis[i].identificador;
    }
    imoveisCaros->numIdent = --j;
}

//Guarda num vetor os Identificadores referentes ao Item B)
void terrenosArgilososMenorArea(tImobiliaria *im, tEspec *e, tIdentificadores *argilososMenorArea){
    tImobiliaria terrenosArgilosos;
    int i, j;
    int cont = 1;

    for(int i=1; i<=im->numImoveis; i++){ //Copia todos os Terrenos com Solo Argiloso para um vetor especifico
        if( (!strcmp(im->imoveis[i].tipo, "triang") && im->imoveis[i].categoria.triang.solo == 'G') || (!strcmp(im->imoveis[i].tipo, "retang") && im->imoveis[i].categoria.retang.solo == 'G') || (!strcmp(im->imoveis[i].tipo, "trapez") && im->imoveis[i].categoria.trapez.solo == 'G') ){
            terrenosArgilosos.imoveis[cont] = im->imoveis[i];
            cont++;
        }
    }
    cont--;
    terrenosArgilosos.numImoveis = cont;
    
    float areas[cont+1]; //Cria um vetor separado para as Areas dos Terrenos

    for(int i=1; i<=terrenosArgilosos.numImoveis; i++){ //Faz o calculo da area para cada tipo de terreno
        if(!strcmp(terrenosArgilosos.imoveis[i].tipo, "triang")){
            areas[i] = calculaAreaTriangular(&terrenosArgilosos.imoveis[i].categoria.triang);
        }
        if(!strcmp(terrenosArgilosos.imoveis[i].tipo, "retang")){
            areas[i] = calculaAreaRetangular(&terrenosArgilosos.imoveis[i].categoria.retang);
        }
        if(!strcmp(terrenosArgilosos.imoveis[i].tipo, "trapez")){
            areas[i] = calculaAreaTrapezoidal(&terrenosArgilosos.imoveis[i].categoria.trapez);
        }
    }
    
    ordenarPorAreas(&terrenosArgilosos, areas); //Ordena o vetor de acordo com a Area

    //numeroArgilosos = parteInteira (percentualLido*totalArgilosos/100)
    int numeroImoveis = (e->menoresArgilosos*terrenosArgilosos.numImoveis/100); //Numero de Identificadores a serem apresentados

    for(int i=terrenosArgilosos.numImoveis-numeroImoveis+1, j=1; i<=terrenosArgilosos.numImoveis; i++, j++){ //Faz a copia dos Itens necessarios para um vetor especifico
        argilososMenorArea->identificadores[j] = terrenosArgilosos.imoveis[i].identificador;
    }
    argilososMenorArea->numIdent = numeroImoveis;
}

//Guarda num vetor os Identificadores referentes ao Item C)
void casasLimitesEspecificos(tImobiliaria *im, tEspec *e, tIdentificadores *casasLimitEspec){
    tImobiliaria casasLimites;
    int cont = 1;
    
    for(int i=1; i<=im->numImoveis; i++){ //Copia para um vetor todos as Casas com Area maior e Preco menor que o limite apresentado no arquivo "espec.txt"
        if(!strcmp(im->imoveis[i].tipo, "casa") && calculaAreaConstruida(&im->imoveis[i].categoria.casa) > e->areaLimite && im->imoveis[i].preco < e->precoLimite){
            casasLimites.imoveis[cont] = im->imoveis[i];
            cont++;
        }
    }
    cont--;
    casasLimites.numImoveis = cont;
    
    ordenarCatalogo(&casasLimites, comparaQuartos); //Ordena o vetor por quantidade de quartos

    for(int i=1; i<=casasLimites.numImoveis; i++){ //Faz a copia dos identificadores a serem apresentados em um vetor especifico
        casasLimitEspec->identificadores[i] = casasLimites.imoveis[i].identificador;
    }
    casasLimitEspec->numIdent = casasLimites.numImoveis;
}

void apresentarResultados(tIdentificadores *imoveisCaros, tIdentificadores *argilososMenorArea, tIdentificadores *casasLimitEspec, tEspec *espec){
    int i, x, y, z;

    //Faz a Soma dos Identificadores i, j, k
    if(espec->i <= imoveisCaros->numIdent){
        x = imoveisCaros->identificadores[espec->i];
    }
    else{
        x = 0;
    }

    if(espec->j <= argilososMenorArea->numIdent){
        y = argilososMenorArea->identificadores[espec->j];
    }
    else{
        y = 0;
    }

    if(espec->k <= casasLimitEspec->numIdent){
        z = casasLimitEspec->identificadores[espec->k];
    }
    else{
        z = 0;
    }

    int total = x+y+z;

    printf("%d\n", total); //Exibe o total no arquivo 'Saida'

    for(i=1; i<=imoveisCaros->numIdent; i++){
        if(i != imoveisCaros->numIdent){ //Exibe os identificadores do item A
            printf("%d, ", imoveisCaros->identificadores[i]);
        }
        else{
            printf("%d", imoveisCaros->identificadores[i]);
        }
    }
    if(imoveisCaros->numIdent > 0)
        printf("\n");

    for(i=1; i<=argilososMenorArea->numIdent; i++){
        if(i != argilososMenorArea->numIdent){ //Exibe os identificadores do item B
            printf("%d, ", argilososMenorArea->identificadores[i]);
        }
        else{
            printf("%d", argilososMenorArea->identificadores[i]);
        }
    }
    if(argilososMenorArea->numIdent > 0)
        printf("\n");

    for(i=1; i<=casasLimitEspec->numIdent; i++){
        if(i != casasLimitEspec->numIdent){ //Exibe os identificadores do item C
            printf("%d, ", casasLimitEspec->identificadores[i]);
        }
        else{
            printf("%d", casasLimitEspec->identificadores[i]);
        }
    }
    if(casasLimitEspec->numIdent > 0)
        printf("\n");
}