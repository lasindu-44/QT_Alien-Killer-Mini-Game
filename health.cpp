#include "health.h"
#include <QFont>
#include <QMessageBox>
#include <QDebug>
#include "Game.h"
Health::Health(QGraphicsItem *parent):QGraphicsTextItem(parent)
{
    //intialize the health to 0
    health=3;

    //draw the text
    setPlainText(QString("Health: " + QString::number(health)));//Health=3
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));
}

void Health::decrease()
{

    health--;
    setPlainText(QString("Health: " + QString::number(health)));// Health

    if(health==0){
       qDebug() <<"game over";
    }
}

int Health::getHealth()
{
    return health;
}
