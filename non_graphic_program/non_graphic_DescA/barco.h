#ifndef BARCO_H
#define BARCO_H

#include "movimiento.h"
#include <iostream>
#include <map>
#include <utility>
#include <string>
using namespace std;

class Barco : public Movimiento {
private:
    map<string, int> estado; // integridad, velocidad, etc.

public:
    Barco(map<string, int> est, int vel, pair<int, int> pos);

    void navegar(const string &direccion);

};

#endif // BARCO_H
