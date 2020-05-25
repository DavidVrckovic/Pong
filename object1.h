#ifndef OBJECT1_H
#define OBJECT1_H

#include<QGraphicsRectItem>

class Object1: public QGraphicsRectItem
{
public:
    void keyPressEvent(QKeyEvent *event);
};

#endif // OBJECT1_H
