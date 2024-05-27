#ifndef MOVIMIENTO_H
#define MOVIMIENTO_H

#include <QWidget>
#include <QKeyEvent>

class Movimiento {
public:
    explicit Movimiento(QWidget *parent, int speed = 5);
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    void update(int *xPointer);

protected:
    QWidget *parent;
    int speed;
    bool left, right;
};

#endif // MOVIMIENTO_H
