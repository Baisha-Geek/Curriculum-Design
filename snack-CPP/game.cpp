#include "game.h"
#include <QGraphicsTextItem>
#include <QBrush>
#include <QTextDocument>
#include <QDebug>
extern double val;
extern QString str;

Game::Game(QWidget *parent):QGraphicsView(parent)
{
    //制作view
    setFixedSize(1400,880);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //制作游戏场景
    gameScene = new QGraphicsScene(this);
    gameScene->setSceneRect(0,0,1400,880);  //设置边界
    QGraphicsPixmapItem *bg = new QGraphicsPixmapItem();
    bg->setPixmap(QPixmap(":/new/images/bg.jpg").scaled(1400,880));
    gameScene->addItem(bg);

    //gameScene to view
    setScene(gameScene);
    score = new Score();
    gameScene->addItem(score);
    snake2 = NULL;
    snake = NULL;

}

void Game::keyPressEvent(QKeyEvent *event)
{
    if(snake)
    snake->keyPressEvent(event);
    else
        QGraphicsView::keyPressEvent(event);
}

void Game::displayMainMenu(QString title,QString play)
{

    //创建标题
    titleText = new QGraphicsTextItem(title);
    QFont titleFont("arial" , 50);
    titleText->setFont( titleFont);
    int xPos = width()/2 - titleText->boundingRect().width()/2;
    int yPos = 100;
    titleText->setPos(xPos,yPos);
    gameScene->addItem(titleText);

    //增加难度系数
    bodyText = new QGraphicsTextItem("请选择难度系数0~9");
    QFont titleFont1("arial" , 20);
    bodyText->setFont(titleFont1);
    int lxPos = width()/2 - bodyText->boundingRect().width()/2;
    int lyPos = 240;
    bodyText->setPos(lxPos,lyPos);
    gameScene->addItem(bodyText);


    //创建play按钮
    Button * playButton = new Button(play,titleText);
    int pxPos = 160;
    int pyPos = 390;
    playButton->setPos(pxPos,pyPos);

    connect(playButton,SIGNAL(clicked()) , this , SLOT(start()));
    //gameScene->addItem(playButton);

    //创建quit按钮
    Button * quitButton = new Button("Quit",titleText);
    int qxPos = 160;
    int qyPos = 530;
    quitButton->setPos(qxPos,qyPos);
    connect(quitButton, SIGNAL(clicked()),this,SLOT(close()));
    //gameScene->addItem(quitButton);


    //QGraphicsProxyWidget *mlineEdit = gameScene->addWidget(new QLineEdit());

    textedit = new QGraphicsTextItem;
    textedit->setTextInteractionFlags(Qt::TextEditorInteraction);
    QFont titleFont2("arial" , 20);
    textedit->setFont(titleFont2);
    int lexPos = width()/2 - textedit->boundingRect().width()/2;
    int leyPos = 300;
    textedit->setPos(lexPos,leyPos);
    str = QString::number(val);
    textedit->setPlainText(str);
    gameScene->addItem(textedit);

    //难度选择按钮
    Button * addButton = new Button("+",titleText);
    int addxPos = 550;
    int addyPos = 200;
    addButton->setPos(addxPos,addyPos);
    connect(addButton, SIGNAL(clicked()),this,SLOT(add()));

    Button * cutButton = new Button("-",titleText);
    int cutxPos = -200;
    int cutyPos = 200;
    cutButton->setPos(cutxPos,cutyPos);
    connect(cutButton, SIGNAL(clicked()),this,SLOT(cut()));

}

void Game::add()
{
    val=val+1;
    if (val>9)
        str = "输入有误！";
    else
        str = QString::number(val);
    textedit->setPlainText(str);
}

void Game::cut()
{
    val=val-1;
    if (val<1)
        str = "输入有误！";
    else
        str = QString::number(val);
    textedit->setPlainText(str);
}


void Game::start()
{
    snake = new MoveSnake();
    snake->setFlag(QGraphicsItem::ItemIsFocusable);
    snake->setFocus();

    score->setVisible(true);
    score->setScore(0);

    gameScene->addItem(snake);
    gameScene->removeItem(titleText);
    gameScene->removeItem(bodyText);
    gameScene->removeItem(textedit);
    delete titleText;
    delete bodyText;
    delete textedit;

    QGraphicsTextItem *fenText = new QGraphicsTextItem("10分");
    QFont titleFont1("arial" , 15);
    fenText->setFont(titleFont1);
    int xPos = 80;
    int yPos = 60;
    fenText->setPos(xPos,yPos);
    gameScene->addItem(fenText);

    QGraphicsTextItem *fenText2 = new QGraphicsTextItem("20分");
    QFont titleFont2("arial" , 15);
    fenText2->setFont(titleFont2);
    int xPos2 = 80;
    int yPos2 = 120;
    fenText2->setPos(xPos2,yPos2);
    gameScene->addItem(fenText2);

    QGraphicsPixmapItem *food = new QGraphicsPixmapItem;
    food->setPixmap(QPixmap(":/new/images/food.png").scaled(40,40));
    food->setPos(20,60);
    gameScene->addItem(food);

    QGraphicsPixmapItem *food2 = new QGraphicsPixmapItem;
    food2->setPixmap(QPixmap(":/new/images/food2.png").scaled(40,40));
    food2->setPos(20,120);
    gameScene->addItem(food2);

    if (snake2)
    snake2->deleteLater();
    snake2 = snake;
}

void Game::gameOver(){
    displayMainMenu("Game Over!","Play Again");
    gameScene->removeItem(snake);
    //delete snake;
}
