#include "Tablero.h"

Tablero::Tablero(int n) : celdas(n) {

    vector<vector<char>> Tab; //TABLERO QUE SE MARCA CUANDO SE COMPLETAN LOS 4 LADOS DE UNA CAJA

    for(int i=0; i<n-1; i++)
        Tab.emplace_back();
    for(int i=0; i<n-1; i++) {
        for (int j = 0; j < n-1; j++)
            Tab[i].push_back(' ');
    }
    this->tablero = Tab;
    this->size = n;
}

void Tablero::setJugador(Jugador* jugador) {
    vecJugadores.push_back(jugador);
}

// Esta función imprime la cuadrícula de Dots-and-Boxes a medida que avanza el juego
void Tablero::imprimir_tablero() {
    for (int i = 0; i< jugadores; i++) {
        cout<<"Jugador "<< char(i+65)<<": "<<vecJugadores[i]->getNombre()<<"  ";
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
        //cout << "El jugador " << vecJugadores[i]->getNombre() << " tiene " << cajas[i] << "\n";
        cout << "El jugador " << vecJugadores[i]->getNombre() << " tiene " << vecJugadores[i]->getPuntos() << "\n";

    cout << "--";
    for (int i = 0; i < size-1; cout << "------", i++);
    cout <<endl;
}

// Esta función comprueba si el tablero está llena o no
bool Tablero::comprueba_lleno() {
    int sum = 0;
    for(int col = 0 ; col < jugadores ; col++)
        sum += vecJugadores[col]->getPuntos();
    //sum+=cajas[col];

    if(sum ==(size-1)*(size-1))
        return true;
    return false;
}

// Esta función comprueba si el punto dado en la matriz columnas está disponible o no
bool Tablero::verificar_columnas_vacias(int i, int j) {
    if(!celdas.getColumnas()[i][j])
        return true;
    return false;
}

// Esta función comprueba si el punto dado en la matriz filas está disponible o no
bool Tablero::verificar_filas_vacias(int i, int j) {
    if(!celdas.getFilas()[i][j])
        return true;
    return false;
}

// Esta función verifica si el lado dado está vacío o no
bool Tablero::marcar_lado_vacio(int i1, int j1, int i2, int j2) {
    if(i1==i2){
        if(j1 < j2 && verificar_columnas_vacias(i1, j1)) return true;
        else if(j2 < j1 && verificar_columnas_vacias(i2, j2)) return true;
        else return false;
    }
    else if(j1==j2) {
        if (i1 < i2 && verificar_filas_vacias(i1, j1)) return true;
        else if (i2 < i1 && verificar_filas_vacias(i2, j2)) return true;
        else return false;
    }
    return false;
}

// Esta función verifica si la posición dada es válida en el tablero o no; es decir si está dentro de los límites del tablero
bool Tablero::verificar_posicion(int i, int j) {
    if((0<=i && i<size) && (0<=j && j<size)) return true;
    return false;
}

// Esta función verifica si el lado dado es válido o no (La diferencia entre puntos solo debe ser de 1)
bool Tablero::verificar_lado_valido(int i1, int j1, int i2, int j2) {
    if((i1 == i2 && abs(j1-j2)==1) || (j1 == j2 && abs(i1-i2)==1))
        return true;
    return false;
}

// Esta función establece el lado dado; es decir verífica si es horizontal o vertical para marcarlos en la matriz correspondiente
// Las funciones que usa para la verificacion se encuentran en la clase Celdas
void Tablero::vertical_o_horizontal(int i1, int j1, int i2, int j2) {
    if(i1 == i2)
        celdas.lado_horizontal(i1,j1);
    else if(j1 == j2)
        celdas.lado_vertical(i1,j1);
}

// Esta función comprueba y establece las casillas completadas de los vecinos; además aumenta en contador de cada jugador
// Y marca una caja cuando se completan los 4 lados
bool Tablero::cajas_vecinas(int i1, int j1, int i2, int j2, int jugador) {

    bool casillas = false;
    if (i1 == i2){
        if (i1 == 0 && celdas.Comprobar_primer_lado(i1,j1)){
            tablero[i1][j1] = nombres[jugador];
            //cajas[jugador] += 1;
            vecJugadores[jugador]->sumarPunto();
            return true;
        }
        else if( i1 == size-1 && celdas.Comprobar_segunda_columna(i1,j1) ){
            tablero[i1-1][j1] = nombres[jugador];
            //cajas[jugador] += 1;
            vecJugadores[jugador]->sumarPunto();
            return true;
        }
        else{
            if (celdas.Comprobar_primer_lado(i1,j1)){
                tablero[i1][j1] = nombres[jugador];
                //cajas[jugador] += 1;
                vecJugadores[jugador]->sumarPunto();
                casillas = true;
            }
            if (celdas.Comprobar_segunda_columna(i1,j1)) {
                if (i1 == 0) {
                    //cajas[jugador] += 1;
                    casillas = false;
                }
                else {
                    tablero[i1 - 1][j1] = nombres[jugador];
                    //cajas[jugador] += 1;
                    vecJugadores[jugador]->sumarPunto();
                    casillas = true;
                }
            }
        }
        return casillas;
    }

    else if(j1 == j2){
        if(j1 == 0 && celdas.Comprobar_primer_lado(i1,j1)){
            tablero[i1][j1] = nombres[jugador];
            //cajas[jugador] += 1;
            vecJugadores[jugador]->sumarPunto();
            return true;
        }
        else if(j1 == size-1 && celdas.Comprobar_segunda_fila(i1,j1)){
            tablero[i1][j1-1] = nombres[jugador];
            //cajas[jugador] += 1;
            vecJugadores[jugador]->sumarPunto();
            return true;
        }
        else{
            if (celdas.Comprobar_primer_lado(i1,j1)){
                tablero[i1][j1] = nombres[jugador];
                //cajas[jugador] += 1;
                vecJugadores[jugador]->sumarPunto();
                casillas = true;
            }

            if (celdas.Comprobar_segunda_fila(i1,j1)){
                if (j1 == 0) {
                    casillas = false;
                }
                else{ tablero[i1][j1-1] = nombres[jugador];
                    //cajas[jugador] += 1;
                    vecJugadores[jugador]->sumarPunto();
                    casillas = true;}
            }
        }
        return casillas;
    }
    return false;
}

// Esta función ordena los puntos del lado dado -> Sirve para escribir de cualquier forma una coordenada valida;
void Tablero::ordena_coordenadas(int &i1, int &j1, int &i2, int &j2) {
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

// Esta función inicia las estructuras del juego
void Tablero::iniciar_casillas() {

    //inicializar matriz del tablero
    for(int i = 0 ; i < size-1 ; i++){
        for(int j = 0 ; j < size-1 ; j++){
            tablero[i][j] = '+';
        }
    }

    // inicializa la matriz de columnas
    for(int i = 0 ; i < size+1 ; i++){
        for(int j = 0 ; j < size ; j++){
            celdas.getColumnas()[i][j] = false;
        }
    }

    // inicializa la matriz de filas
    for(int i = 0 ; i < size ; i++){
        for(int j = 0 ; j < size + 1 ; j++){
            celdas.getFilas()[i][j] = false;
        }
    }

    for(int i=0; i<celdas.getSize(); i++) {
        for (int j = 0; j < celdas.getSize()+1; j++)
            celdas.getFilas()[i][j] = false;
    }

    for(int i=0; i<celdas.getSize()+1; i++) {
        for (int j = 0; j < celdas.getSize(); j++)
            celdas.getColumnas()[i][j] = false;
    }

}

int Tablero::getNroJugadores() const {
    return jugadores;
}


vector<Jugador*> Tablero::getVecJugadores(){
    return vecJugadores;
}
