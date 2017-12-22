#include "mainmodel.h"
#include "student.h"
#include <QVariant>
#include <mainwindow.h>
#include <QDebug>
extern QList<student> students;
extern int stunum, coursenum;

QVariant MainModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (role == Qt::TextAlignmentRole)
    {
        return QVariant(Qt::AlignLeft | Qt::AlignVCenter);
    }
    if (role == Qt::DisplayRole)
    {
        switch (index.column())
        {
            case 0:return students[index.row()].id;
            case 1:return students[index.row()].name;
            case 2:return students[index.row()].clase;
            case 3:return students[index.row()].sex;
            case 4:return students[index.row()].age;
            case 5:return students[index.row()].dornum;
            case 6:return students[index.row()].telnum;
            case 7:return students[index.row()].average;
        }
   }
    return QVariant();
}

bool MainModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    QString id = value.toString();
        if (index.isValid() && role == Qt::EditRole && id != "")
        {
            switch (index.column()) {
            case 0:
                for (student &stu : students)if (stu.id == id)return false;
                    students[index.row()].id = value.toString(); break;
            case 1:students[index.row()].name = value.toString(); break;
            case 2:students[index.row()].clase = value.toString(); break;
            case 3:students[index.row()].sex = value.toString(); break;
            case 4:students[index.row()].age = value.toString(); break;
            case 5:students[index.row()].dornum = value.toString(); break;
            case 6:students[index.row()].telnum = value.toString(); break;
            }
            return true;
        }
        return false;
}

QVariant MainModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal)
    {
        return tableviewHead[section];
    }
    if (role == Qt::DisplayRole && orientation == Qt::Vertical)
    {
        return section+1;
    }
    return QVariant();


}

int MainModel::rowCount(const QModelIndex &parent) const
{
     return students.count();
}

int MainModel::columnCount(const QModelIndex &parent) const
{
     return 8;
}

MainModel::MainModel(QObject *parent): QAbstractTableModel(parent)
{
    tableviewHead << QStringLiteral("学号")
                  << QStringLiteral("姓名")
                  << QStringLiteral("班级")
                  << QStringLiteral("性别")
                  << QStringLiteral("年龄")
                  << QStringLiteral("宿舍")
                  << QStringLiteral("电话")
                  << QStringLiteral("选修");
}

Qt::ItemFlags MainModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
            return Qt::NoItemFlags;
        Qt::ItemFlags fg = QAbstractItemModel::flags(index);
        if (index.column() == 7)return fg;
        fg |= Qt::ItemIsEditable;
        return fg;
}


void MainModel::insertData(int i)
{
    beginResetModel();
    student stu;
    students.insert(students.begin() + i, stu);
    endResetModel();
}

void MainModel::deleteData(int i)
{
    beginResetModel();
    students.erase(students.begin() + i);
    endResetModel();
}

void MainModel::addData()
{
    beginResetModel();
    student stu;
    students << stu;
    endResetModel();
}

void MainModel::searchNext(QString content, int row)
{
    for (int i = row + 1; i < students.count(); i++) {
        if (content == students[i].id || content == students[i].name) {
           // emit searched(i);
            return;
        }
    }
    for (int i = 0; i < row + 1; i++) {
        if (content == students[i].id || content == students[i].name) {
           // emit searched(i);
            return;
        }
    }
   // emit searched(-1);
}


