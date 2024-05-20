#ifndef PERSONAJEPRINCIPAL_H
#define PERSONAJEPRINCIPAL_H

#include "movimiento.h"
#include <iostream>
#include <vector>
#include <map>
#include <stdexcept>
#include <utility>
#include <string>

using namespace std;

class PersonajePrincipal : public Movimiento {
private:

    vector<string> habilidades;
    map<string, int> estado; // salud, experiencia, etc.

public:
    PersonajePrincipal(vector<string> habs, map<string, int> est, int vel, pair<int, int> pos);

    void robarOro();

    void atacar();

    void recibirDano(int cantidad);

    int obtenerSalud() const;
};

#endif // PERSONAJEPRINCIPAL_H
