#ifndef _PROPRIETARIO_H_
#define _PROPRIETARIO_H_

#include "Usuario.h"
#include "../Aplicativo/Lanchonete.h"
#include "../Aplicativo/DeliveryApp.h"

class Proprietario : public Usuario{

public:
    std::vector<Lanchonete *> *lanchonetes; //Lanchonetes que pertencem ao Proprietario

    Proprietario(std::string &nome, std::string &email, std::string &senha);

    ~Proprietario();

    Lanchonete *buscaLanchonetePorNome(std::string &nome) const;

    void listarLanchonetes() const;

    int exibirMenu(DeliveryApp* app) override;

    bool verificarOpcaoValida(int opcao) override;

    std::string type() override;
};

#endif //_PROPRIETARIO_H_
