public class Produto {
    int codigo;
    String nome;
    double preco;
    String categoria;
    double desconto;
    int estoque;

    public Produto(int codigo, String nome, double preco, String categoria, double desconto, int estoque) {
        this.codigo = codigo;
        this.nome = nome;
        this.preco = preco;
        this.categoria = categoria;
        this.desconto = desconto;
        this.estoque = estoque;
    }

    public Produto(int codigo, String nome, double preco, int estoque) {
        this.codigo = codigo;
        this.nome = nome;
        this.preco = preco;
        this.estoque = estoque;

        this.desconto = 0;
        this.categoria = "Sem Categoria";
    }

    double custo(){
        return this.preco - (this.preco * desconto);
    }

    void atualizarEstoque(int qtd){
        this.estoque = qtd;
    }

    void atualizarDesconto(double desconto){
        this.desconto = desconto;
    }

    void atualizarPreco(double preco){
        this.preco = preco;
    }

    public String toString() {
        return "Produto{" +
                "Código=" + codigo +
                ", Nome='" + nome + '\'' +
                ", Preço=" + preco +
                ", Categoria='" + categoria + '\'' +
                ", Desconto=" + desconto +
                ", Estoque=" + estoque +
                '}';
    }
}
