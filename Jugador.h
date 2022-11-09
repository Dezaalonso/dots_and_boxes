#ifndef LABORATORIO_JUGADOR_H
#define LABORATORIO_JUGADOR_H

#include <iostream>
#include <vector>
using namespace std;

class Jugador {
    private:
        string nombre;
    public:
        Jugador() = default;
        Jugador(string nombre);
        string getNombre();

        ~Jugador() = default;
};


#endif
