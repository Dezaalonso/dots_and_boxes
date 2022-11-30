#include "Celdas.h"

Celdas::Celdas(int num) {

    //MATRIZ BULEANA DE FILAS
    vector<vector<bool>> row;
    for(int i=0; i<num; i++)
        row.emplace_back();
    for(int i=0; i<num; i++) {
        for (int j = 0; j < num+1; j++)
            row[i].push_back(false);
    }
    this->filas = row;

    //MATRIZ BULEANA DE COLUMNAS
    vector<vector<bool>> col;
    for(int i=0; i<num+1; i++)
        col.emplace_back();
    for(int i=0; i<num+1; i++) {
        for (int j = 0; j < num; j++)
            col[i].push_back(false);
    }
    this->columnas = col;
    this->size = num;
}

vector<vector<bool>> Celdas::getFilas() {
    return filas;
}

vector<vector<bool>> Celdas::getColumnas() {
    return columnas;
}

// Esta función establece un lado horizontal
void Celdas::lado_horizontal(int i, int j) {
    columnas[i][j] = true;
}

// Esta función establece un lado vertical
void Celdas::lado_vertical(int i, int j) {
    filas[i][j] = true;
}

// Esta función verifica y establece la casilla completada
bool Celdas::Comprobar_primer_lado(int i1, int j1) {
    if(columnas[i1][j1] && filas[i1][j1] && columnas[i1 + 1][j1] && filas[i1][j1 + 1])
        return true;
    return false;
}

// Esta función verifica y establece la casilla completada
bool Celdas::Comprobar_segunda_columna(int i1, int j1) {
    if(i1==0) return true;
    if (columnas[i1-1][j1] && filas[i1-1][j1] && columnas[i1][j1] && filas[i1-1][j1+1])
        return true;
    else return false;
}

// Esta función verifica y establece la casilla completada
bool Celdas::Comprobar_segunda_fila(int i1, int j1) {
    if(j1==0) return true;
    if(columnas[i1][j1-1] && filas[i1][j1-1] && columnas[i1+1][j1-1] && filas[i1][j1])
        return true;
    return false;
}


