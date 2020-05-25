#ifndef OBJECT2_H
#define OBJECT2_H

#include<QGraphicsRectItem>

class Object2: public QGraphicsRectItem
{
public:
    void keyPressEvent(QKeyEvent *event);
};

#endif // OBJECT2_H
