#include "chicken.h"
#include "status.h"
#include <QGraphicsScene>
#include <stdlib.h> // rand() -> to generate really large integer
#include <QTimer>
#include <QDebug>
#include <QGraphicsPixmapItem>
#include <player.h>

Chicken::Chicken() : QObject(), QGraphicsPixmapItem(QPixmap(":/resources/img/PinkcChick .png").scaled(60, 70))
{
    // setting the postion of the enemy within the view dimensions
    int random_number = rand() % 900;
    setPos(random_number,0);

    // moving the enemies downwards automatically
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT (move()));
    timer->start(30);
 }



void Chicken:: move()
{
    // moving enemies downwards
    setPos(x(),y()+5);
    if(y()>800)
    {
        Status::decrease(); // decrease health
        scene()->removeItem(this); // remove chicken that have passed out of view
        delete this;
    }
}
