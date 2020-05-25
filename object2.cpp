#include "object2.h"
#include <QKeyEvent>

void Object2::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Up)
    {
        setPos(x(),y()-20);
    }
    else if(event->key() == Qt::Key_Down)
    {
        setPos(x(),y()+20);
    }
}
