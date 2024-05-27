#include "movimiento.h"
#include "personajeprincipal.h"

Movimiento::Movimiento(QWidget *parent, int speed)
    : parent(parent), speed(speed), left(false), right(false) {}

void Movimiento::keyPressEvent(QKeyEvent *event) {
    switch (event->key()) {
    case Qt::Key_Left:
        left = true;
        break;
    case Qt::Key_Right:
        right = true;
        break;
    default:
        break;
    }
}

void Movimiento::keyReleaseEvent(QKeyEvent *event) {
    switch (event->key()) {
    case Qt::Key_Left:
        left = false;
        break;
    case Qt::Key_Right:
        right = false;
        break;
    default:
        break;
    }
}

void Movimiento::update(int *xPointer) {
    int &x = *xPointer;

    if (left)
        x -= speed;
    else if (right)
        x += speed;

    // Mantener dentro de los límites de la ventana
    if (x < 0) x = 0;
    if (x > parent->width() - 30) x = parent->width() - 30;
}
