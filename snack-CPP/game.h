#ifndef GAME_H
#define GAME_H
#include <QGraphicsView>
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QLabel>
#include <QLineEdit>
#include "movesnake.h"
#include <QGraphicsRectItem>
#include "score.h"
#include "button.h"

class Game:public QGraphicsView
{
    Q_OBJECT
public:
    Game(QWidget *parent = 0);
    void keyPressEvent(QKeyEvent *event);
    Score *score;
    QGraphicsScene *gameScene ;
    MoveSnake *snake;
    MoveSnake *snake2;
    void displayMainMenu(QString title, QString play);
    QGraphicsTextItem *titleText;
    QGraphicsTextItem *bodyText;//
    QGraphicsTextItem *textedit;

    Button *b;
    void gameOver();
public slots:
    void start();
    void add();
    void cut();
};

#endif // GAME_H

