#ifndef _CLIENTE_H_
#define _CLIENTE_H_

#include <string>
#include <iostream>
#include "Usuario.h"
#include "../Aplicativo/DeliveryApp.h"

class Cliente : public Usuario {
private:
    std::string cpf; //CPF do Usuario
    int quantidadeCompras; //Quantidade de itens comprados
    double quantidadeGastos; //Quantidade gasta em dinheiro

public:
    Cliente(std::string &nome, std::string &email, std::string &senha, std::string &cpf,
            int &quantidadeCompras, double &quantidadeGastos);

    Cliente(std::string &nome, std::string &email, std::string &senha, std::string &cpf);

    ~Cliente();

    void addQuantidadeCompras(int quantidade);

    void addQuantidadeGastos(double quantidade);

    int getQuantidadeCompras() const;

    double getQuantidadeGastos() const;

    std::string getCPF();

    int exibirMenu(DeliveryApp* app) override;

    bool verificarOpcaoValida(int opcao) override;

    std::string type() override;

    friend std::ostream &operator<<(std::ostream &stream, const Cliente &c);
};

#endif //_CLIENTE_H_
