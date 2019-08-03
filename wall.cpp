#include <QPainter>
#include "wall.h"
#include "constants.h"
#include <QDebug>

Wall::Wall()
{
    setPos(0, 0);
    setData(GD_Type, GO_Wall);
}
QRectF Wall::boundingRect() const
{
    return QRectF(-100, -100, 200, 200);
}
void Wall::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->save();
    painter->fillPath(shape(), Qt::blue);
    painter->restore();
}
QPainterPath Wall::shape() const
{
    QPainterPath path;
    int i = 0;
    for(i = -100; i <= 100; i+=10){
        path.addRect(QRectF(i, -100, TILE_SIZE, TILE_SIZE));
        path.addRect(QRectF(i, 100, TILE_SIZE, TILE_SIZE));
        path.addRect(QRectF(-100, i, TILE_SIZE, TILE_SIZE));
        path.addRect(QRectF(100, i, TILE_SIZE, TILE_SIZE));
    }
    return path;
}
