#include "changepassword.h"
#include "ui_changepassword.h"
#include <QFile>
#include <QDataStream>
#include <QMessageBox>
#include <QMainWindow>
QMainWindow *mainWindow;
QDialog *loginDlg;
extern QString username;

changePassword::changePassword(QMainWindow *mainwindow,QDialog *logindlg) : QDialog(logindlg),ui(new Ui::changePassword)
{
    mainWindow = mainwindow;
    loginDlg =  logindlg;
    ui->setupUi(this);
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(returnSlot()));
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(submitSlot()));
}

changePassword::~changePassword()
{
    delete ui;
}


void changePassword::submitSlot()
{
    if(!this->judgeEmpty())
    {
        this->clearAll();
        return;
    }

    int i=0, num, j=0;
    QString userName[MAX],password[MAX];
    QFile file("admin");
    if(!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::warning(this,"警告","打开用户文件失败");
        return ;
    }
    QDataStream in(&file);
    while(!in.atEnd())
    {
        in >> userName[i] >> password[i];
        if (userName[i] == username)
        {
            num = i;
        }
        i++;
    }
    file.close();

    if(password[num] != ui->oldPasswordLineEdit->text())
    {
        QMessageBox::warning(this,"警告","旧密码输入有误，请重新输入",QMessageBox::Yes);
        this->clearAll();
        return ;
    }
    else if(ui->newPasswordLineEdit->text() != ui->enterNewPasswordLineEdit->text())
    {
        QMessageBox::warning(this,"警告","两次输入密码不一致，请重新输入",QMessageBox::Yes);
        this->clearAll();
        return ;
    }
    else if(ui->oldPasswordLineEdit->text() == ui->newPasswordLineEdit->text())
    {
        QMessageBox::warning(this,"警告","新旧密码一致，请重新设置",QMessageBox::Yes);
        this->clearAll();
        return ;
    }
    else
    {
        QFile file1("admin");
        if(!file1.open(QIODevice::WriteOnly))
        {
            QMessageBox::warning(this,"警告","重写密码文件时打开文件错误");
            return ;
        }
        file1.resize(0);
        QDataStream out(&file1);
        for(j=0; j<i; j++)
        {
            if(j==num)
            {
                out<< userName[j] << ui->newPasswordLineEdit->text();
            }
            else
            {
                out << userName[j] << password[j];
            }
        }
        file1.close();
        QMessageBox::information(this,"提示","修改密码成功，请重新登录！");
        this->clearAll();
        this->close();
        mainWindow->close();
        loginDlg->showNormal();
    }
}

/*返回按钮槽函数*/
void changePassword::returnSlot()
{
    if(ui->oldPasswordLineEdit->text().isEmpty() && ui->newPasswordLineEdit->text().isEmpty() &&
            ui->enterNewPasswordLineEdit->text().isEmpty())
    {
        this->clearAll();
        this->hide();
        delete this;
    }
    else if(QMessageBox::question(this,"提示","密码尚未修改，是否退出？",QMessageBox::Yes|QMessageBox::No) == QMessageBox::Yes)
    {
        this->clearAll();
        this->hide();
        delete this;
    }
}

void changePassword::clearAll()
{
    ui->oldPasswordLineEdit->clear();
    ui->newPasswordLineEdit->clear();
    ui->enterNewPasswordLineEdit->clear();
}

bool changePassword::judgeEmpty()
{
    if(ui->oldPasswordLineEdit->text().isEmpty())
    {
        QMessageBox::warning(this,"警告","旧密码不能为空");
        return false;
    }
    else if(ui->newPasswordLineEdit->text().isEmpty())
    {
        QMessageBox::warning(this,"警告","新密码不能为空");
        return false;
    }
    else if(ui->enterNewPasswordLineEdit->text().isEmpty())
    {
        QMessageBox::warning(this,"警告","请确认新密码");
        return false;
    }
    else
        return true;
}
