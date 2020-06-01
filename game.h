#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <score1.h>

class Game: public QGraphicsView
{
    Q_OBJECT
public:
    // constructors
    Game(QWidget* parent=NULL);

    void displayMainMenu();

    QGraphicsScene* scene;
    Score1 *score1;

    void createBlockCol(double x);
    void creatBlockGrid();

public slots:
    void start();

};

#endif // GAME_H
