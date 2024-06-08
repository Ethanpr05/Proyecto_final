#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <QGraphicsPixmapItem>
#include <QObject>

class GameObject : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    GameObject(const QString &imagePath);
    virtual void handleCollision() = 0; // Método puro virtual para manejar colisiones
};

#endif // GAMEOBJECT_H
