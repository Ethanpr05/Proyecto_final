#include "gameobject.h"

GameObject::GameObject(const QString &imagePath) {
    setPixmap(QPixmap(imagePath));
}
