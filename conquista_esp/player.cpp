#include "player.h"
#include "enemy.h"
#include "ground.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QBrush>
#include <QList>

Player::Player (): Movement(5), left(false), right(false), jumping(false),
    velocityY(0) {
    setRect(0, 0, 50, 50);
    setBrush(QBrush(Qt::blue));
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();

    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Player::move);
    timer->start(16); // Aproximadamente 60 FPS
}

void Player::keyPressEvent(QKeyEvent *event) {
    Movement::keyPressEvent(event);
    if (event->key() == Qt::Key_Up && !jumping) {
        jumping = true;
        velocityY = -10; // Fuerza del salto
    }
}

void Player::keyReleaseEvent(QKeyEvent *event) {
    Movement::keyReleaseEvent(event);
}

void Player::move() {
    qreal initialX = x();
    qreal initialY = y();
    qreal x = pos().x();
    Movement::update(x);
    setX(x);
    // Movimiento vertical (salto y gravedad)
    if (jumping) {
        setY(y() + velocityY);
        velocityY += gravity;
    }

    checkCollisions();

    // Ajustar la posición si hay colisión
    QList<QGraphicsItem*> collidingItems = scene()->collidingItems(this);
    for (QGraphicsItem* item : collidingItems) {
        if (typeid(*item) == typeid(Ground)) {
            setY(510);
            jumping = false;
            velocityY = 0;
        } else if (typeid(*item) == typeid(Enemy)) {
            setX(initialX); // Revertir la posición horizontal
            setY(initialY); // Revertir la posición vertical
        }
    }
}

void Player::checkCollisions() {
    QList<QGraphicsItem*> collidingItems = scene()->collidingItems(this);

    for (QGraphicsItem* item : collidingItems) {
        if (typeid(*item) == typeid(Ground)) {
            setY(510);
            jumping = false;
            velocityY = 0;
        } else if (typeid(*item) == typeid(Enemy)) {
            handleCollisionWithEnemy();
        }
    }
}

void Player::handleCollisionWithEnemy() {
    // Frenar el movimiento al colisionar con el enemigo
    left = false;
    right = false;
    velocityY=-5;
}
