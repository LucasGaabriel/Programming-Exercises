#ifndef _ADMINISTRADOR_H_
#define _ADMINISTRADOR_H_

#include <string>
#include "Usuario.h"
#include "../Aplicativo/DeliveryApp.h"

class Administrador : public Usuario{

public:
    Administrador(std::string &nome, std::string &email, std::string &senha);

    ~Administrador();

    int exibirMenu(DeliveryApp* app) override;

    bool verificarOpcaoValida(int opcao) override;

    std::string type() override;
};

#endif //_ADMINISTRADOR_H_
