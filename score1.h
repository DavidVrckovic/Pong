#ifndef SCORE1_H
#define SCORE1_H

#include <QGraphicsTextItem>

class Score1: public QGraphicsTextItem
{
public:
    Score1(QGraphicsItem *parent = 0);
    void increase1();
    int getScore1();
private:
    int score;
};

#endif // SCORE1_H
