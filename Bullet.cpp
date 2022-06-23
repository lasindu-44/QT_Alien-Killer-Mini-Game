#include "Bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "Enemy.h"
#include "Game.h"

extern Game * game; // there is an external global object called game

Bullet::Bullet(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    // drew bullet
    setPixmap(QPixmap(":/images/Resources/Images/bullet2.png"));

    //connect
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);

}

void Bullet::move()
{

    //if bullet collides with enemy, destroy both
    QList<QGraphicsItem *>colliding_items =collidingItems();
    for(int i=0, n= colliding_items.size(); i <n; ++i){
        if(typeid(*(colliding_items[i])) == typeid (Enemy)){
            //increase the score
            game->score->increase();

            //remove them both
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            //delete them both
            delete colliding_items[i];
            delete this;
            return;
        }
    }

    //move the bullet up
    setPos(x(),y()-10);

    if(pos(),y() <0){

        scene()->removeItem(this);
        delete this;


    }
}
