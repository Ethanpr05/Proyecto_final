#include "personajeprincipal.h"



PersonajePrincipal::PersonajePrincipal(vector<string> habs, map<string, int> est, int vel, pair<int, int> pos)
    : Movimiento(vel, pos), habilidades(habs), estado(est) {}


void PersonajePrincipal::robarOro() {

}

void PersonajePrincipal::atacar() {

}

void PersonajePrincipal::recibirDano(int cantidad) {
    estado["salud"] -= cantidad;
    if (estado["salud"] <= 0) {
        // Lógica de muerte del personaje
        throw runtime_error("El personaje ha muerto");
    }
}

int PersonajePrincipal::obtenerSalud() const {
    return estado.at("salud");
}
