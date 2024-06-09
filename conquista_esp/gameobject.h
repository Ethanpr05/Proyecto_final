#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <QGraphicsPixmapItem>
#include <QObject>

#include "sprite.h"

class GameObject : public QObject, public QGraphicsRectItem {
    Q_OBJECT
public:
    GameObject();
    virtual void handleCollision() = 0; // Método puro virtual para manejar colisiones
private:
    sprite *object;
};

#endif // GAMEOBJECT_H
