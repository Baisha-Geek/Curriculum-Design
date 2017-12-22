#include "button.h"
#include <QGraphicsTextItem>
#include <QBrush>

Button::Button(QString name, QGraphicsItem *parent)
    :QGraphicsRectItem(parent)
{
    //画框
    setRect(0,0,200,50);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::darkRed);
    setBrush(brush);

    //写字
    text = new QGraphicsTextItem(name,this);
    int xPos = rect().width()/2 - text->boundingRect().width()/2;
    int yPos = rect().height()/2 - text->boundingRect().height()/2;
    text->setPos(xPos,yPos);
    text->setDefaultTextColor(Qt::white);

    setAcceptHoverEvents(true);
}

void Button::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(event)
    emit clicked();

}

//鼠标事件，如果指针进入按钮就变色
void Button::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    //change color
    if(event){
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::red);
    setBrush(brush);
    }
}
//鼠标事件，如果指针离开按钮就变色
void Button::hoverLeaveEvent(QGraphicsSceneHoverEvent *event) {
    //change color
    if(event){
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::darkRed);
    setBrush(brush);
    }
}
