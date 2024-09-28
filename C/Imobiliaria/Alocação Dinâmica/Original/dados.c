#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dados.h"
#include "catalogo.h"
#include "imovel.h"
#include "identificadores.h"

//Leitura dos Dados Relativos, referentes ao arquivo "espec.txt"
tDados lerDadosRelativos(){
    tDados dados;
    FILE *file;

    file = fopen("espec.txt", "r");

    if(!file){
        printf("Nao foi possivel abrir o arquivo 'espec.txt'. Encerrando o programa.\n");
        exit (1);
    }

    fscanf(file, "%d", &dados.imoveisCaros);
    fscanf(file, "%d", &dados.menoresArgilosos);
    fscanf(file, "%f", &dados.areaLimite);
    fscanf(file, "%f", &dados.precoLimite);
    fscanf(file, "%d", &dados.i);
    fscanf(file, "%d", &dados.j);
    fscanf(file, "%d", &dados.k);

    fclose(file);

    return dados;
}

//Guarda num vetor os Identificadores referentes ao Item A)
tIdentificadores imoveisMaisCaros(tCatalogo cat, tDados *dados){
    tIdentificadores imoveisCaros;
    int i, j;
    //numeroImoveis = parteInteira (percentualLido*totalImoveis/100)
    int numeroImoveis = (int)(dados->imoveisCaros * obterNumImoveis(cat) / 100); //Numero de Identificadores a serem apresentados

    inicializaIdentificadores(&imoveisCaros, numeroImoveis);

    adicionarPreco(cat);

    ordenarCatalogo(cat, comparaPreco);

    for(i=obterNumImoveis(cat) - numeroImoveis, j=0; i < obterNumImoveis(cat); i++, j++){ //Copia todos os identificadores necessarios para um vetor especifico
        imoveisCaros.identificadores[j] = obterIdentificador(cat, i);
    }

    return imoveisCaros;
}

//Guarda num vetor os Identificadores referentes ao Item B)
tIdentificadores terrenosArgilososMenorArea(tCatalogo cat, tDados *dados){
    tIdentificadores argilososMenorArea;
    tCatalogo terrenosArgilosos = inicializaCatalogo();

    for(int i=0; i < obterNumImoveis(cat); i++){ //Copia todos os Terrenos com Solo Argiloso para um vetor especifico
        if( (!strcmp(obterTipo(cat, i), "triang") && obterTipoSolo(cat, i) == 'G') || (!strcmp(obterTipo(cat, i), "retang") && obterTipoSolo(cat, i) == 'G') || (!strcmp(obterTipo(cat, i), "trapez") && obterTipoSolo(cat, i) == 'G') ){
            if(obterNumImoveis(terrenosArgilosos) == obterMaxImoveis(terrenosArgilosos)){
                aumentaCatalogo(terrenosArgilosos);
            }
            definirImovel(terrenosArgilosos, obterImovel(cat, i), obterNumImoveis(terrenosArgilosos));
            acrescentarNumImoveis(terrenosArgilosos, 1);
        }
    }

    adicionarAreas(terrenosArgilosos);

    ordenarCatalogo(terrenosArgilosos, comparaArea); //Ordena o vetor de acordo com a Area

    //numeroArgilosos = parteInteira (percentualLido*totalArgilosos/100)
    int numeroImoveis = (int)(dados->menoresArgilosos * obterNumImoveis(terrenosArgilosos)/100); //Numero de Identificadores a serem apresentados

    inicializaIdentificadores(&argilososMenorArea, numeroImoveis);

    for(int i=obterNumImoveis(terrenosArgilosos) - numeroImoveis, j=0; i < obterNumImoveis(terrenosArgilosos); i++, j++){ //Faz a copia dos Itens necessarios para um vetor especifico
        argilososMenorArea.identificadores[j] = obterIdentificador(terrenosArgilosos, i);
    }

    liberaCatalogo(terrenosArgilosos);

    return argilososMenorArea;
}

//Guarda num vetor os Identificadores referentes ao Item C)
tIdentificadores casasLimitesEspecificos(tCatalogo cat, tDados *dados){
    tIdentificadores casasLimitesEspec;
    tCatalogo casasLimites = inicializaCatalogo();

    for(int i=0; i < obterNumImoveis(cat); i++){ //Copia para um vetor todos as Casas com Area maior e Preco menor que o limite apresentado no arquivo "espec.txt"
        if( !strcmp(obterTipo(cat, i), "casa") && calculaArea(obterImovel(cat, i)) > dados->areaLimite && obterPreco(cat, i) < dados->precoLimite){
            if(obterNumImoveis(casasLimites) == obterMaxImoveis(casasLimites)){
                aumentaCatalogo(casasLimites);
            }
            definirImovel(casasLimites, obterImovel(cat, i), obterNumImoveis(casasLimites));
            acrescentarNumImoveis(casasLimites, 1);
        }
    }

    inicializaIdentificadores(&casasLimitesEspec, obterNumImoveis(casasLimites));
    ordenarCatalogo(casasLimites, comparaQuartos); //Ordena o vetor por quantidade de quartos

    for(int i=0; i < obterNumImoveis(casasLimites); i++){ //Faz a copia dos identificadores a serem apresentados em um vetor especifico
        casasLimitesEspec.identificadores[i] = obterIdentificador(casasLimites, i);
    }

    liberaCatalogo(casasLimites);

    return casasLimitesEspec;
}

//Apresenta os Resultados Obtidos anteriormente
void apresentarResultados(tIdentificadores *imoveisCaros, tIdentificadores *argilososMenorArea, tIdentificadores *casasLimitEspec, tDados *dados){

    int i, x, y, z;

    FILE *file;

    file = fopen("saida.txt", "w");

    //Faz a Soma dos Identificadores i, j, k (Fazendo as verificacoes necessarias)
    if(dados->i <= imoveisCaros->numIdent && dados->i != 0){
        x = imoveisCaros->identificadores[dados->i - 1];
    }
    else{
        x = 0;
    }

    if(dados->j <= argilososMenorArea->numIdent && dados->j != 0){
        y = argilososMenorArea->identificadores[dados->j - 1];
    }
    else{
        y = 0;
    }

    if(dados->k <= casasLimitEspec->numIdent && dados->k != 0){
        z = casasLimitEspec->identificadores[dados->k - 1];
    }
    else{
        z = 0;
    }

    int total = x + y + z;

    fprintf(file, "%d\n", total); //Exibe o total no arquivo 'Saida'

    for(i=0; i < imoveisCaros->numIdent; i++){
        if(i != imoveisCaros->numIdent - 1){ //Exibe os identificadores do item A
            fprintf(file, "%d, ", imoveisCaros->identificadores[i]);
        }
        else{
            fprintf(file, "%d", imoveisCaros->identificadores[i]);
        }
    }
    fprintf(file, "\n");

    for(i=0; i < argilososMenorArea->numIdent; i++){
        if(i != argilososMenorArea->numIdent - 1){ //Exibe os identificadores do item B
            fprintf(file, "%d, ", argilososMenorArea->identificadores[i]);
        }
        else{
            fprintf(file, "%d", argilososMenorArea->identificadores[i]);
        }
    }
    fprintf(file, "\n");

    for(i=0; i < casasLimitEspec->numIdent; i++){
        if(i != casasLimitEspec->numIdent - 1){ //Exibe os identificadores do item C
            fprintf(file, "%d, ", casasLimitEspec->identificadores[i]);
        }
        else{
            fprintf(file, "%d", casasLimitEspec->identificadores[i]);
        }
    }
    fprintf(file, "\n");

    fclose(file);

    liberaIdentificadores(imoveisCaros);
    liberaIdentificadores(argilososMenorArea);
    liberaIdentificadores(casasLimitEspec);
}
