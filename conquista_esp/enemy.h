#ifndef ENEMY_H
#define ENEMY_H

#include "movement.h"
#include "sprite.h"
#include <QGraphicsRectItem>
#include <QObject>

class Enemy : public QObject, public QGraphicsRectItem, public Movement {
    Q_OBJECT
public:
    explicit Enemy(int speed, const QString &picture, float limite, float columnas, short int patrolWidth);

public slots:
    void move();

private:
    short int direction;
    void checkCollisions();
    void changeSprite();
    short int patrolWidth;
    short int initialX;

    sprite *enemy;
};

#endif // ENEMY_H
