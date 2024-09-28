#ifndef _DELIVERYAPP_H_
#define _DELIVERYAPP_H_

#include <vector>
#include <string>

class Cliente;
class Proprietario;
class Administrador;
class Usuario;
class Pedido;
class Produto;
class Lanchonete;

class DeliveryApp {

private:
    Proprietario *buscaProprietarioPorNome(const std::string& nome) const;

    Pedido *buscarPedidoPorCodigo(int codigo) const;

    Lanchonete *buscarLanchonetePorIdentificador(int id) const;

    Cliente *buscaClientePorCPF(const std::string& cpf) const;

    Usuario *verificarLogin(std::string email, std::string senha) const;

    bool EmailJaUtilizado(const std::string& email) const;

    void CadastrarUsuario(int tipoUsuario);

    int buscaIndiceAdministrador(Administrador* adm) const;

    int buscaIndiceProprietario(Proprietario* prop) const;

    int buscaIndiceCliente(Cliente* cliente) const;

public:
    std::vector<Cliente *> *clientes;
    std::vector<Proprietario *> *proprietarios;
    std::vector<Administrador *> *administradores;

    DeliveryApp();

    ~DeliveryApp();

    void executarApp();

    void visualizarRelatorioDeDesempenho() const;

    void visualizarRelatorioDeVendas() const;

    void visualizarRelatorioQuantitativo() const;

    void removerPedidoDeUmaLanchonete(Proprietario *proprietario);

    void visualizarDetalhesDeUmPedidoLanchonete(Proprietario *proprietario);

    void visualizarListaDePedidosLanchonete(Proprietario *proprietario);

    void cadastrarLanche(Proprietario *proprietario);

    void removerLanchonete(Proprietario *proprietario) const;

    void cadastrarLanchonete(Proprietario *proprietario);

    void removerCadastro(Usuario *usuario);

    void atribuirNotaLanchonete();

    void fazerPedido(Cliente *cliente);

    void buscarLanchesPorNome() const;

    void visualizarLanchesDeUmaLanchonete() const;

    void listarLanchonetesPorNumeroDeVendas() const;

    void listarLanchonetesPorPrecoMedio() const;

    void listarLanchonetesCategoriaPorPontuacao() const;

    void listarLanchonetesPorPontuacao() const;

    void LeituraArquivos();

    void atualizarTodosOsArquivos() const;

    void escreverLanchonetesNoArquivo() const;

    void escreverPedidosNoArquivo() const;

    void escreverProdutosNoArquivo() const;

    void escreverUsuariosNoArquivo() const;
};

#endif //_DELIVERYAPP_H_
