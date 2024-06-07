// enemy.h
#ifndef ENEMY_H
#define ENEMY_H

#include "movement.h"
#include <QGraphicsRectItem>
#include <QObject>

class Enemy : public QObject, public QGraphicsRectItem, public Movement {
    Q_OBJECT
public:
    explicit Enemy(int speed);

public slots:
    void move();

private:
    short int direction;
    void checkCollisions();
};

#endif // ENEMY_H
