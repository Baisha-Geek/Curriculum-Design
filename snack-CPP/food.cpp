#include "food.h"

#include <QBrush>


food::food(QGraphicsItem *parent,QString name):QGraphicsPixmapItem(parent)
{
    if(name == "APPLE"){
        setPixmap(QPixmap(":/new/images/food.png").scaled(40,40));
        score = 10;
    }
    else{
        setPixmap(QPixmap(":/new/images/food2.png").scaled(40,40,Qt::KeepAspectRatio));
        score = 20;
    }
}
