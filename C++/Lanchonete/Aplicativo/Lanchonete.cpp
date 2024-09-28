#include <iostream>
#include "Lanchonete.h"
#include "../Excecoes/CodigoIdentificadorReplicadoException.h"

using namespace std;

Lanchonete::Lanchonete(int &identificador, string &nome, string &categoria, string &endereco,
                       double &desconto_retirada, double &desconto_consumoLocal, double &preco_medio,
                       double &somaPontuacao, int &quantidadePontuacao) {
    this->identificador = identificador;
    this->nome = nome;
    this->categoria = categoria;
    this->endereco = endereco;
    this->desconto_retirada = desconto_retirada;
    this->desconto_consumoLocal = desconto_consumoLocal;
    this->preco_medio = preco_medio;
    this->somaPontuacao = somaPontuacao;
    this->quantidadePontuacao = quantidadePontuacao;
    this->produtos = new vector<Produto *>();
    this->pedidos = new vector<Pedido *>();
}

Lanchonete::Lanchonete(int &identificador, string &nome, string &categoria, string &endereco,
                       double &desconto_retirada, double &desconto_consumoLocal) {
    this->identificador = identificador;
    this->nome = nome;
    this->categoria = categoria;
    this->endereco = endereco;
    this->desconto_retirada = desconto_retirada;
    this->desconto_consumoLocal = desconto_consumoLocal;
    this->preco_medio = 0;
    this->somaPontuacao = 0;
    this->quantidadePontuacao = 0;
    this->produtos = new vector<Produto *>();
    this->pedidos = new vector<Pedido *>();
}

Lanchonete::Lanchonete(int &identificador, string &nome, string &categoria) {
    this->identificador = identificador;
    this->nome = nome;
    this->categoria = categoria;
    this->endereco = "";
    this->desconto_retirada = -1;
    this->desconto_consumoLocal = -1;
    this->preco_medio = 0;
    this->somaPontuacao = 0;
    this->quantidadePontuacao = 0;
    this->produtos = new vector<Produto *>();
    this->pedidos = new vector<Pedido *>();
}

Lanchonete::~Lanchonete(){
    delete produtos;
    delete pedidos;
}

double Lanchonete::pontuacao() const {
    if (quantidadePontuacao == 0)
        return 0;

    return somaPontuacao / quantidadePontuacao;
}

double Lanchonete::faturamento() const {
    double faturamento = 0;

    for (Pedido *p: *pedidos) {
        faturamento += p->valorTotal();
    }

    return faturamento;
}

int Lanchonete::numeroDeVendas() const {
    int vendas = 0;

    for (Produto *p: *produtos) {
        vendas += p->getQuantidadeVendas();
    }

    return vendas;
}

void Lanchonete::atribuirPontuacao(double pontos) {
    if (pontos < 0 || pontos > 5) {
        cout << "Valor de pontuação deve ser entre 0 e 5" << endl;
        return;
    }

    somaPontuacao += pontos;
    quantidadePontuacao++;
}

Produto *Lanchonete::buscaProdutoPorCodigo(int codigo) const {
    for (Produto *p: *produtos) {
        if (p->getCodigo() == codigo)
            return p;
    }

    return nullptr;
}

void Lanchonete::atualizarPrecoMedio() {
    double precoTotal = 0;

    for (Produto *p: *produtos) {
        precoTotal += p->getPreco();
    }

    this->preco_medio = precoTotal / (double) this->produtos->size();
}

void Lanchonete::cadastrarProduto() const {
    cout << "\n- Cadastro Novo Produto -" << endl;

    int codigo;

    cout << "Código: ";
    cin >> codigo;

    //Se já houver um produto com o mesmo código, lança uma exceção
    if (buscaProdutoPorCodigo(codigo) != nullptr)
        throw CodigoIdentificadorReplicadoException();

    cout << "Nome: ";
    string name;
    cin >> name;

    cout << "Preço: ";
    double preco;
    cin >> preco;

    Produto *p;
    p = new Produto(codigo, name, preco);

    produtos->push_back(p);
}

void Lanchonete::addPedido(Pedido *p) const {
    pedidos->push_back(p);
}

void Lanchonete::listarPedidos() const {
    cout << "\nLista de Pedidos" << endl;
    for (Pedido *p: *pedidos) {
        cout << *p << endl;
    }
}

string Lanchonete::getNome() {
    return nome;
}

string Lanchonete::getCategoria() {
    return categoria;
}

double Lanchonete::getPreco_medio() const {
    return preco_medio;
}

int Lanchonete::getIdentificador() const {
    return identificador;
}

double Lanchonete::getDesconto_retirada() const {
    return desconto_retirada;
}

double Lanchonete::getDesconto_consumoLocal() const {
    return desconto_consumoLocal;
}

double Lanchonete::getSomaPontuacao() const {
    return somaPontuacao;
}

int Lanchonete::getQuantidadePontuacao() const {
    return quantidadePontuacao;
}

string Lanchonete::getEndereco() {
    return endereco;
}

ostream &operator<<(ostream &stream, const Lanchonete &l) {
    if (l.desconto_retirada == -1) {
        stream << "Lanchonete{" <<
             "Identificador=" << l.identificador <<
             ", Nome='" << l.nome << '\'' <<
             ", Categoria='" << l.categoria << '\'' <<
             ", Preço Médio='" << l.preco_medio << '\'' <<
             ", Pontuação=" << l.pontuacao() <<
             ", Número de Vendas=" << l.numeroDeVendas() <<
             ", Produtos=" << l.produtos <<
             ", Pedidos=" << l.pedidos <<
             '}';
    } else {
        stream << "Lanchonete{" <<
             "Identificador=" << l.identificador <<
             ", Nome='" << l.nome + '\'' <<
             ", Categoria='" << l.categoria << '\'' <<
             ", Endereco='" << l.endereco << '\'' <<
             ", Desconto de Retirada=" << l.desconto_retirada <<
             ", Desconto Consumo no Local=" << l.desconto_consumoLocal <<
             ", Preço Médio='" << l.preco_medio << '\'' <<
             ", Pontuação=" << l.pontuacao() <<
             ", Número de Vendas=" << l.numeroDeVendas() <<
             ", Produtos=" << l.produtos <<
             ", Pedidos=" << l.pedidos <<
             '}';
    }

    return stream;
}