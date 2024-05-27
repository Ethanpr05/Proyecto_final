#ifndef ENEMIGO_H
#define ENEMIGO_H

#include "movimiento.h"

class Enemigo : public Movimiento {
public:
    explicit Enemigo(QWidget *parent, int startX, int startY, int patrolWidth, int speed = 2);
    void draw(QPainter *painter);
    void update();

private:
    int x, y;
    int patrolWidth;
    int startX;
    bool movingRight;
};
#endif // ENEMIGO_H
