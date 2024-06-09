#include "ground.h"

Ground::Ground(const QString &picture) {
    setPixmap(QPixmap(picture));
}
