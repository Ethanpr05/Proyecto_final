#include "trap.h"
#include "player.h"

Trap::Trap(const QString &imagePath, float limite, float size) {
    trap = new sprite(imagePath, limite, size);
    trap->setParentItem(this);
    setRect(-50, -50, 30, 34); // Establece el tamaño
    trap->setfilas(0);
    setPen(Qt::NoPen);
}

void Trap::handleCollision() {


}
