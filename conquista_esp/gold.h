#ifndef GOLD_H
#define GOLD_H

#include "gameobject.h"

class Gold : public GameObject {
    Q_OBJECT
public:
    Gold(const QString &imagePath);
    void handleCollision() override;
};

#endif // GOLD_H

