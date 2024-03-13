// Nome: Lucas Gabriel de Oliveira Costa
// Disciplina: Programação III
// Exercício: Fundamentos de C++

#ifndef HORARIO_H
#define HORARIO_H

#include <iostream>

using namespace std;

class Horario {

public:
    int horas;
    int minutos;
    int segundos;

    Horario(int horas, int minutos, int segundos);
    Horario(const Horario &h);
    ~Horario();

    void setHoras(int h);
    void setMinutos(int m);
    void setSegundos(int s);
    int getHoras() const;
    int getMinutos() const;
    int getSegundos() const;

    Horario operator+(const Horario &h) const;
    Horario operator-(const Horario &h) const;
    Horario& operator=(const Horario &h);
    friend ostream& operator<<(ostream &stream, const Horario &h);
};

ostream& operator<<(ostream &stream, const Horario &h);

#endif //HORARIO_H