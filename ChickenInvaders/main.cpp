#include "player.h"
#include <QApplication>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QDebug>
#include <QBrush>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // *******  Create the View ********
    QGraphicsView * view = new QGraphicsView();
    view->setFixedSize(1000, 800);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // ******* Create the Scene ********
    QGraphicsScene * scene =  new QGraphicsScene() ;
    scene->setSceneRect(0, 0, 1000, 800);

    // *******  Create the Player ********
    Player * player = new Player();
    player->setPos(scene->width()/2, (scene->height() - player->pixmap().height())/2);

    // *******  Setting the foucs to the Player ********
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    // *******  Adjust the location of the Player (middle of the screen) ********
    player->setPos(view->width()/2, view->height()-player->y()/2);
    scene->addItem(player);

    // *******   Assign scene to the view   ***************
    view->setScene(scene);
    view->show();

    // *******  Create the Enemies automatically ********
    QTimer * time = new QTimer();
    QObject::connect(time, SIGNAL(timeout()), player, SLOT(createChicken()));
    time->start(2000);

    return a.exec();
}
