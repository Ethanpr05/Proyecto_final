#include "ship.h"
#include "qgraphicsscene.h"
#include "seatrap.h"
#include "seatreasure.h"
#include <QTimer>

Ship::Ship(int speed, const QString &picture, float limite, float size)
    : Movement(speed) {

    ship = new sprite(picture, limite, size);
    ship->setParentItem(this);
    setRect(-30, -40, 65, 80);
    setPen(Qt::NoPen);
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Ship::move);
    timer->start(16);
    lives = 3;
    collectedGold=0;
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

void Ship::collectGold()
{
    collectedGold++;
    emit StealGold(collectedGold);
    if(collectedGold>=4){
        emit won();
    }

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

Ship::~Ship() {
    delete ship;
    delete timer;
}
