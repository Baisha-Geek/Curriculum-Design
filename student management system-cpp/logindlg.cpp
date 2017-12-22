#include "logindlg.h"
#include "ui_logindlg.h"
#include <QMessageBox>
#include <zhuce.h>
#include <QFile>
#include <QDataStream>
#include <QString>
#include <mainwindow.h>
extern QString username;

loginDlg::loginDlg(QWidget *parent) :QDialog(parent),ui(new Ui::loginDlg)
{
    ui->setupUi(this);
    QPalette q;
    q.setBrush(QPalette::Background,QBrush(QPixmap(":/new/images/bg.jpg").scaled(this->size())));
    this->setPalette(q);
    ui->loginBtn->setEnabled(false);
    QObject::connect(ui->uselineEdit,SIGNAL(textChanged(QString)),this,SLOT(loginButtonToUse()));
    QObject::connect(ui->pwdlineEdit,SIGNAL(textChanged(QString)),this,SLOT(loginButtonToUse()));
}

loginDlg::~loginDlg()
{
    delete ui;
}

void loginDlg::shownormal()
{
    this->showNormal();
}

void loginDlg::loginButtonToUse()
{
    ui->loginBtn->setEnabled(true);
}

void loginDlg::on_loginBtn_clicked()
{
    int i=1;
    int m=0;
    QFile file("admin");
    file.flush();
    if (!file.open(QIODevice::ReadWrite))
    {
        QMessageBox::warning(this,"Error",tr("open file error:%1").arg(file.errorString())),QMessageBox::Yes;
        ui->uselineEdit->clear();
        ui->pwdlineEdit->clear();
        ui->uselineEdit->setFocus();
        return;
    }
    QDataStream out(&file);
    while(!out.atEnd())
    {
        QString user;
        QString password;
        out >> user >> password;
        if(ui->uselineEdit->text().trimmed() == user && ui->pwdlineEdit->text() == password)
        {
            i=0;
            m = 1;
            username = user;
            break;
        }
    }
    if (i)
    {
        QMessageBox::warning(this,"Waring","user name or passward error"),QMessageBox::Yes;
        ui->uselineEdit->clear();
        ui->pwdlineEdit->clear();
        ui->uselineEdit->setFocus();
    }
    file.close();

    /*创建主窗口*/
    if (m)
    {
        ui->uselineEdit->clear();
        ui->pwdlineEdit->clear();
        ui->uselineEdit->setFocus();

        MainWindow *mainwindow = new MainWindow(this);
        this->hide();
        mainwindow->show();
    }
}

/*创建注册窗口*/
void loginDlg::on_zhuceBtn_clicked()
{
    zhuce *zhuceDlg = new zhuce(this);
    this->hide();
    zhuceDlg->show();

    ui->uselineEdit->clear();
    ui->pwdlineEdit->clear();
}
