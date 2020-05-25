#include <QApplication>
#include <QGraphicsScene>
#include "object.h"
#include <QGraphicsView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Create a scene
    QGraphicsScene *scene = new QGraphicsScene();

    // Create an item to put into the scene
    object *object1 = new object();
    object1->setRect(0, 0, 100, 100);

    // Make item focusable
    object1->setFlag(QGraphicsItem::ItemIsFocusable);
    object1->setFocus();

    // Add item to the scene
    scene->addItem(object1);

    // Add a view
    QGraphicsView *view = new QGraphicsView(scene);

    // Show a view
    view->show();

    return a.exec();
}
