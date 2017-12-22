#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QMessageBox>
#include <QDataStream>
#include <logindlg.h>
#include <changepassword.h>
#include "student.h"
#include <QDialog>
#include <QList>
#include <QTableView>
#include "mainmodel.h"
#include <QStandardItemModel>
#include "student.h"

int stunum, coursenum;
QDialog *Logindlg;
QList<student> students;
MainModel *mainViewModel= new MainModel;

MainWindow::MainWindow(QDialog *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Logindlg = parent;
    //connect(mainViewModel, SIGNAL(searched(int)), this, SLOT(searched(int)));

    QFile file("student");
    if (!file.open(QIODevice::ReadWrite))
    {
        QMessageBox::warning(this,"Error",tr("open file error:%1").arg(file.errorString())),QMessageBox::Yes;
        return;
    }
    if (file.size() == 0)
    {
        QMessageBox::warning(this,"提示","目前没用学生信息！");
    }
    else
    {
        QDataStream input(&file);
        while(!input.atEnd())
        {
           input >> stunum;
           student stu;
           for(int i=0; i<stunum; i++)
           {
               input >> stu.id
                     >> stu.name
                     >> stu.clase
                     >> stu.sex
                     >> stu.age
                     >> stu.dornum
                     >> stu.telnum
                     >> stu.average
                     >> coursenum;
               for(int j=0; i<coursenum; j++)
               {
                   input >> stu.courses[j].code
                         >> stu.courses[j].name
                         >> stu.courses[j].examGrades
                         >> stu.courses[j].ordGrades
                         >> stu.courses[j].synGrades
                         >> stu.courses[j].credit
                         >> stu.courses[j].rebuild;
               }}
           students << stu;
        }}
    file.close();

    ui->mainView->setModel(mainViewModel);

}


//不及格
void MainWindow::failList()
{
    /*
    QTableView *failWin = new QTableView;
    FailModel *fm = new FailModel;
    failWin->setModel(fm);
    failWin->resize(450, 300);
    failWin->show();
    */
}

//
void MainWindow::searched(int row)
{
    if (row != -1) {
        ui->mainView->selectRow(row);
    }
    else {
        QMessageBox::warning(this, QStringLiteral("警告"), QStringLiteral("未找到查询内容！"), QMessageBox::Yes);
    }
}
void MainWindow::receiveData(QString user)
{
    userName=user;
}

MainWindow::~MainWindow()
{
    delete ui;
}


/*退出系统*/
void MainWindow::on_action_11_triggered()
{
    if(QMessageBox::question(this,"提示","是否退出系统?",QMessageBox::Yes|QMessageBox::No)==QMessageBox::Yes)
    {
        this->close();
        delete this;
    }
}

/*帮助信息*/
void MainWindow::on_action_3_triggered()
{
    QMessageBox::information(this,"说明","此软件为学生成绩管理软件");
}

/*更改密码*/
void MainWindow::on_action_2_triggered()
{
    changePassword *changpass = new changePassword(this,Logindlg);
    changpass->show();
}

//插入
void MainWindow::on_action_7_triggered()
{
    if (ui->mainView->currentIndex().isValid())
    {
         mainViewModel->insertData(ui->mainView->currentIndex().row());
    }
}

//删除
void MainWindow::on_pushButton_2_clicked()
{
    if (ui->mainView->currentIndex().isValid())
    {
        mainViewModel->deleteData(ui->mainView->currentIndex().row());
    }
}

void MainWindow::on_action_9_triggered()
{
    if (ui->mainView->currentIndex().isValid())
    {
        mainViewModel->deleteData(ui->mainView->currentIndex().row());
    }
}

//添加
void MainWindow::on_pushButton_clicked()
{
    mainViewModel->addData();
}

void MainWindow::on_action_triggered()
{
    mainViewModel->addData();
}


//保存
void MainWindow::on_action_5_triggered()
{
    QFile file("student");
    file.open(QIODevice::WriteOnly);
    QDataStream out(&file);
    out << students.count();
    for (int i = 0; i < students.count(); i++)
    {
        QList<course> &cour = students[i].courses;
        out << students[i].id
            << students[i].name
            << students[i].clase
            << students[i].sex
            << students[i].age
            << students[i].dornum
            << students[i].telnum
            << students[i].average
            << cour.count();

        for (int i = 0; i < cour.count(); i++)
        {
            out << cour[i].code
                << cour[i].name
                << cour[i].examGrades
                << cour[i].ordGrades
                << cour[i].synGrades
                << cour[i].credit
                << cour[i].rebuild;
        }
    }
    file.close();
}

//查询
void MainWindow::on_pushButton_4_clicked()
{
    if (ui->searchEdit->text() == "") {
            QMessageBox::warning(this, QStringLiteral("警告"), QStringLiteral("请输入查询内容！"), QMessageBox::Yes);
            return;
        }
        if (ui->mainView->currentIndex().isValid()) {
            mainViewModel->searchNext(ui->searchEdit->text(), ui->mainView->currentIndex().row());
        }
        else
        {
            mainViewModel->searchNext(ui->searchEdit->text(), -1);
        }
}



void MainWindow::on_action_6_triggered()
{
    failList();
}
