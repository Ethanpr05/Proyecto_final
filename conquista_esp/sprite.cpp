#include "sprite.h"

sprite::sprite(const QString &picture, QObject *parent) : QObject(parent)
{

    timer = new QTimer();
    filas = 0;
    columnas = 0;
    pixmap = new QPixmap(picture);

    //dimensiones de c/U de las imagenes
    ancho = 100;
    alto  = 100;

    timer->start(150);// modifica la velocidad en que itera entre las imagenes

    connect(timer,&QTimer::timeout,this,&sprite::Actualizacion);


}

void sprite::Actualizacion()
{
    columnas +=100;
    if(columnas >=600)
    {
        columnas =0;
    }
    this->update(-ancho/2,-alto/2,ancho,alto);

}
QRectF sprite::boundingRect() const
{
    return QRectF(-ancho/2,-alto/2,ancho,alto);
}

void sprite::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-ancho/2,-alto/2,*pixmap,columnas,filas,ancho,alto);
}

void sprite::setfilas(unsigned short int newvalue)
{
    filas=newvalue;
    this->update(-ancho/2,-alto/2,ancho,alto);
}

unsigned short sprite::getFilas() const
{
    return filas;
}
