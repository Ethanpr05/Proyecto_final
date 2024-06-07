#include "movement.h"
#include "player.h"
#include "qevent.h"

Movement::Movement(int speed)
    : speed(speed), left(false), right(false) {}

void Movement::keyPressEvent(QKeyEvent *event) {
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

void Movement::keyReleaseEvent(QKeyEvent *event) {
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

void Movement::update(qreal &x) {

    if (right)
        x += speed;
    else if (left)
        x -= speed;

}
