
// "PROYECTO 2.0/main.cpp" "PROYECTO 2.0/Jugador.h" "PROYECTO 2.0/Jugador.cpp" "PROYECTO 2.0/Tablero.h" "PROYECTO 2.0/Tablero.cpp" PROYECTO 2.0/Celdas.cpp PROYECTO 2.0/Celdas.h

#include "Menu.h"

int main() {
    Menu* menu = new Menu();
    menu->ejecutar();
    delete menu;
    return 0;
}