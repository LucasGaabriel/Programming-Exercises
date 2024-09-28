#include <stdio.h>
#include <math.h>

int main(){
    int opcao, chave;
    char texto;

    scanf("%d", &opcao);

    switch(opcao){
        case 1: 
            scanf("%d%*c", &chave);
            texto = '!';

            while(chave > 26){
                chave = chave % 26;
            }

            while(texto != '.'){
                scanf("%c", &texto);

                if(texto >= 'a' && texto <= 'z'){
                    texto += chave;

                    if(texto > 'z'){
                        texto -= 26;
                    }
                }

                printf("%c", texto);
            }
            break;

        case 2:
            scanf("%d%*c", &chave);
            texto = '!';

            while(chave > 26){
                chave = chave % 26;
            }

            while(texto != '.'){
                scanf("%c", &texto);

                if(texto >= 'a' && texto <= 'z'){
                    texto -= chave;

                    if(texto < 'a'){
                        texto += 26;
                    }
                }

                printf("%c", texto);
            }
            break;

        default: printf("Operacao invalida.");
    }

    return 0;
}