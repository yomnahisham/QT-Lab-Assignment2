#include <bullet.h>
#include <status.h>
#include <chicken.h>
#include <player.h>
#include <QGraphicsScene>
#include <QTimer>
#include <QList>
#include <QMediaPlayer>
#include <QAudioOutput>

Bullet::Bullet() : QObject(), QGraphicsPixmapItem(QPixmap(":/resources/img/red_laser.png"))
{
    // adding sound when laser is shot or constructed
    QAudioOutput* audioLaser = new QAudioOutput();
    QMediaPlayer* soundLaser = new QMediaPlayer();
    soundLaser->setSource(QUrl("qrc:/resources/sounds/lasershot.mp3"));
    soundLaser->setAudioOutput(audioLaser);
    audioLaser->setVolume(50);
    soundLaser->play();

    // moving the laser up using a timer
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);

}

void Bullet:: move()
{
    // moving the laser by 10 up
    setPos(x(),y()-10);
    if (pos().y() + 50 < 0){
        scene()->removeItem (this);   // delete the laser if it has passed out of the screen
        delete this;
    }

    // checking for colliding items and removing them accordingly
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i=0; i< colliding_items.size(); i++){
        if (typeid(*(colliding_items[i])) == typeid(Chicken)){
            Status::increase(); // increasing score whenever chicken is killed

            // adding sound when chicken is killed
            QAudioOutput* audioKill = new QAudioOutput();
            QMediaPlayer* soundKill = new QMediaPlayer();
            soundKill->setSource(QUrl("qrc:/resources/sounds/chickenKill.mp3"));
            soundKill->setAudioOutput(audioKill);
            audioKill->setVolume(50);
            soundKill->play();

            // removing chicken and bullet (all colliding items) from the screen
            scene () -> removeItem(colliding_items[i]);
            scene () -> removeItem(this);
            delete colliding_items[i];
            delete this;
            return;
        }
    }
}
