#ifndef TRAP_H
#define TRAP_H

#include "gameobject.h"

class Trap : public GameObject {
    Q_OBJECT
public:
    Trap(const QString &imagePath);
    void handleCollision() override;
};

#endif // TRAP_H
