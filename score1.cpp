#include <QFont>
#include "score1.h"

Score1::Score1(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    // Initialize the score to 0
    score1 = 0;

    // Draw the text
    setPlainText(QString::number(score1));
    setDefaultTextColor(Qt::yellow);
    setFont(QFont("arial rounded mt bold", 25));
    setPos(695,855);
}

void Score1::increase1()
{
    score1++;
    setPlainText(QString::number(score1));
}

int Score1::getScore1()
{
    return score1;
}
