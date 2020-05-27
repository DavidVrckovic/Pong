#ifndef BALL_H
#define BALL_H

#include <QGraphicsEllipseItem>
#include <QObject>
#include "score1.h"

class Ball: public QObject, public QGraphicsEllipseItem
{
    Q_OBJECT
public:
    Ball();
public slots:
    void move();
};

#endif // BALL_H
