#ifndef _PEDIDO_H_
#define _PEDIDO_H_

#include <vector>
#include <string>
#include "Produto.h"
#include "../Cadastro/Cliente.h"

class Pedido {

private:
    int codigo;
    Cliente *cliente;
    std::string data;

public:
    std::vector<Produto *> *produtos;
    std::vector<int> *quantidadeProdutos;

    Pedido(int &codigo, Cliente *cliente, std::string &data);

    Pedido(int &codigo, Cliente *cliente);

    ~Pedido();

    void imprimirDetalhesPedido();

    void addProduto(Produto *p, int quantidade) const;

    double valorTotal() const;

    int quantidadeDeProdutos() const;

    int getCodigo() const;

    Cliente *getCliente();

    std::string getData();

    friend std::ostream &operator<<(std::ostream &stream, const Pedido &p);
};

#endif //_PEDIDO_H_
