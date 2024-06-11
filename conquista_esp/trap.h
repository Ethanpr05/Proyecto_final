#ifndef TRAP_H
#define TRAP_H

#include "sprite.h"

class Trap : public QObject, public QGraphicsRectItem {
    Q_OBJECT
public:
    Trap(const QString &imagePath, float limite, float size);
    ~Trap();
private:
    sprite *trap;
};

#endif // TRAP_H

