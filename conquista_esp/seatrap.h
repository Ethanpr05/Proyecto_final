#ifndef SEATRAP_H
#define SEATRAP_H

#include "gameobject.h"

class SeaTrap : public GameObject {
    Q_OBJECT
public:
    SeaTrap(unsigned short int _speed);
    void handleCollision() override;
private:
    unsigned short int speed;
    QTimer *timer;
    sprite *seatrap;
public slots:
    void move();
};

#endif // SEATRAP_H
