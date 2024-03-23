#ifndef CHICKEN_H
#define CHICKEN_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>
#include <QLabel>

class Chicken: public QObject , public QGraphicsPixmapItem
{   Q_OBJECT

public:

    Chicken();


private:

    QTimer* move_timer_;

public slots:
    void move();

signals:
    void chickenDestroyed();

};

#endif // CHICKEN_H
