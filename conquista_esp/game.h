#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include "player.h"

class Game : public QObject {
    Q_OBJECT

public:
    Game(QGraphicsView *view);
    void start();
    void loadLevel();
    ~Game();

public slots:
    void checkLevel();

private:
    QGraphicsScene *scene;
    QGraphicsView *view;
    Player *player;
    unsigned short currentLevel;
    unsigned short lastLoadedLevel;
    QTimer *timer;
};

#endif // GAME_H
