#include "qiang.h"

#include <QBrush>

qiang::qiang(QGraphicsItem *parent,QString name):QGraphicsPixmapItem(parent)
{
    if(name == "APPLE")
    {
        setPixmap(QPixmap(":/new/images/qiang1.jpg").scaled(120,40));
    }
    else
    {
        setPixmap(QPixmap(":/new/images/qiang2.jpg").scaled(40,120,Qt::KeepAspectRatio));
    }
}
