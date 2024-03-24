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
    QAudioOutput* audioLaser = new QAudioOutput();
    QMediaPlayer* soundLaser = new QMediaPlayer();
    soundLaser->setSource(QUrl("qrc:/resources/sounds/lasershot.mp3"));
    soundLaser->setAudioOutput(audioLaser);
    audioLaser->setVolume(50);
    soundLaser->play();

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);

}

void Bullet:: move()
{
    setPos(x(),y()-10);
    if (pos().y() + 50 < 0){
        scene()->removeItem (this);
        delete this;
    }

    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i=0; i< colliding_items.size(); i++){
        if (typeid(*(colliding_items[i])) == typeid(Chicken)){
            Status::increase();

            QAudioOutput* audioKill = new QAudioOutput();
            QMediaPlayer* soundKill = new QMediaPlayer();
            soundKill->setSource(QUrl("qrc:/resources/sounds/chickenKill.mp3"));
            soundKill->setAudioOutput(audioKill);
            audioKill->setVolume(50);
            soundKill->play();

            scene () -> removeItem(colliding_items[i]);
            scene () -> removeItem(this);
            delete colliding_items[i];
            delete this;
            return;
        }
    }
}
