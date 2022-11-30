#ifndef LABORATORIO_CELDAS_H
#define LABORATORIO_CELDAS_H

#include <vector>
using namespace std;

class Celdas {
private:
    int size{};
    vector<vector<bool>> filas;
    vector<vector<bool>> columnas;
public:
    Celdas() = default;
    explicit Celdas(int);
    vector<vector<bool>> getFilas();
    vector<vector<bool>> getColumnas();

    void lado_horizontal(int, int);
    void lado_vertical(int, int);
    bool Comprobar_primer_lado(int, int);
    bool Comprobar_segunda_columna(int, int);
    bool Comprobar_segunda_fila(int, int);
    int getSize(){ return size; }

    ~Celdas() = default;
};


#endif
