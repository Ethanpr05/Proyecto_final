#ifndef OBJRECOLECTABLE_H
#define OBJRECOLECTABLE_H

#include "objeto.h"
#include <string>


class ObjetoRecolectable : public Objeto {
private:
    int valor;

public:
    ObjetoRecolectable(string tip, pair<int, int> pos, int val);

    void interactuar();

    int obtenerValor() const;
};


#endif // OBJRECOLECTABLE_H
