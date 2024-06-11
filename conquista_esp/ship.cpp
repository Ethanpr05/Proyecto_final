#include "ship.h"
#include "qgraphicsscene.h"
#include "seatrap.h"
#include <QTimer>

Ship::Ship(int speed)
    : Movement(speed) {

    setRect(0, 0, 50, 90);
    setBrush(QColorConstants::Svg::brown);
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Ship::move);
    timer->start(16);
    lives = 3;
}

void Ship::keyPressEvent(QKeyEvent *event) {
    Movement::keyPressEvent(event);
}

void Ship::keyReleaseEvent(QKeyEvent *event) {
    Movement::keyReleaseEvent(event);
}


void Ship::move()
{
    qreal x = pos().x();
    Movement::update(x);
    setX(x);
}

void Ship::checkCollisions()
{
    if (lives > 0) {
        lives--;

        emit livesChanged(lives); // Actualizar el texto de la vida
        if (lives == 0) {
            timer->stop(); // Detener el temporizador si las vidas llegan a 0
        }
    }
}
