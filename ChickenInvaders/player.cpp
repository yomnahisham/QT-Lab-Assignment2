#include "player.h"
#include "bullet.h"
#include "chicken.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QMessageBox>
#include <QDebug>

Player::Player(QGraphicsTextItem* healthTextItem, QGraphicsTextItem* scoreTextItem)
    : health(3), score(0), healthText(healthTextItem), scoreText(scoreTextItem),
    QObject(), QGraphicsPixmapItem(QPixmap(":/resources/img/ship.png").scaled(70, 80)) {}

void Player::keyPressEvent(QKeyEvent *event)
{
    if(event->key()== Qt::Key_Left)
    {
        if(x()>0)
        {
            setPos(x()-10,y());
        }
    }
    else if(event->key()== Qt::Key_Right)

    { if(x()+100<800)
            setPos(x()+10,y());
    }
    else if(event->key()== Qt::Key_Space)
    {
        Bullet * bullet = new Bullet();
        bullet->setPos(x()+30,y());
        scene()->addItem(bullet);

    }

}

void Player::createChicken(){

    Chicken* chick = new Chicken();
    scene()->addItem(chick);

}
