#include "gold.h"
#include "player.h"
#include "qgraphicsscene.h"
Gold::Gold(const QString &imagePath) : GameObject(imagePath) {
}

void Gold::handleCollision() {
    scene()->removeItem(this);
    delete this;
}
