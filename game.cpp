#include "game.h"
#include "ball.h"
#include "paddle.h"
#include "block.h"
#include "score1.h"
#include "button.h"

Game::Game(QWidget *parent): QGraphicsView(parent){

    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1400,900);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1400,900);
    setScene(scene);
}

void Game::start()
{
    scene->clear();

    setBackgroundBrush(QBrush(QImage(":/Slike/rickgame.jpg")));

    // create a ball
    Ball* ball = new Ball();
    ball->setPos(200,500);
    scene->addItem(ball);

    // create a paddle
    Paddle * paddle = new Paddle();
    paddle->setPos(150, 800);
    scene->addItem(paddle);
    paddle->grabMouse();

    // create the blocks grid
    creatBlockGrid();

    // Create a score
    score1 = new Score1();

    // Add score to the scene
    scene->addItem(score1);

    // set mouse tracking
    setMouseTracking(true);
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
    for (size_t i = 0, n = 13; i < n; ++i)
    {
        createBlockCol(i*102);
    }
}

void Game::displayMainMenu(){

    setBackgroundBrush(QBrush(QImage(":/Slike/rick.jpg")));

    QGraphicsTextItem* titleText = new QGraphicsTextItem(QString("Pong Master"));
    QFont titleFont("arial rounded mt bold",50);
    QColor titleColor("white");
    titleText->setDefaultTextColor(titleColor);
    titleText->setFont(titleFont);
    int txPos = this->width()/2 - titleText->boundingRect().width()/2;
    int tyPos = 100;
    titleText->setPos(txPos,tyPos);
    scene->addItem(titleText);

    Button* playButton = new Button(QString("Play"));
    int bxPos = 150;
    int byPos = this->height()/2 - playButton->boundingRect().height()/2;
    playButton->setPos(bxPos,byPos);
    connect(playButton,SIGNAL(clicked()),this,SLOT(start()));
    scene->addItem(playButton);

    Button* quitButton = new Button(QString("Quit"));
    int qxPos = 1050;
    int qyPos = this->height()/2 - playButton->boundingRect().height()/2;
    quitButton->setPos(qxPos,qyPos);
    connect(quitButton,SIGNAL(clicked()),this,SLOT(close()));
    scene->addItem(quitButton);

}
