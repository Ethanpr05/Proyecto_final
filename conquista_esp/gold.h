#ifndef GOLD_H
#define GOLD_H

#include "gameobject.h"
#include "sprite.h"

class Gold : public GameObject {
    Q_OBJECT
public:
    Gold(const QString &imagePath, float limite, float columnas);
    void handleCollision() override;
private:
    sprite *goldpath;
};

#endif // GOLD_H

