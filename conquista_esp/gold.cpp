#include "gold.h"
#include "player.h"
#include "qgraphicsscene.h"
Gold::Gold(const QString &imagePath, float limite, float sise) {
    goldpath = new sprite(imagePath, limite, sise);
    goldpath->setParentItem(this);
    setRect(-15, -35, 20, 20); // Establece el tamaño
    goldpath->setfilas(0);
    setPen(Qt::NoPen);
}

void Gold::handleCollision() {
    scene()->removeItem(this);
    delete this;
}

Gold::~Gold() {
    delete goldpath;
}
