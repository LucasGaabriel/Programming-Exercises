import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Loja {
    ArrayList<Produto> produtos;
    ArrayList<Cliente> clientes;
    ArrayList<NotaFiscal> notas;

    public int Menu(){
        Scanner s = new Scanner(System.in);
        System.out.println("\n-------- MENU --------");
        System.out.println("1 - Cadastrar Cliente");
        System.out.println("2 - Cadastrar Produto");
        System.out.println("3 - Cadastrar Nota");
        System.out.println("4 - Listar Clientes");
        System.out.println("5 - Listar Produtos");
        System.out.println("6 - Listar Notas");
        System.out.println("7 - Remover Cliente");
        System.out.println("8 - Remover Produto");
        System.out.println("9 - Remover Nota");
        System.out.println("10 - Adicionar Produto na Nota");
        System.out.println("11 - Atualizar Estoque de um Produto");
        System.out.println("12 - Atualizar Preço de um Produto");
        System.out.println("13 - Atualizar Desconto de um Produto");
        System.out.println("14 - Exibir Relatório");
        System.out.println("15 - Exibir Nota Fiscal");
        System.out.println("16 - Listar Todos os Itens de uma Categoria");

        System.out.println("0 - Encerrar");

        System.out.print("Selecione uma opção: ");
        int opcao = s.nextInt();
        s.nextLine();

        switch (opcao) {
            case 1 -> cadastrarCliente();
            case 2 -> cadastrarProduto();
            case 3 -> cadastrarNota();
            case 4 -> listarClientes();
            case 5 -> listarProdutos();
            case 6 -> listarNotas();
            case 7 -> {
                System.out.print("Digite o CPF do Cliente a ser removido: ");
                String cpf = s.nextLine();
                removerCliente(cpf);
            }
            case 8 -> {
                System.out.print("Digite o código do produto a ser removido: ");
                int codigo = s.nextInt();
                removerProduto(codigo);
            }
            case 9 -> {
                System.out.print("Digite o código da nota a ser removida: ");
                int codigo = s.nextInt();
                removerNota(codigo);
            }
            case 10 -> adicionarItemNota();
            case 11 -> {
                System.out.print("Digite o código do produto para atualizar o estoque: ");
                int codigo = s.nextInt();

                Produto p = buscarProduto(codigo);

                if(p == null){
                    System.out.println("(!) Produto não encontrado!");
                    return opcao;
                }

                System.out.print("Digite a quantidade para atualizar o estoque: ");
                int estoque= s.nextInt();

                while(estoque < 0){
                    System.out.println("Estoque deve ser um valor positivo!");
                    System.out.print("Digite um novo valor para o estoque: ");

                    estoque = s.nextInt();
                }

                p.atualizarEstoque(estoque);

                System.out.println("Estoque atualizado com sucesso!");
            }
            case 12 -> {
                System.out.print("Digite o código do produto para atualizar o preço: ");
                int codigo = s.nextInt();

                Produto p = buscarProduto(codigo);

                if(p == null){
                    System.out.println("(!) Produto não encontrado!");
                    return opcao;
                }

                System.out.print("Digite o valor para atualizar o preço: ");
                double preco = s.nextDouble();

                while(preco < 0){
                    System.out.println("O preço deve ser um valor positivo!");
                    System.out.print("Digite um novo preço: ");

                    preco = s.nextDouble();
                    s.nextLine();
                }

                p.atualizarPreco(preco);

                System.out.println("Preço atualizado com sucesso!");
            }
            case 13 -> {
                System.out.print("Digite o código do produto para atualizar o desconto: ");
                int codigo = s.nextInt();

                Produto p = buscarProduto(codigo);

                if(p == null){
                    System.out.println("(!) Produto não encontrado!");
                    return opcao;
                }

                System.out.print("Digite o valor para atualizar o desconto: ");
                double desconto = s.nextDouble();

                while(desconto < 0 || desconto > 1){
                    System.out.println("Desconto deve possuir valor entre 0 e 1!");
                    System.out.print("Digite um novo desconto: ");

                    desconto = s.nextDouble();
                }

                p.atualizarDesconto(desconto);

                System.out.println("Desconto atualizado com sucesso!");
            }
            case 14 -> exibirRelatorio();
            case 15 -> exibirNotaFiscal();
            case 16 -> listarItensCategoria();
            case 0 -> System.out.println("Programa encerrado!");
            default -> System.out.println("Opção inválida!");
        }

        return opcao;
    }

    public Loja(){
        this.produtos = new ArrayList<>();
        this.clientes = new ArrayList<>();
        this.notas = new ArrayList<>();
    }

    void cadastrarCliente() {
        Scanner s = new Scanner(System.in);

        System.out.println("\n--- Cadastro Novo Cliente ---");

        System.out.print("CPF: ");
        String cpf = s.nextLine();

        while(this.buscarCliente(cpf) != null){
            System.out.println("Cliente já cadastrado. Digite um novo CPF: ");
            cpf = s.nextLine();
        }

        System.out.print("Nome: ");
        String nome = s.nextLine();

        System.out.print("Telefone: ");
        String telefone = s.nextLine();

        Cliente c = new Cliente(cpf, nome, telefone);

        this.clientes.add(c);

        System.out.println("Cliente cadastrado com sucesso!");
    }

    void cadastrarProduto(){
        Scanner s = new Scanner(System.in);

        System.out.println("\n--- Cadastro Novo Produto ---");

        System.out.print("Código: ");
        int codigo = s.nextInt();
        s.nextLine(); //Leitura do '\n'

        while(this.buscarProduto(codigo) != null){
            System.out.print("Produto já cadastrado. Digite um novo código: ");
            codigo = s.nextInt();
            s.nextLine();
        }

        System.out.print("Nome: ");
        String nome = s.nextLine();

        System.out.print("Preço: ");
        double preco = s.nextDouble();
        s.nextLine(); //Leitura do '\n'

        while(preco < 0){
            System.out.println("O preço deve ser um valor positivo!");
            System.out.print("Digite um novo preço: ");

            preco = s.nextDouble();
            s.nextLine();
        }

        System.out.print("Categoria: ");
        String categoria = s.nextLine();

        System.out.print("Desconto: ");
        double desconto = s.nextDouble();

        while(desconto < 0 || desconto > 1){
            System.out.println("Desconto deve possuir valor entre 0 e 1!");
            System.out.print("Digite um novo desconto: ");

            desconto = s.nextDouble();
        }

        System.out.print("Estoque: ");
        int estoque = s.nextInt();

        while(estoque < 0){
            System.out.println("Estoque deve ser um valor positivo!");
            System.out.print("Digite um novo valor para o estoque: ");

            estoque = s.nextInt();
        }

        Produto p = new Produto(codigo, nome, preco, categoria, desconto, estoque);

        this.produtos.add(p);

        System.out.println("Produto cadastrado com sucesso!");
    }

    void cadastrarNota(){
        Scanner s = new Scanner(System.in);

        int i = 0;
        int codigo = i;

        while(this.buscarNota(codigo) != null){
            i++;
            codigo = i;
        }

        System.out.println("\n--- Cadastro Nota Fiscal ---");

        System.out.print("CPF do Cliente: ");
        String cpf = s.nextLine();

        if(this.buscarCliente(cpf) == null){
            System.out.println("(!) Cliente não cadastrado!");
            return;
        }

        Cliente comprador = buscarCliente(cpf);

        System.out.print("Método de Pagamento: ");
        String metodoPagamento = s.nextLine();

        NotaFiscal nf = new NotaFiscal(codigo, comprador, metodoPagamento);

        this.notas.add(nf);

        System.out.println("Nota Fiscal cadastrada com sucesso!");
    }

    void listarClientes(){
        if(this.clientes.size() != 0) {
            System.out.println("\n--- Lista de Clientes ---");
            System.out.printf("%-15s %-30s %-15s\n", "CPF:", "Nome:", "Telefone:");
            for (Cliente c : this.clientes) {
                System.out.printf("%-15s %-30s %-15s\n", c.cpf, c.nome, c.telefone);
            }
        }
        else {
            System.out.println("(!) Nenhum cliente cadastrado!");
        }
    }

    void listarProdutos(){
        if(this.produtos.size() != 0) {
            System.out.println("\n--- Lista de Produtos ---");
            System.out.printf("%-10s %-25s %-10s %-20s %-10s %-10s\n", "Código:", "Nome:", "Preço:", "Categoria:", "Desconto:", "Estoque:");
            for (Produto p : this.produtos) {
                System.out.printf("%-10s %-25s %-10s %-20s %-10s %-10s\n", p.codigo, p.nome, p.preco, p.categoria, p.desconto, p.estoque);
            }
        }
        else {
            System.out.println("(!) Nenhum produto cadastrado!");
        }
    }

    void listarNotas(){
        if(this.notas.size() != 0) {
            System.out.println("\n--- Lista de Notas Fiscais ---");
            System.out.printf("%-10s %-30s %-20s %-20s\n", "Código:", "Comprador:", "Data:", "Método de Pagamento:");
            for (NotaFiscal nf : this.notas) {
                System.out.printf("%-10s %-30s %-20s %-20s\n", nf.codigo, nf.comprador.nome, nf.data, nf.metodoPagamento);
            }
        }
        else {
            System.out.println("(!) Nenhuma Nota Fiscal cadastrada!");
        }
    }

    Cliente buscarCliente(String cpf){
        Cliente c = null;

        //Busca o cliente pelo CPF na Lista de Clientes
        for(Cliente cliente : this.clientes){
            if(cliente.cpf.equals(cpf)){
                c = cliente;
                break;
            }
        }

        return c;
    }

    Produto buscarProduto(int codigo){
        Produto p = null;

        //Busca o produto pelo código na Lista de Produtos
        for(Produto produto : this.produtos){
            if(produto.codigo == codigo){
                p = produto;
                break;
            }
        }

        return p;
    }

    NotaFiscal buscarNota(int codigo){
        NotaFiscal nf = null;

        //Busca a nota fiscal pelo código na Lista de Notas Fiscais
        for(NotaFiscal notafiscal : this.notas){
            if(notafiscal.codigo == codigo){
                nf = notafiscal;
                break;
            }
        }

        return nf;
    }

    void removerCliente(String cpf){
        if(this.clientes.removeIf(cliente -> cliente.cpf.equals(cpf))){
            System.out.println("Cliente removido com sucesso!");
        }
        else {
            System.out.println("(!) Cliente não encontrado!");
        }
    }

    void removerProduto(int codigo){
        if(this.produtos.removeIf(produto -> produto.codigo == codigo)){
            System.out.println("Produto removido com sucesso!");
        }
        else {
            System.out.println("(!) Produto não encontrado!");
        }
    }

    void removerNota(int codigo){
        if(this.notas.removeIf(nota -> nota.codigo == codigo)){
            System.out.println("Nota removida com sucesso!");
        }
        else {
            System.out.println("(!) Nota não encontrada!");
        }
    }

    void adicionarItemNota(){
        Scanner s = new Scanner(System.in);

        NotaFiscal nota;
        Produto produto;

        System.out.print("Digite o Código da Nota para adicionar um produto: ");
        int codigoNota = s.nextInt();
        s.nextLine();

        if((nota = this.buscarNota(codigoNota)) == null){
            System.out.println("(!) Nota não encontrada!");
            return;
        }

        System.out.print("Digite o Código do Produto a ser adicionado: ");
        int codigoProduto = s.nextInt();
        s.nextLine();

        if((produto = this.buscarProduto(codigoProduto)) == null){
            System.out.println("(!) Produto não encontrado!");
            return;
        }

        if(produto.estoque == 0){
            System.out.println("(!) Produto sem estoque!");
            return;
        }

        System.out.print("Digite a quantidade do Produto requerida: ");
        int quantidade = s.nextInt();
        s.nextLine();

        if(quantidade > produto.estoque){
            System.out.println("(!) Estoque insuficiente!");
            return;
        }

        produto.estoque -= quantidade;

        ItemCompra item = new ItemCompra(produto, quantidade, produto.custo());

        nota.adicionarItem(item);

        System.out.println("Produto adicionado a nota com sucesso!");
    }

    void exibirRelatorio(){
        System.out.println("\n--- Relatório ---");

        System.out.println("Quantidade de Usuários Cadastrados: " + this.clientes.size());
        System.out.println("Quantidade de Produtos Cadastrados: " + this.produtos.size());
        System.out.println("Quantidade de Compras Realizadas: " + this.notas.size());

        double valorTotalCompras = 0;

        for(NotaFiscal n : this.notas){
            valorTotalCompras += n.custoTotal();
        }

        System.out.println("Valor total de todas as compras realizadas: R$" + valorTotalCompras);

        //Busca 5 produtos mais vendidos
        //Classe auxiliar local para guardar nome e quantidade do produto vendido
        class ItemVendido implements Comparable<ItemVendido> {
            String nome;
            int quantidade;

            public ItemVendido(String nome, int quantidade) {
                this.nome = nome;
                this.quantidade = quantidade;
            }

            public int compareTo(ItemVendido iv){
                if(quantidade > iv.quantidade)
                    return -1;
                else if(quantidade == iv.quantidade)
                    return nome.compareTo(iv.nome);
                else
                    return 1;
            }
        }

        //Inicializa um ArrayList para colocar os Itens Vendidos
        ArrayList<ItemVendido> itensVendidos = new ArrayList<>();
        int index = 0;

        //Busca por todos os Itens de todas as Notas Fiscais
        for(NotaFiscal n : this.notas){
            for(ItemCompra ic : n.itens){

                boolean incluso = false;

                //Verifica se o item já foi incluído no ArrayList de Itens Vendidos
                for(int i=0; i<itensVendidos.size(); i++) {
                    if(itensVendidos.get(i).nome.equals(ic.produto.nome)){
                        incluso = true;
                        index = i;
                        break;
                    }
                }

                //Se o item já está no ArrayList, incrementa a quantidade vendida
                if(incluso){
                    itensVendidos.get(index).quantidade += ic.quantidade;
                }
                else{ //Caso contrário, adiciona o item ao ArrayList
                    ItemVendido novoItem = new ItemVendido(ic.produto.nome, ic.quantidade);
                    itensVendidos.add(novoItem);
                }
            }
        }

        //Ordena os Itens Vendidos
        Collections.sort(itensVendidos);

        System.out.println("\nProdutos mais vendidos: ");
        if(itensVendidos.size() < 5){ //Se tiver menos que 5 produtos, imprime todos eles
            for(ItemVendido item : itensVendidos){
                System.out.println(item.nome);
            }
        }
        else { //Se tiver 5 ou mais produtos, imprime apenas os 5 mais vendidos
            for(int i=0; i<5; i++){
                System.out.println(itensVendidos.get(i).nome);
            }
        }

    }

    void exibirNotaFiscal(){
        Scanner s = new Scanner(System.in);

        System.out.print("Digite o código na nota requerida: ");
        int codigo = s.nextInt();
        s.nextLine();

        NotaFiscal nota = buscarNota(codigo);

        if(nota == null){
            System.out.println("(!) Nota Fiscal não encontrada.");
            return;
        }

        double valorTotalCompra = 0;

        System.out.println("\nCliente: " + nota.comprador.nome + " - CPF: " + nota.comprador.cpf);

        for(ItemCompra ic : nota.itens){
            System.out.println("Produto: " + ic.produto.nome + " - Quantidade: " + ic.quantidade + " - Preço por Unidade: " + ic.custoUnidade + " - Preço Total: " + ic.custoTotal() );
            valorTotalCompra += ic.custoTotal();
        }

        System.out.println("Valor total da compra: R$" + valorTotalCompra);
    }

    void listarItensCategoria(){
        Scanner s = new Scanner(System.in);

        System.out.print("Escreva a categoria de itens buscada: ");
        String categoria = s.nextLine();

        System.out.println("\nTodos os produtos da categoria '" + categoria + "':");
        System.out.printf("%-10s %-25s %-10s %-10s %-10s\n", "Código:", "Nome:", "Preço:", "Desconto:", "Estoque:");
        for(Produto p : produtos){
            if(p.categoria.equalsIgnoreCase(categoria)){
                System.out.printf("%-10s %-25s %-10s %-10s %-10s\n", p.codigo, p.nome, p.preco, p.desconto, p.estoque);
            }
        }
    }
}
