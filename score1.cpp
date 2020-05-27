#include <QFont>
#include "score1.h"

Score1::Score1(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    // Initialize the score to 0
    score = 0;

    // Draw the text
    setPlainText(QString::number(score));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times", 20));
}

void Score1::increase1()
{
    score++;
    setPlainText(QString::number(score));
}

int Score1::getScore1()
{
    return score;
}
