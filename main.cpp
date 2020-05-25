#include<QApplication>
#include<QGraphicsScene>
#include<QGraphicsRectItem>
#include<QGraphicsView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Create a scene
    QGraphicsScene *scene = new QGraphicsScene();

    // Create an item to put into the scene
    QGraphicsRectItem *object1 = new QGraphicsRectItem();
    object1->setRect(0, 0, 100, 100);

    // Add item to the scene
    scene->addItem(object1);

    // Add a view
    QGraphicsView *view = new QGraphicsView(scene);

    // Show a view
    view->show();

    return a.exec();
}
