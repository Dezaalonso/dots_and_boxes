
// "PROYECTO/main.cpp" "PROYECTO/Jugador.h" "PROYECTO/Jugador.cpp" "PROYECTO/Tablero.h" "PROYECTO/Tablero.cpp" PROYECTO/Celdas.cpp PROYECTO/Celdas.h

#include "Jugador.h"
#include "Tablero.h"

void leer_entrada(int &i1, int &j1, int &i2, int &j2, Tablero* tablero) {
    cout << "--- INTRODUCIR PUNTOS ---"<<endl;
    cout<<"Primer punto (i1 j1): ";cin >> i1 >> j1;
    cout<<"Segundo punto (i2 j2): ";cin >> i2 >> j2;
    tablero->puntos_de_jugadores(i1, j1, i2, j2);
    while (!tablero->verificar_posicion(i1, j1) || !tablero->verificar_posicion(i2, j2) ||
        !tablero->verificar_lado_valido(i1, j1, i2, j2) || !tablero->marcar_lado_vacio(i1, j1, i2, j2)) {
        cout<<endl;
        cout << "--- INTRODUCIR PUNTOS VALIDOS ---"<<endl;
        cout<<"Primer punto (i1 j1): ";cin >> i1 >> j1;
        cout<<"Segundo punto (i2 j2): ";cin >> i2 >> j2;
        tablero->puntos_de_jugadores(i1, j1, i2, j2);
    }
}

//FUNCION PRINCIPAL
void Jugar_juego(Tablero* tablero) {
    cout << "---- JUEGO: DOTS AND BOXES ----\n";
    cout << "          Bienvenido...\n";
    cout << "============================\n";
    int jugador = 0;
    while (true) {
        int i1, j1, i2, j2;
        tablero->imprimir_tablero();
        cout<<"||| Turno de jugador "<<tablero->getVecJugadores()[jugador]->getNombre()<<" |||"<<endl;
        leer_entrada(i1, j1, i2, j2, tablero);
        tablero->set_side(i1, j1, i2, j2);
        bool box_complete = tablero->cajas_vecinas(i1, j1, i2, j2, jugador);
        if (tablero->comprueba_lleno()) {

            tablero->imprimir_tablero();

            //ANUNCIO FINAL
            int max_count_boxes = *max_element(tablero->getCajas(), tablero->getCajas()+tablero->getNroJugadores());
            if (count(tablero->getCajas(), tablero->getCajas()+tablero->getNroJugadores(), max_count_boxes) == 1) {
                int idx_max_player = find(tablero->getCajas(), tablero->getCajas()+tablero->getNroJugadores(), max_count_boxes) - tablero->getCajas();
                cout << "Felicitaciones, Jugador " << tablero->getVecJugadores()[idx_max_player]->getNombre() << " eres el ganador"<<endl;
            }
            else
                cout << "Es un empate"<<endl;
            break;
        }

        if (!box_complete) {
            //CAMBIO DE TURNO
            jugador = (jugador + 1) % tablero->getNroJugadores();
        }
    }
}

int main() {
    int n;
    cout<<"Tamanio del Tablero: "; cin>>n;
    Tablero* tablero1 = new Tablero(n);
    string nombre1, nombre2;
    cout<<"Nombre 1: ";cin>>nombre1;
    cout<<"Nombre 2: ";cin>>nombre2;
    Jugador* jugador1 = new Jugador(nombre1);
    Jugador* jugador2 = new Jugador(nombre2);
    tablero1->setJugador(jugador1);
    tablero1->setJugador(jugador2);

    while (true) {
        tablero1->limpiar_casillas();
        Jugar_juego(tablero1);
        char c;
        cout << "JUGAR DE NUEVO [Y/N] ";
        cin >> c;
        if (c != 'y' && c != 'Y')
            break;
    }

    delete tablero1;
    delete jugador2;
    delete jugador1;

    return 0;
}