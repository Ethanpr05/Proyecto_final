#ifndef SEATREASURE_H
#define SEATREASURE_H

#include "qgraphicsitem.h"
#include "sprite.h"
class SeaTreasure : public QObject, public QGraphicsRectItem {
    Q_OBJECT
public:
    SeaTreasure(unsigned short int _speed, const QString &imagePath, float limite, float size);
    ~SeaTreasure();
private:
    void handleCollision();
    unsigned short int speed;
    QTimer *timer;
    sprite *seatreasure;
public slots:
    void move();
};


#endif // SEATREASURE_H
