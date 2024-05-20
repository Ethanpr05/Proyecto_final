#include <iostream>

#include "movimiento.h"
#include "personajeprincipal.h"
#include "enemigo.h"
#include "objeto.h"
#include "obstaculotrampa.h"
#include "objrecolectable.h"
#include "barco.h"

using namespace std;

int main() {
    // Crear objetos del juego
    PersonajePrincipal personaje({"navegacion"}, {{"salud", 100}}, 2, {0, 0});
    Barco barco({{"integridad", 100}}, 1, {0, 0});
    vector<Enemigo> enemigos = {
        Enemigo("Ladron", 10, 2, 1, {5, 0}),
        Enemigo("Indigena", 15, 3, 1, {10, 0})
    };

    vector<Objeto*> objetos;
    objetos.push_back(new ObstaculoTrampa("roca", {2, 2}, 3));
    objetos.push_back(new ObstaculoTrampa("trampa", {3, 3}, 4));
    objetos.push_back(new ObjetoRecolectable("oro", {4, 4}, 100));

    // Simular juego
    try {
        personaje.mover("derecha");
        barco.navegar("arriba");

        for (auto &enemigo : enemigos) {
            enemigo.patrullar();
            enemigo.atacar(personaje);
        }

        for (auto &objeto : objetos) {
            objeto->interactuar();
        }

    } catch (const exception &e) {
        cout << "Error: " << e.what() << endl;
    }

    // Liberar memoria
    for (auto &objeto : objetos) {
        delete objeto;
    }

    return 0;
}

