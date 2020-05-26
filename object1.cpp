#include "object1.h"
#include <QKeyEvent>

void Object1::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_W)
    {
        if(pos().y() > 4)
        {
            setPos(x(),y()-20);
        }
    }
    else if(event->key() == Qt::Key_S)
    {
        if(pos().y()+70 < 795)
        {
            setPos(x(),y()+20);
        }
    }
}
