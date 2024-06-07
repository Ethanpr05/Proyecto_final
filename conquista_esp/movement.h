#ifndef MOVIMIENTO_H
#define MOVIMIENTO_H

#include <QWidget>
#include <QKeyEvent>

class Movement {
public:
    explicit Movement( int speed);
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    void update(qreal &x);

protected:
    int speed;
    bool left, right;
};

#endif // MOVIMIENTO_H
