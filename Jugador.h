#ifndef LABORATORIO_JUGADOR_H
#define LABORATORIO_JUGADOR_H

#include <iostream>
#include <vector>
using namespace std;

class Jugador {
private:
    string nombre;
    int puntos = 0;
public:
    Jugador() = default;
    explicit Jugador(string nombre){
        this->nombre = nombre;
    }
    string getNombre() {
        return nombre;
    }
    void sumarPunto(){ puntos++; }
    int getPuntos() { return puntos; }

    ~Jugador() = default;
};


#endif