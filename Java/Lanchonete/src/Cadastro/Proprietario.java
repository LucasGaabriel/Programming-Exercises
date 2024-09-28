package Cadastro;

import Aplicativo.DeliveryApp;
import Aplicativo.Lanchonete;
import Excecoes.CodigoIdentificadorReplicadoException;

import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;

public class Proprietario extends Usuario {

    public ArrayList<Lanchonete> lanchonetes; //Lanchonetes que pertencem ao Proprietario

    public Proprietario(String nome, String email, String senha){
        super(nome, email, senha);
        lanchonetes = new ArrayList<>();
    }

    public Lanchonete buscaLanchonetePorNome(String nome){
        for(Lanchonete l : lanchonetes){
            if(l.getNome().equals(nome))
                return l;
        }

        return null;
    }

    //Lista todas as lanchonetes do Proprietario
    public void listarLanchonetes(){
        System.out.println("\nLista de Lanchonetes");
        for(Lanchonete l : lanchonetes){
            System.out.println(l);
        }
    }

    @Override
    public int exibirMenu(DeliveryApp app) throws IOException, CodigoIdentificadorReplicadoException {
        Scanner s = new Scanner(System.in);

        System.out.println("\n- Opções do Proprietário: -");
        System.out.println("1 - Cadastrar Lanchonete");
        System.out.println("2 - Remover Lanchonete");
        System.out.println("3 - Cadastrar Lanche em uma Lanchonete");
        System.out.println("4 - Visualizar Lista de Pedidos de uma Lanchonete");
        System.out.println("5 - Visualizar detalhes de um Pedido de uma Lanchonete");
        System.out.println("6 - Remover Pedido de uma Lanchonete");
        System.out.println("7 - Remover Cadastro");
        System.out.println("0 - Sair");
        System.out.print("Escolha uma opçao: ");

        int opcao = s.nextInt();

        switch(opcao){
            case 1 -> app.cadastrarLanchonete(this);
            case 2 -> app.removerLanchonete(this);
            case 3 -> app.cadastrarLanche(this);
            case 4 -> app.visualizarListaDePedidosLanchonete(this);
            case 5 -> app.visualizarDetalhesDeUmPedidoLanchonete(this);
            case 6 -> app.removerPedidoDeUmaLanchonete(this);
            case 7 -> app.removerCadastro(this);
            case 0 -> System.out.println("\nUsuário Desconectado!");
            default -> System.out.println("\nOpção Inválida!");
        }

        return opcao;
    }

    @Override
    public boolean verificarOpcaoValida(int opcao) {
        return opcao != 0 && opcao != 7;
    }

}
