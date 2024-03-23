
#ifndef PLAYER_H
#define PLAYER_H
#include <QGraphicsItem>
#include <QObject>
#include "chicken.h"

class Player: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    QGraphicsTextItem* healthText;
    QGraphicsTextItem* scoreText;
public:
    int health;
    int score;
    Player(QGraphicsTextItem* healthTextItem, QGraphicsTextItem* scoreTextItem);
    void keyPressEvent(QKeyEvent * event);
    void decrease();
    void increase();
    void showGameOver();
signals:
    void gameOver(int score);
public slots:
    void createChicken();

};


#endif // PLAYER_H
