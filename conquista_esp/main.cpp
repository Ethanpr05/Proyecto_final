#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QList>
#include "gold.h"
#include "player.h"
#include "enemy.h"
#include "ground.h"
#include "trap.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    QGraphicsScene *scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, 1600, 600);

    QPixmap backgroundPixmap(":/imagenes/fondoLevel1.png");
    QPixmap scaledBackground = backgroundPixmap.scaled(scene->width(), scene->height());
    QGraphicsPixmapItem *background = new QGraphicsPixmapItem(scaledBackground);
    background->setPos(0, 0);
    scene->addItem(background);
    QList<Ground *> ground;

    ground.push_back(new Ground(":/imagenes/groundlevel1.png"));
    ground.back()->setPos(0, 560);
    scene->addItem(ground.back());
    // Añadir suelo
    /*Ground *ground = new Ground(":/imagenes/groundlevel1.png");
    ground->setPos(0, 560);
    scene->addItem(ground);*/

    Ground *plataform1 = new Ground(":/imagenes/plataformalevel1.png");
    plataform1->setPos(400, 460);
    scene->addItem(plataform1);

    QGraphicsView *view = new QGraphicsView(scene);
    view->setFixedSize(803, 603);

    // Añadir jugador
    Player *player = new Player(":/imagenes/player-Photoroom.png", 600, 100, view);
    player->setPos(view->width()/2 - player->rect().width()/2, view->height() - player->rect().height() - 10);
    scene->addItem(player);

    // Añadir enemigo
    Enemy *enemy = new Enemy(2, ":/imagenes/enemigomejor-removebg-preview.png", 400, 100, 300);
    enemy->setPos(600, 510);
    scene->addItem(enemy);

    Gold *gold = new Gold(":/imagenes/WhatsApp_Image_2024-06-07_at_9.37.19_PM-removebg-preview.png", 1200, 85);
    gold->setPos(600, 570);
    scene->addItem(gold);

    Trap *trap1 = new Trap(":/imagenes/Pit_Trap_Spikes.png", 0, 32);
    trap1->setPos(150, 578);
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

    //level 3
    /*
    ground.push_back(new Ground(":/imagenes/groundlevel3.png"));
    ground.back()->setPos(0, 560);
    scene->addItem(ground.back());
    ground.push_back(new Ground(":/imagenes/plataformalevel3.png"));
    ground.back()->setPos(300, 450);
    scene->addItem(ground.back());
    ground.push_back(new Ground(":/imagenes/plataforma2level3.png"));
    ground.back()->setPos(450, 385);
    scene->addItem(ground.back());

    QGraphicsView *view = new QGraphicsView(scene);
    view->setFixedSize(803, 603);

    // Añadir jugador
    Player *player = new Player(":/imagenes/player-Photoroom.png", 600, 100, view);
    player->setPos(view->width()/2 - player->rect().width()/2, view->height() - player->rect().height() - 10);
    scene->addItem(player);

    // Añadir enemigo
    Enemy *enemy = new Enemy(2, ":/imagenes/enemigomejor-removebg-preview.png", 400, 100, 300);
    enemy->setPos(600, 510);
    scene->addItem(enemy);
    Enemy *enemy1 = new Enemy(2, ":/imagenes/enemigomejor-removebg-preview.png", 400, 100, 300);
    enemy1->setPos(700, 510);
    scene->addItem(enemy1);
    Enemy *enemy2 = new Enemy(2, ":/imagenes/enemigomejor-removebg-preview.png", 400, 100, 80);
    enemy2->setPos(600, 335);
    scene->addItem(enemy2);

    Gold *gold = new Gold(":/imagenes/WhatsApp_Image_2024-06-07_at_9.37.19_PM-removebg-preview.png", 1200, 85);
    gold->setPos(600, 570);
    scene->addItem(gold);
    Gold *gold1 = new Gold(":/imagenes/WhatsApp_Image_2024-06-07_at_9.37.19_PM-removebg-preview.png", 1200, 85);
    gold1->setPos(50, 570);
    scene->addItem(gold1);
    Gold *gold2 = new Gold(":/imagenes/WhatsApp_Image_2024-06-07_at_9.37.19_PM-removebg-preview.png", 1200, 85);
    gold2->setPos(600, 380);
    scene->addItem(gold2);
    Gold *gold3 = new Gold(":/imagenes/WhatsApp_Image_2024-06-07_at_9.37.19_PM-removebg-preview.png", 1200, 85);
    gold3->setPos(600, 570);
    scene->addItem(gold3);

    Trap *trap = new Trap(":/imagenes/traplevel3quiza.png", 0, 32);
    trap->setPos(150, 595);
    scene->addItem(trap);
    Trap *trap1 = new Trap(":/imagenes/traplevel3quiza.png", 0, 32);
    trap1->setPos(500, 418);
    scene->addItem(trap1);
    Trap *trap2 = new Trap(":/imagenes/traplevel3quiza.png", 0, 32);
    trap2->setPos(800, 418);
    scene->addItem(trap2);

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
*/

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
