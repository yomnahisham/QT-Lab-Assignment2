#include "player.h"
#include "bullet.h"
#include "chicken.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QMessageBox>
#include <QDebug>
#include <QMediaPlayer>


Player::Player(): QObject(), QGraphicsPixmapItem(QPixmap(":/resources/img/ship.png").scaled(70, 80)) {

    bulletsound = new QMediaPlayer();
    bulletsound-> setSource(QUrl("C:\\Users\\user\\Downloads\\laser_sound.wav"));


}

void Player::keyPressEvent(QKeyEvent *event)
{
    if(event->key()== Qt::Key_Left)
    {
        if(x()>0)
        {
            setPos(x()-20,y());
        }
    }
    else if(event->key()== Qt::Key_Right)

    { if(x()+100<1000)
            setPos(x()+20,y());
    }
    else if(event->key()== Qt::Key_Space)
    {
        Bullet * bullet = new Bullet();
        bullet->setPos(x()+30,y());
        scene()->addItem(bullet);

        //play bullet sound effect
        if (bulletsound->mediaStatus() == QMediaPlayer::PlayingState){

            bulletsound->setPosition(0);
        } else if (bulletsound->mediaStatus() == QMediaPlayer::StoppedState){
            bulletsound->play();


        }



    }

}


void Player::createChicken(){

    Chicken* chick = new Chicken();
    scene()->addItem(chick);

}


