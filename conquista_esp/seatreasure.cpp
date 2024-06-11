#include "seatreasure.h"
#include "qgraphicsscene.h"
#include "ship.h"
#include <QTimer>
#include <QRandomGenerator>

SeaTreasure::SeaTreasure(unsigned short _speed, const QString &imagePath, float limite, float size) {
    /*setRect(0, 0, 50, 50);
    setBrush(QColorConstants::Svg::brown);*/
    seatreasure = new sprite(imagePath, limite, size);
    seatreasure->setParentItem(this);
    setRect(-45, -45, 65, 55); // Establece el tamaño
    seatreasure->setfilas(0);
    setPen(Qt::NoPen);
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &SeaTreasure::move);
    timer->start(16);
    speed=_speed;
}

void SeaTreasure::handleCollision() {
    QList<QGraphicsItem*> collidingItems = scene()->collidingItems(this);

    for (QGraphicsItem* item : collidingItems){
        if (typeid(*item) == typeid(Ship)){
            setY(0);
            int newX = QRandomGenerator::global()->bounded(300, 1000); // Generar un valor aleatorio entre 100 y 900
            setX(newX);
            static_cast<Ship*>(item)->collectGold();
        }
    }

}

void SeaTreasure::move() {
    // Mover hacia abajo
    setY(y() + speed);
    handleCollision();
    // Si llega al límite inferior, reposicionar en la parte superior
    if (y() >= 600) {
        setY(0);
        int newX = QRandomGenerator::global()->bounded(300, 1000); // Generar un valor aleatorio entre 100 y 900
        setX(newX);
    }
}


SeaTreasure::~SeaTreasure() {

}
