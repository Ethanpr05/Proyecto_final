#ifndef OBJETO_H
#define OBJETO_H

#include <utility>
#include <string>
using namespace std;

class Objeto {
protected:
    string tipo;
    pair<int, int> posicion;

public:
    Objeto(string tip, pair<int, int> pos);

    virtual void interactuar() = 0; // Método virtual

    pair<int, int> obtenerPosicion() const;
};

#endif // OBJETO_H
