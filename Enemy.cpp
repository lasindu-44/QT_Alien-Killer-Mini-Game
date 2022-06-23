#include "Enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h>
#include "Game.h"

extern Game * game;

Enemy::Enemy(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    //set Random Position
    int random_number =rand() % 700;
    setPos(random_number,0);
    // drew the enmey
     setPixmap(QPixmap(":/images/Resources/Images/Enemy.png"));

    //connect
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);

}

void Enemy::move()
{
    //move enmy down
    setPos(x(),y()+5);
    //destroy enemy when it goes out of the screen
    if(pos(),y()  >600){

        //secrease the health
        game->health->decrease();


        scene()->removeItem(this);
        delete this;


    }
}
