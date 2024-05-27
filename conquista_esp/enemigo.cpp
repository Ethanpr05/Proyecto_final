#include "enemigo.h"
#include <QPainter>

Enemigo::Enemigo(QWidget *parent, int startX, int startY, int patrolWidth, int speed)
    : Movimiento(parent, speed), x(startX), y(startY), patrolWidth(patrolWidth), startX(startX), movingRight(true) {}

void Enemigo::draw(QPainter *painter) {
    painter->setBrush(Qt::red);
    painter->drawRect(x, y, 30, 30); // Tamaño del enemigo (30x30) para simplicidad
}

void Enemigo::update() {
    // Movimiento de patrulla
    if (movingRight) {
        x += speed;
        if (x > startX + patrolWidth) {
            movingRight = false;
        }
    } else {
        x -= speed;
        if (x < startX) {
            movingRight = true;
        }
    }

    // Llamar a la actualización de Movimiento si es necesario
    Movimiento::update(&x);
}
