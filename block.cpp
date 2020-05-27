#include "block.h"
#include <QBrush>

Block::Block(QGraphicsItem *parent): QGraphicsRectItem(parent)
{
    // draw rect
    setRect(50,0,100,50);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::blue);
    setBrush(brush);
}
