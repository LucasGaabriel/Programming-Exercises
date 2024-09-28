#include <iostream>
#include <vector>
#include "Proprietario.h"

using namespace std;

Proprietario::Proprietario(string &nome, string &email, string &senha) : Usuario(nome, email, senha) {
    this->lanchonetes = new vector<Lanchonete *>();
}

Proprietario::~Proprietario(){
    for(Lanchonete* l : *lanchonetes)
        delete l;
    delete lanchonetes;
}

Lanchonete *Proprietario::buscaLanchonetePorNome(string &nome) const {
    for (Lanchonete *l: *lanchonetes) {
        if (l->getNome() == nome)
            return l;
    }

    return nullptr;
}

void Proprietario::listarLanchonetes() const {
    cout << "\nLista de Lanchonetes" << endl;
    for (Lanchonete *l: *lanchonetes) {
        cout << *l << endl;
    }
}

int Proprietario::exibirMenu(DeliveryApp* app) {

    cout << "\n- Opções do Proprietário: -" << endl;
    cout << "1 - Cadastrar Lanchonete" << endl;
    cout << "2 - Remover Lanchonete" << endl;
    cout << "3 - Cadastrar Lanche em uma Lanchonete" << endl;
    cout << "4 - Visualizar Lista de Pedidos de uma Lanchonete" << endl;
    cout << "5 - Visualizar detalhes de um Pedido de uma Lanchonete" << endl;
    cout << "6 - Remover Pedido de uma Lanchonete" << endl;
    cout << "7 - Remover Cadastro" << endl;
    cout << "0 - Sair" << endl;
    cout << "Escolha uma opçao: ";

    int opcao;
    cin >> opcao;

    switch (opcao) {
        case 1:
            app->cadastrarLanchonete(this);
            break;
        case 2:
            app->removerLanchonete(this);
            break;
        case 3:
            app->cadastrarLanche(this);
            break;
        case 4:
            app->visualizarListaDePedidosLanchonete(this);
            break;
        case 5:
            app->visualizarDetalhesDeUmPedidoLanchonete(this);
            break;
        case 6:
            app->removerPedidoDeUmaLanchonete(this);
            break;
        case 7:
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

bool Proprietario::verificarOpcaoValida(int opcao) {
    return opcao != 0 && opcao != 7;
}

string Proprietario::type(){
    return "Proprietario";
}