
#include "Menu.h"

void limpiar() {
    cout << "\033[2J\033[0;0H";
}


Menu::Menu() {
    cout << "---- JUEGO: DOTS AND BOXES ----\n";
    cout << "          Bienvenido...\n";
    cout << "============================\n";
    int n = input<int>("Tamanio del Tablero: ");
    tablero = new Tablero(n);
    auto nombre1 = input<string> ("Nombre 1: ");
    auto nombre2 = input<string> ("Nombre 2: ");
    jugador1 = new Jugador(nombre1);
    jugador2 = new Jugador(nombre2);
    tablero->setJugador(jugador1);
    tablero->setJugador(jugador2);
}

// Esta función lee una entrada de posición válida
void Menu::leer_entrada(int &i1, int &j1, int &i2, int &j2) {
    do{
        cout << "--- INTRODUCIR PUNTOS ---"<<endl;
        cout<<"Primer punto (i1 j1): "; cin >> i1 >> j1;
        cout<<"Segundo punto (i2 j2): "; cin >> i2 >> j2;
        tablero->ordena_coordenadas(i1, j1, i2, j2);}
    while (!tablero->verificar_posicion(i1, j1) || !tablero->verificar_posicion(i2, j2) ||
           !tablero->verificar_lado_valido(i1, j1, i2, j2) || !tablero->marcar_lado_vacio(i1, j1, i2, j2));
}

// FUNCION PRINCIPAL
void Menu::Jugar_juego() {
    int jugador = 0;
    while (true) {
        limpiar();
        int i1, j1, i2, j2;
        // Imprime el tablero
        tablero->imprimir_tablero();
        //esperar();

        // Leer una entrada del jugador y refica si es valida;
        cout<<"||| Turno de jugador "<<tablero->getVecJugadores()[jugador]->getNombre()<<" |||"<<endl;
        leer_entrada(i1, j1, i2, j2);

        // Establecer la posición de entrada con la marca, verifica si la posicion ingresada es vertical u horizontal
        tablero->vertical_o_horizontal(i1, j1, i2, j2);

        //// Establecer las cajas vecinas con la marca,ya que cajas vecinas comprueba y marca en la matriz tablero
        bool caja_completa = tablero->cajas_vecinas(i1, j1, i2, j2, jugador);

        // Comprobar si el estado del tablero está completo
        if (tablero->comprueba_lleno()) {
            limpiar();
            tablero->imprimir_tablero();
            //ANUNCIO FINAL
            int ju1 = tablero->getVecJugadores()[0]->getPuntos();
            int ju2 = tablero->getVecJugadores()[1]->getPuntos();
            if(ju2<ju1)
                cout << "Felicitaciones, Jugador " << tablero->getVecJugadores()[0]->getNombre() << " eres el ganador" << endl;
            else if(ju1<ju2)
                cout << "Felicitaciones, Jugador " << tablero->getVecJugadores()[1]->getNombre() << " eres el ganador" << endl;
            else if(ju1 ==ju2)
                cout << "Es un empate"<<endl;
            break;
        }
        if (!caja_completa) {
            //CAMBIO DE TURNO
            jugador = (jugador + 1) % 2;
        }
    }
}

void Menu::ejecutar() {
    tablero->iniciar_casillas();
    Jugar_juego();
    cout<<"Fin del juego :D";
}

Menu::~Menu() {
    delete tablero;
    delete jugador2;
    delete jugador1;
}