#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include "player.h"
#include "enemy.h"
#include "ground.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    QGraphicsScene *scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, 800, 600);

    QPixmap backgroundPixmap(":/imagenes/background.jpg");
    QPixmap scaledBackground = backgroundPixmap.scaled(scene->width(), scene->height());
    QGraphicsPixmapItem *background = new QGraphicsPixmapItem(scaledBackground);
    background->setPos(0, 0);
    scene->addItem(background);
    // Añadir suelo
    Ground *ground = new Ground();
    ground->setPos(0, 560);
    scene->addItem(ground);

    // Añadir jugador
    Player *player = new Player(":/imagenes/player.png");
    player->setPos(100, 510);
    scene->addItem(player);

    // Añadir enemigo
    Enemy *enemy = new Enemy(2, ":/imagenes/enemigoDI-removebg-preview.png");
    enemy->setPos(400, 510);
    scene->addItem(enemy);

    QGraphicsView *view = new QGraphicsView(scene);
    view->setFixedSize(803, 603);
    view->show();

    return a.exec();
}
