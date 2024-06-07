#ifndef PLAYER_H
#define PLAYER_H

#include "movement.h"
#include <QGraphicsRectItem>
#include <QObject>
#include <QKeyEvent>

class Player : public QObject, public QGraphicsRectItem, public Movement {
    Q_OBJECT
public:
    Player();
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;

public slots:
    void move() ;

private:
    bool left, right, jumping;
    qreal velocityY;
    const qreal gravity = 0.5;
    void checkCollisions();
    void handleCollisionWithEnemy();
};

#endif // PLAYER_H
