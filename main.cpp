/*#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMediaPlayer>
#include <QTimer>
#include "object1.h"
#include "object2.h"
#include "ball.h"
#include "score1.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Create a scene
    QGraphicsScene *scene = new QGraphicsScene();

    // Create an item (player1) to put into the scene
    Object1 *player1 = new Object1();
    player1->setRect(0, 0, 20, 70);

    // Create an item (player2) to put into the scene
    Object2 *player2 = new Object2();
    player2->setRect(0, 0, 20, 70);

    // Create an item (ball) to put into the scene
    Ball *ball = new Ball();
    ball->setRect(0, 0, 15, 15);

    // Create a score
    Score1 *score1 = new Score1();

    // Make player1 focusable
    player1->setFlag(QGraphicsItem::ItemIsFocusable);
    player1->setFocus();

    // Make player2 focusable
    player2->setFlag(QGraphicsItem::ItemIsFocusable);
    player2->setFocus();

    // Add player1 to the scene
    scene->addItem(player1);

    // Add player2 to the scene
    scene->addItem(player2);

    // Add ball to the scene
    scene->addItem(ball);

    // Add score to the scene
    scene->addItem(score1);

    // Add a view
    QGraphicsView *view = new QGraphicsView(scene);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // Show a view
    view->show();

    // Set a view at fixed size
    view->setFixedSize(1000, 800);

    // Set scene size
    scene->setSceneRect(0, 0, 1000, 800);

    // Set player1 at position
    player1->setPos(10, 365);

    // Set player2 at position
    player2->setPos(970, 365);

    // Set ball at position
    ball->setPos(490, 395);

    // Play background music
    QMediaPlayer *background_music = new QMediaPlayer();
    background_music->setMedia(QUrl("qrc:/sounds/pong-background.mp3"));
    background_music->play();

    return a.exec();
}
*/


#include <QApplication>
#include "game.h"

Game* game;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    game = new Game();
    game->show();
    game->start();

    return a.exec();
}
