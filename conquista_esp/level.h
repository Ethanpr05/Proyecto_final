#ifndef LEVEL_H
#define LEVEL_H

#include <QWidget>
#include <QPainter>

class Level {
public:
    explicit Level(QWidget *parent);
    void draw(QPainter *painter);
    void update();

private:
    QWidget *parent;
};


#endif // LEVEL_H
