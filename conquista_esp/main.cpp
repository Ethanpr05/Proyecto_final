#include <QApplication>
#include "game.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    Game game;
    game.resize(800, 600);
    game.show();

    return app.exec();
}
