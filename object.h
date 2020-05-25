#ifndef OBJECT_H
#define OBJECT_H

#include<QGraphicsRectItem>

class object: public QGraphicsRectItem
{
public:
    void keyPressEvent(QKeyEvent * event);
};

#endif // OBJECT_H
