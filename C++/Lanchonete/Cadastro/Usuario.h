#ifndef _USUARIO_H_
#define _USUARIO_H_

#include "../Aplicativo/DeliveryApp.h"
#include <string>

class Usuario {

private:
    std::string nome;
    std::string email;
    std::string senha;

public:
    Usuario(std::string &nome, std::string &email, std::string &senha);

    ~Usuario();

    std::string getNome() const;

    std::string getEmail();

    std::string getSenha();

    bool verificarUsuario(std::string &email, std::string &senha);

    virtual int exibirMenu(DeliveryApp* app) = 0;

    virtual bool verificarOpcaoValida(int opcao) = 0;

    virtual std::string type() = 0;
};

#endif //_USUARIO_H_
