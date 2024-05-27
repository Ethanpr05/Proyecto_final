#include "game.h"
#include <QPainter>
#include <QKeyEvent>

Game::Game(QWidget *parent)
    : QWidget(parent), player(new PersonajePrincipal(this)), level(new Level(this)), enemigo(new Enemigo(this, 50, 550, 550)) {
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Game::onUpdate);
    timer->start(16); // Aproximadamente 60 FPS
    setFixedSize(800, 600);
    // Habilitamos el foco para que el widget pueda recibir eventos de teclado
    setFocusPolicy(Qt::StrongFocus);
}

Game::~Game() {
    delete player;
    delete level;
    delete enemigo; // Eliminar el enemigo
}

void Game::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    level->draw(&painter);
    player->draw(&painter);
    enemigo->draw(&painter); // Dibujar el enemigo
}

void Game::keyPressEvent(QKeyEvent *event) {
    player->keyPressEvent(event);
}

void Game::keyReleaseEvent(QKeyEvent *event) {
    player->keyReleaseEvent(event);
}

void Game::onUpdate() {
    player->update();
    enemigo->update(); // Actualizar el enemigo
    level->update();
    update();
}
