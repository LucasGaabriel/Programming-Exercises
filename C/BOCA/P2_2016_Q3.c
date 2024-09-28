#include <stdio.h>
#include <stdlib.h>

//Código do Cliente: inteiro positivo - Acaba quando encontrar -1
//Produtos: apenas letras MAIÚSCULAS - Acab quando encontra 0

int EhProduto(char prd){
    if(prd >= 'A' && prd <= 'Z')
        return 1;
    else
        return 0;
}

int AcabaramOsProdutos(char prd){
    if(prd == '0')
        return 1;
    else
        return 0;
}

int QtdDoProdutoMaisComprado(){
    int qtdProdutos = 0, maiorProdutos = 0;
    char produto, x;

    scanf("%c", &produto);

    while(!(AcabaramOsProdutos(produto))){
        if(EhProduto(produto)){
            qtdProdutos = 0;
            x = produto;

            while(produto == x && produto != '0'){
                qtdProdutos++;
                scanf("%c", &produto);
            }

        }
        if(produto != '0')
            scanf("%c", &produto);

        if(qtdProdutos > maiorProdutos)
            maiorProdutos = qtdProdutos;
    }

    return maiorProdutos;
}
    

int main(){
    int cliente, qtdProdutos, produtoMaior = 0, clienteMaior = 0;

    scanf("%d", &cliente);

    do{

        qtdProdutos = QtdDoProdutoMaisComprado();

        if(qtdProdutos > produtoMaior){
            produtoMaior = qtdProdutos;
            clienteMaior = cliente;
        }
        
        scanf("%d", &cliente);

    } while(cliente != -1);

    printf("CLIENT:%d QTD:%d", clienteMaior, produtoMaior);

    return 0;
}