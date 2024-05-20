#include "enemigo.h"


Enemigo::Enemigo(string tip, int fuerza, int rango, int vel, pair<int, int> pos)
    : Movimiento(vel, pos), tipo(tip), fuerza(fuerza), rangoAtaque(rango) {}

void Enemigo::patrullar() {
    // Lógica para moverse de un lado a otro
    mover("izquierda");
}

void Enemigo::atacar(PersonajePrincipal &personaje) {
    if (abs(personaje.obtenerPosicion().first - posicion.first) <= rangoAtaque &&
        abs(personaje.obtenerPosicion().second - posicion.second) <= rangoAtaque) {
        personaje.recibirDano(fuerza);
    }
}
