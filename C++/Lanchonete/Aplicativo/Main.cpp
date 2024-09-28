#include <iostream>
#include "DeliveryApp.h"
#include "../Excecoes/LoginInvalidoException.h"
#include "../Excecoes/CodigoNaoEncontradoException.h"
#include "../Excecoes/CodigoIdentificadorReplicadoException.h"

using namespace std;

int main() {
    DeliveryApp *app = new DeliveryApp();

    try {

        app->LeituraArquivos();
        app->executarApp();

    } catch (LoginInvalidoException&) {

        cerr << "(!) Usuário não cadastrado. Inicie o programa novamente e cadastre-se!" << endl;

    } catch (CodigoNaoEncontradoException &e){

        cerr << e.what() << endl;

    } catch (CodigoIdentificadorReplicadoException &e) {

        cerr << e.what() << endl;

    }

    app->atualizarTodosOsArquivos();

    delete app;

    return 0;
}
