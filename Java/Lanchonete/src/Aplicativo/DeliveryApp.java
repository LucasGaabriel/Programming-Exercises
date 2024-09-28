package Aplicativo;

import Excecoes.CodigoIdentificadorReplicadoException;
import Excecoes.CodigoNaoEncontradoException;
import Excecoes.LoginInvalidoException;
import Cadastro.Administrador;
import Cadastro.Cliente;
import Cadastro.Proprietario;
import Cadastro.Usuario;

import java.io.*;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.Scanner;

public class DeliveryApp {
    private static final String ARQUIVO_USUARIOS = "src/Aplicativo/Files/usuarios.csv";
    private static final String ARQUIVO_LANCHONETES = "src/Aplicativo/Files/lanchonetes.csv";
    private static final String ARQUIVO_PRODUTOS = "src/Aplicativo/Files/produtos.csv";
    private static final String ARQUIVO_PEDIDOS = "src/Aplicativo/Files/pedidos.csv";

    private static final int CLIENTE = 1;
    private static final int PROPRIETARIO = 2;
    private static final int ADMINISTRADOR = 3;

    public ArrayList<Cliente> clientes;
    public ArrayList<Proprietario> proprietarios;
    public ArrayList<Administrador> administradores;

    public DeliveryApp(){
        clientes = new ArrayList<>();
        proprietarios = new ArrayList<>();
        administradores = new ArrayList<>();
    }

    public void executarApp() throws LoginInvalidoException, IOException, CodigoNaoEncontradoException,
                                                                CodigoIdentificadorReplicadoException {
        Scanner s = new Scanner(System.in);
        int opcao;

        do {
            System.out.println("\n- Aplicativo de Delivery -");
            System.out.println("1 - Login");
            System.out.println("2 - Cadastro");
            System.out.println("0 - Sair");
            System.out.print("Escolha uma opção: ");

            opcao = s.nextInt();
            s.nextLine(); //Captura o '\n'

            if (opcao == 1) {
                System.out.print("Digite seu email: ");
                String email = s.nextLine();

                System.out.print("Digite sua senha: ");
                String senha = s.nextLine();

                Usuario usuario = verificarLogin(email, senha);

                if (usuario == null) {
                    throw new LoginInvalidoException("Usuário não cadastrado!\n");
                }

                int opcaoMenu;

                do {

                    opcaoMenu = usuario.exibirMenu(this);

                } while (usuario.verificarOpcaoValida(opcaoMenu));

            }
            else if (opcao == 2) {

                int tipoUsuario;

                do {
                    System.out.println("\nComo você deseja se cadastrar?");
                    System.out.println("1 - Cliente");
                    System.out.println("2 - Proprietário");
                    System.out.println("3 - Administrador");
                    System.out.print("Escolha uma opção: ");

                    tipoUsuario = s.nextInt();

                    if (tipoUsuario >= 1 && tipoUsuario <= 3)
                        CadastrarUsuario(tipoUsuario);
                    else
                        System.out.println("\nOpção Inválida.");

                } while (tipoUsuario < 1 || tipoUsuario > 3);

            }
            else if (opcao == 0) {
                System.out.println("\nPrograma encerrado!");
            }
            else {
                System.out.println("\nOpção inválida!");
            }

        } while (opcao != 0);
    }

    private static class SortByMaisGastos implements Comparator<Cliente> {

        @Override
        public int compare(Cliente c1, Cliente c2) {
            if(c1.getQuantidadeGastos() < c2.getQuantidadeGastos())
                return 1;
            else if(c1.getQuantidadeGastos() > c2.getQuantidadeGastos())
                return -1;

            return 0;
        }
    }

    private static class SortByMaisCompras implements Comparator<Cliente> {

        @Override
        public int compare(Cliente c1, Cliente c2) {
            if(c1.getQuantidadeCompras() < c2.getQuantidadeCompras())
                return 1;
            else if(c1.getQuantidadeCompras() > c2.getQuantidadeCompras())
                return -1;

            return 0;
        }
    }

    private static class SortByMaiorFaturamento implements Comparator<Lanchonete> {

        @Override
        public int compare(Lanchonete l1, Lanchonete l2) {
            if(l1.faturamento() < l2.faturamento())
                return 1;
            else if(l1.faturamento() > l2.faturamento())
                return -1;

            return 0;
        }
    }

    private static class SortByMaisFaturados implements Comparator<Produto> {

        @Override
        public int compare(Produto p1, Produto p2) {
            if(p1.faturamento() < p2.faturamento())
                return 1;
            else if(p1.faturamento() > p2.faturamento())
                return -1;

            return 0;
        }
    }

    private static class SortByNome implements Comparator<Produto> {

        @Override
        public int compare(Produto p1, Produto p2) {
            return p1.getNome().compareTo(p2.getNome());
        }
    }

    private static class SortByMaisBaratos implements Comparator<Produto> {

        @Override
        public int compare(Produto p1, Produto p2) {
            return Double.compare(p1.getPreco(), p2.getPreco());
        }
    }

    private static class SortByMaisVendidos implements Comparator<Produto> {

        @Override
        public int compare(Produto p1, Produto p2) {
            return Double.compare(p2.getQuantidadeVendas(), p1.getQuantidadeVendas());
        }
    }

    private static class SortByNumeroDeVendas implements Comparator<Lanchonete> {

        @Override
        public int compare(Lanchonete l1, Lanchonete l2) {
            return Double.compare(l2.numeroDeVendas(), l1.numeroDeVendas());
        }
    }

    private static class SortByPrecoMedio implements Comparator<Lanchonete> {

        @Override
        public int compare(Lanchonete l1, Lanchonete l2) {
            return Double.compare(l1.getPreco_medio(), l2.getPreco_medio());
        }
    }

    private static class SortByPontuacao implements Comparator<Lanchonete> {

        @Override
        public int compare(Lanchonete l1, Lanchonete l2) {
            return Double.compare(l2.pontuacao(), l1.pontuacao());
        }
    }

    public void visualizarRelatorioDeDesempenho(){

        System.out.println("\n- Relatório de Desempenho -\n");

        for(Proprietario proprietario : proprietarios){
            for(Lanchonete lanchonete : proprietario.lanchonetes){
                //Imprime as informações da Lanchonete
                System.out.println(lanchonete);

                //Calculo do número médio de produtos por pedido
                //Valor médio por produto vendido
                //Valor médio dos pedidos.
                int qtdProdutosTotais = 0;
                double valorTotalProdutos = 0;

                for(Pedido pedido : lanchonete.pedidos){

                    qtdProdutosTotais += pedido.quantidadeDeProdutos();
                    valorTotalProdutos += pedido.valorTotal();

                }

                //Imprime as informações somente se a Lanchonete possuir algum pedido registrado
                if(lanchonete.pedidos.size() != 0) {
                    System.out.println("Número médio de Produtos por Pedido: " +
                                        qtdProdutosTotais / lanchonete.pedidos.size());
                    System.out.println("Valor médio por Produto vendido: R$" +
                                        valorTotalProdutos / qtdProdutosTotais);
                    System.out.println("Valor médio dos Pedidos: R$" +
                                        valorTotalProdutos / lanchonete.pedidos.size() + "\n");
                }
                else {
                    System.out.println("Lanchonete não possui pedidos registrados!\n");
                }
            }
        }
    }

    public void visualizarRelatorioDeVendas(){

        System.out.println("\n- Relatório de Vendas -\n");

        ArrayList<Produto> produtos = new ArrayList<>();
        ArrayList<Lanchonete> lanchonetes = new ArrayList<>();

        //Adiciona todas as Lanchonetes e Produtos em um ArrayList específico para ordenar
        for(Proprietario proprietario : proprietarios){
            for(Lanchonete lanchonete : proprietario.lanchonetes){
                lanchonetes.add(lanchonete);
                produtos.addAll(lanchonete.produtos);
            }
        }

        //Ordena os produtos pelo mais vendido
        produtos.sort(new SortByMaisVendidos());

        int cont = 5; //Quantidade maxima de produtos exibidos nos grupos

        System.out.println("Lanches mais vendidos:");
        int i=0;
        for(Produto p : produtos){
            System.out.println(p);

            if(++i == cont) //Sempre exibe uma quantidade maxima de elementos definida na variável 'cont'
                break;
        }

        //Ordena os produtos que tiveram maior faturamento
        produtos.sort(new SortByMaisFaturados());

        System.out.println("\nLanches que mais faturaram:");
        i=0;
        for(Produto p : produtos){
            System.out.println(p);

            if(++i == cont) //Sempre exibe uma quantidade maxima de elementos definida na variável 'cont'
                break;
        }

        //Ordena as lanchonetes que mais venderam
        lanchonetes.sort(new SortByNumeroDeVendas());

        System.out.println("\nLanchonetes que mais venderam:");
        i=0;
        for(Lanchonete l : lanchonetes){
            System.out.println(l);

            if(++i == cont) //Sempre exibe uma quantidade maxima de elementos definida na variável 'cont'
                break;
        }

        //Ordena as lanchonetes que mais faturaram
        lanchonetes.sort(new SortByMaiorFaturamento());

        System.out.println("\nLanchonetes que mais faturaram:");
        i=0;
        for(Lanchonete l : lanchonetes){
            System.out.println(l);

            if(++i == cont) //Sempre exibe uma quantidade maxima de elementos definida na variável 'cont'
                break;
        }

        //Ordena os clientes que fizeram mais compras
        clientes.sort(new SortByMaisCompras());

        System.out.println("\nClientes que mais compraram:");
        i=0;
        for(Cliente c : clientes){
            System.out.println(c);

            if(++i == cont) //Sempre exibe uma quantidade maxima de elementos definida na variável 'cont'
                break;
        }

        //Ordena os clientes que mais gastaram em compras
        clientes.sort(new SortByMaisGastos());

        System.out.println("\nClientes que mais gastaram em compras:");
        i=0;
        for(Cliente c : clientes){
            System.out.println(c);

            if(++i == cont) //Sempre exibe uma quantidade maxima de elementos definida na variável 'cont'
                break;
        }
    }

    public void visualizarRelatorioQuantitativo(){

        System.out.println("\n- Relatório Quantitativo -\n");

        int qtdLanchonetes = 0;
        int qtdLanches = 0;
        int qtdPedidos = 0;
        double valorTotalVendas = 0;

        //Calculo das informações necessárias
        for(Proprietario p : proprietarios){
            qtdLanchonetes += p.lanchonetes.size();

            for(Lanchonete l : p.lanchonetes){
                qtdLanches += l.produtos.size();
                qtdPedidos += l.pedidos.size();

                for(Pedido pedido : l.pedidos){
                    valorTotalVendas += pedido.valorTotal();
                }
            }
        }

        System.out.println("Clientes Cadastrados: " + clientes.size());
        System.out.println("Lanchonetes Cadastradas: " + qtdLanchonetes);
        System.out.println("Lanches Cadastrados: " + qtdLanches);
        System.out.println("Pedidos Cadastrados: " + qtdPedidos);
        System.out.println("Valor total de vendas: " + valorTotalVendas);
    }

    public void removerPedidoDeUmaLanchonete(Proprietario proprietario) throws IOException {
        Scanner s = new Scanner(System.in);

        //Mostra as lanchonetes do Proprietario
        proprietario.listarLanchonetes();

        System.out.print("Digite o código da Lanchonete: ");
        int codigo = s.nextInt();
        s.nextLine();

        //Busca a Lanchonete desejada
        Lanchonete l = buscarLanchonetePorIdentificador(codigo);

        if(l == null){
            System.out.println("Lanchonete não encontrada.");
            return;
        }

        //Mostra os pedidos da lanchonete
        l.listarPedidos();

        System.out.print("Digite o código do Pedido a ser removido: ");
        codigo = s.nextInt();

        //Busca o pedido a ser removido
        Pedido p = buscarPedidoPorCodigo(codigo);

        l.pedidos.remove(p);

        //Atualiza os Pedidos no Arquivo
        escreverPedidosNoArquivo();
    }

    public void visualizarDetalhesDeUmPedidoLanchonete(Proprietario proprietario){
        Scanner s = new Scanner(System.in);

        //Mostra as Lanchonetes do Proprietario
        proprietario.listarLanchonetes();

        System.out.print("Digite o Identificador da Lanchonete desejada: ");
        int id = s.nextInt();

        //Busca a lanchonete desejada
        Lanchonete lanchonete = buscarLanchonetePorIdentificador(id);

        if(lanchonete == null){
            System.out.println("Lanchonete não encontrada!");
            return;
        }

        //Mostra os pedidos da lanchonete
        lanchonete.listarPedidos();

        System.out.print("Digite o código do Pedido desejado: ");
        id = s.nextInt();

        //Busca o pedido desejado
        Pedido p = buscarPedidoPorCodigo(id);

        if(p == null){
            System.out.println("Pedido não encontrado!");
            return;
        }

        //Imprime o pedido de forma detalhada
        p.imprimirDetalhesPedido();
    }

    public void visualizarListaDePedidosLanchonete(Proprietario proprietario){
        Scanner s = new Scanner(System.in);

        //Mostra as Lanchonetes do Proprietário
        proprietario.listarLanchonetes();

        System.out.print("Digite o Identificador da Lanchonete desejada: ");
        int id = s.nextInt();

        //Busca a lanchonete desejada
        Lanchonete lanchonete = buscarLanchonetePorIdentificador(id);

        if(lanchonete == null){
            System.out.println("Lanchonete não encontrada!");
            return;
        }

        //Lista todos os Pedidos da Lanchonete
        lanchonete.listarPedidos();

        //Mostra a quantidade de pedidos da Lanchonete
        System.out.println("Quantidade de Pedidos: " + lanchonete.pedidos.size());

    }

    public void cadastrarLanche(Proprietario proprietario) throws CodigoIdentificadorReplicadoException, IOException {
        Scanner s = new Scanner(System.in);

        proprietario.listarLanchonetes();

        System.out.print("Digite o Identificador da Lanchonete desejada: ");
        int id = s.nextInt();

        Lanchonete lanchonete = buscarLanchonetePorIdentificador(id);

        if(lanchonete != null) {
            //Cadastra um produto novo na Lanchonete
            lanchonete.cadastrarProduto();

            //Atualiza o preco medio dos Produtos
            lanchonete.atualizarPrecoMedio();
        }

        //Atualiza os produtos no arquivo
        escreverProdutosNoArquivo();
    }

    public void removerLanchonete(Proprietario proprietario) throws IOException {
        Scanner s = new Scanner(System.in);

        System.out.println("\n- Remoção de Lanchonete -");

        proprietario.listarLanchonetes();

        System.out.print("Digite o Identificador da Lanchonete a ser removida: ");
        int id = s.nextInt();

        proprietario.lanchonetes.removeIf(lanchonete -> lanchonete.getIdentificador() == id);

        //Atualiza os Arquivos
        escreverLanchonetesNoArquivo();
        escreverProdutosNoArquivo();
        escreverPedidosNoArquivo();
    }

    public void cadastrarLanchonete(Proprietario proprietario) throws IOException {
        Scanner s = new Scanner(System.in);

        System.out.println("\n- Cadastro Lanchonete -");
        System.out.println("A nova lanchonete possui Loja física?");
        System.out.println("1 - Sim");
        System.out.println("0 - Não");
        System.out.print("Escolha uma opção: ");
        int lojaFisica = s.nextInt();
        s.nextLine();

        if(lojaFisica != 0 && lojaFisica != 1){
            System.out.println("\nOpção inválida.");
            return;
        }

        int identificador;
        Lanchonete l;

        do {
            System.out.print("Código identificador: ");
            identificador = s.nextInt();
            s.nextLine();

            l = buscarLanchonetePorIdentificador(identificador);

            if(l != null){
                System.out.println("Identificador já usado. Escolha outro!");
            }

        } while (l != null);

        System.out.print("Nome da Lanchonete: ");
        String nome = s.nextLine();

        System.out.print("Categoria de produtos da Lanchonete: ");
        String categoria = s.nextLine();

        //Se a loja possuir endereço fisico, busca mais detalhes. Se nao, adiciona a nova Lanchonete ao proprietario
        if(lojaFisica == 0){
            proprietario.lanchonetes.add(new Lanchonete(identificador, nome, categoria));
        }
        else {
            System.out.print("Endereço da Lanchonete: ");
            String endereco = s.nextLine();

            System.out.print("Desconto de Retirada do Produto na Loja: ");
            double desconto_retirada = s.nextDouble();

            System.out.print("Desconto de Consumo do Produto na Loja: ");
            double desconto_consumo = s.nextDouble();

            proprietario.lanchonetes.add(new Lanchonete(identificador, nome, categoria, endereco,
                                                        desconto_retirada, desconto_consumo));
        }

        //Atualiza as Lanchonetes no arquivo
        escreverLanchonetesNoArquivo();
    }

    public void removerCadastro(Usuario usuario) throws IOException {
        Scanner s = new Scanner(System.in);

        int opcao;

        do {
            System.out.println("\nTem certeza que deseja remover seu cadastro?");
            System.out.println("1 - Sim");
            System.out.println("0 - Nao");
            System.out.print("Selecione uma opção: ");
            opcao = s.nextInt();

        } while (opcao != 0 && opcao != 1);

        if(opcao == 0) {
            System.out.println("Cadastro NÃO foi removido!");
            return;
        }

        //Remove de formas diferentes dependendo do tipo de Usuario
        //Alguns usuários possuem informações adicionais em diferentes lugares e arquivos
        switch (usuario.getClass().getSimpleName()) {
            case "Cliente" -> {

                //Remove todos os pedidos feitos pelo Cliente
                for (Proprietario proprietario : proprietarios) {
                    for (Lanchonete lanchonete : proprietario.lanchonetes) {
                        lanchonete.pedidos.removeIf(pedido -> pedido.getCliente() == usuario);
                    }
                }

                //Remove o cliente da lista de clientes
                clientes.remove((Cliente)usuario);

                //Atualiza os arquivos
                escreverPedidosNoArquivo();
                escreverUsuariosNoArquivo();
            }
            case "Proprietario" -> {

                //Remove o proprietario
                proprietarios.remove((Proprietario)usuario);

                //Atualiza todos os arquivos (Informacoes do Proprietario estão em todos os arquivos)
                atualizarTodosOsArquivos();
            }
            case "Administrador" -> {

                //Remove o administrador
                administradores.remove((Administrador)usuario);

                //Atualiza os usuarios no arquivo
                escreverUsuariosNoArquivo();
            }
        }

        System.out.println("Cadastro removido com Sucesso!");
    }

    public void atribuirNotaLanchonete() throws CodigoNaoEncontradoException, IOException {
        Scanner s = new Scanner(System.in);

        System.out.print("Digite o código da Lanchonete para atribuir uma Nota: ");
        int codigo = s.nextInt();
        s.nextLine();

        //Busca a Lanchonete desejada
        Lanchonete l = buscarLanchonetePorIdentificador(codigo);

        if(l == null){
            throw new CodigoNaoEncontradoException("Lanchonete não encontrada!");
        }

        System.out.print("Digite uma nota de 0 a 5: ");
        double nota = s.nextDouble();

        //Atribui a pontuaçao a Lanchonete desejada
        l.atribuirPontuacao(nota);

        //Atualiza a Pontuaçao da Lanchonete no arquivo
        escreverLanchonetesNoArquivo();
    }

    public void fazerPedido(Cliente cliente) throws IOException {
        Scanner s = new Scanner(System.in);

        System.out.print("Digite o código da Lanchonete para fazer um pedido: ");
        int codigoLanchonete = s.nextInt();
        s.nextLine();

        //Busca a Lanchonete Desejada
        Lanchonete lanchonete = buscarLanchonetePorIdentificador(codigoLanchonete);

        if(lanchonete == null){
            System.out.println("Lanchonete não encontrada!\n");
            return;
        }

        int i = 0;
        int codigo = i;

        //Atribui um código ao Pedido
        //O código é o menor possível iniciando de 0, não possuindo nenhum outro pedido com o mesmo código
        while(buscarPedidoPorCodigo(codigo) != null){
            i++;
            codigo = i;
        }

        Pedido novoPedido = new Pedido(codigo, cliente);

        int opcao;

        do {
            System.out.println("\n- Novo Pedido -");
            System.out.println("1 - Adicionar Produto");
            System.out.println("2 - Visualizar Produtos");
            System.out.println("0 - Confirmar Pedido");
            System.out.println("Valor total: R$" + novoPedido.valorTotal());
            System.out.print("Escolha uma opção: ");
            opcao = s.nextInt();
            s.nextLine();

            if (opcao == 1){

                Produto p;

                do {
                    System.out.print("Digite o código do Produto: ");
                    int codigoProduto = s.nextInt();
                    s.nextLine();

                    p = lanchonete.buscaProdutoPorCodigo(codigoProduto);

                    if (p == null)
                        System.out.println("Produto não encontrado!");

                } while (p == null);

                System.out.print("Digite a quantidade desejada do Produto: ");
                int qtd = s.nextInt();
                s.nextLine();

                //Adiciona as compras e gastos ao Cliente
                cliente.addQuantidadeCompras(qtd);
                cliente.addQuantidadeGastos(p.getPreco() * qtd);

                //Adiciona as vendas ao produto
                p.addQuantidadeVendas(qtd);

                //Adiciona o produto e a quantidade no Novo Pedido
                novoPedido.addProduto(p, qtd);
            }
            else if(opcao == 2){
                System.out.println("\nProdutos do pedido atual:");
                for(i=0; i<novoPedido.produtos.size(); i++){
                    System.out.println(novoPedido.produtos.get(i) + " | Quantidade: " +
                                        novoPedido.quantidadeProdutos.get(i));
                }
            }
            else if(opcao == 0){
                System.out.println("Pedido realizado!");
            }
            else {
                System.out.println("Opçao invalida!");
            }

        } while (opcao != 0);

        //Adiciona o pedido a Lanchonete
        lanchonete.addPedido(novoPedido);

        //Atualiza os arquivos
        escreverUsuariosNoArquivo();
        escreverProdutosNoArquivo();
        escreverPedidosNoArquivo();
    }

    public void buscarLanchesPorNome(){
        Scanner s = new Scanner(System.in);

        System.out.println("\nEscreva o lanche ou termo a ser buscado: ");
        String nome = s.nextLine();

        //Busca os Lanches que possuem o Termo digitado no nome
        System.out.println("\nLanches encontrados:");
        for(Proprietario proprietario : proprietarios){
            for(Lanchonete lanchonete : proprietario.lanchonetes){
                for(Produto produto : lanchonete.produtos){
                    if(produto.getNome().contains(nome)){
                        System.out.println("Lanche: " + produto.getNome() +
                                            " [Código: " + produto.getCodigo() + "] - Loja: " +
                                            lanchonete.getNome() + " [Código: " +
                                            lanchonete.getIdentificador() + "]");
                    }
                }
            }
        }
    }

    public void visualizarLanchesDeUmaLanchonete() throws CodigoNaoEncontradoException {
        Scanner s = new Scanner (System.in);

        System.out.print("\nDigite o identificador da Lanchonete desejada: ");
        int id = s.nextInt();

        //Busca a lanchonete desejada
        Lanchonete l = buscarLanchonetePorIdentificador(id);

        if(l == null){
            throw new CodigoNaoEncontradoException("Lanchonete não encontrada!\n");
        }

        System.out.println("\nDados da Lanchonete:");
        System.out.println(l);

        int cont = 3; //Quantidade maxima de produtos exibidos nos grupos

        //Ordena os produtos pelos mais Vendidos
        l.produtos.sort(new SortByMaisVendidos());

        System.out.println("\nProdutos mais vendidos:");
        int i=0;
        for(Produto p : l.produtos){
            System.out.println(p);

            if(++i == cont) //Sempre exibe uma quantidade maxima de elementos definida na variável 'cont'
                break;
        }

        //Ordena os produtos pelos mais baratos
        l.produtos.sort(new SortByMaisBaratos());

        System.out.println("\nProdutos mais baratos:");
        i=0;
        for(Produto p : l.produtos){
            System.out.println(p);

            if(++i == cont) //Sempre exibe uma quantidade maxima de elementos definida na variável 'cont'
                break;
        }

        //Ordena os produtos pelo nome, para exibir todos ordenadamente
        l.produtos.sort(new SortByNome());

        System.out.println("\nLista de todos os Produtos:");
        for(Produto p : l.produtos){
            System.out.println(p);
        }
    }

    public void listarLanchonetesPorNumeroDeVendas(){
        ArrayList<Lanchonete> lanchonetes = new ArrayList<>();

        for(Proprietario p : proprietarios){
            //Adiciona todas as lanchonetes de todos os proprietários no ArrayList
            lanchonetes.addAll(p.lanchonetes);
        }

        //Ordena pelo numero de vendas
        lanchonetes.sort(new SortByNumeroDeVendas());

        System.out.println("\nLanchonetes Ordenadas pelo Número de Vendas dos Produtos:");
        for(Lanchonete l : lanchonetes){
            System.out.println(l);
        }
    }

    public void listarLanchonetesPorPrecoMedio(){
        ArrayList<Lanchonete> lanchonetes = new ArrayList<>();

        for(Proprietario p : proprietarios){
            //Adiciona todas as lanchonetes de todos os proprietários no ArrayList
            lanchonetes.addAll(p.lanchonetes);
        }

        //Ordena as lanchonetes pelo preco medio
        lanchonetes.sort(new SortByPrecoMedio());

        System.out.println("\nLanchonetes Ordenadas pelo Preço Médio dos Produtos:");
        for(Lanchonete l : lanchonetes){
            System.out.println(l);
        }
    }

    public void listarLanchonetesCategoriaPorPontuacao(){
        Scanner s = new Scanner(System.in);

        System.out.print("\nDigite a Categoria de Lanchonetes desejadas: ");
        String categoria = s.nextLine();

        //ArrayList para adicionar as Lanchonetes específicas da categoria
        ArrayList<Lanchonete> lanchonetes = new ArrayList<>();

        //Adiciona as Lanchonetes da categoria especifica no ArrayList
        for(Proprietario p : proprietarios){
            for(Lanchonete l : p.lanchonetes){
                if(l.getCategoria().equalsIgnoreCase(categoria))
                    lanchonetes.add(l);
            }
        }

        //Ordena as lanchonetes pela Pontuação
        lanchonetes.sort(new SortByPontuacao());

        System.out.println("\nLanchonetes Ordenadas pela Pontuação da Categoria: '" + categoria + "'");
        for(Lanchonete l : lanchonetes){
            System.out.println(l);
        }
    }

    public void listarLanchonetesPorPontuacao(){
        ArrayList<Lanchonete> lanchonetes = new ArrayList<>();

        for(Proprietario p : proprietarios){
            //Adiciona todas as lanchonetes de todos os proprietários no ArrayList
            lanchonetes.addAll(p.lanchonetes);
        }

        //Ordena as lanchonetes pela pontuação
        lanchonetes.sort(new SortByPontuacao());

        System.out.println("\nLanchonetes Ordenadas pela Pontuação:");
        for(Lanchonete l : lanchonetes){
            System.out.println(l);
        }
    }

    private Proprietario buscaProprietarioPorNome(String nome){
        for(Proprietario p : proprietarios){
            if(p.getNome().equals(nome))
                return p;
        }

        return null;
    }

    //Faz a leitura de todos os arquivos e preenche os ArrayLists
    public void LeituraArquivos() throws IOException {

        //LEITURA DOS USUÁRIOS
        File f = new File(ARQUIVO_USUARIOS);

        //Se o arquivo ainda não existe, cria um vazio
        if(!f.exists()){
            FileWriter fw = new FileWriter(f);
            fw.close();
        }

        Scanner s = new Scanner(f);

        while(s.hasNextLine()){
            String line = s.nextLine();
            String[] parts = line.split(";");

            //Adiciona os Usuarios presentes nos arquivos
            switch (parts[0]) {
                case "Cliente" -> clientes.add(new Cliente(parts[1], parts[2], parts[3], parts[4],
                                                    Integer.parseInt(parts[5]), Double.parseDouble(parts[6])));

                case "Proprietario" -> proprietarios.add(new Proprietario(parts[1], parts[2], parts[3]));

                case "Administrador" -> administradores.add(new Administrador(parts[1], parts[2], parts[3]));
            }
        }

        s.close();

        //LEITURA DAS LANCHONETES
        f = new File(ARQUIVO_LANCHONETES);

        //Se o arquivo ainda não existe, cria um vazio
        if(!f.exists()){
            FileWriter fw = new FileWriter(f);
            fw.close();
        }

        s = new Scanner(f);

        while(s.hasNextLine()){
            String line = s.nextLine();
            String[] parts = line.split(";");

            //Busca o proprietário da Lanchonete
            Proprietario proprietario = buscaProprietarioPorNome(parts[0]);

            //Adiciona a lanchonete ao Proprietario dependendo do tipo de estabelecimento (Delivery ou hibrido)
            if(proprietario != null) {
                if (parts[1].equals("0")) {
                    proprietario.lanchonetes.add(new Lanchonete(Integer.parseInt(parts[2]), parts[3], parts[4],
                                                        "", -1, -1,
                                                                Double.parseDouble(parts[5]),
                                                                Double.parseDouble(parts[6]),
                                                                Integer.parseInt(parts[7])));
                } else if (parts[1].equals("1")) {
                    proprietario.lanchonetes.add(new Lanchonete(Integer.parseInt(parts[2]), parts[3], parts[4],
                                                                parts[5], Double.parseDouble(parts[6]),
                                                                Double.parseDouble(parts[7]),
                                                                Double.parseDouble(parts[8]),
                                                                Double.parseDouble(parts[9]),
                                                                Integer.parseInt(parts[10])));
                }
            }
        }

        s.close();

        //LEITURA DOS PRODUTOS
        f = new File(ARQUIVO_PRODUTOS);

        //Se o arquivo ainda não existe, cria um vazio
        if(!f.exists()){
            FileWriter fw = new FileWriter(f);
            fw.close();
        }

        s = new Scanner(f);

        while(s.hasNextLine()){
            String line = s.nextLine();
            String[] parts = line.split(";");

            //Busca o proprietário da Lanchonete que possui o produto
            Proprietario proprietario = buscaProprietarioPorNome(parts[0]);

            if(proprietario == null){
                System.out.println("Proprietario não encontrado!");
                return;
            }

            //Busca a lanchonete que possui o produto
            Lanchonete lanchonete = proprietario.buscaLanchonetePorNome(parts[1]);

            //Adiciona o produto na lanchonete
            lanchonete.produtos.add(new Produto(Integer.parseInt(parts[2]), parts[3],
                                                Double.parseDouble(parts[4]),
                                                Integer.parseInt(parts[5])));

        }

        s.close();

        //LEITURA DOS PEDIDOS
        f = new File(ARQUIVO_PEDIDOS);

        //Se o arquivo ainda não existe, cria um vazio
        if(!f.exists()){
            FileWriter fw = new FileWriter(f);
            fw.close();
        }

        s = new Scanner(f);

        while(s.hasNextLine()){
            String line = s.nextLine();
            String[] parts = line.split(";");

            //Busca o proprietário da Lanchonete que possui o pedido
            Proprietario proprietario = buscaProprietarioPorNome(parts[0]);

            if(proprietario == null){
                System.out.println("Proprietario não encontrado!");
                return;
            }

            //Busca a lanchonete que possui o pedido
            Lanchonete lanchonete = proprietario.buscaLanchonetePorNome(parts[1]);

            //Busca o cliente que fez o pedido
            Cliente cliente = buscaClientePorCPF(parts[3]);

            //Adiciona o pedido na lanchonete
            Pedido pedido = new Pedido(Integer.parseInt(parts[2]), cliente, parts[4]);
            lanchonete.pedidos.add(pedido);

            int qtdProdutos = Integer.parseInt(parts[5]);

            //Adiciona os Produtos nos Pedidos
            for(int i=0, x=6; i<qtdProdutos; i++, x++){
                int codigoProduto = Integer.parseInt(parts[x]);
                x++;
                Produto produto = lanchonete.buscaProdutoPorCodigo(codigoProduto);
                pedido.addProduto(produto, Integer.parseInt(parts[x]));
            }

        }

        s.close();

    }

    private Pedido buscarPedidoPorCodigo(int codigo){
        for(Proprietario proprietario : proprietarios){
            for(Lanchonete lanchonete : proprietario.lanchonetes){
                for(Pedido pedido : lanchonete.pedidos){
                    if(pedido.getCodigo() == codigo)
                        return pedido;
                }
            }
        }

        return null;
    }

    private Lanchonete buscarLanchonetePorIdentificador(int id){
        for(Proprietario p : proprietarios){
            for(Lanchonete l : p.lanchonetes){
                if(l.getIdentificador() == id)
                    return l;
            }
        }

        return null;
    }

    private Cliente buscaClientePorCPF(String cpf){
        for(Cliente c : clientes){
            if(c.getCPF().equals(cpf))
                return c;
        }

        return null;
    }

    private Usuario verificarLogin(String email, String senha){
        for(Cliente c : clientes){
            if(c.verificarUsuario(email, senha))
                return c;
        }

        for(Proprietario p : proprietarios){
            if(p.verificarUsuario(email, senha))
                return p;
        }

        for(Administrador a : administradores){
            if(a.verificarUsuario(email, senha))
                return a;
        }

        return null;
    }

    public void atualizarTodosOsArquivos() throws IOException {
        escreverLanchonetesNoArquivo();
        escreverPedidosNoArquivo();
        escreverProdutosNoArquivo();
        escreverUsuariosNoArquivo();
    }

    //Salva todas as Lanchonetes em um Arquivo
    public void escreverLanchonetesNoArquivo() throws IOException {
        FileWriter fw = new FileWriter(ARQUIVO_LANCHONETES);

        for(Proprietario proprietario : proprietarios){
            for(Lanchonete lanchonete : proprietario.lanchonetes){
                fw.write(proprietario.getNome() + ";");

                if(lanchonete.getDesconto_retirada() == -1){
                    fw.write("0;" + lanchonete.getIdentificador() + ";" + lanchonete.getNome() + ";" +
                                lanchonete.getCategoria() + ";" + lanchonete.getPreco_medio() + ";" +
                                lanchonete.getSomaPontuacao() + ";" + lanchonete.getQuantidadePontuacao() + "\n");
                }
                else {
                    fw.write("1;" + lanchonete.getIdentificador() + ";" + lanchonete.getNome() + ";" +
                                lanchonete.getCategoria() + ";" + lanchonete.getEndereco() + ";" +
                                lanchonete.getDesconto_retirada() + ";" +
                                lanchonete.getDesconto_consumoLocal() + ";" +
                                lanchonete.getPreco_medio() + ";" + lanchonete.getSomaPontuacao() + ";" +
                                lanchonete.getQuantidadePontuacao() + "\n");
                }
            }
        }

        fw.close();
    }

    //Salva todos os pedidos em um Arquivo
    public void escreverPedidosNoArquivo() throws IOException {
        FileWriter fw = new FileWriter(ARQUIVO_PEDIDOS);

        for(Proprietario proprietario : proprietarios){
            for(Lanchonete lanchonete : proprietario.lanchonetes){
                for(Pedido pedido : lanchonete.pedidos){
                    fw.write(proprietario.getNome() + ";" + lanchonete.getNome() + ";" +
                                pedido.getCodigo() + ";" + pedido.getCliente().getCPF() + ";" +
                                pedido.getData() + ";" + pedido.produtos.size());

                    for(int i=0; i<pedido.produtos.size(); i++){
                        fw.write(";" + pedido.produtos.get(i).getCodigo() + ";" +
                                    pedido.quantidadeProdutos.get(i));
                    }

                    fw.write("\n");
                }
            }
        }

        fw.close();
    }

    //Salva todos os produtos em um Arquivo
    public void escreverProdutosNoArquivo() throws IOException {
        FileWriter fw = new FileWriter(ARQUIVO_PRODUTOS);

        for(Proprietario proprietario : proprietarios){
            for(Lanchonete lanchonete : proprietario.lanchonetes){
                for(Produto produto : lanchonete.produtos){
                    fw.write(proprietario.getNome() + ";" + lanchonete.getNome() + ";" +
                                produto.getCodigo() + ";" + produto.getNome() + ";" + produto.getPreco() + ";" +
                                produto.getQuantidadeVendas() + "\n");
                }
            }
        }

        fw.close();
    }

    //Salva todos os Usuarios em um Arquivo
    public void escreverUsuariosNoArquivo() throws IOException {
        FileWriter fw = new FileWriter(ARQUIVO_USUARIOS);

        for(Administrador a : administradores){
            fw.write("Administrador" + ";" + a.getNome() + ";" + a.getEmail() + ";" + a.getSenha() + "\n");
        }

        for(Cliente c : clientes){
            fw.write("Cliente" + ";" + c.getNome() + ";" + c.getEmail() + ";" + c.getSenha() + ";" +
                        c.getCPF() + ";" + c.getQuantidadeCompras() + ";" + c.getQuantidadeGastos() + "\n");
        }

        for(Proprietario p : proprietarios){
            fw.write("Proprietario" + ";" + p.getNome() + ";" + p.getEmail() + ";" + p.getSenha() + "\n");
        }

        fw.close();
    }

    //Verifica se um email já esta sendo utilizado por algum usuario
    private boolean EmailJaUtilizado(String email){
        for(Proprietario p : proprietarios){
            if(p.getEmail().equals(email))
                return true;
        }

        for(Cliente c : clientes){
            if(c.getEmail().equals(email))
                return true;
        }

        for(Administrador a : administradores){
            if(a.getEmail().equals(email))
                return true;
        }

        return false;
    }

    private void CadastrarUsuario(int tipoUsuario) throws IOException {
        Scanner s = new Scanner(System.in);

        System.out.println("\n- Cadastro Novo Usuario -");

        System.out.print("Nome: ");
        String nome = s.nextLine();

        System.out.print("Email: ");
        String email = s.nextLine();

        //Verifica se o email já está em uso
        if(EmailJaUtilizado(email)){
            System.out.println("\nEmail já utilizado!");
            return;
        }

        System.out.print("Senha: ");
        String senha = s.nextLine();

        if(tipoUsuario == CLIENTE){

            System.out.print("CPF: ");
            String cpf = s.nextLine();

            clientes.add(new Cliente(nome, email, senha, cpf));
        }
        else if (tipoUsuario == PROPRIETARIO){

            proprietarios.add(new Proprietario(nome, email, senha));
        }
        else if(tipoUsuario == ADMINISTRADOR){

            administradores.add(new Administrador(nome, email, senha));
        }

        //Atualiza os usuários no arquivo
        escreverUsuariosNoArquivo();

        System.out.println("Usuario Cadastrado com Sucesso!");
    }
}
