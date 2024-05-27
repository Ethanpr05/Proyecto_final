#ifndef PERSONAJEPRINCIPAL_H
#define PERSONAJEPRINCIPAL_H

#include "movimiento.h"

class PersonajePrincipal : public Movimiento {
public:
    explicit PersonajePrincipal(QWidget *parent);
    void draw(QPainter *painter);
    void keyPressEvent(QKeyEvent *event) ;
    void keyReleaseEvent(QKeyEvent *event) ;
    void update();

    // Getter para obtener la posición x
    int getX() const { return x; }
    int* getXPointer() { return &x; }

private:
    int x, y;
    int dy;
    bool jumping;
    bool onGround;

    void jump();
};
#endif // PERSONAJEPRINCIPAL_H
