package Cadastro;

import Aplicativo.DeliveryApp;

import java.io.IOException;
import java.util.Scanner;

public class Administrador extends Usuario {

    public Administrador(String nome, String email, String senha){
        super(nome, email, senha);
    }

    @Override
    public int exibirMenu(DeliveryApp app) throws IOException {
        Scanner s = new Scanner(System.in);

        System.out.println("\n- Opções do Administrador: -");
        System.out.println("1 - Visualizar Relatório Quantitativo");
        System.out.println("2 - Visualizar Relatório de Vendas");
        System.out.println("3 - Visualizar Relatório de Desempenho");
        System.out.println("4 - Remover Cadastro");
        System.out.println("0 - Sair");
        System.out.print("Escolha uma opçao: ");
        int opcao = s.nextInt();

        switch(opcao){
            case 1 -> app.visualizarRelatorioQuantitativo();
            case 2 -> app.visualizarRelatorioDeVendas();
            case 3 -> app.visualizarRelatorioDeDesempenho();
            case 4 -> app.removerCadastro(this);
            case 0 -> System.out.println("\nUsuário Desconectado!");
            default -> System.out.println("\nOpção Inválida!");
        }

        return opcao;
    }

    @Override
    public boolean verificarOpcaoValida(int opcao) {
        return opcao != 0 && opcao != 4;
    }

}
