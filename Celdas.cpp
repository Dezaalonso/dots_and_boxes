#include "Celdas.h"

Celdas::Celdas(int num) {
    vector<vector<bool>> row;
    for(int i=0; i<num; i++)
        row.push_back(vector<bool>());
    for(int i=0; i<num; i++) {
        for (int j = 0; j < num+1; j++)
            row[i].push_back(false);
    }
    this->filas = row;

    vector<vector<bool>> col;
    for(int i=0; i<num+1; i++)
        col.push_back(vector<bool>());
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

void Celdas::lado_horizontal(int i, int j) {
    columnas[i][j] = true;
}

void Celdas::lado_vertical(int i, int j) {
    filas[i][j] = true;
}

bool Celdas::Comprobar_primer_lado(int i1, int j1) {
    if(columnas[i1][j1] == true && filas[i1][j1] == true && columnas[i1+1][j1] == true && filas[i1][j1+1] == true)
        return true;
    return false;
}

bool Celdas::Comprobar_segunda_columna(int i1, int j1) {
    if(columnas[i1-1][j1] == true && filas[i1-1][j1] == true && columnas[i1][j1] == true && filas[i1-1][j1+1] == true)
        return true;
    return false;
}

bool Celdas::Comprobar_segunda_fila(int i1, int j1) {
    if(columnas[i1][j1-1] == true && filas[i1][j1-1] == true && columnas[i1+1][j1-1] == true && filas[i1][j1] == true)
        return true;
    return false;
}







