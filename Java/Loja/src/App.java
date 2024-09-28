public class App {
    public static void main(String[] args){

        Loja loja = new Loja();

        int opcao;

        do {
            opcao = loja.Menu();
        } while (opcao != 0);

    }
}
