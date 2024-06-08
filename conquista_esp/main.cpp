#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include "gold.h"
#include "player.h"
#include "enemy.h"
#include "ground.h"
#include "trap.h"

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
    Player *player = new Player(":/imagenes/player.png", 600, view);
    player->setPos(view->width()/2 - player->rect().width()/2, view->height() - player->rect().height() - 10);
    scene->addItem(player);

    // Añadir enemigo
    Enemy *enemy = new Enemy(2, ":/imagenes/enemigomejor-removebg-preview.png", 400);
    enemy->setPos(200, 510);
    scene->addItem(enemy);

    Gold *gold = new Gold(":/imagenes/gold.png");
    gold->setPos(600, 510);
    scene->addItem(gold);

    Trap *trap1 = new Trap(":/imagenes/Pit_Trap_Spikes.png");
    trap1->setPos(100, 550);
    scene->addItem(trap1);

    QGraphicsTextItem *lifeText = new QGraphicsTextItem();
    lifeText->setPlainText("Lives: 30");
    lifeText->setDefaultTextColor(Qt::red);
    lifeText->setFont(QFont("Arial", 16));
    lifeText->setPos(10, 10);
    scene->addItem(lifeText);

    QGraphicsTextItem *ColGoldText = new QGraphicsTextItem();
    ColGoldText->setPlainText("Oro: 0");
    ColGoldText->setDefaultTextColor(Qt::yellow);
    ColGoldText->setFont(QFont("Arial", 20));
    ColGoldText->setPos(180, 10);
    scene->addItem(ColGoldText);

    // Conectar la actualización del texto de vidas al jugador
    QObject::connect(player, &Player::livesChanged, [=](unsigned short int lives) {
        lifeText->setPlainText(QString("Lives: %1").arg(lives));
    });

    QObject::connect(player, &Player::StealGold, [=](unsigned short int collectedGold) {
        ColGoldText->setPlainText(QString("Oro: %1").arg(collectedGold));
    });


    view->centerOn(player);
    view->show();

    return a.exec();
}
