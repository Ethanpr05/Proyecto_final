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
    scene->setSceneRect(0, 0, 1330, 600);

    QPixmap backgroundPixmap(":/imagenes/fondoLevel1.png");
    QPixmap scaledBackground = backgroundPixmap.scaled(scene->width(), scene->height());
    QGraphicsPixmapItem *background = new QGraphicsPixmapItem(scaledBackground);
    background->setPos(0, 0);
    scene->addItem(background);
    QList<Ground *> ground;
    QList<Trap *> trap;
    QList<Gold *> man;

    // Añadir suelo
    ground.push_back(new Ground(":/imagenes/groundlevel1.png"));
    ground.back()->setPos(0, 560);
    scene->addItem(ground.back());
    ground.push_back(new Ground(":/imagenes/plataforma1level1.png"));
    ground.back()->setPos(120, 320);
    scene->addItem(ground.back());
    ground.push_back(new Ground(":/imagenes/plataforma1level1.png"));
    ground.back()->setPos(1005, 265);
    scene->addItem(ground.back());
    ground.push_back(new Ground(":/imagenes/plataforma1level1.png"));
    ground.back()->setPos(550, 350);
    scene->addItem(ground.back());
    ground.push_back(new Ground(":/imagenes/plataforma1level1.png"));
    ground.back()->setPos(350, 150);
    scene->addItem(ground.back());
    ground.push_back(new Ground(":/imagenes/plataformalevel1.png"));
    ground.back()->setPos(855, 415);
    scene->addItem(ground.back());
    ground.push_back(new Ground(":/imagenes/plataformalevel1.png"));
    ground.back()->setPos(150, 470);
    scene->addItem(ground.back());
    ground.push_back(new Ground(":/imagenes/plataformalevel1.png"));
    ground.back()->setPos(5, 410);
    scene->addItem(ground.back());
    ground.push_back(new Ground(":/imagenes/plataformalevel1.png"));
    ground.back()->setPos(5, 200);
    scene->addItem(ground.back());
    ground.push_back(new Ground(":/imagenes/plataformalevel1.png"));
    ground.back()->setPos(150, 100);
    scene->addItem(ground.back());
    ground.push_back(new Ground(":/imagenes/plataformalevel1.png"));
    ground.back()->setPos(750, 100);
    scene->addItem(ground.back());

    QGraphicsView *view = new QGraphicsView(scene);
    view->setFixedSize(1280, 603);

    // Añadir jugador
    Player *player = new Player(":/imagenes/player-Photoroom.png", 600, 100, view);
    player->setPos(50, view->height() - player->rect().height() - 10);
    scene->addItem(player);

    // Añadir enemigo
    /*Enemy *enemy = new Enemy(2, ":/imagenes/enemigomejor-removebg-preview.png", 400, 100, 300);
    enemy->setPos(600, 510);
    scene->addItem(enemy);*/

    man.push_back(new Gold(":/imagenes/WhatsApp_Image_2024-06-07_at_9.37.19_PM-removebg-preview.png", 1200, 85));
    man.back()->setPos(220, 325);
    scene->addItem(man.back());
    man.push_back(new Gold(":/imagenes/WhatsApp_Image_2024-06-07_at_9.37.19_PM-removebg-preview.png", 1200, 85));
    man.back()->setPos(1105, 270);
    scene->addItem(man.back());
    man.push_back(new Gold(":/imagenes/Kinglevel1-removebg-preview.png", 400, 100));
    man.back()->setPos(650, 315);
    scene->addItem(man.back());
    man.push_back(new Gold(":/imagenes/WhatsApp_Image_2024-06-07_at_9.37.19_PM-removebg-preview.png", 1200, 85));
    man.back()->setPos(450, 155);
    scene->addItem(man.back());

    trap.push_back(new Trap(":/imagenes/Pit_Trap_Spikes.png", 0, 32));
    trap.back()->setPos(300, 578);
    scene->addItem(trap.back());
    trap.push_back(new Trap(":/imagenes/Pit_Trap_Spikes.png", 0, 32));
    trap.back()->setPos(400, 578);
    scene->addItem(trap.back());
    trap.push_back(new Trap(":/imagenes/Pit_Trap_Spikes.png", 0, 32));
    trap.back()->setPos(500, 578);
    scene->addItem(trap.back());
    trap.push_back(new Trap(":/imagenes/Pit_Trap_Spikes.png", 0, 32));
    trap.back()->setPos(600, 578);
    scene->addItem(trap.back());
    trap.push_back(new Trap(":/imagenes/Pit_Trap_Spikes.png", 0, 32));
    trap.back()->setPos(700, 578);
    scene->addItem(trap.back());
    trap.push_back(new Trap(":/imagenes/Pit_Trap_Spikes.png", 0, 32));
    trap.back()->setPos(800, 578);
    scene->addItem(trap.back());
    trap.push_back(new Trap(":/imagenes/Pit_Trap_Spikes.png", 0, 32));
    trap.back()->setPos(900, 578);
    scene->addItem(trap.back());
    trap.push_back(new Trap(":/imagenes/Pit_Trap_Spikes.png", 0, 32));
    trap.back()->setPos(1000, 578);
    scene->addItem(trap.back());
    trap.push_back(new Trap(":/imagenes/Pit_Trap_Spikes.png", 0, 32));
    trap.back()->setPos(1100, 578);
    scene->addItem(trap.back());
    trap.push_back(new Trap(":/imagenes/Pit_Trap_Spikes.png", 0, 32));
    trap.back()->setPos(1200, 578);
    scene->addItem(trap.back());
    trap.push_back(new Trap(":/imagenes/Pit_Trap_Spikes.png", 0, 32));
    trap.back()->setPos(950, 250);
    scene->addItem(trap.back());
    trap.push_back(new Trap(":/imagenes/Pit_Trap_Spikes.png", 0, 32));
    trap.back()->setPos(680, 150);
    scene->addItem(trap.back());
    trap.push_back(new Trap(":/imagenes/Pit_Trap_Spikes.png", 0, 32));
    trap.back()->setPos(480, 300);
    scene->addItem(trap.back());

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
    QPixmap backgroundPixmap(":/imagenes/fondolevel3mejor.png");
    QPixmap scaledBackground = backgroundPixmap.scaled(scene->width(), scene->height());
    QGraphicsPixmapItem *background = new QGraphicsPixmapItem(scaledBackground);
    background->setPos(0, 0);
    scene->addItem(background);
    QList<Ground *> ground;

    // Añadir suelo
    ground.push_back(new Ground(":/imagenes/groundlevel3.png"));
    ground.back()->setPos(0, 560);
    scene->addItem(ground.back());
    ground.push_back(new Ground(":/imagenes/plataformalevel3.png"));
    ground.back()->setPos(150, 450);
    scene->addItem(ground.back());
    ground.push_back(new Ground(":/imagenes/plataformalevel3.png"));
    ground.back()->setPos(830, 340);
    scene->addItem(ground.back());
    ground.push_back(new Ground(":/imagenes/plataforma1level3.png"));
    ground.back()->setPos(352, 385);
    scene->addItem(ground.back());
    ground.push_back(new Ground(":/imagenes/plataforma1level3.png"));
    ground.back()->setPos(1020, 280);
    scene->addItem(ground.back());

    QGraphicsView *view = new QGraphicsView(scene);
    view->setFixedSize(1280, 603);

    // Añadir jugador
    Player *player = new Player(":/imagenes/player-Photoroom.png", 600, 100, view);
    player->setPos(50, view->height() - player->rect().height() -50);
    scene->addItem(player);

    // Añadir enemigo
    Enemy *enemy = new Enemy(2, ":/imagenes/enemigomejor-removebg-preview.png", 400, 100, 1200);
    enemy->setPos(1200, 230);
    scene->addItem(enemy);
    Enemy *enemy1 = new Enemy(2, ":/imagenes/enemigomejor-removebg-preview.png", 400, 100, 400);
    enemy1->setPos(400, 510);
    scene->addItem(enemy1);
    Enemy *enemy2 = new Enemy(2, ":/imagenes/enemigomejor-removebg-preview.png", 400, 100, 500);
    enemy2->setPos(500, 335);
    scene->addItem(enemy2);

    Gold *gold = new Gold(":/imagenes/WhatsApp_Image_2024-06-07_at_9.37.19_PM-removebg-preview.png", 1200, 85);
    gold->setPos(600, 560);
    scene->addItem(gold);
    Gold *gold1 = new Gold(":/imagenes/WhatsApp_Image_2024-06-07_at_9.37.19_PM-removebg-preview.png", 1200, 85);
    gold1->setPos(50, 560);
    scene->addItem(gold1);
    Gold *gold2 = new Gold(":/imagenes/WhatsApp_Image_2024-06-07_at_9.37.19_PM-removebg-preview.png", 1200, 85);
    gold2->setPos(530, 380);
    scene->addItem(gold2);
    Gold *gold3 = new Gold(":/imagenes/WhatsApp_Image_2024-06-07_at_9.37.19_PM-removebg-preview.png", 1200, 85);
    gold3->setPos(1190, 280);
    scene->addItem(gold3);

    Trap *trap = new Trap(":/imagenes/traplevel3quiza.png", 0, 32);
    trap->setPos(150, 595);
    scene->addItem(trap);
    Trap *trap1 = new Trap(":/imagenes/traplevel3quiza.png", 0, 32);
    trap1->setPos(460, 418);
    scene->addItem(trap1);
    Trap *trap2 = new Trap(":/imagenes/traplevel3quiza.png", 0, 32);
    trap2->setPos(655, 418);
    scene->addItem(trap2);
    Trap *trap3 = new Trap(":/imagenes/traplevel3quiza.png", 0, 32);
    trap3->setPos(1130, 315);
    scene->addItem(trap3);

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
