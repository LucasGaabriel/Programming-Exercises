#include <iostream>
#include "Cliente.h"

using namespace std;

Cliente::Cliente(string &nome, string &email, string &senha, string &cpf,
                 int &quantidadeCompras, double &quantidadeGastos) : Usuario(nome, email, senha) {
    this->cpf = cpf;
    this->quantidadeCompras = quantidadeCompras;
    this->quantidadeGastos = quantidadeGastos;
}

Cliente::Cliente(string &nome, string &email, string &senha, string &cpf) : Usuario(nome, email, senha) {
    this->cpf = cpf;
    this->quantidadeCompras = 0;
    this->quantidadeGastos = 0;
}

Cliente::~Cliente() = default;

void Cliente::addQuantidadeCompras(int quantidade) {
    quantidadeCompras += quantidade;
}

void Cliente::addQuantidadeGastos(double quantidade) {
    quantidadeGastos += quantidade;
}

int Cliente::getQuantidadeCompras() const {
    return quantidadeCompras;
}

double Cliente::getQuantidadeGastos() const {
    return quantidadeGastos;
}

string Cliente::getCPF() {
    return cpf;
}

int Cliente::exibirMenu(DeliveryApp* app) {

    cout << "\n- Opções do Cliente: -" << endl;
    cout << "1 - Listar Lanchonetes ordenadas pela pontuação" << endl;
    cout << "2 - Listar Lanchonetes de uma categoria ordenada pela pontuação" << endl;
    cout << "3 - Listar Lanchonetes ordenadas pelo preço médio dos produtos" << endl;
    cout << "4 - Listar Lanchonetes ordenadas pelo número de vendas" << endl;
    cout << "5 - Visualizar Lanches de uma Lanchonete" << endl;
    cout << "6 - Buscar Lanches por Nome" << endl;
    cout << "7 - Fazer um Pedido" << endl;
    cout << "8 - Atribuir Nota para uma Lanchonete" << endl;
    cout << "9 - Remover Cadastro" << endl;
    cout << "0 - Sair" << endl;
    cout << "Escolha uma opçao: ";

    int opcao;
    cin >> opcao;

    switch (opcao) {
        case 1:
            app->listarLanchonetesPorPontuacao();
            break;
        case 2:
            app->listarLanchonetesCategoriaPorPontuacao();
            break;
        case 3:
            app->listarLanchonetesPorPrecoMedio();
            break;
        case 4:
            app->listarLanchonetesPorNumeroDeVendas();
            break;
        case 5:
            app->visualizarLanchesDeUmaLanchonete();
            break;
        case 6:
            app->buscarLanchesPorNome();
            break;
        case 7:
            app->fazerPedido(this);
            break;
        case 8:
            app->atribuirNotaLanchonete();
            break;
        case 9:
            app->removerCadastro(this);
            break;
        case 0:
            cout << "\nUsuário Desconectado!" << endl;
            break;
        default:
            cout << "\nOpção Inválida!" << endl;
            break;
    }

    return opcao;
}

bool Cliente::verificarOpcaoValida(int opcao) {
    return opcao != 0 && opcao != 9;
}

string Cliente::type(){
    return "Cliente";
}

ostream &operator<<(ostream &stream, const Cliente &c) {
    stream << "Cliente{" <<
         "Nome=" + c.getNome() <<
         ", CPF='" + c.cpf + '\'' <<
         ", Quantidade de Compras=" << c.quantidadeCompras <<
         ", Quantidade de Gastos=" << c.quantidadeGastos <<
         '}';

    return stream;
}
