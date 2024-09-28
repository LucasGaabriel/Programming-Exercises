package Cadastro;

import Aplicativo.DeliveryApp;
import Excecoes.CodigoIdentificadorReplicadoException;
import Excecoes.CodigoNaoEncontradoException;

import java.io.IOException;

public abstract class Usuario {
    private final String nome;
    private final String email;
    private final String senha;

    public Usuario(String nome, String email, String senha){
        this.nome = nome;
        this.email = email;
        this.senha = senha;
    }

    public String getNome() {
        return nome;
    }

    public String getEmail() {
        return email;
    }

    public String getSenha() {
        return senha;
    }

    public boolean verificarUsuario(String email, String senha){
        return this.email.equals(email) && this.senha.equals(senha);
    }

    public abstract int exibirMenu(DeliveryApp app) throws CodigoNaoEncontradoException,
                                                            IOException,
                                                            CodigoIdentificadorReplicadoException;

    //Retorna 'false' em todas as opções que devem redirecionar o usuario para a tela de Login/Cadastro
    public abstract boolean verificarOpcaoValida(int opcao);
}
