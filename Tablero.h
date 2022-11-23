#ifndef LABORATORIO_TABLERO_H
#define LABORATORIO_TABLERO_H

#include "Jugador.h"
#include "Celdas.h"

class Tablero {
private:
    const int jugadores = 2;
    vector<Jugador*> vecJugadores;
    vector<char> nombres = {'A','B'}; //PARA MARCAR LAS CAJAS CUANDO SE COMPLETAN LOS 4 LADOS
    int size{};
    vector<vector<char>> tablero;
    Celdas celdas;

public:
    Tablero() = default;
    explicit Tablero(int n);

    void imprimir_tablero();//
    void setJugador(Jugador* );
    bool comprueba_lleno();//
    bool verificar_columnas_vacias(int, int);//
    bool verificar_filas_vacias(int, int);//
    void vertical_o_horizontal(int, int, int, int);//
    bool cajas_vecinas(int, int, int, int, int);//
    void iniciar_casillas();//
    void ordena_coordenadas(int& , int&, int&, int&);//
    bool verificar_posicion(int, int);//
    bool verificar_lado_valido(int, int, int, int);//
    bool marcar_lado_vacio(int, int, int, int);//

    int getNroJugadores() const;//
    vector<Jugador *> getVecJugadores();
    ~Tablero() = default;
};


#endif
