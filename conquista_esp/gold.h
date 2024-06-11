#ifndef GOLD_H
#define GOLD_H

#include "sprite.h"

class Gold : public QObject, public QGraphicsRectItem {
    Q_OBJECT
public:
    Gold(const QString &imagePath, float limite, float sise);
    void handleCollision();
    ~Gold();
private:
    sprite *goldpath;
};

#endif // GOLD_H

