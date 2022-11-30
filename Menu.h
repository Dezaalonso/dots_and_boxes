
#ifndef LABORATORIO_MENU_H
#define LABORATORIO_MENU_H

#include "Jugador.h"
#include "Tablero.h"
#include <algorithm>

template <typename T>
T input(string label) {
    T value;
    cout << label;
    cin >> value;
    cin.clear();
    //cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    return value;
}

class Menu {
private:
    Tablero* tablero;
    Jugador* jugador1;
    Jugador* jugador2;
    void leer_entrada(int &i1, int &j1, int &i2, int &j2);
    void Jugar_juego();
public:
    Menu();
    void ejecutar();
    ~Menu();
};


#endif
