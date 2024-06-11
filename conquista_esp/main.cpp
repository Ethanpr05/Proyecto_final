#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QList>
#include "game.h"
#include "gold.h"
#include "levels.h"
#include "player.h"
#include "enemy.h"
#include "ground.h"
#include "seatrap.h"
#include "ship.h"
#include "trap.h"



int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    QGraphicsView *view = new QGraphicsView();
    Game game(view);
    game.start();

    view->show();
    return a.exec();
}
