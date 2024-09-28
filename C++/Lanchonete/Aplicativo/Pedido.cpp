#include <iostream>
#include <string>
#include <vector>
#include "Pedido.h"

using namespace std;

Pedido::Pedido(int &codigo, Cliente *cliente, string &data) {
    this->codigo = codigo;
    this->cliente = cliente;
    this->data = data;

    produtos = new vector<Produto *>();
    quantidadeProdutos = new vector<int>();
}

Pedido::Pedido(int &codigo, Cliente *cliente) {
    string date = __DATE__;
    string time = __TIME__;
    string dataCompleta = date + " " + time;

    this->codigo = codigo;
    this->cliente = cliente;
    this->data = dataCompleta;

    produtos = new vector<Produto *>();
    quantidadeProdutos = new vector<int>();
}

Pedido::~Pedido(){
    delete produtos;
    delete quantidadeProdutos;
}

void Pedido::imprimirDetalhesPedido() {
    cout << "\nCódigo=" << codigo << ", Cliente=" << cliente->getNome() << ", Data=" << data << "\n" << endl;

    for (int i = 0; i < produtos->size(); i++) {
        cout << "Produto=" + produtos->at(i)->getNome() <<
             ", Quantidade=" << quantidadeProdutos->at(i) <<
             ", Valor Unitario=" << produtos->at(i)->getPreco() <<
             ", Valor Total=" << (produtos->at(i)->getPreco() * quantidadeProdutos->at(i)) << endl;
    }

    cout << "\nValor total do pedido: R$" << this->valorTotal() << endl;
}

void Pedido::addProduto(Produto *p, int quantidade) const {
    this->produtos->push_back(p);
    this->quantidadeProdutos->push_back(quantidade);
}

double Pedido::valorTotal() const {
    double valor = 0;

    for (int i = 0; i < produtos->size(); i++) {
        valor += (produtos->at(i)->getPreco() * quantidadeProdutos->at(i));
    }

    return valor;
}

int Pedido::quantidadeDeProdutos() const {
    int qtd = 0;

    for (int x: *quantidadeProdutos) {
        qtd += x;
    }

    return qtd;
}

int Pedido::getCodigo() const {
    return codigo;
}

Cliente *Pedido::getCliente() {
    return cliente;
}

string Pedido::getData() {
    return data;
}

ostream &operator<<(ostream &stream, const Pedido &p) {
    stream << "Pedido{" <<
         "Codigo=" << p.codigo <<
         ", Cliente=" << p.cliente->getNome() <<
         ", Data='" << p.data + '\'' <<
         ", Quantidade de Produtos=" << p.quantidadeDeProdutos() <<
         ", Valor Total=" << p.valorTotal() <<
         '}';

    return stream;
}
