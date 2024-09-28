public class ItemCompra {
    Produto produto;
    int quantidade;
    double custoUnidade;

    public ItemCompra(Produto produto, int quantidade, double custo){
        this.produto = produto;
        this.quantidade = quantidade;
        this.custoUnidade = custo;
    }

    public String toString() {
        return "ItemCompra{" +
                "Produto=" + produto +
                ", Quantidade=" + quantidade +
                ", CustoUnidade=" + custoUnidade +
                '}';
    }

    public double custoTotal(){
        return custoUnidade * quantidade;
    }
}
