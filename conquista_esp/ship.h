#ifndef SHIP_H
#define SHIP_H


#include "movement.h"
#include "sprite.h"
#include <QGraphicsRectItem>
#include <QObject>
#include <QKeyEvent>

class Ship : public QObject, public QGraphicsRectItem, public Movement {
    Q_OBJECT
public:
    explicit Ship(int speed, const QString &picture, float limite, float size);
    void keyPressEvent(QKeyEvent *event) override;
    void checkCollisions();
    void keyReleaseEvent(QKeyEvent *event) override;
    void collectGold();
    ~Ship();
public slots:
    void move();
private:
    QTimer *timer;
    sprite *ship;

    unsigned short int lives, collectedGold;
signals:
    void won();
    void StealGold(unsigned short int collectedGold);
    void livesChanged(unsigned short int lives);
};

#endif // SHIP_H
