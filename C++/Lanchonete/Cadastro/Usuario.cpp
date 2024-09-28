#include "Usuario.h"

Usuario::Usuario(std::string &nome, std::string &email, std::string &senha) {
    this->nome = nome;
    this->email = email;
    this->senha = senha;
}

Usuario::~Usuario() = default;

std::string Usuario::getNome() const {
    return nome;
}

std::string Usuario::getEmail() {
    return email;
}

std::string Usuario::getSenha() {
    return senha;
}

bool Usuario::verificarUsuario(std::string &email, std::string &senha) {
    return this->email == email && this->senha == senha;
}
