#include "chicken.h"
#include <QGraphicsScene>
#include <stdlib.h> // rand() -> to generate really large integer
#include <QTimer>
#include <QDebug>
#include <QGraphicsPixmapItem>
#include <player.h>

Chicken::Chicken() : QObject(), QGraphicsPixmapItem(QPixmap(":/resources/img/PinkcChick .png"))
{
    // *******  Setting the postion of the enemy within the view dimensions ********
    int random_number = rand() % 700;
    setPos(random_number,0);

    // *******  Moving the enemies downwards automatically every 50 milli second ********
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT (move()));
    timer->start(50);
 }


// Function move: move the enemy downwards untill the end of the scene then remove it and delete it
void Chicken:: move()
{
    setPos(x(),y()+5);
    if(y()+100>800)
    {
        scene()->removeItem(this);
        delete this;
    }
}
