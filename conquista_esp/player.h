#ifndef PLAYER_H
#define PLAYER_H

#include "movement.h"
#include <QGraphicsRectItem>
#include <QObject>
#include <QKeyEvent>
#include "sprite.h"
#include <QGraphicsView>
#include <QGraphicsTextItem>

class Player : public QObject, public QGraphicsRectItem, public Movement {
    Q_OBJECT
public:
    Player(const QString &picture, float limite, float size, QGraphicsView *view);
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;
    ~Player();

public slots:
    void move();
signals:
    void livesChanged(unsigned short int lives);
    void StealGold(unsigned short int collectedGold);
    void won();
private:
    bool left, right, jumping, onGround;
    qreal velocityY;
    const qreal gravity = 0.5;
    unsigned short int lives, collectedGold;  // Cambiar a unsigned short int
    QTimer *timer;
    QGraphicsView *view;
    QGraphicsTextItem *lifeText; // Añadir elemento de texto para mostrar la vida
    void checkCollisions();
    void decreaseLife();

    sprite *player;
};

#endif // PLAYER_H
