package Cadastro;

import Aplicativo.DeliveryApp;
import Excecoes.CodigoNaoEncontradoException;

import java.io.IOException;
import java.util.Scanner;

public class Cliente extends Usuario {
    private final String cpf; //CPF do Usuario
    private int quantidadeCompras; //Quantidade de itens comprados
    private double quantidadeGastos; //Quantidade gasta em dinheiro

    public Cliente(String nome, String email, String senha, String cpf, int quantidadeCompras, double quantidadeGastos) {
        super(nome, email, senha);
        this.cpf = cpf;
        this.quantidadeCompras = quantidadeCompras;
        this.quantidadeGastos = quantidadeGastos;
    }

    @Override
    public String toString() {
        return "Cliente{" +
                "Nome=" + this.getNome() +
                ", CPF='" + cpf + '\'' +
                ", Quantidade de Compras=" + quantidadeCompras +
                ", Quantidade de Gastos=" + quantidadeGastos +
                '}';
    }

    public Cliente (String nome, String email, String senha, String cpf){
        this(nome, email, senha, cpf, 0, 0);
    }

    public void addQuantidadeCompras(int quantidade){
        quantidadeCompras += quantidade;
    }

    public void addQuantidadeGastos(double quantidade){
        quantidadeGastos += quantidade;
    }

    public int getQuantidadeCompras(){
        return quantidadeCompras;
    }

    public double getQuantidadeGastos(){
        return quantidadeGastos;
    }

    public String getCPF() {
        return cpf;
    }

    @Override
    public int exibirMenu(DeliveryApp app) throws CodigoNaoEncontradoException, IOException {
        Scanner s = new Scanner(System.in);

        System.out.println("\n- Opções do Cliente: -");
        System.out.println("1 - Listar Lanchonetes ordenadas pela pontuação");
        System.out.println("2 - Listar Lanchonetes de uma categoria ordenada pela pontuação");
        System.out.println("3 - Listar Lanchonetes ordenadas pelo preço médio dos produtos");
        System.out.println("4 - Listar Lanchonetes ordenadas pelo número de vendas");
        System.out.println("5 - Visualizar Lanches de uma Lanchonete");
        System.out.println("6 - Buscar Lanches por Nome");
        System.out.println("7 - Fazer um Pedido");
        System.out.println("8 - Atribuir Nota para uma Lanchonete");
        System.out.println("9 - Remover Cadastro");
        System.out.println("0 - Sair");
        System.out.print("Escolha uma opçao: ");

        int opcao = s.nextInt();

        switch(opcao){
            case 1 -> app.listarLanchonetesPorPontuacao();
            case 2 -> app.listarLanchonetesCategoriaPorPontuacao();
            case 3 -> app.listarLanchonetesPorPrecoMedio();
            case 4 -> app.listarLanchonetesPorNumeroDeVendas();
            case 5 -> app.visualizarLanchesDeUmaLanchonete();
            case 6 -> app.buscarLanchesPorNome();
            case 7 -> app.fazerPedido(this);
            case 8 -> app.atribuirNotaLanchonete();
            case 9 -> app.removerCadastro(this);
            case 0 -> System.out.println("\nUsuário Desconectado!");
            default -> System.out.println("\nOpção Inválida!");
        }

        return opcao;
    }

    @Override
    public boolean verificarOpcaoValida(int opcao) {
        return opcao != 0 && opcao != 9;
    }

}
