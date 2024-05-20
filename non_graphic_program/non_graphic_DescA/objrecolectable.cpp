#include "objrecolectable.h"


ObjetoRecolectable::ObjetoRecolectable(string tip, pair<int, int> pos, int val)
    : Objeto(tip, pos), valor(val) {}

void ObjetoRecolectable::interactuar()  {
    // Lógica para recolectar el objeto
}

int ObjetoRecolectable::obtenerValor() const {
    return valor;
}
