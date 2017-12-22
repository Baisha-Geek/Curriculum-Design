#include"mineGame.h"
#include <QLayout>
#include <windows.h>
#include <QProcess>
#include <QMessageBox>
mineGame::mineGame(QWidget* parent) : QMainWindow(parent)
{
    setWindowTitle ("扫雷游戏");
    resize (600, 450);

    mine_land = new mineLand;
    setCentralWidget(mine_land);

    //游戏难度选择
    options = new GameOption(this);
    connect(options, SIGNAL(new_level(int)),mine_land,SLOT(set_level(int)));

    //游戏结束
    game_end = new GameEnd(this);
    connect(mine_land, SIGNAL(win()), game_end,  SLOT(win_show()));
    connect(mine_land, SIGNAL(lost()), game_end, SLOT(lost_show()));

    //游戏菜单
    begin_action = new QAction(QIcon(QPixmap(":/images/kai.png")), "开始");
    begin_action->setStatusTip(tr("开始新游戏"));
    connect(begin_action,SIGNAL(triggered()),mine_land,SLOT(new_game()));

    option_action = new QAction(QIcon(QPixmap(":/images/xuanxiang.png")), "选项");
    option_action->setStatusTip(tr("选择游戏难度."));
    connect(option_action,SIGNAL(triggered()),this,SLOT(new_level()));

    close_action = new QAction(QIcon(QPixmap(":/images/tui.png")), "退出");
    connect(close_action,SIGNAL(triggered()),this,SLOT(close()));


    //帮助
    info_action = new QAction(QIcon(QPixmap(":/images/shuming.png")), "说明");
    info_action->setStatusTip(tr("胜利条件."));
    connect(info_action,SIGNAL(triggered()),this,SLOT(show_help()));

    //动作添加
    game_menu = new QMenu(tr("游戏"),this);
    game_menu->addAction(begin_action);
    game_menu->addAction(option_action);
    //game_menu->addSeparator();  //加分割线
    game_menu->addAction(close_action);
    help_menu = new QMenu(tr("信息"),this);
    help_menu->addAction(info_action);

    //把菜单+到菜单栏上
    menus = menuBar();
    menus->addMenu(game_menu);
    menus->addMenu(help_menu);
    //生成状态栏
    statusBar();
    layout()->setSizeConstraint(QLayout::SetFixedSize);  //固定大小
    setWindowIcon(QIcon(tr(":/images/ico.jpeg")));
}

void mineGame::new_level()
{
    options->exec();
}
void mineGame::show_help()
{
    QMessageBox::information(this,"说明","此软件为扫雷游戏");
}

