#include "snakepart.h"
#include <QBrush>
#include <QDebug>
#include "game.h"
#include "food.h"
#include <typeinfo>
#include "qiang.h"
extern Game *game;
SnakePart::SnakePart(QGraphicsItem *parent):QGraphicsPixmapItem(parent)
{
    setZValue(1);

}


SnakePart *SnakePart::getForward()
{
    return forward;
}

void SnakePart::setForward(SnakePart *value)
{
    forward = value;
}

SnakePart *SnakePart::getBackward()
{
    return backward;
}

void SnakePart::setBackward(SnakePart *value)
{
    backward = value;
}

QString SnakePart::getDirection()
{
    return direction;
}

void SnakePart::setDirection( QString value)
{
    direction = value;
}


void SnakePart::move()
{
    static int first;
    //qDebug() << direction << "dsdsd";
    if (direction == "DOWN")
        this->setY(this->y()+40);
    else if(direction == "UP")
        this->setY(this->y()-40);
    else if(direction == "LEFT")
        this->setX(this->x()-40);
    else if(direction == "RIGHT")
        this->setX(this->x()+40);

    if(this->getForward()!= NULL)
        direction = this->getForward()->direction;

    if(first)
    {
        if(this->y() >= 880 )
        {
            this->setY(0);
        }
        else if(this->y()<0)
        {
            this->setY(880);
        }
        else if(this->x() < 0)
        {
            this->setX(1400);
        }
        else if(this->x() >= 1400)
        {
            this->setX(0);
        }
    }
    first++;
    if(part == "HEAD")
    {
        checkCollidingObjects();
        checkCollidingObjects2();
    }
    setImage();

}

void SnakePart::addBehind()
{
    int x;
    int y;
  //  qDebug() << 40;
    if(this->getForward()->getDirection() == "UP")
    {
        x = this->getForward()->x();
        y = this->getForward()->y() + 40;
    }
    else if(this->getForward()->getDirection() == "DOWN")
    {
        x = this->getForward()->x();
        y = this->getForward()->y() - 40;
    }
    else if(this->getForward()->getDirection() == "RIGHT")
    {
        y = this->getForward()->y();
        x = this->getForward()->x() - 40;
    }
    else if(this->getForward()->getDirection() == "LEFT")
    {
        y = this->getForward()->y();
        x = this->getForward()->x() + 40;
    }
    setPos(x,y);
}

void SnakePart::setImage()
{
    if(part == "HEAD")
    {

        if(direction == "UP")
        {
          setPixmap(QPixmap(":/new/images/headup.png").scaled(40,40));
        }
        else if(direction == "DOWN")
        {
           setPixmap(QPixmap(":/new/images/headDown.png").scaled(40,40));
        }
        else if(direction == "LEFT")
        {
            setPixmap(QPixmap(":/new/images/headLeft.png").scaled(40,40));
        }
        else if(direction == "RIGHT")
        {
            setPixmap(QPixmap(":/new/images/head.png").scaled(40,40,Qt::KeepAspectRatio));
        }
        setZValue(2);

    }
    else if(part == "TAIL")
    {
        if(direction == "UP")
        {
          setPixmap(QPixmap(":/new/images/tailUp.png").scaled(40,40));
        }
        else if(direction == "DOWN")
        {
           setPixmap(QPixmap(":/new/images/tailDown.png").scaled(40,40));
        }
        else if(direction == "LEFT")
        {
            setPixmap(QPixmap(":/new/images/tailLeft.png").scaled(40,40));
        }
        else if(direction == "RIGHT")
        {
            setPixmap(QPixmap(":/new/images/tail.png").scaled(40,40));
        }
    }
    else if (part == "PART")
    {
        if(direction == this->backward->getDirection())
        {
            if(direction == "LEFT" ||direction ==  "RIGHT")
                setPixmap(QPixmap(":/new/images/left-right.png").scaled(40,40));
            else if (direction == "UP" || direction == "DOWN")
                setPixmap(QPixmap(":/new/images/up-down.png").scaled(40,40));
        }
        else
        {
            if((direction == "UP" && this->backward->getDirection() == "LEFT")
                    || (direction == "RIGHT" && this->backward->getDirection() == "DOWN"))
                setPixmap(QPixmap(":/new/images/leftUp-downRight.png").scaled(40,40));
            else if((direction == "UP" && this->backward->getDirection() == "RIGHT")
                    || (direction == "LEFT" && this->backward->getDirection() == "DOWN"))
                setPixmap(QPixmap(":/new/images/rightUp-downLeft.png").scaled(40,40));
            else if((direction == "LEFT" && this->backward->getDirection() == "UP")
                    || (direction == "DOWN" && this->backward->getDirection() == "RIGHT"))
                setPixmap(QPixmap(":/new/images/upLeft-rightDown.png").scaled(40,40));
            else
                setPixmap(QPixmap(":/new/images/upRight-leftDown.png").scaled(40,40));

        }

    }
}


//检测碰撞
void SnakePart::checkCollidingObjects()
{
    QList <QGraphicsItem *> coll = this->collidingItems();
    for(int i = 0,n = coll.length(); i < n; i++)
    {
        food *f = dynamic_cast<food *>(coll[i]);//将一个指向基类的指针转换为一个指向派生类的指针（如果不能正确转换，则返回0——空指针）
        if(f)
        {
            QPointF thisCenter(x()+10,y()+10);
            QPointF foodCenter(f->x()+10,f->y()+10);
            QLineF ln(thisCenter,foodCenter);
            if(ln.length() == 0)   //吃到食物
            {
                game->snake->addPart();
                game->gameScene->removeItem(f);
                game->score->setScore(game->score->getScore()+f->score);
                delete f;
            }
        }
        else if(coll[i])
        {
            if(typeid(*coll[i]) == typeid(SnakePart)) //用来检测指针类型
                game->gameOver();
            return;
        }
    }
}

//撞墙
void SnakePart::checkCollidingObjects2()
{
    QList <QGraphicsItem *> coll = this->collidingItems();
    for(int i = 0,n = coll.length(); i < n; i++)
    {
        qiang *f = dynamic_cast<qiang *>(coll[i]);
        if(f)
        {
            if(y()==f->y() || x()==f->x())
            {
                game->gameOver();
            }
        }
        else if(coll[i])
        {
            if(typeid(*coll[i]) == typeid(SnakePart))
                game->gameOver();
            return;
        }
    }
}



