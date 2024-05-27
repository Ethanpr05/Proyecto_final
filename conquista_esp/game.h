#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include <QTimer>
#include "personajeprincipal.h"
#include "level.h"
#include "enemigo.h"

class Game : public QWidget {
    Q_OBJECT

public:
    explicit Game(QWidget *parent = nullptr);
    ~Game();

protected:
    void paintEvent(QPaintEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;

private slots:
    void onUpdate();

private:
    QTimer *timer;
    PersonajePrincipal *player;
    Level *level;
    Enemigo *enemigo;
};
#endif // GAME_H
