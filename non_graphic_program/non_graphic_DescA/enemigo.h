#ifndef ENEMIGO_H
#define ENEMIGO_H

#include "personajeprincipal.h"
#include <iostream>
#include <utility>
#include <cmath>


class Enemigo : public Movimiento {
private:
    string tipo;
    int fuerza;
    int rangoAtaque;

public:
    Enemigo(string tip, int fuerza, int rango, int vel, pair<int, int> pos);

    void patrullar();

    void atacar(PersonajePrincipal &personaje);
};




#endif // ENEMIGO_H
