package Aplicativo;

public class Produto {
    private final int codigo; //Codigo do produto
    private final String nome; //Nome do produto
    private final double preco; //Preco do produto
    private int quantidadeVendas; //Quantidade do produto que foi vendido

    public Produto(int codigo, String nome, double preco, int quantidadeVendas){
        this.codigo = codigo;
        this.nome = nome;
        this.preco = preco;
        this.quantidadeVendas = quantidadeVendas;
    }

    public Produto(int codigo, String nome, double preco){
        this(codigo, nome, preco, 0);
    }

    public double faturamento(){
        return preco * quantidadeVendas;
    }

    @Override
    public String toString() {
        return "Produto{" +
                "codigo=" + codigo +
                ", nome='" + nome + '\'' +
                ", preco=" + preco +
                ", quantidadeVendas=" + quantidadeVendas +
                '}';
    }

    public int getCodigo() {
        return codigo;
    }

    public String getNome() {
        return nome;
    }

    public double getPreco() {
        return preco;
    }

    public int getQuantidadeVendas() {
        return quantidadeVendas;
    }

    public void addQuantidadeVendas(int quantidade){
        quantidadeVendas += quantidade;
    }
}
