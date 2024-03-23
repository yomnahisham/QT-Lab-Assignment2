#include "player.h"
#include <QApplication>
#include <QGraphicsPixmapItem>
#include <QGraphicsTextItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QDebug>
#include <QBrush>
#include "global.h"

bool isHit;


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // creating view
    QGraphicsView * view = new QGraphicsView();
    view->setFixedSize(1000, 800);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // creating scene
    QGraphicsScene * scene =  new QGraphicsScene() ;
    scene->setSceneRect(0, 0, 1000, 800);

    // initializing health and score
    QGraphicsTextItem* healthTextItem = new QGraphicsTextItem("Health: 3");
    QGraphicsTextItem* scoreTextItem = new QGraphicsTextItem("Score: 0");
    healthTextItem->setPos(10, 10);
    scoreTextItem->setPos(10, 30);
    scene->addItem(healthTextItem);
    scene->addItem(scoreTextItem);

    // creating the player
    Player *player = new Player(healthTextItem, scoreTextItem);
    player->setPos(scene->width()/2, (scene->height() - player->pixmap().height())/2);

    // focus on player
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    // adjusting position of player
    player->setPos(view->width()/2, view->height()-player->y()/2);
    scene->addItem(player);

    // add scene ot view
    view->setScene(scene);
    view->show();

    // automatically create chicken
    QTimer * time = new QTimer();
    QObject::connect(time, SIGNAL(timeout()), player, SLOT(createChicken()));
    time->start(2000);

    return a.exec();
}
