#include "enemy.h"
#include "ground.h"
#include "player.h"
#include <QTimer>
#include <QBrush>
#include <QGraphicsScene>


Enemy::Enemy(int speed, const QString &picture, float limite, float size, short int _initialX)
    : Movement(speed)
{
    enemy = new sprite(picture, limite, size);
    enemy->setParentItem(this);
    setRect(-37, -14, 70, 65); // Establece el tamaño del enemigo
    enemy->setY(18);
    enemy->setfilas(100);
    setPen(Qt::NoPen);
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Enemy::move);
    timer->start(16);
    direction =-1;
    patrolWidth = 150;
    initialX=_initialX;
}

void Enemy::move() {
    if(direction<0){
        left=true;
        right =false;
    }
    else if(direction>0){
        right = true;
        left=false;
    }
    qreal x = pos().x();
    Movement::update(x);
    setPos(x, pos().y());
    checkCollisions();

}

void Enemy::checkCollisions() {
    QList<QGraphicsItem*> collidingItems = scene()->collidingItems(this);
    for (QGraphicsItem* item : collidingItems) {
        if (typeid(*item) == typeid(Player)) {
            direction *= -1;
            changeSprite();
        } else if (typeid(*item) == typeid(Ground)&& (pos().x() < initialX-patrolWidth || pos().x() > initialX+patrolWidth)) {
            direction *= -1;
            changeSprite();
        }
    }
}

void Enemy::changeSprite()
{

    if(direction<0){
        // Cambiar filas del nuevo sprite
        enemy->setfilas(100);
        enemy->setY(18);
    }
    if(direction>0){
        enemy->setfilas(0);
        enemy->setY(14);
    }
}

Enemy::~Enemy() {

}
