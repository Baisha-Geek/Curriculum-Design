#include "zhuce.h"
#include "ui_zhuce.h"
#include <QDataStream>
#include <QFile>
#include <QMessageBox>
#include "logindlg.h"

zhuce::zhuce(QWidget *parent) :QDialog(parent),ui(new Ui::zhuce)
{
    ui->setupUi(this);

    connect(ui->returnbutton,SIGNAL(clicked()),parent,SLOT(shownormal()));
    connect(ui->returnbutton,SIGNAL(clicked()),this,SLOT(close()));
}

zhuce::~zhuce()
{
    delete ui;
}

void zhuce::on_pushButton_clicked()
{
    int i=0;
    QFile file("admin");
    if (!file.open(QIODevice::ReadWrite))
    {
        QMessageBox::warning(this,"Error",tr("open file error:%1").arg(file.errorString())),QMessageBox::Yes;
        return;
    }

    QDataStream in(&file);
    while(!in.atEnd())
    {
        QString user;
        QString password;
        in >> user >> password;
        if(ui->lineEdit->text().trimmed() == user)
        {
            QMessageBox::warning(this,"Error","用户已存在！"),QMessageBox::Yes;
            ui->lineEdit->clear();
            ui->lineEdit_2->clear();
            ui->lineEdit_3->clear();
            ui->lineEdit->setFocus();
            break;
        }
        else
            i=1;
    }

    file.seek(file.size()); //转到文件末尾；
    if (i || file.size()==0)
    {
        if (ui->lineEdit_2->text().trimmed() == ui->lineEdit_3->text().trimmed())
        {
            in << ui->lineEdit->text().trimmed();
            in << ui->lineEdit_2->text().trimmed();

            QMessageBox::information(this,"提示","用户注册成功！"),QMessageBox::Yes;
            ui->lineEdit->clear();
            ui->lineEdit_2->clear();
            ui->lineEdit_3->clear();
        }
        else
        {
            QMessageBox::warning(this,"Error","两次输入的密码不一致！"),QMessageBox::Yes;
            ui->lineEdit->clear();
            ui->lineEdit_2->clear();
            ui->lineEdit_3->clear();
            ui->lineEdit->setFocus();
            return;
        }
    }
    file.close();
}

