#include "barco.h"



Barco::Barco(map<string, int> est, int vel, pair<int, int> pos)
    : Movimiento(vel, pos), estado(est) {}

void Barco::navegar(const string &direccion) {
    this->mover(direccion);
}
