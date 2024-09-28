#include <stdio.h>
#include <stdlib.h>

//Ler o Texto e Armazenar em um Vetor
int lerTexto(char *texto, char c){
    int i = 0;

    while(scanf("%c", &c) == 1 && c != '.'){
        texto[i] = c;
        i++;
    }

    return i;
}

//Converte todas as letras maiúsculas em minúsculas
void converteMinuscula(char *texto, int qtd){
    int i;
    for(i=0; i<qtd; i++){
        if(texto[i] >= 'A' && texto[i] <= 'Z')
            texto[i] += 32;
    }
}

//Transforma em Espaço tudo que não for letra
void removeCaracteres(char *texto, int qtd){
	int i = 0;
	for(i=0; i<qtd; i++){
		if(!(texto[i] >= 'a' && texto[i] <= 'z')){
			texto[i] = ' ';
		}
	}
}

//Remove todos os espaços
int removeEspacos(char *texto, int qtd){
	int i, j;
	
	for(i=0; i<qtd; i++){
		if(texto[i] == ' '){
			while(texto[i] == ' '){
				for(j=i; j<qtd; j++){
					texto[j] = texto[j+1];
				}
				qtd--;
			}
			
		}
	}
	
	return qtd;
}

int main(){
    int ocorrencias[80], i, j, x, fim = 0, qtdLetras = 0;
    char texto[80], letras[80], c;

	//Lê o texto, converte tudo para minuscula (para facilitar), e remove tudo que não for letra.
    fim = lerTexto(texto, c);
    converteMinuscula(texto, fim);
    removeCaracteres(texto, fim);
	fim = removeEspacos(texto, fim);

	//Faz copia dos vetores
	for(i=0; i<fim; i++){
		ocorrencias[i] = 0;
		letras[i] = texto[i];
	}

	//Tudo que for letra repetida, é transformada em espaço.
	for(i=0; i<fim; i++){
		for(j=i+1; j<fim; j++){
			if(letras[i] == letras[j]){
				letras[j] = ' ';
			}
		}
	}

	//Remove os espaços deixados pelo comando anterior.
	qtdLetras = removeEspacos(letras, fim);

	//Marca a ocorrencia de cada letra num vetor separado.
	x = 0;
	for(i=0; i<qtdLetras; i++){
		for(j=0; j<fim; j++){
			if(letras[i] == texto[j]){
				ocorrencias[x]++;
			}
		}
		x++;
	}
	
	//Imprime as letras e a ocorrencia delas, sem repetiçao.
    for(i=0; i<x; i++){
        printf("(%c, %d) ", letras[i], ocorrencias[i]);
    }

    return 0;
}


