#include <bullet.h>
#include <chicken.h>
#include <player.h>
#include <QGraphicsScene>
#include <QTimer>
#include <QList>

Bullet::Bullet() : QObject(), QGraphicsPixmapItem()
{
    QPixmap bulletImage(":/resources/img/red_laser.png");
    setPixmap(bulletImage.scaled(40, 50));

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);
}

Bullet::Bullet(const QPointF& pos, const QImage& image, QGraphicsItem* parent)
    : QGraphicsPixmapItem(parent),
    m_position(pos),
    m_image(image),
    m_speed(10.0) {
    setPixmap(QPixmap::fromImage(image));
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
