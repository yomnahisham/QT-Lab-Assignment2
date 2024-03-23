#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QImage>
#include "player.h"

class Bullet : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT


public:
    Bullet(const QPointF& pos, const QImage& image, QGraphicsItem* parent = nullptr);

    Bullet();


private:
    QPointF m_position;
    QImage m_image;
    qreal m_speed;

public slots:
    void move();
};




#endif // BULLET_H
