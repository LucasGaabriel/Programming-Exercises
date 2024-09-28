package Aplicativo;

import Cadastro.Cliente;

import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.ArrayList;

public class Pedido {
    private final int codigo;
    private final Cliente cliente;
    private final String data;
    public ArrayList<Produto> produtos;
    public ArrayList<Integer> quantidadeProdutos;

    public Pedido(int codigo, Cliente cliente, String data){
        this.codigo = codigo;
        this.cliente = cliente;
        this.data = data;

        produtos = new ArrayList<>();
        quantidadeProdutos = new ArrayList<>();
    }
    public Pedido(int codigo, Cliente cliente){

        //Pega a data atual no formato dia/mes/ano horas:minutos:segundos
        this(codigo, cliente, DateTimeFormatter.ofPattern("dd/MM/yyyy HH:mm:ss").format(LocalDateTime.now()));

    }

    @Override
    public String toString() {
        return "Pedido{" +
                "Codigo=" + codigo +
                ", Cliente=" + cliente.getNome() +
                ", Data='" + data + '\'' +
                ", Quantidade de Produtos=" + quantidadeDeProdutos() +
                ", Valor Total=" + valorTotal() +
                '}';
    }

    public void imprimirDetalhesPedido(){
        System.out.println("\nCódigo=" + codigo + ", Cliente=" + cliente.getNome() + ", Data=" + data + "\n");

        for(int i=0; i<produtos.size(); i++){
            System.out.println("Produto=" + produtos.get(i).getNome() +
                                ", Quantidade=" + quantidadeProdutos.get(i) +
                                ", Valor Unitario=" + produtos.get(i).getPreco() +
                                ", Valor Total=" + (produtos.get(i).getPreco() * quantidadeProdutos.get(i)) );
        }

        System.out.println("\nValor total do pedido: R$" + this.valorTotal());
    }

    //Adiciona um produto ao pedido
    void addProduto(Produto p, int quantidade){
        this.produtos.add(p);
        this.quantidadeProdutos.add(quantidade);
    }

    //Retorna valor total do pedido
    public double valorTotal(){
        double valor = 0;

        for(int i=0; i<produtos.size(); i++){
            valor += (produtos.get(i).getPreco() * quantidadeProdutos.get(i));
        }

        return valor;
    }

    //Retorna a quantidade de produtos totais do pedido
    public int quantidadeDeProdutos(){
        int qtd = 0;

        for(int x : quantidadeProdutos){
            qtd += x;
        }

        return qtd;
    }

    public int getCodigo() {
        return codigo;
    }

    public Cliente getCliente() {
        return cliente;
    }

    public String getData() {
        return data;
    }
}
