#include "status.h"
#include "player.h"
#include "chicken.h"
#include "bullet.h"
#include <QString>
#include <QMessageBox>
#include <QGraphicsScene>

// setting static member variables
int Status::health = 3;
int Status::score = 0;
QGraphicsTextItem* Status::healthTextItem = nullptr;
QGraphicsTextItem* Status::scoreTextItem = nullptr;

void Status::setHealthText(QGraphicsTextItem* healthText) {
    // function to set to set health for initialization
    healthTextItem = healthText;
    healthTextItem->setPlainText("Health: " + QString::number(health));
    healthTextItem->setPos(20, 30);
}

void Status::setScoreText(QGraphicsTextItem* scoreText){
    // function to set to set score for initialization
    scoreTextItem = scoreText;
    scoreTextItem->setPlainText("Score: " + QString::number(score));
    scoreTextItem->setPos(20, 50);
}

void Status::increase() {
    // function to increase health by 100
    score += 100;
    // updating score
    scoreTextItem->setPlainText("Score: " + QString::number(score));
}

void Status::decrease() {
    // function to decrease health and score
    if (health > 0) {
        health--;
        score -= 100;
    }

    // updating health and score
    healthTextItem->setPlainText("Health: " + QString::number(health));
    scoreTextItem->setPlainText("Score: " + QString::number(score));
    QGraphicsScene* healthscene = healthTextItem->scene();

    if (health == 0) {
        // game over message
        healthscene->clear();
        QGraphicsTextItem* gameOverText = new QGraphicsTextItem();
        gameOverText->setDefaultTextColor(Qt::red);
        gameOverText->setPlainText("GAME OVER!");

        // Set the position relative to the scene
        gameOverText->setPos((healthscene->width() - gameOverText->boundingRect().width()) / 2,
                             (healthscene->height() - gameOverText->boundingRect().height()) / 2);
        healthscene->addItem(gameOverText);

        // Update existing QMessageBox content instead of creating a new one
        QMessageBox msg;
        msg.setWindowTitle(QString("Game Over"));
        msg.setText(QString("GAME OVER. Your score was ") + QString::number(score));
        msg.exec();
    }
}


