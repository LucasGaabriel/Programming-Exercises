#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <boost/algorithm/string.hpp>
#include "DeliveryApp.h"
#include "../Cadastro/Cliente.h"
#include "../Cadastro/Proprietario.h"
#include "../Cadastro/Administrador.h"
#include "../Excecoes/LoginInvalidoException.h"
#include "../Excecoes/CodigoNaoEncontradoException.h"

#define CLIENTE 1
#define PROPRIETARIO 2
#define ADMINISTRADOR 3

#define ARQUIVO_USUARIOS "../Aplicativo/Files/usuarios.csv"
#define ARQUIVO_LANCHONETES "../Aplicativo/Files/lanchonetes.csv"
#define ARQUIVO_PRODUTOS "../Aplicativo/Files/produtos.csv"
#define ARQUIVO_PEDIDOS "../Aplicativo/Files/pedidos.csv"

DeliveryApp::DeliveryApp() {
    clientes = new vector<Cliente *>();
    proprietarios = new vector<Proprietario *>();
    administradores = new vector<Administrador *>();
}

DeliveryApp::~DeliveryApp(){
    for(Cliente* c : *clientes)
        delete c;
    delete clientes;

    for(Proprietario* p : *proprietarios)
        delete p;
    delete proprietarios;

    for(Administrador* a : *administradores)
        delete a;
    delete administradores;
}

void DeliveryApp::executarApp() {
    int opcao;

    do {
        cout << "\n- Aplicativo de Delivery -" << endl;
        cout << "1 - Login" << endl;
        cout << "2 - Cadastro" << endl;
        cout << "0 - Sair" << endl;
        cout << ("Escolha uma opção: ");

        cin >> opcao;

        if (opcao == 1) {
            cout << "Digite seu email: ";
            string email;
            cin >> email;

            cout << "Digite sua senha: ";
            string senha;
            cin >> senha;

            Usuario *usuario = verificarLogin(email, senha);

            if (usuario == nullptr) {
                throw LoginInvalidoException();
            }

            int opcaoMenu;

            do {

                opcaoMenu = usuario->exibirMenu(this);

            } while (usuario->verificarOpcaoValida(opcaoMenu));

        } else if (opcao == 2) {

            int tipoUsuario;

            do {
                cout << "\nComo você deseja se cadastrar?" << endl;
                cout << "1 - Cliente" << endl;
                cout << "2 - Proprietário" << endl;
                cout << "3 - Administrador" << endl;
                cout << "Escolha uma opção: ";

                cin >> tipoUsuario;

                if (tipoUsuario >= 1 && tipoUsuario <= 3)
                    CadastrarUsuario(tipoUsuario);
                else
                    cout << "\nOpção Inválida." << endl;

            } while (tipoUsuario < 1 || tipoUsuario > 3);

        } else if (opcao == 0) {
            cout << "\nPrograma encerrado!" << endl;
        } else {
            cout << "\nOpção inválida!" << endl;
        }

    } while (opcao != 0);
}

int DeliveryApp::buscaIndiceAdministrador(Administrador* adm) const {
    for(int i=0; i<administradores->size(); i++)
        if(administradores->at(i) == adm)
            return i;

    return -1;
}

int DeliveryApp::buscaIndiceProprietario(Proprietario* prop) const {
    for(int i=0; i<proprietarios->size(); i++)
        if(proprietarios->at(i) == prop)
            return i;

    return -1;
}

int DeliveryApp::buscaIndiceCliente(Cliente* cliente) const {
    for(int i=0; i<clientes->size(); i++)
        if(clientes->at(i) == cliente)
            return i;

    return -1;
}


static bool SortByMaisGastos(Cliente *c1, Cliente *c2) {
    if (c1->getQuantidadeGastos() > c2->getQuantidadeGastos())
        return true;
    else
        return false;
}

static bool SortByMaisCompras(Cliente *c1, Cliente *c2) {
    if (c1->getQuantidadeCompras() > c2->getQuantidadeCompras())
        return true;
    else
        return false;
}

static bool SortByMaiorFaturamento(Lanchonete *l1, Lanchonete *l2) {
    if (l1->faturamento() > l2->faturamento())
        return true;
    else
        return false;
}

static bool SortByMaisFaturados(Produto *p1, Produto *p2) {
    if (p1->faturamento() > p2->faturamento())
        return true;
    else
        return false;
}

static bool SortByNome(Produto *p1, Produto *p2) {
    return p1->getNome() < p2->getNome();
}

static bool SortByMaisBaratos(Produto *p1, Produto *p2) {
    return p1->getPreco() < p2->getPreco();
}

static bool SortByMaisVendidos(Produto *p1, Produto *p2) {
    return p1->getQuantidadeVendas() > p2->getQuantidadeVendas();
}

static bool SortByNumeroDeVendas(Lanchonete *l1, Lanchonete *l2) {
    return l1->numeroDeVendas() > l2->numeroDeVendas();
}

static bool SortByPrecoMedio(Lanchonete *l1, Lanchonete *l2) {
    return l1->getPreco_medio() < l2->getPreco_medio();
}

static bool SortByPontuacao(Lanchonete *l1, Lanchonete *l2) {
    return l1->pontuacao() > l2->pontuacao();
}

void DeliveryApp::visualizarRelatorioDeDesempenho() const {

    cout << "\n- Relatório de Desempenho -\n" << endl;

    for (Proprietario *proprietario: *proprietarios) {
        for (Lanchonete *lanchonete: *proprietario->lanchonetes) {
            //Imprime as informações da Lanchonete
            cout << lanchonete << endl;

            //Calculo do número médio de produtos por pedido
            //Valor médio por produto vendido
            //Valor médio dos pedidos.
            int qtdProdutosTotais = 0;
            double valorTotalProdutos = 0;

            for (Pedido *pedido: *lanchonete->pedidos) {

                qtdProdutosTotais += pedido->quantidadeDeProdutos();
                valorTotalProdutos += pedido->valorTotal();

            }

            //Imprime as informações somente se a Lanchonete possuir algum pedido registrado
            if (!lanchonete->pedidos->empty()) {
                cout << "Número médio de Produtos por Pedido: " <<
                     qtdProdutosTotais / lanchonete->pedidos->size() << endl;
                cout << "Valor médio por Produto vendido: R$" <<
                     valorTotalProdutos / qtdProdutosTotais << endl;
                cout << "Valor médio dos Pedidos: R$" <<
                     valorTotalProdutos / (double)lanchonete->pedidos->size() << endl << endl;
            } else {
                cout << "Lanchonete não possui pedidos registrados!\n" << endl;
            }
        }
    }
}

void DeliveryApp::visualizarRelatorioDeVendas() const {

    cout << "\n- Relatório de Vendas -\n" << endl;

    vector<Produto *> *produtos;
    produtos = new vector<Produto *>();
    vector<Lanchonete *> *lanchonetes;
    lanchonetes = new vector<Lanchonete *>();

    //Adiciona todas as Lanchonetes e Produtos em um Vector específico para ordenar
    for (Proprietario *proprietario: *proprietarios) {
        for (Lanchonete *lanchonete: *proprietario->lanchonetes) {
            lanchonetes->push_back(lanchonete);

            for (Produto *produto: *lanchonete->produtos)
                produtos->push_back(produto);
        }
    }

    //Ordena os produtos pelo mais vendido
    sort(produtos->begin(), produtos->end(), SortByMaisVendidos);

    int cont = 5; //Quantidade maxima de produtos exibidos nos grupos

    cout << "Lanches mais vendidos:" << endl;
    int i = 0;
    for (Produto *p: *produtos) {
        cout << *p << endl;

        if (++i == cont) //Sempre exibe uma quantidade maxima de elementos definida na variável 'cont'
            break;
    }

    //Ordena os produtos que tiveram maior faturamento
    sort(produtos->begin(), produtos->end(), SortByMaisFaturados);

    cout << "\nLanches que mais faturaram:" << endl;
    i = 0;
    for (Produto *p: *produtos) {
        cout << *p << endl;

        if (++i == cont) //Sempre exibe uma quantidade maxima de elementos definida na variável 'cont'
            break;
    }

    //Ordena as lanchonetes que mais venderam
    sort(lanchonetes->begin(), lanchonetes->end(), SortByNumeroDeVendas);

    cout << "\nLanchonetes que mais venderam:" << endl;
    i = 0;
    for (Lanchonete *l: *lanchonetes) {
        cout << *l << endl;

        if (++i == cont) //Sempre exibe uma quantidade maxima de elementos definida na variável 'cont'
            break;
    }

    //Ordena as lanchonetes que mais faturaram
    sort(lanchonetes->begin(), lanchonetes->end(), SortByMaiorFaturamento);

    cout << "\nLanchonetes que mais faturaram:" << endl;
    i = 0;
    for (Lanchonete *l: *lanchonetes) {
        cout << *l << endl;

        if (++i == cont) //Sempre exibe uma quantidade maxima de elementos definida na variável 'cont'
            break;
    }

    //Ordena os clientes que fizeram mais compras
    sort(clientes->begin(), clientes->end(), SortByMaisCompras);

    cout << "\nClientes que mais compraram:" << endl;
    i = 0;
    for (Cliente *c: *clientes) {
        cout << *c << endl;

        if (++i == cont) //Sempre exibe uma quantidade maxima de elementos definida na variável 'cont'
            break;
    }

    //Ordena os clientes que mais gastaram em compras
    sort(clientes->begin(), clientes->end(), SortByMaisGastos);

    cout << "\nClientes que mais gastaram em compras:" << endl;
    i = 0;
    for (Cliente *c: *clientes) {
        cout << *c << endl;

        if (++i == cont) //Sempre exibe uma quantidade maxima de elementos definida na variável 'cont'
            break;
    }

    delete produtos;
    delete lanchonetes;
}

void DeliveryApp::visualizarRelatorioQuantitativo() const {

    cout << "\n- Relatório Quantitativo -\n" << endl;

    int qtdLanchonetes = 0;
    int qtdLanches = 0;
    int qtdPedidos = 0;
    double valorTotalVendas = 0;

    //Calculo das informações necessárias
    for (Proprietario *p: *proprietarios) {
        qtdLanchonetes += (int) p->lanchonetes->size();

        for (Lanchonete *l: *p->lanchonetes) {
            qtdLanches += (int) l->produtos->size();
            qtdPedidos += (int) l->pedidos->size();

            for (Pedido *pedido: *l->pedidos) {
                valorTotalVendas += pedido->valorTotal();
            }
        }
    }

    cout << "Clientes Cadastrados: " << clientes->size() << endl;
    cout << "Lanchonetes Cadastradas: " << qtdLanchonetes << endl;
    cout << "Lanches Cadastrados: " << qtdLanches << endl;
    cout << "Pedidos Cadastrados: " << qtdPedidos << endl;
    cout << "Valor total de vendas: " << valorTotalVendas << endl;
}

void DeliveryApp::removerPedidoDeUmaLanchonete(Proprietario *proprietario) {

    //Mostra as lanchonetes do Proprietario
    proprietario->listarLanchonetes();

    cout << "Digite o código da Lanchonete: ";
    int codigo;
    cin >> codigo;

    //Busca a Lanchonete desejada
    Lanchonete *l = buscarLanchonetePorIdentificador(codigo);

    if (l == nullptr) {
        cout << "Lanchonete não encontrada." << endl;
        return;
    }

    //Mostra os pedidos da lanchonete
    l->listarPedidos();

    cout << "Digite o código do Pedido a ser removido: ";
    cin >> codigo;

    //Busca o pedido a ser removido
    Pedido *p = buscarPedidoPorCodigo(codigo);

    for(int i=0; i<l->pedidos->size(); i++){
        if(l->pedidos->at(i) == p){
            delete l->pedidos->at(i);
            l->pedidos->erase(l->pedidos->begin() + i - 1);
        }
    }

    //Atualiza os Pedidos no Arquivo
    escreverPedidosNoArquivo();
}

void DeliveryApp::visualizarDetalhesDeUmPedidoLanchonete(Proprietario *proprietario) {

    //Mostra as Lanchonetes do Proprietario
    proprietario->listarLanchonetes();

    cout << "Digite o Identificador da Lanchonete desejada: ";
    int id;
    cin >> id;

    //Busca a lanchonete desejada
    Lanchonete *lanchonete = buscarLanchonetePorIdentificador(id);

    if (lanchonete == nullptr) {
        cout << "Lanchonete não encontrada!" << endl;
        return;
    }

    //Mostra os pedidos da lanchonete
    lanchonete->listarPedidos();

    cout << "Digite o código do Pedido desejado: ";
    cin >> id;

    //Busca o pedido desejado
    Pedido *p = buscarPedidoPorCodigo(id);

    if (p == nullptr) {
        cout << "Pedido não encontrado!" << endl;
        return;
    }

    //Imprime o pedido de forma detalhada
    p->imprimirDetalhesPedido();
}

void DeliveryApp::visualizarListaDePedidosLanchonete(Proprietario *proprietario) {

    //Mostra as Lanchonetes do Proprietário
    proprietario->listarLanchonetes();

    cout << "Digite o Identificador da Lanchonete desejada: ";
    int id;
    cin >> id;

    //Busca a lanchonete desejada
    Lanchonete *lanchonete = buscarLanchonetePorIdentificador(id);

    if (lanchonete == nullptr) {
        cout << "Lanchonete não encontrada!" << endl;
        return;
    }

    //Lista todos os Pedidos da Lanchonete
    lanchonete->listarPedidos();

    //Mostra a quantidade de pedidos da Lanchonete
    cout << "Quantidade de Pedidos: " << lanchonete->pedidos->size() << endl;
}

void DeliveryApp::cadastrarLanche(Proprietario *proprietario) {

    proprietario->listarLanchonetes();

    cout << "Digite o Identificador da Lanchonete desejada: ";
    int id;
    cin >> id;

    Lanchonete *lanchonete = buscarLanchonetePorIdentificador(id);

    if (lanchonete != nullptr) {
        //Cadastra um produto novo na Lanchonete
        lanchonete->cadastrarProduto();

        //Atualiza o preco medio dos Produtos
        lanchonete->atualizarPrecoMedio();
    }

    //Atualiza os produtos no arquivo
    escreverProdutosNoArquivo();
}

void DeliveryApp::removerLanchonete(Proprietario *proprietario) const {

    cout << "\n- Remoção de Lanchonete -" << endl;

    proprietario->listarLanchonetes();

    cout << "Digite o Identificador da Lanchonete a ser removida: ";
    int id;
    cin >> id;

    for(int i=0; i<proprietario->lanchonetes->size(); i++){
        if(proprietario->lanchonetes->at(i)->getIdentificador() == id){
            delete proprietario->lanchonetes->at(i);
            proprietario->lanchonetes->erase(proprietario->lanchonetes->begin() + i - 1);
        }
    }

    //Atualiza os Arquivos
    escreverLanchonetesNoArquivo();
    escreverProdutosNoArquivo();
    escreverPedidosNoArquivo();
}

void DeliveryApp::cadastrarLanchonete(Proprietario *proprietario) {

    cout << "\n- Cadastro Lanchonete -" << endl;
    cout << "A nova lanchonete possui Loja física?" << endl;
    cout << "1 - Sim" << endl;
    cout << "0 - Não" << endl;
    cout << "Escolha uma opção: ";
    int lojaFisica;
    cin >> lojaFisica;

    if (lojaFisica != 0 && lojaFisica != 1) {
        cout << "\nOpção inválida." << endl;
        return;
    }

    int identificador;
    Lanchonete *l;

    do {
        cout << "Código identificador: ";
        cin >> identificador;

        l = buscarLanchonetePorIdentificador(identificador);

        if (l != nullptr) {
            cout << "Identificador já usado. Escolha outro!" << endl;
        }

    } while (l != nullptr);

    cout << "Nome da Lanchonete: ";
    string nome;
    cin >> nome;

    cout << "Categoria de produtos da Lanchonete: ";
    string categoria;
    cin >> categoria;

    //Se a loja possuir endereço fisico, busca mais detalhes. Se nao, adiciona a nova Lanchonete ao proprietario
    if (lojaFisica == 0) {
        proprietario->lanchonetes->push_back(new Lanchonete(identificador, nome, categoria));
    } else {
        cout << "Endereço da Lanchonete: ";
        string endereco;
        cin >> endereco;

        cout << "Desconto de Retirada do Produto na Loja: ";
        double desconto_retirada;
        cin >> desconto_retirada;

        cout << "Desconto de Consumo do Produto na Loja: ";
        double desconto_consumo;
        cin >> desconto_consumo;

        proprietario->lanchonetes->push_back(new Lanchonete(identificador, nome, categoria, endereco,
                                                            desconto_retirada, desconto_consumo));
    }

    //Atualiza as Lanchonetes no arquivo
    escreverLanchonetesNoArquivo();
}

void DeliveryApp::removerCadastro(Usuario *usuario) {

    int opcao;

    do {
        cout << "\nTem certeza que deseja remover seu cadastro?" << endl;
        cout << "1 - Sim" << endl;
        cout << "0 - Nao" << endl;
        cout << "Selecione uma opção: ";
        cin >> opcao;

    } while (opcao != 0 && opcao != 1);

    if (opcao == 0) {
        cout << "Cadastro NÃO foi removido!" << endl;
        return;
    }

    //Remove de formas diferentes dependendo do tipo de Usuario
    //Alguns usuários possuem informações adicionais em diferentes lugares e arquivos
    if(usuario->type() == "Cliente") {

        //Remove todos os pedidos feitos pelo Cliente
        for (Proprietario* proprietario: *proprietarios) {
            for (Lanchonete* lanchonete: *proprietario->lanchonetes) {
                for(int i = 0; i < lanchonete->pedidos->size(); i++) {
                    if (lanchonete->pedidos->at(i)->getCliente() == usuario) {
                        lanchonete->pedidos->erase(lanchonete->pedidos->begin() + i - 1);
                    }
                }
            }
        }

        //Remove o cliente da lista de clientes
        int idx = buscaIndiceCliente((Cliente*) usuario);
        clientes->erase(clientes->begin() + idx - 1);

        //Atualiza os arquivos
        escreverPedidosNoArquivo();
        escreverUsuariosNoArquivo();
    }
    else if(usuario->type() == "Proprietario") {

        //Remove o proprietario
        int idx = buscaIndiceProprietario((Proprietario*) usuario);
        proprietarios->erase(proprietarios->begin() + idx - 1);

        //Atualiza todos os arquivos (Informacoes do Proprietario estão em todos os arquivos)
        atualizarTodosOsArquivos();

    }
    else if(usuario->type() == "Administrador") {

        //Remove o administrador
        int idx = buscaIndiceAdministrador((Administrador*) usuario);
        administradores->erase(administradores->begin() + idx - 1);

        //Atualiza os usuarios no arquivo
        escreverUsuariosNoArquivo();

    }

    cout << "Cadastro removido com Sucesso!" << endl;
}

void DeliveryApp::atribuirNotaLanchonete() {

    cout << "Digite o código da Lanchonete para atribuir uma Nota: ";
    int codigo;
    cin >> codigo;

    //Busca a Lanchonete desejada
    Lanchonete *l = buscarLanchonetePorIdentificador(codigo);

    if (l == nullptr) {
        throw CodigoNaoEncontradoException();
    }

    cout << "Digite uma nota de 0 a 5: ";
    double nota;
    cin >> nota;

    //Atribui a pontuaçao a Lanchonete desejada
    l->atribuirPontuacao(nota);

    //Atualiza a Pontuaçao da Lanchonete no arquivo
    escreverLanchonetesNoArquivo();
}

void DeliveryApp::fazerPedido(Cliente *cliente) {

    cout << "Digite o código da Lanchonete para fazer um pedido: ";
    int codigoLanchonete;
    cin >> codigoLanchonete;

    //Busca a Lanchonete Desejada
    Lanchonete *lanchonete = buscarLanchonetePorIdentificador(codigoLanchonete);

    if (lanchonete == nullptr) {
        cout << "Lanchonete não encontrada!\n" << endl;
        return;
    }

    int i = 0;
    int codigo = i;

    //Atribui um código ao Pedido
    //O código é o menor possível iniciando de 0, não possuindo nenhum outro pedido com o mesmo código
    while (buscarPedidoPorCodigo(codigo) != nullptr) {
        i++;
        codigo = i;
    }

    Pedido *novoPedido;
    novoPedido = new Pedido(codigo, cliente);

    int opcao;

    do {
        cout << "\n- Novo Pedido -" << endl;
        cout << "1 - Adicionar Produto" << endl;
        cout << "2 - Visualizar Produtos" << endl;
        cout << "0 - Confirmar Pedido" << endl;
        cout << "Valor total: R$" << novoPedido->valorTotal() << endl;
        cout << "Escolha uma opção: ";
        cin >> opcao;

        if (opcao == 1) {

            Produto *p;

            do {
                cout << "Digite o código do Produto: ";
                int codigoProduto;
                cin >> codigoProduto;

                p = lanchonete->buscaProdutoPorCodigo(codigoProduto);

                if (p == nullptr)
                    cout << "Produto não encontrado!" << endl;

            } while (p == nullptr);

            cout << "Digite a quantidade desejada do Produto: ";
            int qtd;
            cin >> qtd;

            //Adiciona as compras e gastos ao Cliente
            cliente->addQuantidadeCompras(qtd);
            cliente->addQuantidadeGastos(p->getPreco() * qtd);

            //Adiciona as vendas ao produto
            p->addQuantidadeVendas(qtd);

            //Adiciona o produto e a quantidade no Novo Pedido
            novoPedido->addProduto(p, qtd);
        } else if (opcao == 2) {
            cout << "\nProdutos do pedido atual:" << endl;
            for (i = 0; i < novoPedido->produtos->size(); i++) {
                cout << *novoPedido->produtos->at(i) << " | Quantidade: " <<
                     novoPedido->quantidadeProdutos->at(i) << endl;
            }
        } else if (opcao == 0) {
            cout << "Pedido realizado!" << endl;
        } else {
            cout << "Opçao invalida!" << endl;
        }

    } while (opcao != 0);

    //Adiciona o pedido a Lanchonete
    lanchonete->addPedido(novoPedido);

    //Atualiza os arquivos
    escreverUsuariosNoArquivo();
    escreverProdutosNoArquivo();
    escreverPedidosNoArquivo();
}

void DeliveryApp::buscarLanchesPorNome() const {

    cout << "\nEscreva o lanche ou termo a ser buscado: " << endl;
    string nome;
    cin >> nome;

    //Busca os Lanches que possuem o Termo digitado no nome
    cout << "\nLanches encontrados:" << endl;
    for (Proprietario *proprietario: *proprietarios) {
        for (Lanchonete *lanchonete: *proprietario->lanchonetes) {
            for (Produto *produto: *lanchonete->produtos) {
                if (produto->getNome().find(nome) != string::npos) {
                    cout << "Lanche: " << produto->getNome() <<
                            " [Código: " << produto->getCodigo() << "] - Loja: " <<
                            lanchonete->getNome() << " [Código: " <<
                            lanchonete->getIdentificador() << "]" << endl;
                }
            }
        }
    }
}

void DeliveryApp::visualizarLanchesDeUmaLanchonete() const {

    cout << "\nDigite o identificador da Lanchonete desejada: ";
    int id;
    cin >> id;

    //Busca a lanchonete desejada
    Lanchonete* l = buscarLanchonetePorIdentificador(id);

    if (l == nullptr) {
        throw CodigoNaoEncontradoException();
    }

    cout << "\nDados da Lanchonete:" << endl;
    cout << *l << endl;

    int cont = 3; //Quantidade maxima de produtos exibidos nos grupos

    //Ordena os produtos pelos mais Vendidos
    sort(l->produtos->begin(), l->produtos->end(), SortByMaisVendidos);

    cout << "\nProdutos mais vendidos:" << endl;
    int i = 0;
    for (Produto* p : *l->produtos) {
        cout << *p << endl;

        if (++i == cont) //Sempre exibe uma quantidade maxima de elementos definida na variável 'cont'
            break;
    }

    //Ordena os produtos pelos mais baratos
    sort(l->produtos->begin(), l->produtos->end(), SortByMaisBaratos);

    cout << "\nProdutos mais baratos:" << endl;
    i = 0;
    for (Produto* p: *l->produtos) {
        cout << *p << endl;

        if (++i == cont) //Sempre exibe uma quantidade maxima de elementos definida na variável 'cont'
            break;
    }

    //Ordena os produtos pelo nome, para exibir todos ordenadamente
    sort(l->produtos->begin(), l->produtos->end(), SortByNome);

    cout << "\nLista de todos os Produtos:" << endl;
    for (Produto* p: *l->produtos) {
        cout << *p << endl;
    }
}

void DeliveryApp::listarLanchonetesPorNumeroDeVendas() const {
    vector<Lanchonete *> *lanchonetes;
    lanchonetes = new vector<Lanchonete *>();

    for (Proprietario* p: *proprietarios) {
        //Adiciona todas as lanchonetes de todos os proprietários no ArrayList
        for(Lanchonete* l : *p->lanchonetes)
            lanchonetes->push_back(l);
    }

    //Ordena pelo numero de vendas
    sort(lanchonetes->begin(), lanchonetes->end(), SortByNumeroDeVendas);

    cout << "\nLanchonetes Ordenadas pelo Número de Vendas dos Produtos:" << endl;
    for (Lanchonete* l: *lanchonetes) {
        cout << *l << endl;
    }

    delete lanchonetes;
}

void DeliveryApp::listarLanchonetesPorPrecoMedio() const {
    vector<Lanchonete*>* lanchonetes;
    lanchonetes = new vector<Lanchonete*>();

    for (Proprietario* p: *proprietarios) {
        //Adiciona todas as lanchonetes de todos os proprietários no ArrayList
        for(Lanchonete* l : *p->lanchonetes)
            lanchonetes->push_back(l);
    }

    //Ordena as lanchonetes pelo preco medio
    sort(lanchonetes->begin(), lanchonetes->end(), SortByPrecoMedio);

    cout << "\nLanchonetes Ordenadas pelo Preço Médio dos Produtos:" << endl;
    for (Lanchonete* l: *lanchonetes) {
        cout << *l << endl;
    }

    delete lanchonetes;
}

void DeliveryApp::listarLanchonetesCategoriaPorPontuacao() const {

    cout << "\nDigite a Categoria de Lanchonetes desejadas: ";
    string categoria;
    cin >> categoria;

    //ArrayList para adicionar as Lanchonetes específicas da categoria
    vector<Lanchonete*>* lanchonetes;
    lanchonetes = new vector<Lanchonete*>();

    //Adiciona as Lanchonetes da categoria especifica no ArrayList
    for (Proprietario* p: *proprietarios) {
        for (Lanchonete* l: *p->lanchonetes) {
            if (l->getCategoria() == categoria)
                lanchonetes->push_back(l);
        }
    }

    //Ordena as lanchonetes pela Pontuação
    sort(lanchonetes->begin(), lanchonetes->end(), SortByPontuacao);

    cout << "\nLanchonetes Ordenadas pela Pontuação da Categoria: '" + categoria + "'" << endl;
    for (Lanchonete* l: *lanchonetes) {
        cout << *l << endl;
    }

    delete lanchonetes;
}

void DeliveryApp::listarLanchonetesPorPontuacao() const {
    vector<Lanchonete*>* lanchonetes;
    lanchonetes = new vector<Lanchonete*>();

    for (Proprietario* p: *proprietarios) {
        //Adiciona todas as lanchonetes de todos os proprietários no ArrayList
        for(Lanchonete* l : *p->lanchonetes)
            lanchonetes->push_back(l);
    }

    //Ordena as lanchonetes pela pontuação
    sort(lanchonetes->begin(), lanchonetes->end(), SortByPontuacao);

    cout << "\nLanchonetes Ordenadas pela Pontuação:" << endl;
    for (Lanchonete* l: *lanchonetes) {
        cout << *l << endl;
    }

    delete lanchonetes;
}

Proprietario* DeliveryApp::buscaProprietarioPorNome(const string& nome) const {
    for (Proprietario* p: *proprietarios) {
        if (p->getNome() == nome)
            return p;
    }

    return nullptr;
}

void DeliveryApp::LeituraArquivos() {
    //Criar os arquivos que nao existirem
    ofstream createFile;

    //LEITURA DOS USUÁRIOS
    ifstream file;
    file.open(ARQUIVO_USUARIOS);

    //Se o arquivo ainda não existe, cria um vazio
    if (!file.is_open()) {
        createFile.open(ARQUIVO_USUARIOS);
        createFile.close();
    }

    while (!file.eof()) {
        string line;
        vector<string> words;
        getline(file, line);
        boost::split(words, line, boost::is_any_of(";"));

        string tipoUsuario = words[0];

        //Adiciona os Usuarios presentes nos arquivos
        if(tipoUsuario == "Cliente") {

            int qtdCompras = stoi(words[5]);
            double qtdGastos = stod(words[6]);

            clientes->push_back(new Cliente(words[1], words[2], words[3], words[4],
                                            qtdCompras, qtdGastos));
        }
        else if(tipoUsuario == "Proprietario") {

            proprietarios->push_back(new Proprietario(words[1], words[2], words[3]));

        }
        else if(tipoUsuario == "Administrador") {

            administradores->push_back(new Administrador(words[1], words[2], words[3]));

        }

    }

    file.close();

    //LEITURA DAS LANCHONETES
    file.open(ARQUIVO_LANCHONETES);

    //Se o arquivo ainda não existe, cria um vazio
    if (!file.is_open()) {
        createFile.open(ARQUIVO_LANCHONETES);
        createFile.close();
    }

    while (!file.eof()) {
        string line;
        vector<string> words;
        getline(file, line);
        boost::split(words, line, boost::is_any_of(";"));

        //Busca o proprietário da Lanchonete
        Proprietario* proprietario = buscaProprietarioPorNome(words[0]);

        //Adiciona a lanchonete ao Proprietario dependendo do tipo de estabelecimento (Delivery ou hibrido)
        if (proprietario != nullptr) {
            if (stoi(words[1]) == 0) {

                int identificador = stoi(words[2]);
                double precoMedio = stod(words[5]);
                double somaPontuacao = stod(words[6]);
                int qtdPontuacao = stoi(words[7]);

                double desconto = -1;
                string vazia;

                proprietario->lanchonetes->push_back(new Lanchonete(identificador, words[3], words[4],
                                                                    vazia, desconto, desconto, precoMedio,
                                                                    somaPontuacao, qtdPontuacao));
            } else {

                int identificador = stoi(words[2]);
                double retirada = stod(words[6]);
                double consumoLocal = stod(words[7]);
                double precoMedio = stod(words[8]);
                double somaPontuacao = stod(words[9]);
                int qtdPontuacao = stoi(words[10]);

                proprietario->lanchonetes->push_back(new Lanchonete(identificador, words[3], words[4],
                                                                    words[5], retirada, consumoLocal,
                                                                    precoMedio, somaPontuacao,
                                                                    qtdPontuacao));
            }
        }
    }

    file.close();

    //LEITURA DOS PRODUTOS
    file.open(ARQUIVO_PRODUTOS);

    //Se o arquivo ainda não existe, cria um vazio
    if (!file.is_open()) {
        createFile.open(ARQUIVO_PRODUTOS);
        createFile.close();
    }

    while (!file.eof()) {
        string line;
        vector<string> words;
        getline(file, line);
        boost::split(words, line, boost::is_any_of(";"));

        //Busca o proprietário da Lanchonete que possui o produto
        Proprietario* proprietario = buscaProprietarioPorNome(words[0]);

        if (proprietario == nullptr) {
            continue;
        }

        //Busca a lanchonete que possui o produto
        Lanchonete* lanchonete = proprietario->buscaLanchonetePorNome(words[1]);

        int codigo = stoi(words[2]);
        double preco = stod(words[4]);
        int quantidadeVendas = stoi(words[5]);

        //Adiciona o produto na lanchonete
        lanchonete->produtos->push_back(new Produto(codigo, words[3], preco, quantidadeVendas));
    }

    file.close();

    //LEITURA DOS PEDIDOS
    file.open(ARQUIVO_PEDIDOS);

    //Se o arquivo ainda não existe, cria um vazio
    if (!file.is_open()) {
        createFile.open(ARQUIVO_PEDIDOS);
        createFile.close();
    }

    while (!file.eof()) {
        string line;
        vector<string> words;
        getline(file, line);
        boost::split(words, line, boost::is_any_of(";"));

        //Busca o proprietário da Lanchonete que possui o pedido
        Proprietario* proprietario = buscaProprietarioPorNome(words[0]);

        if (proprietario == nullptr) {
            continue;
        }

        //Busca a lanchonete que possui o pedido
        Lanchonete* lanchonete = proprietario->buscaLanchonetePorNome(words[1]);

        int identificador = stoi(words[2]);

        //Busca o cliente que fez o pedido
        Cliente* cliente = buscaClientePorCPF(words[3]);

        //Adiciona o pedido na lanchonete
        Pedido *pedido;
        pedido = new Pedido(identificador, cliente, words[4]);
        lanchonete->pedidos->push_back(pedido);

        int qtdProdutos = stoi(words[5]);

        //Adiciona os Produtos nos Pedidos
        for (int i = 0, x = 6; i < qtdProdutos; i++, x++) {
            int codigoProduto = stoi(words[x]);
            x++;
            int qtdProduto = stoi(words[x]);
            Produto* produto = lanchonete->buscaProdutoPorCodigo(codigoProduto);
            pedido->addProduto(produto, qtdProduto);
        }

    }

    file.close();
}

Pedido *DeliveryApp::buscarPedidoPorCodigo(int codigo) const {
    for (Proprietario* proprietario: *proprietarios) {
        for (Lanchonete* lanchonete: *proprietario->lanchonetes) {
            for (Pedido* pedido: *lanchonete->pedidos) {
                if (pedido->getCodigo() == codigo)
                    return pedido;
            }
        }
    }

    return nullptr;
}

Lanchonete *DeliveryApp::buscarLanchonetePorIdentificador(int id) const {
    for (Proprietario* p: *proprietarios) {
        for (Lanchonete* l: *p->lanchonetes) {
            if (l->getIdentificador() == id)
                return l;
        }
    }

    return nullptr;
}

Cliente *DeliveryApp::buscaClientePorCPF(const string& cpf) const {
    for (Cliente* c: *clientes) {
        if (c->getCPF() == cpf)
            return c;
    }

    return nullptr;
}

Usuario *DeliveryApp::verificarLogin(string email, string senha) const {
    for (Cliente* c: *clientes) {
        if (c->verificarUsuario(email, senha))
            return c;
    }

    for (Proprietario* p: *proprietarios) {
        if (p->verificarUsuario(email, senha))
            return p;
    }

    for (Administrador* a: *administradores) {
        if (a->verificarUsuario(email, senha))
            return a;
    }

    return nullptr;
}

void DeliveryApp::atualizarTodosOsArquivos() const {
    escreverLanchonetesNoArquivo();
    escreverPedidosNoArquivo();
    escreverProdutosNoArquivo();
    escreverUsuariosNoArquivo();
}

void DeliveryApp::escreverLanchonetesNoArquivo() const {
    ofstream file;
    file.open(ARQUIVO_LANCHONETES);

    for (Proprietario* proprietario: *proprietarios) {
        for (Lanchonete* lanchonete: *proprietario->lanchonetes) {
            file << proprietario->getNome() << ";";

            if (lanchonete->getDesconto_retirada() == -1) {
                file << "0;" << lanchonete->getIdentificador() << ";" << lanchonete->getNome() << ";" <<
                         lanchonete->getCategoria() << ";" << lanchonete->getPreco_medio() << ";" <<
                         lanchonete->getSomaPontuacao() << ";" << lanchonete->getQuantidadePontuacao() << "\n";
            } else {
                file << "1;" << lanchonete->getIdentificador() << ";" << lanchonete->getNome() << ";" <<
                         lanchonete->getCategoria() << ";" << lanchonete->getEndereco() << ";" <<
                         lanchonete->getDesconto_retirada() << ";" <<
                         lanchonete->getDesconto_consumoLocal() << ";" <<
                         lanchonete->getPreco_medio() << ";" << lanchonete->getSomaPontuacao() << ";" <<
                         lanchonete->getQuantidadePontuacao() << "\n";
            }
        }
    }

    file.close();
}

void DeliveryApp::escreverPedidosNoArquivo() const {
    ofstream file;
    file.open(ARQUIVO_PEDIDOS);

    for (Proprietario* proprietario: *proprietarios) {
        for (Lanchonete* lanchonete: *proprietario->lanchonetes) {
            for (Pedido* pedido: *lanchonete->pedidos) {
                file << proprietario->getNome() << ";" << lanchonete->getNome() << ";" <<
                         pedido->getCodigo() << ";" << pedido->getCliente()->getCPF() << ";" <<
                         pedido->getData() << ";" << pedido->produtos->size();

                for (int i = 0; i < pedido->produtos->size(); i++) {
                    file << ";" << pedido->produtos->at(i)->getCodigo() << ";" <<
                             pedido->quantidadeProdutos->at(i);
                }

                file << "\n";
            }
        }
    }

    file.close();
}

void DeliveryApp::escreverProdutosNoArquivo() const {
    ofstream file;
    file.open(ARQUIVO_PRODUTOS);

    for (Proprietario* proprietario: *proprietarios) {
        for (Lanchonete* lanchonete: *proprietario->lanchonetes) {
            for (Produto* produto: *lanchonete->produtos) {
                file << proprietario->getNome() << ";" << lanchonete->getNome() << ";" <<
                         produto->getCodigo() << ";" << produto->getNome() << ";" << produto->getPreco() << ";" <<
                         produto->getQuantidadeVendas() << "\n";
            }
        }
    }

    file.close();
}

void DeliveryApp::escreverUsuariosNoArquivo() const {
    ofstream file;
    file.open(ARQUIVO_USUARIOS);

    for (Administrador* a: *administradores) {
        file << "Administrador" << ";" << a->getNome() << ";" << a->getEmail() << ";" << a->getSenha() << "\n";
    }

    for (Cliente* c: *clientes) {
        file << "Cliente" << ";" << c->getNome() << ";" << c->getEmail() << ";" << c->getSenha() << ";" <<
                 c->getCPF() << ";" << c->getQuantidadeCompras() << ";" << c->getQuantidadeGastos() << "\n";
    }

    for (Proprietario* p: *proprietarios) {
        file << "Proprietario" << ";" << p->getNome() << ";" << p->getEmail() << ";" << p->getSenha() << "\n";
    }

    file.close();
}

bool DeliveryApp::EmailJaUtilizado(const string& email) const {
    for (Proprietario* p: *proprietarios) {
        if (p->getEmail() == email)
            return true;
    }

    for (Cliente* c: *clientes) {
        if (c->getEmail() == email)
            return true;
    }

    for (Administrador* a: *administradores) {
        if (a->getEmail() == email)
            return true;
    }

    return false;
}

void DeliveryApp::CadastrarUsuario(int tipoUsuario) {

    cout << "\n- Cadastro Novo Usuario -" << endl;

    cout << "Nome: ";
    string nome;
    cin >> nome;

    cout << "Email: ";
    string email;
    cin >> email;

    //Verifica se o email já está em uso
    if (EmailJaUtilizado(email)) {
        cout << "\nEmail já utilizado!" << endl;
        return;
    }

    cout << "Senha: ";
    string senha;
    cin >> senha;

    if (tipoUsuario == CLIENTE) {

        cout << "CPF: ";
        string cpf;
        cin >> cpf;

        clientes->push_back(new Cliente(nome, email, senha, cpf));

    } else if (tipoUsuario == PROPRIETARIO) {

        proprietarios->push_back(new Proprietario(nome, email, senha));

    } else if (tipoUsuario == ADMINISTRADOR) {

        administradores->push_back(new Administrador(nome, email, senha));

    }

    //Atualiza os usuários no arquivo
    escreverUsuariosNoArquivo();

    cout << "Usuario Cadastrado com Sucesso!" << endl;
}
