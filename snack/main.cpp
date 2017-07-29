#include "game.h"
#include <QApplication>
#include <QIcon>
Game *game;
double val = 1;
QString str;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon(":/new/images/snack.png"));
    game = new Game();
    game->show();
    game->displayMainMenu("贪吃蛇大作战","Play");
    return a.exec();
}
