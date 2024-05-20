#include "objeto.h"


Objeto::Objeto(string tip, pair<int, int> pos) : tipo(tip), posicion(pos) {}

pair<int, int> Objeto::obtenerPosicion() const {
    return posicion;
}
