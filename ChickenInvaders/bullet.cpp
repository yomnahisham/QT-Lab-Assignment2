#include <bullet.h>
#include <chicken.h>
#include <player.h>
#include <QGraphicsScene>
#include <QTimer>
#include <QList>

Bullet::Bullet() : QObject(), QGraphicsPixmapItem(QPixmap(":/resources/img/red_laser.png"))
{
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
            scene () -> removeItem(colliding_items[i]);
            scene () -> removeItem(this);
            delete colliding_items[i];
            delete this;
            return;
        }
    }
}
