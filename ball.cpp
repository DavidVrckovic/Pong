/*#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "ball.h"
#include "score1.h"

Ball::Ball(): QGraphicsEllipseItem()
{
    // Connect public slot to timer
    QTimer *ball_timer = new QTimer();
    connect(ball_timer, SIGNAL(timeout()), this, SLOT(move()));

    ball_timer->start(300);
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
    }
}
*/

#include "ball.h"
#include <QTimer>
#include <QBrush>
#include "game.h"
#include "paddle.h"
#include "block.h"
#include "score1.h"

extern Game *game;

Ball::Ball(QGraphicsItem *parent): QGraphicsEllipseItem(parent), QObject()
{
    // draw rect
    setRect(0,0,50,50);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::red);
    setBrush(brush);

    // move up right initially
    xVelocity = 0;
    yVelocity = -5;

    // set timer
    QTimer* timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(15);
}

double Ball::getCenterX()
{
    return x() + rect().width()/2;
}

void Ball::move()
{
    // if out of bounds, reverse the velocity
    reverseVelocityIfOutOfBounds();

    // if collides with paddle, reverse yVelocity, and add xVelocity
    // depending on where (in the x axis) the ball hits the paddle
    handlePaddleCollision();

    // handle collisions with blocks (destroy blocks and reverse ball velocity)
    handleBlockCollision();

    moveBy(xVelocity, yVelocity);
}

void Ball::reverseVelocityIfOutOfBounds(){
    // check if out of bound, if so, reverse the proper velocity
    double screenW = game->width();
    double screenH = game->height();

    // left edge
    if(mapToScene(rect().topLeft()).x() <= 0)
    {
        xVelocity = -1 * xVelocity;
    }

    // right edge
    if(mapToScene(rect().topRight()).x() >= screenW)
    {
        xVelocity = -1 * xVelocity;
    }

    // top edge
    if(mapToScene(rect().topLeft()).y() <= 0)
    {
        yVelocity = -1 * yVelocity;
    }

    // bottom edge - NONE (can fall through bottom)
}

void Ball::handlePaddleCollision()
{
    QList<QGraphicsItem*> cItems = collidingItems();
    for(size_t i = 0, n = cItems.size(); i < n; ++i)
    {
        Paddle* paddle = dynamic_cast<Paddle*>(cItems[i]);
        if(paddle)
        {
            // collides with paddle

            // reverse the y velocity
            yVelocity = -1 * yVelocity;

            // add to x velocity depending on where it hits the paddle
            double ballX = getCenterX();
            double paddleX = paddle->getCenterX();

            double dvx = ballX - paddleX;
            xVelocity = (xVelocity + dvx)/15;

            return;
        }
    }
}

void Ball::handleBlockCollision()
{
    QList<QGraphicsItem*> cItems = collidingItems();
    for(size_t i = 0, n = cItems.size(); i < n; ++i)
    {
        Block* block = dynamic_cast<Block*>(cItems[i]);
        // collides with block
        if(block)
        {
            double xPad = 15, yPad = 15;
            double ballx = pos().x(), bally = pos().y();
            double blockx = block->pos().x(), blocky = block->pos().y();

            // collides from bottom
            if(bally > blocky + yPad && yVelocity < 0)
            {
                yVelocity = -1 * yVelocity;
            }

            // collides from top
            if(blocky > bally + yPad && yVelocity > 0 )
            {
                yVelocity = -1 * yVelocity;
            }

            // collides from right
            if(ballx > blockx + xPad && xVelocity < 0)
            {
                xVelocity = -1 * xVelocity;
            }

            // collides from left
            if(blockx > ballx + xPad && xVelocity > 0)
            {
                xVelocity = -1 * xVelocity;
            }

            // delete block(s)
            game->scene->removeItem(block);
            game->score1->increase1();
            delete block;
        }
    }
}
