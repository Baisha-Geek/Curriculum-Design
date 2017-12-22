#include "movesnake.h"
#include "snakepart.h"
#include <QTimer>
#include <QTime>
#include <food.h>
#include "qiang.h"
#include <QDebug>
#include <QFont>
#include "game.h"
extern double val;
extern Game *game;

MoveSnake::MoveSnake(QGraphicsItem *parent):QGraphicsRectItem(parent)
{
    snakeHead = new SnakePart(this);
    snakeHead->setForward(NULL);
    snakeHead->setBackward(NULL);
    snakeHead->setPos(760,400);
    snakeHead->setDirection("RIGHT");
    snakeHead->part = "HEAD";
    snakeHead->setImage();
    snakeTail = snakeHead;

    t = new QTimer();
    connect(t,SIGNAL(timeout()),this,SLOT(move()));

    foodTimer = new QTimer();
    connect(foodTimer,SIGNAL(timeout()),this,SLOT(makeFood()));

    food2Timer = new QTimer();
    connect(food2Timer,SIGNAL(timeout()),this,SLOT(makeFood2()));

    if (val>3)
    {
        qiangTimer = new QTimer();
        connect(qiangTimer,SIGNAL(timeout()),this,SLOT(makeqiang()));

        qiang2Timer = new QTimer();
        connect(qiang2Timer,SIGNAL(timeout()),this,SLOT(makeqiang2()));
    }

    clearTimer = new QTimer();
    connect(clearTimer,SIGNAL(timeout()),this,SLOT(clear()));

    direction = "RIGHT";

    addPart();
    addPart();

    text = new QGraphicsTextItem(this);
    text->setVisible(true);
    text->setPlainText("Press Space to continue");
    int txPos = 700 - text->boundingRect().width()/2;
    int tyPos = 300;
    text->setPos(txPos,tyPos);
    text->setFont(QFont("",14));
    if (val>7)
    {
        makeBoard(); //显示网格
    }
}

void MoveSnake::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Down && snakeHead->getDirection() != "UP")
    {
      //  snake->setY(snake->y()+40);
        direction = "DOWN";
    }
    else if(event->key() == Qt::Key_Up && snakeHead->getDirection() != "DOWN")
    {
      //  snake->setY(snake->y()-40);
        direction = "UP";
    }
    else if(event->key() == Qt::Key_Right && snakeHead->getDirection() != "LEFT")
    {
      //  snake->setX(snake->x()+40);
        direction = "RIGHT";
    }
    else if(event->key() == Qt::Key_Left && snakeHead->getDirection() != "RIGHT")
    {
        //snake->setX(snake->x()-40);
        direction = "LEFT";
    }
    else if(event->key() == Qt::Key_Space)
    {
        if(t->isActive())
        {
            foodTimer->stop();
            food2Timer->stop();
            if (val >3)
            {
                qiangTimer->stop();
                qiang2Timer->stop();
            }
            clearTimer->stop();
            t->stop();
            text->setVisible(true);
        }
        else
        {
            foodTimer->start(3000);
            food2Timer->start(7000);
            if (val >3)
            {
                qiangTimer->start((12-val)*1000);
                qiang2Timer->start((11-val)*1000);
            }
            clearTimer->start(6000);
            t->start((12-val)*22);  //设置难度系数

            qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
            text->setVisible(false);
        }
    }
}


void MoveSnake::makeBoard()
{
    for(int i = 0 ;i <9*5;i++)
    {
        for(int j = 0; j < 14*5; j++)
        {
            QGraphicsRectItem *rect= new QGraphicsRectItem(this);
            rect->setRect(j*40,i*40,40,40);
        }
    }
}

void MoveSnake::move()
{
    snakeHead->setDirection(direction);
    moveSnake();
}

void MoveSnake::makeFood()
{
    food * f1 = new food(this,"APPLE");
    f1->setX(qrand() % (1400/40)* 40 + 160);
    f1->setY(qrand() % (880/40) * 40 + 160);
}
void MoveSnake::makeFood2()
{
    food * f1 = new food(this);
    f1->setX(qrand() % (1400/40)* 40 + 160);
    f1->setY(qrand() % (880/40) * 40 + 160) ;
}

void MoveSnake::makeqiang()
{
    qiang *f1 = new qiang(this,"APPLE");
    f1->setX(qrand() % (1400/40)* 40 + 160);
    f1->setY(qrand() % (880/40) * 40 + 160) ;
}

void MoveSnake::makeqiang2()
{
    qiang *f1 = new qiang(this);
    f1->setX(qrand() % (1400/40)* 40 + 160);
    f1->setY(qrand() % (880/40) * 40 + 160) ;
}

void MoveSnake::clear()
{
    QList <QGraphicsItem *> coll = this->collidingItems();
    for(int i = 0,n = coll.length(); i < n; i++)
    {
        food *f = dynamic_cast<food *>(coll[i]);
        if (f)
        {
            game->gameScene->removeItem(f);
            delete f;
        }
    }
}

void MoveSnake::addPart()
{
    SnakePart *part = new SnakePart(this);
    SnakePart *temp = snakeHead;
    while(temp->getBackward() != NULL)
    {
        temp = temp->getBackward();
    }

    temp->setBackward( part);
    part->setForward( temp);
    part->setBackward(NULL);
    part->addBehind();
    part->setDirection(temp->getDirection());
    snakeTail = part;
    part->part = "TAIL";
    if(temp != snakeHead)
    temp->part = "PART";
    part->setImage();
    temp->setImage();
}

void MoveSnake::moveSnake()
{
   SnakePart *temp = snakeTail;
   while(temp!=NULL)
   {
       temp->move();
       temp = temp->getForward();
   }
}

