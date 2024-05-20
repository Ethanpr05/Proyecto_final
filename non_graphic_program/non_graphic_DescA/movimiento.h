#ifndef MOVIMIENTO_H
#define MOVIMIENTO_H

#include <iostream>
#include <stdexcept>
#include <utility>
#include <string>
using namespace std;
class Movimiento
{
protected:
    int velocidad;
    pair<int, int> posicion;

public:
    Movimiento(int vel, pair<int, int> pos);

    void mover(const string &direccion);

    pair<int, int> obtenerPosicion() const;
};

#endif // MOVIMIENTO_H
