// Nome: Lucas Gabriel de Oliveira Costa
// Disciplina: Estruturas de Dados I
// Trabalho 2 - O Compactador de Huffman

#include <stdlib.h>
#include <string.h>
#include "huffman.h"

#define NUM 256
#define numBits 1024

void compactador(char* nomeArquivo){

    //Abre o arquivo para fazer a leitura e compactar
    FILE* arquivo = fopen(nomeArquivo, "rb");

    if(!arquivo){
        printf("Não foi possivel abrir o arquivo de entrada '%s'! Encerrando o programa...\n", nomeArquivo);
        exit(1);
    }

    //Faz a leitura de todo o arquivo, sempre incrementando a ocorrencia de um caractere no vetor de pesos, usado para montar a arvore de Huffman
    unsigned int* pesos = definirPesosCaracteres(arquivo);

    //Monta uma lista inicial com todas as arvores contendo um caracter e o peso. As suas subarvores inicialmente sao todas NULL
    ListaArvores* listaDeArvores = montarListaDeArvoresInicial(pesos);

    //Usando a Codificacao de Huffman, gera uma arvore Otima com a listaDeArvores formada anteriormente
    Arvore* arvoreOtima = codificacaoDeHuffman(listaDeArvores);

    //Gera o arquivo compactado, com base na arvore Otima de Huffman montada
    gerarArquivoCompactado(arvoreOtima, arquivo, nomeArquivo, pesos);

    //Libera a memoria do vetor de pesos
    free(pesos);

    //Libera memoria da lista de Arvores
    liberarLista(listaDeArvores);

    //Fecha o arquivo de entrada usado para a compactacao
    fclose(arquivo);
}

void descompactador(char* nomeArquivo){

    //Verifica se o arquivo possui a extensao .comp
    if(strstr(nomeArquivo, ".comp") == NULL){
        printf("A entensao do arquivo a ser descompactado deve ser '.comp'\n");
        exit(1);
    }

    //Abre o arquivo para fazer a leitura e descompactar
    FILE* arquivo = fopen(nomeArquivo, "rb");

    if(!arquivo){
        printf("Não foi possivel abrir o arquivo de entrada '%s'! Encerrando o programa...\n", nomeArquivo);
        exit(1);
    }

    //Le os primeiros 256 bytes do arquivo, contendo os pesos, usados para montar a arvore Otima de Huffman
    unsigned int* pesos = lerPesosCaracteres(arquivo);

    //Monta uma lista inicial com todas as arvores contendo um caracter e o peso. As suas subarvores inicialmente sao todas NULL
    ListaArvores* listaDeArvores = montarListaDeArvoresInicial(pesos);

    //Usando a Codificacao de Huffman, gera uma arvore Otima com a listaDeArvores formada anteriormente
    Arvore* arvoreOtima = codificacaoDeHuffman(listaDeArvores);

    //Gera o arquivo descompactado inicial, com base na arvore de Huffman montada
    gerarArquivoDescompactado(arvoreOtima, arquivo, nomeArquivo);

    //Libera a memoria para os pesos
    free(pesos);

    //Libera a memoria da lista de Arvores
    liberarLista(listaDeArvores);

    //Fecha o arquivo de entrada usado para descompactacao
    fclose(arquivo);
}

unsigned int* definirPesosCaracteres(FILE* arquivo){

    //Aloca memoria para o vetor de pesos, com 256 posicoes
    unsigned int* pesos = (unsigned int*) malloc (sizeof(unsigned int) * NUM);

    //Inicializa todos os pesos com 0
    for(int i=0; i<NUM; i++){
        pesos[i] = 0;
    }

    unsigned char caracter;

    //Enquanto houver caracter para ser lido no arquivo, lê o caracter e incrementa seu peso
    while(fread(&caracter, 1, 1, arquivo)){
        pesos[(unsigned char)caracter]++;
    }

    return pesos;
}

unsigned int* lerPesosCaracteres(FILE* arquivo){

    //Aloca memoria para o vetor de pesos, com 256 posicoes
    unsigned int* pesos = (unsigned int*) malloc (sizeof(unsigned int) * NUM);

    //Le os pesos de cada caractere no inicio do arquivo
    for(int i=0; i<NUM; i++){
        fread(&pesos[i], sizeof(unsigned int), 1, arquivo);
    }

    return pesos;
}

ListaArvores* montarListaDeArvoresInicial(unsigned int* pesosCaracteres){
    ListaArvores* listaDeArvores = inicializaLista();

    //Percorre por todo o vetor de pesos
    for(int i=0; i<NUM; i++){
        if(pesosCaracteres[i] > 0){
            //Cria uma arvore para cada caracter onde o peso for maior do que 0 e insere na lista já ordenada crescentemente
            Arvore* arvore = criaArvore((char)i, pesosCaracteres[i], NULL, NULL);
            inserirNaListaOrdenadoPorPeso(listaDeArvores, arvore);
        }
    }

    return listaDeArvores;
}

Arvore* codificacaoDeHuffman(ListaArvores* listaDeArvores){

    Arvore* t1;
    Arvore* t2;

    //Algoritmo de Huffman que se repete até que reste apenas 1 arvore na lista
    while(retornaQuantidadeArvoresDaLista(listaDeArvores) > 1) {

        //Pega as 2 primeiras arvores da lista e define com T1 e T2
        t1 = retornaArvoreDoIndice(listaDeArvores, 0);
        t2 = retornaArvoreDoIndice(listaDeArvores, 1);

        //Cria uma nova arvore Tr com um caracter qualquer (Definido aqui como espaco ' '), em que o peso é a soma dos pesos de T1 e T2
        //Sua subArvore esquerda é T1 e sua subArvore direita é T2
        Arvore *Tr = criaArvore(' ', retornaPeso(t1) + retornaPeso(t2), t1, t2);

        //Remove T1 e T2 da lista, mantendo elas na memória
        retirarDaListaSemLiberarArvore(listaDeArvores, t1);
        retirarDaListaSemLiberarArvore(listaDeArvores, t2);

        //Insere a nova arvore Tr na lista já ordenada
        inserirNaListaOrdenadoPorPeso(listaDeArvores, Tr);
    }

    //Retorna a unica arvore que sobrou na lista, a arvore Otima de Huffman
    return retornaArvoreDoIndice(listaDeArvores, 0);
}

//Adiciona um ".comp" ao final do nome do arquivo
static char* gerarNomeArquivoCompactado(char* nomeArquivo){
    strcat(nomeArquivo, ".comp");

    return nomeArquivo;
}

//Faz a busca pelo codigo corresponde ao caracter na Arvore Otima e escreve no MapaBits
static int escreverSequenciaNoMapaDeBits(Arvore* arvore, char* mapaBits, unsigned char caractere, int tamanho){

    int ok;

    //Se o nó for um nó folha e for o caracter buscado
    if( (retornaSubarvoreEsquerda(arvore) == NULL && retornaSubarvoreDireita(arvore) == NULL) && retornaCaracter(arvore) == caractere){
        //Coloca o caracter de final de string no lugar que corresponde ao tamanho atual da Arvore
        mapaBits[tamanho] = '\0';

        return 1;
    }
    else {
        ok = 0;

        //Se a arvore tiver um nó a esquerda
        if(retornaSubarvoreEsquerda(arvore)){
            //Adiciona um '0' no mapaBits no lugar que corresponde ao tamanho atual da Arvore
            mapaBits[tamanho] = '0';

            //Faz a verificacao na subArvore esquerda
            ok = escreverSequenciaNoMapaDeBits(retornaSubarvoreEsquerda(arvore), mapaBits, caractere, tamanho + 1);
        }
        //Se a arvore tiver um nó a direita e ainda nao tiver encontrado o caracter
        if(retornaSubarvoreDireita(arvore) && ok == 0){
            //Adiciona um '1' no mapaBits no lugar que corresponde ao tamanho atual da Arvore
            mapaBits[tamanho] = '1';

            //Faz a verificacao na subArvore direita
            ok = escreverSequenciaNoMapaDeBits(retornaSubarvoreDireita(arvore), mapaBits, caractere, tamanho + 1);
        }
        //Se nao tiver encontrado o caracter
        if(ok == 0){
            //Coloca o caracter de final de string no lugar que corresponde ao tamanho atual da Arvore
            mapaBits[tamanho] = '\0';
        }

        return ok;
    }
}

//Retira a extensao .comp do nome do arquivo
static char* gerarNomeArquivoDescompactado(char* nomeArquivo){

    //Encontra o indice do '.' referente ao ".comp" do nome do arquivo
    int i = (int)strlen(nomeArquivo) - 5;

    //Se a extensao do arquivo for ".comp"
    if(!strcmp(&nomeArquivo[i], ".comp")){
        //Adiciona caracter de final de string no lugar do ponto '.'
        nomeArquivo[i] = '\0';
    }
    else {
        printf("A entensao do arquivo a ser descompactado deve ser '.comp'\n");
        exit(1);
    }

    //Verifica se gerou o nome corretamente
    if(!nomeArquivo){
        printf("Falha na geracao de nome do arquivo descompactado!\n");
        exit(1);
    }

    return nomeArquivo;
}

void gerarArquivoCompactado(Arvore* arvoreOtima, FILE* arquivo, char* nomeArquivo, unsigned int* pesos){

    //Adiciona um ".comp" no nome do arquivo
    nomeArquivo = gerarNomeArquivoCompactado(nomeArquivo);

    //Abre um arquivo para escrita
    FILE* arqCompactado = fopen(nomeArquivo, "wb");

    if(!arqCompactado) {
        printf("Não foi possivel abrir o arquivo '%s' para escrita!\n", nomeArquivo);
        exit(1);
    }

    //Escreve os pesos dos caracteres no inicio do arquivo compactado
    //É atraves dos pesos que a arvore sera montada na hora da descompactacao
    for(int i=0; i<NUM; i++){
        fwrite(&pesos[i], sizeof(unsigned int), 1, arqCompactado);
    }

    //Pula o tamanho de um unsigned int no arquivo, para depois ser colocado o tamanho maximo a ser lido para descompactar
    fseek(arqCompactado, sizeof(unsigned int), SEEK_CUR);

    //Variavel usada na leitura do arquivo original
    //Cada byte do arquivo sera lido e armazenado nessa variavel
    unsigned char leitura;

    //Variavel usada na escrita do arquivo compactado
    //Inicializa a variavel com 0
    unsigned char escrita = 0;

    //Variavel para escrever no arquivo compactado e auxiliar na hora da descompactacao
    //Esse é o tamanho máximo a ser lido na descompactacao
    unsigned int tamanhoMax = 0;

    //Retorna para leitura a partir do início do arquivo a ser compactado
    //O arquivo será lido novamente a partir do inicio, e a cada leitura é escrito no arquivo compactado a sequência correspondente induzida pela Arvore Otima de Huffman
    fseek(arquivo, 0, SEEK_SET);

    //Enquanto tiver caracter para ser lido no arquivo
    while(fread(&leitura, 1, 1, arquivo)){

        //Cria um "MapadeBits" com 1024 posicoes e inicializa todas as posições com 0
        char mapaBits[numBits] = {0};

        //Faz a busca pelo codigo corresponde ao caracter na Arvore Otima e escreve no MapaBits, comecando com o tamanho da arvore 0
        escreverSequenciaNoMapaDeBits(arvoreOtima, mapaBits, leitura, 0);

        //Caminha pelo MapaDeBits
        for(int i=0; mapaBits[i] != 0 && i<numBits; i++){

            //Se o bit atual for '1'
            if(mapaBits[i] == '1') {

                //Define o bit (tamanhoMax % 8) como '1' na variável de escrita
                //Usa-se aqui o operador OR bit a bit
                escrita |= (1 << (tamanhoMax % 8));
            }

            //Incrementa o tamanho maximo
            tamanhoMax++;

            //Se ja tiver formado 1 byte
            if (tamanhoMax % 8 == 0){
                //Escreve a variavel de escrita no arquivo
                fwrite(&escrita, 1, 1, arqCompactado);

                //Reseta a variavel de escrita
                escrita = 0;
            }
        }
    }

    //Escreve o que tiver restado no arquivo
    fwrite(&escrita, 1, 1, arqCompactado);

    //Move para a posicao correta para escrever o tamanho maximo a ser lido pelo descompactador
    fseek(arqCompactado, NUM * sizeof(unsigned int), SEEK_SET);

    //Escreve no arquivo o tamanho para ser usado no descompactador
    fwrite(&tamanhoMax, sizeof(unsigned int), 1, arqCompactado);

    //Fecha o arquivo compactado usado para escrita
    fclose(arqCompactado);
}

//Faz a verificacao se deve percorrer a arvore pela esquerda ou pela direita. Retornar 0 deve percorrer para a esquerda, retornar 1 deve percorrer para a direita
static int verificaBit(unsigned char leitura, unsigned int leituraAtual) {
    //Testa o bit (leituraAtual % 8) (Usando operador AND bit a bit)
    //Se o bit encontrado for diferente de 0, retorna 1, caso contrario, retorna 0
    if( (leitura & ( 1 << (leituraAtual % 8) )) != 0 ){
        return 1;
    }
    else {
        return 0;
    }
}

void gerarArquivoDescompactado(Arvore* arvoreOtima, FILE* arquivo, char* nomeArquivo){

    //Remove a extensao ".comp" do nome do arquivo
    nomeArquivo = gerarNomeArquivoDescompactado(nomeArquivo);

    //Abre um arquivo para escrita
    FILE* arqDescompactado = fopen(nomeArquivo, "wb");

    if(!arqDescompactado) {
        printf("Não foi possivel abrir o arquivo '%s' para escrita!\n", nomeArquivo);
        exit(1);
    }

    //Variavel que determina o limite da leitura do arquivo compactado.
    unsigned int tamanhoMax;

    //Salva o tamanho maximo a ser lido para descompactar
    fread(&tamanhoMax, sizeof(unsigned int), 1, arquivo);

    //Variaveis auxiliares para leitura
    unsigned char leitura = 0;
    unsigned int leituraAtual = 0;

    //Faz a checagem e leitura ate o tamanho maximo guardado anteriormente
    while(leituraAtual < tamanhoMax){

        //Ponteiro para a arvoreOtima para caminhar por ela
        Arvore* arvore = arvoreOtima;

        //Caminha pela arvore ate encontrar o caracter correspondente pela sequencia de bits
        //O loop se repete enquanto a arvore nao for um Nó folha
        while((retornaSubarvoreEsquerda(arvore) != NULL) || (retornaSubarvoreDireita(arvore) != NULL)){
            
            //Se estiver na hora de ler um novo byte
            if(leituraAtual % 8 == 0){
                //Faz a leitura de um novo byte do arquivo e salva na variavel de leitura
                fread(&leitura, 1, 1, arquivo);
            }

            //Faz a verificacao de 1 bit, para determinar se deve percorrer a arvore pela esquerda ou pela direita
            if(verificaBit(leitura, leituraAtual) == 0){
                arvore = retornaSubarvoreEsquerda(arvore);
            }
            else {
                arvore = retornaSubarvoreDireita(arvore);
            }

            //Incrementa a leitura atual
            leituraAtual++;
        }

        //Retorna o caracter do Nó Folha encontrado correspondente ao caracter correto que deve ser escrito
        unsigned char caracter = retornaCaracter(arvore);

        //Escreve o caracter encontrado no arquivo descompactado
        fwrite(&caracter, 1, 1, arqDescompactado);
    }

    //Fecha o arquivo descompactado usado para escrita
    fclose(arqDescompactado);
}