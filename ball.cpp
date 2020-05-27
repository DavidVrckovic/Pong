#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "ball.h"
#include "score1.h"

Ball::Ball(): QGraphicsEllipseItem()
{
    // Connect public slot to timer
    QTimer *ball_timer = new QTimer();
    connect(ball_timer, SIGNAL(timeout()), this, SLOT(move()));

    ball_timer->start(50);
}

void Ball::move()
{
    // Move ball
    int i = 0;
    while(i == 0)
    {
        setPos(x()+5, y()-7);
        if(pos().y() < 0)
        {
            i = 1;
        }
        break;
    }
    while(i == 1)
    {
        setPos(x()+5, y()+7);
        if(pos().y() > 800)
        {
            i = 0;
        }
        break;
    }
    if(pos().x() < 0)
    {
        score1->increase();
    }
}
