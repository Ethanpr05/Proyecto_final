#include "obstaculotrampa.h"


ObstaculoTrampa::ObstaculoTrampa(string tip, pair<int, int> pos, int dan)
    : Objeto(tip, pos) {}

void ObstaculoTrampa::interactuar()  {

}


int ObstaculoTrampa::obtenerDano() const {
    return dano;
}
