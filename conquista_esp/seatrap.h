#ifndef SEATRAP_H
#define SEATRAP_H

#include "sprite.h"

class SeaTrap : public QObject, public QGraphicsRectItem {
    Q_OBJECT
public:
    SeaTrap(unsigned short int _speed, const QString &imagePath, float limite, float size);
    ~SeaTrap();
private:
    void handleCollision();
    unsigned short int speed;
    QTimer *timer;
    sprite *seatrap;
public slots:
    void move();
};

#endif // SEATRAP_H

