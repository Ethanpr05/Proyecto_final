#include "game.h"
#include "levels.h"

Game::Game(QGraphicsView *view) : view(view), currentLevel(1), lastLoadedLevel(0) {
    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, 1330, 600);
    view->setScene(scene);
    view->setFixedSize(1280, 603);
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Game::checkLevel);
    timer->start(16);
}

void Game::start() {
    loadLevel();
}

void Game::checkLevel() {
    if (currentLevel != lastLoadedLevel) {
        loadLevel();
    }
}

void Game::loadLevel() {
    scene->clear(); // Limpiar la escena para el próximo nivel

    if (currentLevel == 1) {
        level1(scene, view, currentLevel);
    } else if (currentLevel == 2) {
        level2(scene, view, currentLevel);
    } else if (currentLevel == 3) {
        level3(scene, view, currentLevel);
    }else if (currentLevel == 4) {
        QPixmap backgroundPixmap(":/imagenes/win.png");
        QPixmap scaledBackground = backgroundPixmap.scaled(scene->width(), scene->height());
        QGraphicsPixmapItem *background = new QGraphicsPixmapItem(scaledBackground);
        background->setPos(0, 0);
        scene->addItem(background);
    }

    lastLoadedLevel = currentLevel; // Actualizar el nivel cargado
}
