#ifndef TRAP_H
#define TRAP_H

#include "gameobject.h"

class Trap : public GameObject {
    Q_OBJECT
public:
    Trap(const QString &imagePath, float limite, float size);
    void handleCollision() override;
private:
    sprite *trap;
};

#endif // TRAP_H
