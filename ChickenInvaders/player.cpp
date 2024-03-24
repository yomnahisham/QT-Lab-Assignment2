#include "player.h"
#include "bullet.h"
#include "chicken.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QMessageBox>
#include <QDebug>
#include <QMediaPlayer>

<<<<<<< HEAD
Player::Player(): QObject(), QGraphicsPixmapItem(QPixmap(":/resources/img/ship.png").scaled(70, 80)) {}
=======


Player::Player(): QObject(), QGraphicsPixmapItem(QPixmap(":/resources/img/ship.png").scaled(70, 80)) {

    bulletsound = new QMediaPlayer();
    bulletsound-> setSource(QUrl("C:\\Users\\user\\Downloads\\laser_sound.wav"));


}
>>>>>>> cb2b3711257566c6e4fc3f8ff5a0d9e371713980

void Player::keyPressEvent(QKeyEvent *event)
{
    // if left key pressed, move player left
    if(event->key()== Qt::Key_Left){
        if(x()>0){
            setPos(x()-20,y());
        }
    } else if (event->key()== Qt::Key_Right) { // if right key pressed, move right
            if(x()+100<1000)
            setPos(x()+20,y());
    } else if(event->key()== Qt::Key_Space) { // if space key pressed, fire bullet

        // creating bullet and setting position
        Bullet * bullet = new Bullet();
        bullet->setPos(x()+30,y());
        scene()->addItem(bullet);
<<<<<<< HEAD
=======

        //play bullet sound effect
        if (bulletsound->mediaStatus() == QMediaPlayer::PlayingState){

            bulletsound->setPosition(0);
        } else if (bulletsound->mediaStatus() == QMediaPlayer::StoppedState){
            bulletsound->play();


        }



>>>>>>> cb2b3711257566c6e4fc3f8ff5a0d9e371713980
    }
}

void Player::createChicken(){

    // creating chicken enemies
    Chicken* chick = new Chicken();
    scene()->addItem(chick);

}


