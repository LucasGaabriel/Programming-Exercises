// Nome: Lucas Gabriel de Oliveira Costa
// Disciplina: Programação III
// Exercício: Fundamentos de C++

#include <iostream>
#include "Horario/Horario.h"

using namespace std;

void funcao_f(Horario h){
    cout << "funcao_f chamada" << endl;
}

void funcao_g(Horario &h){
    cout << "funcao_g chamada" << endl;
}

void funcao_h(Horario *h){
    cout << "funcao_h chamada" << endl;
}

/*                    EXERCICIO 2
int main(){

    Horario* h1 = new Horario(19, 15, 25);

    cout << "h1: " << h1->horas << "h" << h1->minutos << "m" << h1->segundos << "s\n";

    delete h1;

    return 0;
}
*/

/*                    EXERCICIO 4
int main(){

    Horario h1(10, 4, 55);
    Horario h2(2, 12, 23);
    Horario h3(h1);
    Horario *h4 = new Horario(h2);
    Horario h5 = h1;
    h3 = h1;

    funcao_f(h1);
    funcao_g(h1);
    funcao_h(&h1);
    funcao_h(h4);

    delete h4;

    return 0;
}
*/

/*                        EXERCICIO 5
int main(){
    int horas, minutos, segundos;

    cout << "Horas: ";
    cin >> horas;

    cout << "Minutos: ";
    cin >> minutos;

    cout << "Segundos: ";
    cin >> segundos;

    Horario *h1 = new Horario(horas, minutos, segundos);

    cout << "H1: " << h1->horas << "h" << h1->minutos << "m" << h1->segundos << "s" << endl;

    delete h1;

    return 0;
}
*/

/*                                 EXERCICIO 6
int main(){
    int horas, minutos, segundos;

    cout << "Horas: ";
    cin >> horas;

    cout << "Minutos: ";
    cin >> minutos;

    cout << "Segundos: ";
    cin >> segundos;

    Horario* h = new Horario(horas, minutos, segundos);

    cout << "H: " << h->getHoras() << "h" << h->getMinutos() << "m" << h->getSegundos() << "s" << endl;

    cout << "Novas horas: ";
    cin >> horas;

    h->setHoras(horas);

    cout << "Novos minutos: ";
    cin >> minutos;

    h->setMinutos(minutos);

    cout << "Novos segundos: ";
    cin >> segundos;

    h->setSegundos(segundos);

    cout << "H: " << h->getHoras() << "h" << h->getMinutos() << "m" << h->getSegundos() << "s" << endl;

    return 0;
}
*/

int main(){
    Horario h1(5, 25, 15);
    Horario h2(14, 35, 15);

    Horario h3 = h1+h2;

    cout << "Soma: " << h3 << endl;

    h3 = h1-h2;

    cout << "Subtração: " << h3 << endl;

    return 0;
}