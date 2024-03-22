#ifndef PLAYER_H
#define PLAYER_H
#include <QGraphicsItem>
#include <QObject>

class Player: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Player();
public:
    void keyPressEvent(QKeyEvent * event);
public slots:
    void createChicken();

};

#endif // PLAYER_H
