#include "level.h"

Level::Level(QWidget *parent) : parent(parent) {}

void Level::draw(QPainter *painter) {
    painter->setBrush(Qt::green);
    painter->drawRect(0, parent->height() - 20, parent->width(), 20); // Nivel del suelo
}

void Level::update() {
    // Actualizar elementos del nivel
}
