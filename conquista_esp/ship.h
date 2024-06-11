#ifndef SHIP_H
#define SHIP_H


#include "movement.h"
#include <QGraphicsRectItem>
#include <QObject>
#include <QKeyEvent>

class Ship : public QObject, public QGraphicsRectItem, public Movement {
    Q_OBJECT
public:
    explicit Ship(int speed);
    void keyPressEvent(QKeyEvent *event) override;
    void checkCollisions();
    void keyReleaseEvent(QKeyEvent *event) override;
public slots:
    void move();
private:
    QTimer *timer;

    unsigned short int lives;
signals:
    void livesChanged(unsigned short int lives);
};

#endif // SHIP_H
