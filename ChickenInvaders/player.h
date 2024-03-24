#ifndef PLAYER_H
#define PLAYER_H
#include <QGraphicsItem>
#include <QObject>
#include "chicken.h"
#include <QMediaPlayer>


class Player: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    QGraphicsTextItem* healthText;
    QGraphicsTextItem* scoreText;
    QMediaPlayer * bulletsound;


public:
    Player();
    void keyPressEvent(QKeyEvent * event);

public slots:
    void createChicken();

};


#endif // PLAYER_H
