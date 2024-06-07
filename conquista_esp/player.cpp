#include "player.h"
#include "enemy.h"
#include "ground.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QBrush>
#include <QList>
#include <QGraphicsView>

Player::Player(const QString &picture, QGraphicsView *view)
    : Movement(5), left(false), right(false), jumping(false),
    velocityY(0), lives(30), view(view) {
    player = new sprite(picture);
    player->setParentItem(this);
    setRect(-31, -8, 70, 60); // Establece el tamaño del jugador
    player->setfilas(0);
    player->setY(20);
    setPen(Qt::NoPen);
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Player::move);
    timer->start(16); // Aproximadamente 60 FPS
    //connect(this, &::Player::itemChange, this);
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
    if (Movement::left) {
        player->setfilas(200);
    }
    if (Movement::right) {
        player->setfilas(100);
    }
    if (jumping) {
        setY(y() + velocityY);
        velocityY += gravity;
        if (Movement::left) {
            player->setfilas(300);
        } else {
            player->setfilas(400);
        }
    }
    if (!jumping && !Movement::left && !Movement::right) {
        player->setfilas(0);
    }

    checkCollisions();

    /* // Ajustar la posición si hay colisión
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
    }*/

    // Centrar la vista en el jugador
    view->centerOn(this);
    setFocus();
}

void Player::checkCollisions() {
    qreal initialX = x(); // Guardar la posición inicial en X
    qreal initialY = y(); // Guardar la posición inicial en Y

    QList<QGraphicsItem*> collidingItems = scene()->collidingItems(this);

    for (QGraphicsItem* item : collidingItems) {
        if (typeid(*item) == typeid(Ground)) {
            setY(510);
            jumping = false;
            velocityY = 0;
        } else if (typeid(*item) == typeid(Enemy)) {
            // Si se colisiona con un enemigo desde arriba, rebota sin hacerse daño
            if (y() < item->y()) {
                velocityY = -5;
            } else {
                // Si se colisiona con un enemigo desde los lados, rebota y pierde vida
                setX(initialX); // Revertir la posición horizontal
                setY(initialY); // Revertir la posición vertical
                decreaseLife(); // Disminuir la vida
                // Añadir efecto de rebote
                if (x() < item->x()) {
                    setX(x() - 25); // Rebota hacia la izquierda
                } else {
                    setX(x() + 25); // Rebota hacia la derecha
                }
            }
        }
    }
}
/*void Player::handleCollisionWithEnemy() {
    // Frenar el movimiento al colisionar con el enemigo
    left = false;
    right = false;
    velocityY = -5;
    decreaseLife(); // Disminuir la vida

}*/

void Player::decreaseLife() {
    if (lives > 0) {
        lives--;
        emit livesChanged(lives); // Actualizar el texto de la vida
        if (lives == 0) {
            timer->stop(); // Detener el temporizador si las vidas llegan a 0
        }
    }
}
