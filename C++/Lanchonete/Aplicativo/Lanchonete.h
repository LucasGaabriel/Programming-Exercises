#ifndef _LANCHONETE_H_
#define _LANCHONETE_H_

#include <string>
#include <vector>
#include "Produto.h"
#include "Pedido.h"

class Lanchonete {
private:
    int identificador; //Codigo identificador da Lanchonete
    std::string nome; //Nome da Lanchonete
    std::string categoria; //Categoria de Produtos da Lanchonete
    std::string endereco; //Endereço da Lanchonete
    double desconto_retirada; //Desconto de retirada na Lanchonete
    double desconto_consumoLocal; //Desconto de consumo na Lanchonete
    double preco_medio; //Preço medio dos produtos da Lanchonete
    double somaPontuacao; //Somatorio de todas as pontuações
    int quantidadePontuacao; //Quantidade de vezes que foi atribuida uma pontuação

public:
    std::vector<Produto *> *produtos; //Produtos da Lanchonete
    std::vector<Pedido *> *pedidos; //Pedidos feitos na Lanchonete

    Lanchonete(int &identificador, std::string &nome, std::string &categoria, std::string &endereco,
               double &desconto_retirada, double &desconto_consumoLocal, double &preco_medio,
               double &somaPontuacao, int &quantidadePontuacao);

    Lanchonete(int &identificador, std::string &nome, std::string &categoria, std::string &endereco,
               double &desconto_retirada, double &desconto_consumoLocal);

    Lanchonete(int &identificador, std::string &nome, std::string &categoria);

    ~Lanchonete();

    double pontuacao() const;

    double faturamento() const;

    int numeroDeVendas() const;

    void atribuirPontuacao(double pontos);

    Produto *buscaProdutoPorCodigo(int codigo) const;

    void atualizarPrecoMedio();

    void cadastrarProduto() const;

    void addPedido(Pedido *p) const;

    void listarPedidos() const;

    std::string getNome();

    std::string getCategoria();

    double getPreco_medio() const;

    int getIdentificador() const;

    double getDesconto_retirada() const;

    double getDesconto_consumoLocal() const;

    double getSomaPontuacao() const;

    int getQuantidadePontuacao() const;

    std::string getEndereco();

    friend std::ostream &operator<<(std::ostream &stream, const Lanchonete &c);
};

#endif //_LANCHONETE_H_
