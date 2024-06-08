#ifndef SPRITE_H
#define SPRITE_H

#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include <QPainter>

class sprite : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit sprite(const QString &picture, float _limite, QObject *parent = nullptr);

    QTimer *timer;
    QPixmap *pixmap;

    float filas,columnas;

    float ancho;
    float alto;
    float limite;

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void setfilas(unsigned short int newvalue);
    unsigned short int getFilas() const;

signals:

public slots:
    void Actualizacion();
};

#endif // SPRITE_H
