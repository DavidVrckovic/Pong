/*#ifndef BALL_H
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
*/

#ifndef BALL_H
#define BALL_H

#include <QGraphicsRectItem>

class Ball: public QObject, public QGraphicsEllipseItem
{
    Q_OBJECT
public:
    // constructors
    Ball(QGraphicsItem* parent=NULL);

    // public methods
    double getCenterX();

public slots:
    // public slots
    void move();

private:
    // private attributes
    double xVelocity;
    double yVelocity;

    // private methods
    void reverseVelocityIfOutOfBounds();
    void handlePaddleCollision();
    void handleBlockCollision();
};

#endif // BALL_H
