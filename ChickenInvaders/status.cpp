#include "status.h"
#include "player.h"
#include "chicken.h"
#include "bullet.h"
#include <QString>
#include <QMessageBox>
#include <QGraphicsScene>

int Status::health = 3;
int Status::score = 0;
QGraphicsTextItem* Status::healthTextItem = nullptr;
QGraphicsTextItem* Status::scoreTextItem = nullptr;

void Status::setHealthText(QGraphicsTextItem* healthText) {
    healthTextItem = healthText;
    healthTextItem->setPlainText("Health: " + QString::number(health));
    healthTextItem->setPos(20, 30);
}

void Status::setScoreText(QGraphicsTextItem* scoreText){
    scoreTextItem = scoreText;
    scoreTextItem->setPlainText("Score: " + QString::number(score));
    scoreTextItem->setPos(20, 50);
}

void Status::increase() {
    score += 100;
    scoreTextItem->setPlainText("Score: " + QString::number(score));
}

void Status::decrease() {
    if(health > 0){
        health--;
        score -= 100;
    }
    healthTextItem->setPlainText("Health: " + QString::number(health));
    scoreTextItem->setPlainText("Score: " + QString::number(score));
    QGraphicsScene* healthscene = healthTextItem->scene();

    if(health == 0) {
        healthscene->clear();
        QGraphicsTextItem* gameOverText = new QGraphicsTextItem();
        gameOverText->setDefaultTextColor(Qt::red);
        gameOverText->setPlainText("GAME OVER!");
        gameOverText->setPos(healthscene->width() / 2, healthscene->height() / 2);

        healthscene->addItem(gameOverText);

        QMessageBox* msg = new QMessageBox();
        msg->setWindowTitle(QString("Game Over"));
        msg->setText(QString("GAME OVER. Your score was ") + QString::number(score));
        msg->exec();
    }
}
