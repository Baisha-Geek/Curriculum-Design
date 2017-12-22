#ifndef LOGINDLG_H
#define LOGINDLG_H

#include <QDialog>
#include <zhuce.h>
namespace Ui
{
    class loginDlg;
}

class loginDlg : public QDialog
{
    Q_OBJECT

public:
    explicit loginDlg(QWidget *parent = 0);
    ~loginDlg();

private slots:
    void on_loginBtn_clicked();

    void on_zhuceBtn_clicked();
    void loginButtonToUse();
    void shownormal();

private:
    Ui::loginDlg *ui;
    //zhuce zhuceDlg;

signals:
   void sendData(QString);
};

#endif // LOGINDLG_H
