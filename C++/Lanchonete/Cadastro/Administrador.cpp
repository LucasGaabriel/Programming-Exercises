#include <iostream>
#include "Administrador.h"

using namespace std;

Administrador::Administrador(string &nome, string &email, string &senha) : Usuario(nome, email, senha) {}

Administrador::~Administrador() = default;

int Administrador::exibirMenu(DeliveryApp* app) {

    cout << "\n- Opções do Administrador: -" << endl;
    cout << "1 - Visualizar Relatório Quantitativo" << endl;
    cout << "2 - Visualizar Relatório de Vendas" << endl;
    cout << "3 - Visualizar Relatório de Desempenho" << endl;
    cout << "4 - Remover Cadastro" << endl;
    cout << "0 - Sair" << endl;
    cout << "Escolha uma opçao: ";

    int opcao;
    cin >> opcao;

    switch (opcao) {
        case 1:
            app->visualizarRelatorioQuantitativo();
            break;
        case 2:
            app->visualizarRelatorioDeVendas();
            break;
        case 3:
            app->visualizarRelatorioDeDesempenho();
            break;
        case 4:
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

bool Administrador::verificarOpcaoValida(int opcao) {
    return opcao != 0 && opcao != 4;
}

string Administrador::type(){
    return "Administrador";
}
