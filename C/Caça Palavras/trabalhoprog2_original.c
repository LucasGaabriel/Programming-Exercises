/*
    Nome: Lucas Gabriel de Oliveira Costa
    Matricula: 2019109482
    Disciplina: Programacao II
    Trabalho Computacional: Caca Palavras 
    Data: 01/07/2019
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 100
#define M 25
#define MaxLetras 16

typedef struct {
    char nome[MaxLetras];
    int pontuacao;
    int pontosFeitos;
    int pontosRecebidos;
} tJogador;

//Le e retorna o nome dos Jogadores
tJogador lerJogador(tJogador jogador){

    scanf("%s", jogador.nome);

    return jogador;
}

//Inicializa as pontuacoes dos jogadores
tJogador inicializaPontuacao(tJogador jogador){

    jogador.pontuacao = 0;
    jogador.pontosFeitos = 0;
    jogador.pontosRecebidos = 0;

    return jogador;
}

//Preenche a Matriz de Estatisticas com as Palavras dos Jogadores
void inicializaEstatisticas(int pPorJ, char palavrasEncontradas[][MaxLetras], char palavras1[][MaxLetras], char palavras2[][MaxLetras]){
    int i, j;

    for(i=0; i<pPorJ; i++) //Preenche primeiro com as palavras do Jogador 1
        strcpy(palavrasEncontradas[i], palavras1[i]);

    for(i=0, j=pPorJ; i<pPorJ*2; i++, j++) //Depois preenche com as palavras do Jogador 2
        strcpy(palavrasEncontradas[j], palavras2[i]);
}

//Preenche (Inicializa) o Mapa Ordenado
void inicializaMapaOrdenado(int tamM, int mapaOrdenado[][N]){
    int i, j;

    for(i=0; i<tamM; i++){
        for(j=0; j<tamM; j++){
            mapaOrdenado[i][j] = 0; //Preenche a Matriz do Mapa Ordenado com zeros
        }
    }
}

//Preenche a Pontuacao com '2' se a palavra pertencer ao Jogador, ou com '1' se pertencer ao outro Jogador (Estatisticas.txt)
void addEstatisticas(int w, int p[], int t[], char Encontradas[][MaxLetras], int pPorJ, int jogada, char palavras[][MaxLetras]){
    int i, j;

    //Busca a lista a qual a Palavra Pertence
    //Se pertencer ao proprio Jogador a Pontuacao recebe 2, caso contrario, recebe 1.
    for(i=0, j=w; i<pPorJ*2; i++){
        if(strcmp(palavras[j], Encontradas[i]) == 0){
            if(jogada % 2 != 0 && i < pPorJ){
                p[i] = 2;
            }
            else if(jogada % 2 != 0 && i >= pPorJ){
                p[i] = 1;
            }
            else if(jogada % 2 == 0 && i < pPorJ){
                p[i] = 1;
            }
            else if(jogada % 2 == 0 && i >= pPorJ){
                p[i] = 2;
            }
            t[i] = jogada;
        }
    }
}

//Ordena as Palavras encontradas por Pontuacao e Alfabeticamente para serem escritas no arquivo 'Estatisticas'
void ordenaPalavrasEncontradas(int pPorJ, int p[], int t[], char palavrasEncontradas[][MaxLetras]){
    int i, j, aux1, qtd0 = 0, qtd1 = 0, qtd2 = 0;
    char aux2[MaxLetras];

    //Ordena primeiramente em ordem decrescente pela Pontuacao
    for(i=0; i<pPorJ*2; i++){
        for(j=0; j<pPorJ*2-1; j++){
            if(p[j] < p[j+1]){
                aux1 = p[j];
                p[j] = p[j+1];
                p[j+1] = aux1;

                strcpy(aux2, palavrasEncontradas[j]);
                strcpy(palavrasEncontradas[j], palavrasEncontradas[j+1]);
                strcpy(palavrasEncontradas[j+1], aux2);

                aux1 = t[j];
                t[j] = t[j+1];
                t[j+1] = aux1;
            }
        }
    }

    //Conta quantas palavras possuem a Pontuacao '0', '1' e '2'
    for(i=0; i<pPorJ*2; i++){
        if(p[i] == 0)
            qtd0++;
        else if(p[i] == 1)
            qtd1++;
        else if(p[i] == 2)
            qtd2++;
    }

    //Ordena alfabeticamente as palavras com Pontuacao '2'
    for(i=0; i<qtd2; i++){
        for(j=0; j<qtd2-1; j++){
            if(strcmp(palavrasEncontradas[j], palavrasEncontradas[j+1]) == 1){
                strcpy(aux2, palavrasEncontradas[j]);
                strcpy(palavrasEncontradas[j], palavrasEncontradas[j+1]);
                strcpy(palavrasEncontradas[j+1], aux2);

                aux1 = t[j];
                t[j] = t[j+1];
                t[j+1] = aux1;
            }
        }
    }

    //Ordena alfabeticamente as palavras com Pontuacao '1'
    for(i=qtd2; i<qtd1+qtd2; i++){
        for(j=qtd2; j<qtd1+qtd2-1; j++){
            if(strcmp(palavrasEncontradas[j], palavrasEncontradas[j+1]) == 1){
                strcpy(aux2, palavrasEncontradas[j]);
                strcpy(palavrasEncontradas[j], palavrasEncontradas[j+1]);
                strcpy(palavrasEncontradas[j+1], aux2);

                aux1 = t[j];
                t[j] = t[j+1];
                t[j+1] = aux1;
            }
        }
    }

    //Ordena alfabeticamente as palavras com Pontuacao '0'
    for(i=qtd1+qtd2; i<pPorJ; i++){
        for(j=qtd1+qtd2; j<pPorJ-1; j++){
            if(strcmp(palavrasEncontradas[j], palavrasEncontradas[j+1]) == 1){
                strcpy(aux2, palavrasEncontradas[j]);
                strcpy(palavrasEncontradas[j], palavrasEncontradas[j+1]);
                strcpy(palavrasEncontradas[j+1], aux2);

                aux1 = t[j];
                t[j] = t[j+1];
                t[j+1] = aux1;
            }
        }
    }
}

//Exibe todas as informacoes referente ao jogo (Como Palavras restantes, nome dos jogadores e pontuacoes e a 'Matriz Caca Palavras')
void exibeInfo(int tamM, int pPorJ, char mChar[][N], char palavras1[][MaxLetras], char palavras2[][MaxLetras], char matrizCP[][N], tJogador jogador1, tJogador jogador2){
    int i, j;
    
    //Nome dos Jogadores e Pontos
    printf("|            Palavras Restantes           |\n");                  
    printf("|%-16s(%02d)|%-16s(%02d)|\n", jogador1.nome, jogador1.pontuacao, jogador2.nome, jogador2.pontuacao);
    printf("|--------------------|--------------------|\n");
    
    //Palavras Restantes
    for(i=0; i<pPorJ; i++){
        if(palavras1[i][0] != '\0' || palavras2[i][0] != '\0')
            printf("|%-20s|%-20s|\n", palavras1[i], palavras2[i]);
    }
    printf("\n    ");

    //Numero das colunas da Matriz "Caca Palavras"
    for(i=0; i<tamM; i++){
        printf("%02d ", i);
    }
    printf("\n");

    //Linhas e os elementos da Matriz "Caca Palavras"
    for(i=0; i<tamM; i++){
        printf("%02d|", i);
        for(j=0; j<tamM; j++){
            printf(" %c ", matrizCP[i][j]);
        }
        printf("|\n");
    }
    printf("\n");
}

//Remove todos os espacos deixados por letras repetidas (Inicializacao.txt)
void removeEspaco(char iniciais[], int pPorJ){
    int i, j;

    //Remove todos os espacos
    for(i=0; i<pPorJ-1; i++){
        if(iniciais[i] == ' '){
            for(j=i; j<pPorJ-1; j++){
                iniciais[j] = iniciais[j+1];
            }
        }
    }
}

//Ordena alfabeticamente as iniciais encontradas (Inicializacao.txt)
void ordenaIniciais(char iniciais[], int lim){
    int i, j;
    char aux;
    
    //Ordena alfabeticamente as Iniciais das Palavras
    for(i=0; i<lim; i++){
        for(j=0; j<lim-1; j++){
            if(iniciais[j] > iniciais[j+1]){
                aux = iniciais[j];
                iniciais[j] = iniciais[j+1];
                iniciais[j+1] = aux;
            }
        }
    }
}

//Verifica a ocorrencia das Iniciais nas palavras do Jogador e armazena no vetor de 'Ocorrencias' (Inicializacao.txt)
void verificaOcorrencia(char iniciais[], int ocorrenciaIniciais[], int pPorJ, int lim, char palavras[][MaxLetras]){
    int i, j;

    for(i=0; i<lim; i++){
        for(j=0; j<pPorJ; j++){
            if(iniciais[i] == palavras[j][0])
                ocorrenciaIniciais[i]++;
        }
    }
}

//Preenche um vetor com as Iniciais das palavras do Jogador e remove as Iniciais repetidas [Trocando para um espaco ' '] (Inicializacao.txt)
void exibeIniciais(FILE *arquivo, char palavras[][MaxLetras], int pPorJ){
    int i, j, w, ocorrenciaIniciais[M] = {0}, limite = pPorJ;
    char iniciais[M];

    //Preenche um vetor com as iniciais das palavras
    for(i=0; i<pPorJ; i++){
        iniciais[i] = palavras[i][0];
    }

    //Encontra e preenche com espaco as letras repetidas
    for(i=0; i<pPorJ-1; i++){
        for(j=i+1; j<pPorJ; j++){
            if(iniciais[i] == iniciais[j] && iniciais[i] != ' '){
                iniciais[j] = ' ';
                limite--;
            }
        }
    }

    removeEspaco(iniciais, pPorJ);
    ordenaIniciais(iniciais, limite);
    verificaOcorrencia(iniciais, ocorrenciaIniciais, pPorJ, limite, palavras);

    fprintf(arquivo,"Letras Iniciais:\n");
    
    for(i=0; i<limite; i++){
        fprintf(arquivo,"%c -> %d\n", iniciais[i], ocorrenciaIniciais[i]);
    }
}

//Verifica a Maior Palavra do Jogador para ser exibida no arquivo 'Inicializacao.txt'
int verificaMaiorPalavra(char palavras[][MaxLetras], int pPorJ){
    int i, maior = 0, tam, indiceMaior = 0;

    for(i=0; i<pPorJ; i++){
        tam = strlen(palavras[i]);
        if(tam > maior){
            maior = tam;
            indiceMaior = i;
        }
    }

    return indiceMaior;
}

//Gera o arquivo 'Inicializacao.txt' na pasta 'saida' do diretorio informado
void arquivoInicializacao(tJogador jogador1, tJogador jogador2, char palavras1[][MaxLetras], char palavras2[][MaxLetras], int pPorJ, char **argv){
    int i, maiorPalavra;
    char saida[1000];
    FILE *arquivo;

    //Escreve o arquivo na subpasta 'saida' do diretorio informado
    strcpy(saida, argv[1]);
    strcat(saida, "/saida/Inicializacao.txt");
    arquivo = fopen(saida, "w");
    
    //JOGADOR 1
    fprintf(arquivo,"--Jogador 1--\n");
    fprintf(arquivo,"Nome: %s\n", jogador1.nome);
    fprintf(arquivo,"Palavras:\n");

    for(i=0; i<pPorJ; i++){
        fprintf(arquivo,"%s\n", palavras1[i]);
    }

    maiorPalavra = verificaMaiorPalavra(palavras1, pPorJ);

    //Maior Palavra
    fprintf(arquivo,"Maior Palavra:\n");
    fprintf(arquivo,"%s\n", palavras1[maiorPalavra]);

    exibeIniciais(arquivo, palavras1, pPorJ);
    
    fprintf(arquivo,"\n");

    //JOGADOR 2
    fprintf(arquivo,"--Jogador 2--\n");
    fprintf(arquivo,"Nome: %s\n", jogador2.nome);
    fprintf(arquivo,"Palavras:\n");

    for(i=0; i<pPorJ; i++){
        fprintf(arquivo,"%s\n", palavras2[i]);
    }

    maiorPalavra = verificaMaiorPalavra(palavras2, pPorJ);

    //Maior Palavra
    fprintf(arquivo,"Maior Palavra:\n");
    fprintf(arquivo,"%s\n", palavras2[maiorPalavra]);

    exibeIniciais(arquivo, palavras2, pPorJ);
    
    fprintf(arquivo,"\n");

    fclose(arquivo);
}

//Gera o arquivo 'Estatisticas' na pasta 'saida' do diretorio informado
void arquivoEstatisticas(tJogador jogador1, tJogador jogador2, int pPorJ, int p[], int t[], char palavrasEncontradas[][MaxLetras], char **argv){
    FILE *arquivo;
    char saida[1000];
    int i;

    //Escreve o arquivo na subpasta 'saida' do diretorio informado
    strcpy(saida, argv[1]);
    strcat(saida, "/saida/Estatisticas.txt");
    arquivo = fopen(saida, "w");

    fprintf(arquivo,"--------------\n");
    fprintf(arquivo,"--- PONTOS ---\n");
    fprintf(arquivo,"--------------\n\n");

    //Nome e Pontuacao JOGADOR 1
    fprintf(arquivo,"%s\n", jogador1.nome);
    fprintf(arquivo,"Feitos: %d\n", jogador1.pontosFeitos);
    fprintf(arquivo,"Recebidos: %d\n", jogador1.pontosRecebidos);
    fprintf(arquivo,"Total: %d\n\n", jogador1.pontuacao);

    //Nome e Pontuacao JOGADOR 2
    fprintf(arquivo,"%s\n", jogador2.nome);
    fprintf(arquivo,"Feitos: %d\n", jogador2.pontosFeitos);
    fprintf(arquivo,"Recebidos: %d\n", jogador2.pontosRecebidos);
    fprintf(arquivo,"Total: %d\n\n", jogador2.pontuacao);

    fprintf(arquivo,"---------------------------\n");
    fprintf(arquivo,"--- PALAVRAS POR PONTOS ---\n");
    fprintf(arquivo,"---------------------------\n\n");
    
    fprintf(arquivo,"|P|     Palavra    | T |\n");
    fprintf(arquivo,"|-|----------------|---|\n");

    ordenaPalavrasEncontradas(pPorJ, p, t, palavrasEncontradas);

    //Pontuacao, Palavras e Turnos em que foram encontradas
    for(i=0; i<pPorJ*2; i++)
        fprintf(arquivo,"|%d|%-16s|%03d|\n", p[i], palavrasEncontradas[i], t[i]);

    fclose(arquivo);
}

//Gera o arquivo 'MapaOrdenado.txt' na pasta 'saida' do diretorio informado
void arquivoMapaOrdenado(int tamM, int mO[][N], char **argv){
    int i, j;
    char saida[1000];
    FILE *arquivo;

    //Escreve o arquivo na subpasta 'saida' do diretorio informado
    strcpy(saida, argv[1]);
    strcat(saida, "/saida/MapaOrdenado.txt");
    arquivo = fopen(saida, "w");

    //Escreve o Mapa Ordenado no arquivo 'MapaOrdenado.txt'
    for(i=0; i<tamM; i++){
        for(j=0; j<tamM; j++){
            if(mO[i][j] != 0)           //Se na posicao tiver um numero diferente de zero, imprime esse numero
                fprintf(arquivo,"%02d ", mO[i][j]); 
            else                        //Se tiver um zero, imprime '--' no lugar                         
                fprintf(arquivo,"-- ");
        }
        fprintf(arquivo,"\n");
    }

    fclose(arquivo);
}

//Remove a palavra encontrada da lista de Palavras do Jogador
void removePalavra(int w, int pPorJ, char palavras[][MaxLetras]){
    int i, tam = 0;
    
    //Verifica quantas palavras ainda restam na lista e grava em 'tam'
    for(i=0; i<pPorJ; i++){
        if(palavras[i][0] >= 'a' && palavras[i][0] <= 'z')
            tam++;
    }
    
    //Remove a palavra encontrada da lista e preenche o "vazio" com as palavras restantes
    for(i=w; i<tam-1; i++){
        strcpy(palavras[i], palavras[i+1]);
    }
    palavras[i][0] = '\0'; //Preenche a ultima posicao (Palavra repetida) com o caracter nulo
}

//Verifica se a jogada e valida/invalida
int jogadaInvalida(int x, int y, char matrizCP[][N], int tamM){

    if(matrizCP[x][y] >= 'A' && matrizCP[x][y] <= 'Z')
        return 1;   //Retorna 1 se a coordenada ja tiver sido jogada
    else if(x >= tamM || x < 0 || y >= tamM || y < 0)
        return 2;   //Retorna 2 se a coordenada esta fora do tabuleiro

    return 0; //Retorna 0 se a jogada for valida
}

//Busca palavras na diagonal (Direita-Baixo)
int buscaDireitaBaixo(int tamM, char mChar[][N], char palavras[][MaxLetras], char matrizCP[][N], int x, int y, int pPorJ, int jogada, int p[], int t[], char Encontradas[][MaxLetras], int numMO, int mO[][N]){
    int i, j, w, a, tam, cont = 0;
	
	//Busca palavras para direita-baixo nas Palavras do Jogador.
    for(w=0; w<pPorJ; w++){
        cont = 0;
        if(mChar[x][y] == palavras[w][0]){
            tam = strlen(palavras[w]);

            for(i=x, j=y, a=0; a<tam; i++, j++, a++){
                if(mChar[i][j] == palavras[w][a])
                    cont++;
            }

            if(cont == tam){
                for(i=x, j=y, a=0; a<tam; i++, j++, a++){
                	if(!(matrizCP[i][j] >= 'A' && matrizCP[i][j] <= 'Z'))
                    	matrizCP[i][j] = palavras[w][a];
                    if(a == 0)
                        matrizCP[i][j] -= 32;
                    if(mO[i][j] == 0)
                        mO[i][j] = numMO;
                }
                addEstatisticas(w, p, t, Encontradas, pPorJ, jogada, palavras);
                removePalavra(w, pPorJ, palavras);
                return 1;
            }
        }   
    }

    return 0;
}

//Busca palavras na diagonal (Direita-Cima)
int buscaDireitaCima(int tamM, char mChar[][N], char palavras[][MaxLetras], char matrizCP[][N], int x, int y, int pPorJ, int jogada, int p[], int t[], char Encontradas[][MaxLetras], int numMO, int mO[][N]){
    int i, j, w, a, tam, cont = 0;

    //Busca palavras para direita-cima nas Palavras do Jogador.
    for(w=0; w<pPorJ; w++){
        cont = 0;
        if(mChar[x][y] == palavras[w][0]){
            tam = strlen(palavras[w]);

            for(i=x, j=y, a=0; a<tam; i--, j++, a++){
                if(mChar[i][j] == palavras[w][a])
                    cont++;
            }

            if(cont == tam){
                for(i=x, j=y, a=0; a<tam; i--, j++, a++){
                	if(!(matrizCP[i][j] >= 'A' && matrizCP[i][j] <= 'Z'))
                    	matrizCP[i][j] = palavras[w][a];
                    if(a == 0)
                        matrizCP[i][j] -= 32;
                    if(mO[i][j] == 0)
                        mO[i][j] = numMO;
                }
                addEstatisticas(w, p, t, Encontradas, pPorJ, jogada, palavras);
                removePalavra(w, pPorJ, palavras);               
                return 1;
            }
        }   
    }
    
    return 0;
}

//Busca palavras na diagonal (Esquerda-Cima)
int buscaEsquerdaCima(int tamM, char mChar[][N], char palavras[][MaxLetras], char matrizCP[][N], int x, int y, int pPorJ, int jogada, int p[], int t[], char Encontradas[][MaxLetras], int numMO, int mO[][N]){
    int i, j, w, a, tam, cont = 0;

    //Busca palavras para esquerda-cima nas Palavras do Jogador.
    for(w=0; w<pPorJ; w++){
        cont = 0;
        if(mChar[x][y] == palavras[w][0]){
            tam = strlen(palavras[w]);

            for(i=x, j=y, a=0; a<tam; i--, j--, a++){
                if(mChar[i][j] == palavras[w][a])
                    cont++;
            }

            if(cont == tam){
                for(i=x, j=y, a=0; a<tam; i--, j--, a++){
                	if(!(matrizCP[i][j] >= 'A' && matrizCP[i][j] <= 'Z'))
                    	matrizCP[i][j] = palavras[w][a];
                    if(a == 0)
                        matrizCP[i][j] -= 32;
                    if(mO[i][j] == 0)
                        mO[i][j] = numMO;
                }
                addEstatisticas(w, p, t, Encontradas, pPorJ, jogada, palavras);
                removePalavra(w, pPorJ, palavras);
                return 1;
            }
        }   
    }
    
    return 0;
}

//Busca palavras na diagonal (Esquerda-Baixo)
int buscaEsquerdaBaixo(int tamM, char mChar[][N], char palavras[][MaxLetras], char matrizCP[][N], int x, int y, int pPorJ, int jogada, int p[], int t[], char Encontradas[][MaxLetras], int numMO, int mO[][N]){
    int i, j, w, a, tam, cont = 0;

    //Busca palavras para esquerda-baixo nas Palavras do Jogador.
    for(w=0; w<pPorJ; w++){
        cont = 0;
        if(mChar[x][y] == palavras[w][0]){
            tam = strlen(palavras[w]);

            for(i=x, j=y, a=0; a<tam; i++, j--, a++){
                if(mChar[i][j] == palavras[w][a])
                    cont++;
            }

            if(cont == tam){
                for(i=x, j=y, a=0; a<tam; i++, j--, a++){
                	if(!(matrizCP[i][j] >= 'A' && matrizCP[i][j] <= 'Z'))
                    	matrizCP[i][j] = palavras[w][a];
                    if(a == 0)
                        matrizCP[i][j] -= 32;
                    if(mO[i][j] == 0)
                        mO[i][j] = numMO;
                }
                addEstatisticas(w, p, t, Encontradas, pPorJ, jogada, palavras);
                removePalavra(w, pPorJ, palavras);
                return 1;
            }
        }   
    }
    
    return 0;
}

//Verifica se ha alguma Palavra na Diagonal das Coordenadas digitadas pelo jogador
int verificaDiagonal(int tamM, char mChar[][N], char palavras1[][MaxLetras], char palavras2[][MaxLetras], char matrizCP[][N], int x, int y, int pPorJ, int jogada, int p[], int t[], char Encontradas[][MaxLetras], int numMO, int mO[][N]){

    //Busca palavras nas diagonais nas Palavras do Jogador 1 (Retornando 1, caso encontre) e do Jogador 2 (Retornando 2, caso encontre)

    if(buscaDireitaBaixo(tamM, mChar, palavras1, matrizCP, x, y, pPorJ, jogada, p, t, Encontradas, numMO, mO))
        return 1;
    else if(buscaDireitaBaixo(tamM, mChar, palavras2, matrizCP, x, y, pPorJ, jogada, p, t, Encontradas, numMO, mO))
        return 2;

    if(buscaDireitaCima(tamM, mChar, palavras1, matrizCP, x, y, pPorJ, jogada, p, t, Encontradas, numMO, mO))
        return 1;
    else if(buscaDireitaCima(tamM, mChar, palavras2, matrizCP, x, y, pPorJ, jogada, p, t, Encontradas, numMO, mO))
        return 2;
    
    if(buscaEsquerdaCima(tamM, mChar, palavras1, matrizCP, x, y, pPorJ, jogada, p, t, Encontradas, numMO, mO))
        return 1;
    else if(buscaEsquerdaCima(tamM, mChar, palavras2, matrizCP, x, y, pPorJ, jogada, p, t, Encontradas, numMO, mO))
        return 2;

    if(buscaEsquerdaBaixo(tamM, mChar, palavras1, matrizCP, x, y, pPorJ, jogada, p, t, Encontradas, numMO, mO))
        return 1;
    else if(buscaEsquerdaBaixo(tamM, mChar, palavras2, matrizCP, x, y, pPorJ, jogada, p, t, Encontradas, numMO, mO))
        return 2;

    return 0;
}

//Busca palavras para baixo
int buscaBaixo(int tamM, char mChar[][N], char palavras[][MaxLetras], char matrizCP[][N], int x, int y, int pPorJ, int jogada, int p[], int t[], char Encontradas[][MaxLetras], int numMO, int mO[][N]){
    int i, j, w, a, tam, cont = 0;
	
	//Busca palavras para baixo nas Palavras do Jogador.
    for(w=0; w<pPorJ; w++){
        cont = 0;
        if(mChar[x][y] == palavras[w][0]){
            tam = strlen(palavras[w]);

            for(i=x, j=y, a=0; a<tam; i++, a++){
                if(mChar[i][j] == palavras[w][a])
                    cont++;
            }

            if(cont == tam){
                for(i=x, j=y, a=0; a<tam; i++, a++){
                	if(!(matrizCP[i][j] >= 'A' && matrizCP[i][j] <= 'Z'))
                    	matrizCP[i][j] = palavras[w][a];
                    if(a == 0)
                        matrizCP[i][j] -= 32;
                    if(mO[i][j] == 0)
                        mO[i][j] = numMO;
                }
                addEstatisticas(w, p, t, Encontradas, pPorJ, jogada, palavras);
                removePalavra(w, pPorJ, palavras);
                return 1;
            }
        }   
    }
    
    return 0;
}

//Busca palavras para cima
int buscaCima(int tamM, char mChar[][N], char palavras[][MaxLetras], char matrizCP[][N], int x, int y, int pPorJ, int jogada, int p[], int t[], char Encontradas[][MaxLetras], int numMO, int mO[][N]){
    int i, j, w, a, tam, cont = 0;

    //Busca palavras para cima nas Palavras do Jogador.
    for(w=0; w<pPorJ; w++){
        cont = 0;
        if(mChar[x][y] == palavras[w][0]){
            tam = strlen(palavras[w]);

            for(i=x, j=y, a=0; a<tam; i--, a++){
                if(mChar[i][j] == palavras[w][a])
                    cont++;
            }

            if(cont == tam){
                for(i=x, j=y, a=0; a<tam; i--, a++){
                	if(!(matrizCP[i][j] >= 'A' && matrizCP[i][j] <= 'Z'))
                    	matrizCP[i][j] = palavras[w][a];
                    if(a == 0)
                        matrizCP[i][j] -= 32;
                    if(mO[i][j] == 0)
                        mO[i][j] = numMO;
                }
                addEstatisticas(w, p, t, Encontradas, pPorJ, jogada, palavras);
                removePalavra(w, pPorJ, palavras);
                return 1;
            }
        }   
    }
    
    return 0;
}

//Verifica se ha alguma Palavra na Vertical das Coordenadas digitadas pelo jogador
int verificaVertical(int tamM, char mChar[][N], char palavras1[][MaxLetras], char palavras2[][MaxLetras], char matrizCP[][N], int x, int y, int pPorJ, int jogada, int p[], int t[], char Encontradas[][MaxLetras], int numMO, int mO[][N]){
	
    //Busca palavras para cima e para baixo nas Palavras do Jogador 1 (Retornando 1, caso encontre) e do Jogador 2 (Retornando 2, caso encontre)

    if(buscaBaixo(tamM, mChar, palavras1, matrizCP, x, y, pPorJ, jogada, p, t, Encontradas, numMO, mO))
        return 1;
    else if(buscaBaixo(tamM, mChar, palavras2, matrizCP, x, y, pPorJ, jogada, p, t, Encontradas, numMO, mO))
        return 2;

    if(buscaCima(tamM, mChar, palavras1, matrizCP, x, y, pPorJ, jogada, p, t, Encontradas, numMO, mO))
        return 1;
    else if(buscaCima(tamM, mChar, palavras2, matrizCP, x, y, pPorJ, jogada, p, t, Encontradas, numMO, mO))
        return 2;

    return 0;
}

//Busca palavras para a direita
int buscaDireita(int tamM, char mChar[][N], char palavras[][MaxLetras], char matrizCP[][N], int x, int y, int pPorJ, int jogada, int p[], int t[], char Encontradas[][MaxLetras], int numMO, int mO[][N]){
    int i, j, w, a, tam, cont = 0;

    //Busca palavras para a direita nas Palavras do Jogador.
    for(w=0; w<pPorJ; w++){
        cont = 0;
        if(mChar[x][y] == palavras[w][0]){
            tam = strlen(palavras[w]);

            for(i=x, j=y, a=0; a<tam; j++, a++){
                if(mChar[i][j] == palavras[w][a])
                    cont++;
            }

            if(cont == tam){
                for(i=x, j=y, a=0; a<tam; j++, a++){
                	if(!(matrizCP[i][j] >= 'A' && matrizCP[i][j] <= 'Z'))
                    	matrizCP[i][j] = palavras[w][a];
                    if(a == 0)
                        matrizCP[i][j] -= 32;
                    if(mO[i][j] == 0)
                        mO[i][j] = numMO;
                }
                addEstatisticas(w, p, t, Encontradas, pPorJ, jogada, palavras);
                removePalavra(w, pPorJ, palavras);
                return 1;
            }
        }   
    }

    return 0;
}

//Busca palavras para a esquerda
int buscaEsquerda(int tamM, char mChar[][N], char palavras[][MaxLetras], char matrizCP[][N], int x, int y, int pPorJ, int jogada, int p[], int t[], char Encontradas[][MaxLetras], int numMO, int mO[][N]){
    int i, j, w, a, tam, cont = 0;

    //Busca palavras para a esquerda nas Palavras do Jogador.
    for(w=0; w<pPorJ; w++){
        cont = 0;
        if(mChar[x][y] == palavras[w][0]){
            tam = strlen(palavras[w]);

            for(i=x, j=y, a=0; a<tam; j--, a++){
                if(mChar[i][j] == palavras[w][a])
                    cont++;
            }

            if(cont == tam){
                for(i=x, j=y, a=0; a<tam; j--, a++){
                	if(!(matrizCP[i][j] >= 'A' && matrizCP[i][j] <= 'Z'))
                    	matrizCP[i][j] = palavras[w][a];
                    if(a == 0)
                        matrizCP[i][j] -= 32;
                    if(mO[i][j] == 0)
                        mO[i][j] = numMO;
                }
                addEstatisticas(w, p, t, Encontradas, pPorJ, jogada, palavras);
                removePalavra(w, pPorJ, palavras);
                return 1;
            }
        }   
    }

    return 0;
}

//Verifica se ha alguma Palavra na Horizontal das Coordenadas digitadas pelo jogador
int verificaHorizontal(int tamM, char mChar[][N], char palavras1[][MaxLetras], char palavras2[][MaxLetras], char matrizCP[][N], int x, int y, int pPorJ, int jogada, int p[], int t[], char Encontradas[][MaxLetras], int numMO, int mO[][N]){
    
    //Busca palavras para a direita e para a esquerda nas Palavras do Jogador 1 (Retornando 1, caso encontre) e do Jogador 2 (Retornando 2, caso encontre)

    if(buscaDireita(tamM, mChar, palavras1, matrizCP, x, y, pPorJ, jogada, p, t, Encontradas, numMO, mO))
        return 1;
    else if(buscaDireita(tamM, mChar, palavras2, matrizCP, x, y, pPorJ, jogada, p, t, Encontradas, numMO, mO))
        return 2;

    if(buscaEsquerda(tamM, mChar, palavras1, matrizCP, x, y, pPorJ, jogada, p, t, Encontradas, numMO, mO))
        return 1;
    else if(buscaEsquerda(tamM, mChar, palavras2, matrizCP, x, y, pPorJ, jogada, p, t, Encontradas, numMO, mO))
        return 2;

    return 0;
} 

//Verifica se ha alguma Palavra nas coordenadas digitadas pelo jogador
int verificaPalavra(int tamM, char mChar[][N], char palavras1[][MaxLetras], char palavras2[][MaxLetras], char matrizCP[][N], int x, int y, int pPorJ, int jogada, int p[], int t[], char Encontradas[][MaxLetras], int numMO, int mO[][N]){
    int ok;

    //Para cada funcao, se houver uma palavra descoberta, ja pode retornar, pois nao ha mais de uma palavra em cada coordenada

    if(ok = verificaHorizontal(tamM, mChar, palavras1, palavras2, matrizCP, x, y, pPorJ, jogada, p, t, Encontradas, numMO, mO))
        return ok;
    
    if(ok = verificaVertical(tamM, mChar, palavras1, palavras2, matrizCP, x, y, pPorJ, jogada, p, t, Encontradas, numMO, mO))
        return ok;
    
    if(ok = verificaDiagonal(tamM, mChar, palavras1, palavras2, matrizCP, x, y, pPorJ, jogada, p, t, Encontradas, numMO, mO))
        return ok;
    
    //Revela a letra da coordenada (Em maiusculo) em caso de nao encontrar nenhuma palavra.
    matrizCP[x][y] = mChar[x][y]-32;
    return 0;
}

//Verifica e exibe o ganhador que tiver a maior quantidade de pontos ou se houve empate
void verificaGanhador(tJogador jogador1, tJogador jogador2){

    //Exibe o ganhador (Aquele com maior quantidade de pontos)
    if(jogador1.pontuacao > jogador2.pontuacao)
        printf("%s Ganhou!!!", jogador1.nome);
    else if(jogador2.pontuacao > jogador1.pontuacao)
        printf("%s Ganhou!!!", jogador2.nome);
    else //Se a pontuacao for igual, houve empate
        printf("Empate");
}

//EXECUCAO DO JOGO
void jogo(int maximoJogadas, int tamanhoMatriz, int palavrasPorJogador, char matrizCaracteres[][N], char matrizCacaPalavras[][N], char palavras1[][MaxLetras], char palavras2[][MaxLetras], tJogador jogador1, tJogador jogador2, char **argv){
    int i, x, y, ok, invalido, pPalavrasEncontradas[50] = {0}, tPalavrasEncontradas[50] = {0}, numMapaOrdenado = 1, mapaOrdenado[N][N];
    char palavrasEncontradas[50][MaxLetras];

    inicializaEstatisticas(palavrasPorJogador, palavrasEncontradas, palavras1, palavras2);

    inicializaMapaOrdenado(tamanhoMatriz, mapaOrdenado);

    exibeInfo(tamanhoMatriz, palavrasPorJogador, matrizCaracteres, palavras1, palavras2, matrizCacaPalavras, jogador1, jogador2);

    //EXECUCAO DO JOGO
    //Garante que o jogo tera um limite de jogadas e terminara assim que o limite for atingido ou ate que as palavras de algum dos jogadores acabe 
    for(i=1; i<=maximoJogadas*2 && palavras1[0][0] != '\0' && palavras2[0][0] != '\0'; i++){

        if(i % 2 != 0){ //Se o numero da jogada for IMPAR, a vez e do 1o Jogador

            printf("%s por favor entre com as coordenadas para a sua jogada:\n", jogador1.nome);
            scanf("%d %d", &x, &y);

            //Verifica se a jogada e valida.
            while(invalido = jogadaInvalida(x, y, matrizCacaPalavras, tamanhoMatriz)){ 
                exibeInfo(tamanhoMatriz, palavrasPorJogador, matrizCaracteres, palavras1, palavras2, matrizCacaPalavras, jogador1, jogador2);

                if(invalido == 1)
                    printf("Coordenadas ja jogadas. %s por favor entre com novas coordenadas para a sua jogada:\n", jogador1.nome);
                if(invalido == 2)
                    printf("Coordenadas fora do tabuleiro. %s por favor entre com novas coordenadas para a sua jogada:\n", jogador1.nome);
            
                scanf("%d %d", &x, &y);
            }

            //Verifica se ha alguma palavra na coordenada jogada
            ok = verificaPalavra(tamanhoMatriz, matrizCaracteres, palavras1, palavras2, matrizCacaPalavras, x, y, palavrasPorJogador, i, pPalavrasEncontradas, tPalavrasEncontradas, palavrasEncontradas, numMapaOrdenado, mapaOrdenado);
            
            if(ok > 0) //Controla o numero de palavras descobertas para ser usado no mapa ordenado 
                numMapaOrdenado++;

            //Acrescenta a pontuacao ao jogador, de acordo com a palavra descoberta
            if(ok == 1){
                jogador1.pontuacao += 2;
                jogador1.pontosFeitos += 2;
            }
            else if(ok == 2){
                jogador2.pontuacao += 1;
                jogador2.pontosRecebidos += 1;
            }

            exibeInfo(tamanhoMatriz, palavrasPorJogador, matrizCaracteres, palavras1, palavras2, matrizCacaPalavras, jogador1, jogador2);
        }
		else{ //Se o numero da jogada for PAR, a vez e do 2o Jogador
			
        	printf("%s por favor entre com as coordenadas para a sua jogada:\n", jogador2.nome);
        	scanf("%d %d", &x, &y);

        	//Verifica se a jogada e valida.
        	while(invalido = jogadaInvalida(x, y, matrizCacaPalavras, tamanhoMatriz)){ 
                exibeInfo(tamanhoMatriz, palavrasPorJogador, matrizCaracteres, palavras1, palavras2, matrizCacaPalavras, jogador1, jogador2);

            	if(invalido == 1)
                	printf("Coordenadas ja jogadas. %s por favor entre com novas coordenadas para a sua jogada:\n", jogador2.nome);
            	if(invalido == 2)
                	printf("Coordenadas fora do tabuleiro. %s por favor entre com novas coordenadas para a sua jogada:\n", jogador2.nome);
            
            	scanf("%d %d", &x, &y);
        	}

            //Verifica se ha alguma palavra na coordenada jogada
        	ok = verificaPalavra(tamanhoMatriz, matrizCaracteres, palavras1, palavras2, matrizCacaPalavras, x, y, palavrasPorJogador, i, pPalavrasEncontradas, tPalavrasEncontradas, palavrasEncontradas, numMapaOrdenado, mapaOrdenado);
            
            if(ok > 0) //Controla o numero de palavras descobertas para ser usado no mapa ordenado 
                numMapaOrdenado++;

            //Acrescenta a pontuacao ao jogador, de acordo com a palavra descoberta
        	if(ok == 2){
            	jogador2.pontuacao += 2;
                jogador2.pontosFeitos += 2;
            }
        	else if(ok == 1){
            	jogador1.pontuacao += 1;
                jogador1.pontosRecebidos += 1;
            }

        	exibeInfo(tamanhoMatriz, palavrasPorJogador, matrizCaracteres, palavras1, palavras2, matrizCacaPalavras, jogador1, jogador2);
    	}
    }

    //Verifica e exibe o ganhador da partida
    verificaGanhador(jogador1, jogador2);

    //Gera o arquivo Estatisticas
    arquivoEstatisticas(jogador1, jogador2, palavrasPorJogador, pPalavrasEncontradas, tPalavrasEncontradas, palavrasEncontradas, argv);

    //Gera o mapa Ordenado
    arquivoMapaOrdenado(tamanhoMatriz, mapaOrdenado, argv);
}

//FUNÇÃO PRINCIPAL
int main(int argc, char **argv){

    int maximoJogadas, tamanhoMatriz, palavrasPorJogador, i, j;
    char matrizCaracteres[N][N], matrizCacaPalavras[N][N], palavras1[M][MaxLetras], palavras2[M][MaxLetras], saida[1000];
    tJogador jogador1, jogador2;
    FILE *arquivo;

    //Verifica se o diretorio do arquivo de configuracao foi passado para o programa.
    if(argc != 2){
        printf("ERRO: O diretorio de arquivos de configuracao nao foi informado.");
        exit(1);
    }

    //Le o arquivo 'config.txt'.
    strcpy(saida, argv[1]);
    strcat(saida, "/config.txt");
    arquivo = fopen(saida, "r");

    //Verifica se o programa conseguiu ler o arquivo 'config.txt'.
    if(arquivo == NULL){
        printf("ERRO: Nao foi possivel ler o arquivo de configuracao no diretorio informado: '%s'.\nPrograma encerrado.\n", argv[1]);
        exit(1);
    }
    
    //Faz a leitura do arquivo de configuracao e armazena cada informacao em sua respectiva variavel
    fscanf(arquivo,"%d %d", &maximoJogadas, &tamanhoMatriz);
    
    for(i=0; i<tamanhoMatriz; i++){
        fscanf(arquivo,"%s", matrizCaracteres[i]);
    }

    fscanf(arquivo,"%d", &palavrasPorJogador);

    for(i=0; i<palavrasPorJogador; i++){
        fscanf(arquivo,"%s", palavras1[i]);
    }

    for(i=0; i<palavrasPorJogador; i++){
        fscanf(arquivo,"%s", palavras2[i]);
    }

    fclose(arquivo);
    
    //Informar o Nome dos Jogadores
    printf("Nome do Jogador 1:\n");
    jogador1 = lerJogador(jogador1);
    printf("Nome do Jogador 2:\n");
    jogador2 = lerJogador(jogador2);
   
    //Gera o arquivo de Inicializacao
    arquivoInicializacao(jogador1, jogador2, palavras1, palavras2, palavrasPorJogador, argv);
    
    //Preenche (Inicializa) a Matriz que vai ser utilizada no Caca Palavras com '-'.
    for(i=0; i<tamanhoMatriz; i++){
        for(j=0; j<tamanhoMatriz; j++){
            matrizCacaPalavras[i][j] = '-';
        }
	}
    
    //Inicializa as pontuacoes dos jogadores
    jogador1 = inicializaPontuacao(jogador1);
    jogador2 = inicializaPontuacao(jogador2);
    
    //Executa o jogo
    jogo(maximoJogadas, tamanhoMatriz, palavrasPorJogador, matrizCaracteres, matrizCacaPalavras, palavras1, palavras2, jogador1, jogador2, argv);

    return 0;
}
