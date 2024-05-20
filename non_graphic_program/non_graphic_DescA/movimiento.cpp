#include "movimiento.h"


Movimiento::Movimiento(int vel, pair<int, int> pos) : velocidad(vel), posicion(pos) {}

void Movimiento::mover(const string &direccion) {
    if (direccion == "arriba") {
        posicion.second += velocidad;
    } else if (direccion == "abajo") {
        posicion.second -= velocidad;
    } else if (direccion == "izquierda") {
        posicion.first -= velocidad;
    } else if (direccion == "derecha") {
        posicion.first += velocidad;
    } else {
        throw invalid_argument("Direccion invalida");
    }
}

pair<int, int> Movimiento::obtenerPosicion() const {
    return posicion;
}
