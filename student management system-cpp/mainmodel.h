#ifndef MAINMODEL_H
#define MAINMODEL_H
#include <QAbstractTableModel>
#include <QStringList>

class MainModel : public QAbstractTableModel
{
public:
     MainModel(QObject *parent = 0);

     int rowCount(const QModelIndex &parent) const;
     int columnCount(const QModelIndex &parent) const;

     QVariant data(const QModelIndex &index, int role) const;

     QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;

     bool setData ( const QModelIndex & index, const QVariant &value, int role = Qt::EditRole );

     Qt::ItemFlags flags(const QModelIndex &index) const;

     QStringList tableviewHead;

    // bool insertRows(int position,int rows,const QModelIndex &index = QModelIndex());

     //bool removeRows(int position,int rows,const QModelIndex &index = QModelIndex());

    void insertData(int i);
    void deleteData(int i);
    void addData();
    void searchNext(QString content, int row);

signals:
    void searched(int);
};

#endif // MAINMODEL_H
