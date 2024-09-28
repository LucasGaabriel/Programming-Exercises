package Aplicativo;

import Excecoes.CodigoIdentificadorReplicadoException;
import Excecoes.CodigoNaoEncontradoException;
import Excecoes.LoginInvalidoException;

import java.io.IOException;

public class Main {
    public static void main(String[] args) throws IOException {

        DeliveryApp app = new DeliveryApp();

        try {
        
            app.LeituraArquivos();
            app.executarApp();

        } catch (LoginInvalidoException e) {

            System.out.println("(!) Usuário não cadastrado. Inicie o programa novamente e cadastre-se!");

        } catch (CodigoNaoEncontradoException | CodigoIdentificadorReplicadoException e){

            System.out.println(e.getMessage());

        } catch (IOException e) {

            throw new RuntimeException(e);

        } finally {

            app.atualizarTodosOsArquivos();

        }
    }
}