#include "player.h"
#include "status.h"
#include <QApplication>
#include <QGraphicsPixmapItem>
#include <QGraphicsTextItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QDebug>
#include <QBrush>
#include <QUrl>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QApplication>


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
    QGraphicsTextItem* scoreText = new QGraphicsTextItem();
    QGraphicsTextItem* healthText = new QGraphicsTextItem();

    // adding health and score to scene
    scene->addItem(scoreText);
    scene->addItem(healthText);

    // setting status values
    Status::setHealthText(healthText);
    Status::setScoreText(scoreText);

    // creating the player
    Player *player = new Player();
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
