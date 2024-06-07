#include "enemy.h"
#include "ground.h"
#include "player.h"
#include <QTimer>
#include <QBrush>
#include <QGraphicsScene>


Enemy::Enemy(int speed)
    : Movement(speed)
{

    setRect(0, 0, 50, 50);
    setBrush(QBrush(Qt::red));
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Enemy::move);
    timer->start(16);
    //right = true;
    direction =-1;
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
        } else if (typeid(*item) == typeid(Ground)&& (pos().x() < 0 || pos().x() > 790)) {
            direction *= -1;
        }
    }
}
