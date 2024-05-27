#include "personajeprincipal.h"
#include <QPainter>

PersonajePrincipal::PersonajePrincipal(QWidget *parent)
    : Movimiento(parent), x(50), y(parent->height() +100 ), dy(0), jumping(false), onGround(true) {}

void PersonajePrincipal::draw(QPainter *painter) {
    painter->setBrush(Qt::blue);
    painter->drawRect(x, y, 30, 30); // Tamaño de Mario (30x30) para simplicidad
}

void PersonajePrincipal::keyPressEvent(QKeyEvent *event) {
    Movimiento::keyPressEvent(event); // Llamamos al método de la clase base para manejar el movimiento horizontal
    switch (event->key()) {
    case Qt::Key_Up:
        if (onGround) {
            jump();
        }
        break;
    default:
        break;
    }
}

void PersonajePrincipal::keyReleaseEvent(QKeyEvent *event) {
    Movimiento::keyReleaseEvent(event); // Llamamos al método de la clase base para manejar el movimiento horizontal
}

void PersonajePrincipal::update() {
    Movimiento::update(&x); // Llamamos al método de la clase base para manejar el movimiento horizontal

    // Gravedad
    if (!onGround) {
        dy += 1; // Incremento de la velocidad hacia abajo
    } else {
        dy = 0;
    }
    y += dy;

    // Comprobar si el jugador toca el suelo
    if (y >= parent->height() - 50) {
        y = parent->height() - 50;
        onGround = true;
        jumping = false;
    }

    // Aplicar límites de la ventana
    if (getX() < 0) x = 0;
    if (getX() > parent->width() - 30) x = parent->width() - 30;
}

void PersonajePrincipal::jump() {
    jumping = true;
    onGround = false;
    dy = -20; // Fuerza del salto
}
