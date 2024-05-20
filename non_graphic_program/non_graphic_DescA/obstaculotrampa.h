#ifndef OBSTACULOTRAMPA_H
#define OBSTACULOTRAMPA_H

#include "Objeto.h"
#include <iostream>
#include <string>
using namespace std;

class ObstaculoTrampa : public Objeto {
private:

    int dano;

public:
    ObstaculoTrampa(string tip, pair<int, int> pos, int dan);

    void interactuar();

    int obtenerDano() const;
};


#endif // OBSTACULOTRAMPA_H
