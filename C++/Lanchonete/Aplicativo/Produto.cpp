#include <iostream>
#include <string>
#include "Produto.h"

using namespace std;

Produto::Produto(int &codigo, string &nome, double &preco, int &quantidadeVendas) {
    this->codigo = codigo;
    this->nome = nome;
    this->preco = preco;
    this->quantidadeVendas = quantidadeVendas;
}

Produto::Produto(int &codigo, string &nome, double &preco) {
    this->codigo = codigo;
    this->nome = nome;
    this->preco = preco;
    this->quantidadeVendas = 0;
}

Produto::~Produto() = default;

double Produto::faturamento() const {
    return preco * quantidadeVendas;
}

int Produto::getCodigo() const {
    return codigo;
}

string Produto::getNome() {
    return nome;
}

double Produto::getPreco() const {
    return preco;
}

int Produto::getQuantidadeVendas() const {
    return quantidadeVendas;
}

void Produto::addQuantidadeVendas(int quantidade) {
    quantidadeVendas += quantidade;
}

ostream &operator<<(ostream &stream, const Produto &p) {
    stream << "Produto{" <<
         "codigo=" << p.codigo <<
         ", nome='" << p.nome << '\'' <<
         ", preco=" << p.preco <<
         ", quantidadeVendas=" << p.quantidadeVendas <<
         '}';

    return stream;
}
