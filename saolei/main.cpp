#include "mineGame.h"
#include <QApplication>
#include <QSplashScreen>

int main(int argc , char** argv)
{
    QApplication app(argc,argv);
    mineGame game;
    game.show();
    return app.exec();
}
