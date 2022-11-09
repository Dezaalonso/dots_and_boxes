#ifndef LABORATORIO_TABLERO_H
#define LABORATORIO_TABLERO_H

#include "Jugador.h"
#include "Celdas.h"

class Tablero {
    private:
        const int jugadores = 2;
        vector<Jugador*> vecJugadores;
        vector<char> nombres = {'A','B'};
        int size;
        vector<vector<char>> tablero;
        Celdas celdas;
        int* cajas;

    public:
        Tablero() = default;
        Tablero(int n);

        void puntos_de_jugadores(int& , int&, int&, int&);
        bool verificar_posicion(int, int);
        bool verificar_lado_valido(int, int, int, int);
        bool marcar_lado_vacio(int, int, int, int);
        void imprimir_tablero();
        void setJugador(Jugador* );
        bool comprueba_lleno();
        bool verificar_columnas_llenas(int, int);
        bool verificar_filas_llenas(int, int);
        void set_side(int, int, int, int);
        bool cajas_vecinas(int, int, int, int, int);
        void limpiar_casillas();

        int getNroJugadores();
        int* getCajas();
        vector<Jugador *> getVecJugadores();

        ~Tablero();
};


#endif
