#include "game.h"
#include "ball.h"
#include "paddle.h"
#include "block.h"
#include "score1.h"

Game::Game(QWidget *parent): QGraphicsView(parent){
    // initialize scene
    scene = new QGraphicsScene(0, 0, 1400, 900);
    setScene(scene);

    // Add a view
    QGraphicsView *view = new QGraphicsView(scene);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // Show a view
    view->show();

    // Set a view at fixed size
    view->setFixedSize(1400, 900);

    // Create a score
    Score1 *score1 = new Score1();

    // Add score to the scene
    scene->addItem(score1);

    // set mouse tracking
    setMouseTracking(true);
}

void Game::start()
{
    // create a ball
    Ball* ball = new Ball();
    ball->setPos(200,500);
    scene->addItem(ball);

    // create a paddle
    Paddle* paddle = new Paddle();
    paddle->setPos(150, 800);
    scene->addItem(paddle);
    paddle->grabMouse();

    // create the blocks grid
    creatBlockGrid();
}

void Game::createBlockCol(double x)
{
    for (size_t i = 0, n = 8; i < n; ++i)
    {
        Block* block = new Block();
        block->setPos(x,i*52); // 2 space b/w blocks (50 height of block)
        scene->addItem(block);
    }
}

void Game::creatBlockGrid()
{
    for (size_t i = 0, n = 10; i < n; ++i)
    {
        createBlockCol(i*102);
    }
}
