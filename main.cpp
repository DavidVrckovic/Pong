#include <QApplication>
#include <QGraphicsScene>
#include "object1.h"
#include "object2.h"
#include <QGraphicsView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Create a scene
    QGraphicsScene *scene = new QGraphicsScene();

    // Create an item (player1) to put into the scene
    object1 *player1 = new object1();
    player1->setRect(0, 0, 20, 70);

    // Create an item (player2) to put into the scene
    object2 *player2 = new object2();
    player2->setRect(0, 0, 20, 70);

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

    // Add a view
    QGraphicsView *view = new QGraphicsView(scene);

    // Show a view
    view->show();

    // Set a view at fixed size
    view->setFixedSize(1000, 800);

    // Set scene size
    scene->setSceneRect(0, 0, 1000, 800);

    // Set player1 at position
    player1->setPos(10, 330);

    // Set player2 at position
    player2->setPos(970, 330);

    return a.exec();
}
