#include "GameEnd.h"
#include <QVBoxLayout>

GameEnd::GameEnd(QWidget* parent):QDialog(parent)
{  
    con = true;
    show_label = new QLabel;
    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(show_label);
    setLayout(layout);
    setWindowTitle(tr("Come On !"));
}
void GameEnd::win_show()
{
    con = true;
    how_show();
}
void GameEnd::lost_show()
{
    con = false;
    how_show();
}
void GameEnd::how_show()
{
    QPalette pt = show_label->palette();

    if(con == true)   //显示胜率or失败，同时显示不同颜色
    {
        QPixmap win_map(":/images/ok.jpg");
        show_label->setPixmap(win_map);
    }
    else if(con == false)
    {
        QPixmap lose_map(":/images/end1.jpg");
        show_label->setPixmap(lose_map);
    }
    exec();
}
void GameEnd::closeEvent(QCloseEvent*)
{
    hide();
}
