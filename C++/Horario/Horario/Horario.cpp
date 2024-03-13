// Nome: Lucas Gabriel de Oliveira Costa
// Disciplina: Programação III
// Exercício: Fundamentos de C++

#include <iostream>
#include "Horario.h"
#include "ValorInvalidoException.h"

using namespace std;

Horario::Horario(int horas, int minutos, int segundos){
    if(minutos < 0 || minutos >= 60 ){
        cout << "Minutos inválidos" << endl;
        throw ValorInvalidoException();
    }

    if(segundos < 0 || segundos >= 60 ){
        cout << "Segundos inválidos" << endl;
        throw ValorInvalidoException();
    }

    this->horas = horas;
    this->minutos = minutos;
    this->segundos = segundos;

    cout << "Construtor Chamado!" << endl;
}

Horario::Horario(const Horario &h){
    this->horas = h.horas;
    this->minutos = h.minutos;
    this->segundos = h.segundos;

    cout << "Construtor de Cópia Chamado!" << endl;
}

Horario::~Horario(){
    cout << "Destrutor Chamado!" << endl;
}

void Horario::setHoras(int h){
    this->horas = h;
}

void Horario::setMinutos(int m){
    if(m < 0 || m >= 60 )
        throw ValorInvalidoException();

    this->minutos = m;
}

void Horario::setSegundos(int s){
    if(s < 0 || s >= 60 )
        throw ValorInvalidoException();

    this->segundos = s;
}

int Horario::getHoras() const{
    return horas;
}

int Horario::getMinutos() const{
    return minutos;
}

int Horario::getSegundos() const{
    return segundos;
}

Horario Horario::operator+(const Horario &h) const {
    int newH = this->horas + h.horas;
    int newM = this->minutos + h.minutos;
    int newS = this->segundos + h.segundos;

    if(newS >= 60){
        newS -= 60;
        newM += 1;
    }

    if(newM >= 60){
        newM -= 60;
        newH += 1;
    }

    Horario somaHorario(newH, newM, newS);
    return somaHorario;
}

Horario Horario::operator-(const Horario &h) const {
    int newH = this->horas - h.horas;
    int newM = this->minutos - h.minutos;
    int newS = this->segundos - h.segundos;

    if(newS < 0){
        newS += 60;
        newM -= 1;
    }

    if(newM < 0){
        newM += 60;
        newH -= 1;
    }

    if(newH < 0){
        cout << "Horário resultante é negativo!" << endl;
    }

    Horario diferencaHorario(newH, newM, newS);
    return diferencaHorario;
}

Horario& Horario::operator=(const Horario &h){
    this->horas = h.horas;
    this->minutos = h.minutos;
    this->segundos = h.segundos;

    return *this;
}

ostream& operator<<(ostream &stream, const Horario &h){
    cout << "Horario -> " << h.horas << "h" << h.minutos << "m" << h.segundos << "s" << endl;
    return stream;
}
