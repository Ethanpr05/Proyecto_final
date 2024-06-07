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
    scene->setSceneRect(0, 0, 1600, 600);

    QPixmap backgroundPixmap(":/imagenes/background.jpg");
    QPixmap scaledBackground = backgroundPixmap.scaled(scene->width(), scene->height());
    QGraphicsPixmapItem *background = new QGraphicsPixmapItem(scaledBackground);
    background->setPos(0, 0);
    scene->addItem(background);

    // Añadir suelo
    Ground *ground = new Ground();
    ground->setPos(0, 560);
    scene->addItem(ground);

    QGraphicsView *view = new QGraphicsView(scene);
    view->setFixedSize(803, 603);

    // Añadir jugador
    Player *player = new Player(":/imagenes/player.png", view);
    player->setPos(view->width()/2 - player->rect().width()/2, view->height() - player->rect().height() - 10);
    scene->addItem(player);

    // Añadir enemigo
    Enemy *enemy = new Enemy(2, ":/imagenes/enemigoDI-removebg-preview.png");
    enemy->setPos(200, 510);
    scene->addItem(enemy);

    QGraphicsTextItem *lifeText = new QGraphicsTextItem();
    lifeText->setPlainText("Lives: 30");
    lifeText->setDefaultTextColor(Qt::red);
    lifeText->setFont(QFont("Arial", 16));
    lifeText->setPos(10, 10);
    scene->addItem(lifeText);

    // Conectar la actualización del texto de vidas al jugador
    QObject::connect(player, &Player::livesChanged, [=](unsigned short int lives) {
        lifeText->setPlainText(QString("Lives: %1").arg(lives));
    });

    view->centerOn(player);
    view->show();

    return a.exec();
}
