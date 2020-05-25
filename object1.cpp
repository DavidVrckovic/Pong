#include "object1.h"
#include <QKeyEvent>

void object1::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_W)
    {
        setPos(x(),y()-20);
    }
    else if(event->key() == Qt::Key_S)
    {
        setPos(x(),y()+20);
    }
}
