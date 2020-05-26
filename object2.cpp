#include "object2.h"
#include <QKeyEvent>

void Object2::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Up)
    {
        if(pos().y() > 4)
        {
            setPos(x(),y()-20);
        }
    }
    else if(event->key() == Qt::Key_Down)
    {
        if(pos().y()+70 < 795)
        {
            setPos(x(),y()+20);
        }
    }
}
