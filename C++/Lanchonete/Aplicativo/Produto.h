#ifndef _PRODUTO_H_
#define _PRODUTO_H_

#include <iostream>
#include <string>

class Produto {

private:
    int codigo; //Codigo do produto
    std::string nome; //Nome do produto
    double preco; //Preco do produto
    int quantidadeVendas; //Quantidade do produto que foi vendido

public:
    Produto(int &codigo, std::string &nome, double &preco, int &quantidadeVendas);

    Produto(int &codigo, std::string &nome, double &preco);

    ~Produto();

    double faturamento() const;

    int getCodigo() const;

    std::string getNome();

    double getPreco() const;

    int getQuantidadeVendas() const;

    void addQuantidadeVendas(int quantidade);

    friend std::ostream &operator<<(std::ostream &stream, const Produto &p);
};

#endif //_PRODUTO_H_
