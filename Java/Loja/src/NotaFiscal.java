import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.ArrayList;

public class NotaFiscal {
    int codigo;
    Cliente comprador;
    String data;
    String metodoPagamento;
    ArrayList<ItemCompra> itens;

    public NotaFiscal(int codigo, Cliente comprador, String metodoPagamento) {
        this.codigo = codigo;
        this.comprador = comprador;
        this.metodoPagamento = metodoPagamento;
        this.itens = new ArrayList<>();

        //Pega a data atual no formato dia/mes/ano horas:minutos:segundos
        DateTimeFormatter data = DateTimeFormatter.ofPattern("dd/MM/yyyy HH:mm:ss");
        this.data = data.format(LocalDateTime.now());
    }

    public String toString() {
        return "NotaFiscal{" +
                "Código=" + codigo +
                ", Comprador=" + comprador +
                ", Data='" + data + '\'' +
                ", MétodoDePagamento='" + metodoPagamento + '\'' +
                ", Itens=" + itens +
                '}';
    }

    void adicionarItem(ItemCompra item){
        this.itens.add(item);
    }

    double custoTotal(){
        double valorTotal = 0;

        for(ItemCompra item: itens){
            valorTotal += item.custoTotal();
        }

        return valorTotal;
    }
}
