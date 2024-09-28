package Aplicativo;

import Excecoes.CodigoIdentificadorReplicadoException;

import java.util.ArrayList;
import java.util.Scanner;

public class Lanchonete {
    private final int identificador; //Codigo identificador da Lanchonete
    private final String nome; //Nome da Lanchonete
    private final String categoria; //Categoria de Produtos da Lanchonete
    private final String endereco; //Endereço da Lanchonete
    private final double desconto_retirada; //Desconto de retirada na Lanchonete
    private final double desconto_consumoLocal; //Desconto de consumo na Lanchonete
    private double preco_medio; //Preço medio dos produtos da Lanchonete
    private double somaPontuacao; //Somatorio de todas as pontuações
    private int quantidadePontuacao; //Quantidade de vezes que foi atribuida uma pontuação
    public ArrayList<Produto> produtos; //Produtos da Lanchonete
    public ArrayList<Pedido> pedidos; //Pedidos feitos na Lanchonete

    public Lanchonete(int identificador, String nome, String categoria, String endereco,
                      double desconto_retirada, double desconto_consumoLocal, double preco_medio,
                      double somaPontuacao, int quantidadePontuacao) {
        this.identificador = identificador;
        this.nome = nome;
        this.categoria = categoria;
        this.endereco = endereco;
        this.desconto_retirada = desconto_retirada;
        this.desconto_consumoLocal = desconto_consumoLocal;
        this.preco_medio = preco_medio;
        this.somaPontuacao = somaPontuacao;
        this.quantidadePontuacao = quantidadePontuacao;
        this.produtos = new ArrayList<>();
        this.pedidos = new ArrayList<>();
    }

    public Lanchonete(int identificador, String nome, String categoria, String endereco,
                      double desconto_retirada, double desconto_consumoLocal){
        this(identificador, nome, categoria, endereco,
                desconto_retirada, desconto_consumoLocal, 0, 0, 0);
    }

    public Lanchonete(int identificador, String nome, String categoria){
        this(identificador, nome, categoria, "", -1, -1);
    }

    @Override
    public String toString() {
        if(this.desconto_retirada == -1) {
            return "Lanchonete{" +
                    "Identificador=" + identificador +
                    ", Nome='" + nome + '\'' +
                    ", Categoria='" + categoria + '\'' +
                    ", Preço Médio='" + preco_medio + '\'' +
                    ", Pontuação=" + this.pontuacao() +
                    ", Número de Vendas=" + this.numeroDeVendas() +
                    ", Produtos=" + produtos +
                    ", Pedidos=" + pedidos +
                    '}';
        }
        else {
            return "Lanchonete{" +
                    "Identificador=" + identificador +
                    ", Nome='" + nome + '\'' +
                    ", Categoria='" + categoria + '\'' +
                    ", Endereco='" + endereco + '\'' +
                    ", Desconto de Retirada=" + desconto_retirada +
                    ", Desconto Consumo no Local=" + desconto_consumoLocal +
                    ", Preço Médio='" + preco_medio + '\'' +
                    ", Pontuação=" + this.pontuacao() +
                    ", Número de Vendas=" + this.numeroDeVendas() +
                    ", Produtos=" + produtos +
                    ", Pedidos=" + pedidos +
                    '}';
        }
    }

    public double pontuacao(){
        if(quantidadePontuacao == 0)
            return 0;

        return somaPontuacao / quantidadePontuacao;
    }

    //Retorna o valor total de todos os pedidos (Faturamento total da lanchonete)
    public double faturamento(){
        double faturamento = 0;

        for(Pedido p : this.pedidos){
            faturamento += p.valorTotal();
        }

        return faturamento;
    }

    public int numeroDeVendas(){
        int vendas = 0;

        for(Produto p : this.produtos){
            vendas += p.getQuantidadeVendas();
        }

        return vendas;
    }

    public void atribuirPontuacao(double pontos){
        if(pontos < 0 || pontos > 5){
            System.out.println("Valor de pontuação deve ser entre 0 e 5");
            return;
        }

        somaPontuacao += pontos;
        quantidadePontuacao++;
    }

    public Produto buscaProdutoPorCodigo(int codigo){
        for(Produto p : this.produtos){
            if(p.getCodigo() == codigo)
                return p;
        }

        return null;
    }

    public void atualizarPrecoMedio(){
        double precoTotal = 0;

        for(Produto p : this.produtos){
            precoTotal += p.getPreco();
        }

        this.preco_medio = precoTotal/this.produtos.size();
    }

    public void cadastrarProduto() throws CodigoIdentificadorReplicadoException {
        Scanner s = new Scanner(System.in);

        System.out.println("\n- Cadastro Novo Produto -");

        int codigo;

        System.out.print("Código: ");
        codigo = s.nextInt();
        s.nextLine(); //Capturar o '\n'

        //Se já houver um produto com o mesmo código, lança uma exceção
        if(buscaProdutoPorCodigo(codigo) != null)
            throw new CodigoIdentificadorReplicadoException("Código do Produto já utilizado!\n");

        System.out.print("Nome: ");
        String nome = s.nextLine();

        System.out.print("Preço: ");
        double preco = s.nextDouble();

        Produto p = new Produto(codigo, nome, preco);

        produtos.add(p);
    }

    public void addPedido(Pedido p){
        pedidos.add(p);
    }

    public void listarPedidos(){
        System.out.println("\nLista de Pedidos");
        for(Pedido p : pedidos){
            System.out.println(p);
        }
    }
    public String getNome() {
        return nome;
    }

    public String getCategoria() {
        return categoria;
    }

    public double getPreco_medio() {
        return preco_medio;
    }

    public int getIdentificador() {
        return identificador;
    }

    public double getDesconto_retirada() {
        return desconto_retirada;
    }

    public double getDesconto_consumoLocal() {
        return desconto_consumoLocal;
    }

    public double getSomaPontuacao() {
        return somaPontuacao;
    }

    public int getQuantidadePontuacao() {
        return quantidadePontuacao;
    }

    public String getEndereco() {
        return endereco;
    }
}
