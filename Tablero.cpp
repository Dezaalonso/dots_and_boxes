#include "Tablero.h"

Tablero::Tablero(int n) : celdas(n) {

    vector<vector<char>> Tab;
    for(int i=0; i<n-1; i++)
        Tab.push_back(vector<char>());
    for(int i=0; i<n-1; i++) {
        for (int j = 0; j < n-1; j++)
            Tab[i].push_back(' ');
    }
    this->tablero = Tab;

    int* puntos = new int [jugadores];
    this->cajas = puntos;
    this->size = n;
}

void Tablero::setJugador(Jugador* jugador) {
    vecJugadores.push_back(jugador);
}

void Tablero::imprimir_tablero() {
    for (int i = 0; i< jugadores; i++) {
        cout<<"Jugador "<< i+1<<": "<<vecJugadores[i]->getNombre()<<"  ";
        if (i<jugadores-1)
            cout << "vs  ";
    }
    cout<<endl;
    cout<<"--";
    for (int i=0; i<size-1;cout<<"------", i++);
    cout<<endl;
    for (int i = 0; i < size; i++) {
        cout << " + ";
        for (int j = 0; j < size; j++) {
            (celdas.getColumnas()[i][j])? cout << "---" : cout << "   ";
            if (j < size-1)
                cout << " + ";
        }
        cout<<endl;
        for (int j = 0; j < size+1; j++) {
            (celdas.getFilas()[i][j]) ? cout << " |  " : cout << "    ";
            if (i < size-1 && j < size-1)
                (tablero[i][j] != '+')? cout << tablero[i][j] : cout << " ";
            cout<<" ";
        }
        cout <<endl;
    }
    for (int i = 0; i< jugadores; i++)
        cout << "El jugador "<<vecJugadores[i]->getNombre()<<" tiene "<< cajas[i] << "\n";
    cout << "--";
    for (int i = 0; i < size-1; cout << "------", i++);
    cout <<endl;
}

bool Tablero::comprueba_lleno() {
    int sum = 0;
    for(int col = 0 ; col < jugadores ; col++)
        sum+=cajas[col];

    if(sum ==(size-1)*(size-1))
        return true;
    return false;
}

bool Tablero::verificar_columnas_llenas(int i, int j) {
    if(celdas.getColumnas()[i][j]==false)
        return true;
    return false;
}

bool Tablero::verificar_filas_llenas(int i, int j) {
    if(celdas.getFilas()[i][j] == false)
        return true;
    return false;
}

bool Tablero::marcar_lado_vacio(int i1, int j1, int i2, int j2) {
    if(i1==i2){
        if(j1 < j2 && verificar_columnas_llenas(i1,j1)) return true;
        else if(j2 < j1 && verificar_columnas_llenas(i2,j2)) return true;
        else return false;
    }
    else if(j1==j2) {
        if (i1 < i2 && verificar_filas_llenas(i1, j1)) return true;
        else if (i2 < i1 && verificar_filas_llenas(i2, j2)) return true;
        else return false;
    }
    return false;
}

bool Tablero::verificar_posicion(int i, int j) {
    if((0<=i && i<size) && (0<=j && j<size)) {
        return true;
    }
    return false;
}

bool Tablero::verificar_lado_valido(int i1, int j1, int i2, int j2) {
    if((i1 == i2 && abs(j1-j2)==1) || (j1 == j2 && abs(i1-i2)==1))
        return true;
    return false;
}

void Tablero::set_side(int i1, int j1, int i2, int j2) {
    if(i1 == i2)
        celdas.lado_horizontal(i1,j1);
    else if(j1 == j2)
        celdas.lado_vertical(i1,j1);
}

bool Tablero::cajas_vecinas(int i1, int j1, int i2, int j2, int jugador) {
    bool casillas = false;

    if (i1 == i2){
        if (i1 == 0 && celdas.Comprobar_primer_lado(i1,j1)){
            tablero[i1][j1] = nombres[jugador];
            cajas[jugador] += 1;
            return true;
        }
        else if( i1 == size-1 && celdas.Comprobar_segunda_columna(i1,j1) ){
            tablero[i1-1][j1] = nombres[jugador];
            cajas[jugador] += 1;
            return true;
        }
        else{
            if (celdas.Comprobar_primer_lado(i1,j1)){
                tablero[i1][j1] = nombres[jugador];
                cajas[jugador] += 1;
                casillas = true;
            }
            if (celdas.Comprobar_segunda_columna(i1,j1)){
                tablero[i1-1][j1] = nombres[jugador];
                cajas[jugador] += 1;
                casillas = true;
            }
        }
        return casillas;
    }

    else if(j1 == j2){
        if(j1 == 0 && celdas.Comprobar_primer_lado(i1,j1)){
            tablero[i1][j1] = nombres[jugador];
            cajas[jugador] += 1;
            return true;
        }
        else if(j1 == size-1 && celdas.Comprobar_segunda_fila(i1,j1)){
            tablero[i1][j1-1] = nombres[jugador];
            cajas[jugador] += 1;
            return true;
        }
        else{
            if (celdas.Comprobar_primer_lado(i1,j1)){
                tablero[i1][j1] = nombres[jugador];
                cajas[jugador] += 1;
                casillas = true;
            }
            if (celdas.Comprobar_segunda_fila(i1,j1)){
                tablero[i1][j1-1] = nombres[jugador];
                cajas[jugador] += 1;
                casillas = true;
            }
        }
        return casillas;
    }
    return false; //Creo que generará algún problema
}

void Tablero::puntos_de_jugadores(int &i1, int &j1, int &i2, int &j2) {

    if(i1 == i2){
        if(j2<j1){
            int temp = j1;
            j1 = j2;
            j2 = temp;
        }
    }
    else if(j1 == j2){
        if(i2<i1){
            int temp = i1;
            i1 = i2;
            i2 = temp;
        }
    }
}

void Tablero::limpiar_casillas() {

    for(int col = 0 ; col < jugadores ; col++){
        cajas[col] = 0;
    }

    for(int i = 0 ; i < size-1 ; i++){
        for(int j = 0 ; j < size-1 ; j++){
            tablero[i][j] = '+';
        }
    }

    for(int i = 0 ; i < size+1 ; i++){
        for(int j = 0 ; j < size ; j++){
            celdas.getColumnas()[i][j] = false;
        }
    }

    for(int i = 0 ; i < size ; i++){
        for(int j = 0 ; j < size + 1 ; j++){
            celdas.getFilas()[i][j] = false;
        }
    }
}

int Tablero::getNroJugadores() {
    return jugadores;
}

int* Tablero::getCajas() {
    return cajas;
}

vector<Jugador*> Tablero::getVecJugadores(){
    return vecJugadores;
}

Tablero::~Tablero() {
    delete cajas;
}