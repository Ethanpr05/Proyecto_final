#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QList>
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
    unsigned short int whichlvl=1;

    QGraphicsScene *scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, 1330, 600);
    QGraphicsView *view = new QGraphicsView(scene);
    view->setFixedSize(1280, 603);
    unsigned short int *level = &whichlvl;
    // level3(scene, view, *level);

    switch(whichlvl){
    case 1:{
        level3(scene, view, *level);
    }
    break;
    case 2:{
        scene->clear();
        //level2(scene, view);
        //view->show();
    }
    break;
    case 3:{
        //level2(scene, view);
        //view->show();
    }
    break;
    }

    view->show();
    return a.exec();
}
